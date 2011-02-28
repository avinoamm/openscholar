<?php

/**
 * Imports an image as a filefield image of a given node
 * 
 * Usage example:
 * --------------
 * $node = node_load(array('nid' => 61));
 * $image = drupal_get_path('module', 'vsite_design').'/theme/images/default_logo.jpg';
 * simport_node_add_imagefield_image($image, 'field_img', $node);
 * 
 * @param $source  the path to the source image
 * @param $field_name the name of the cck field 
 * @param $node the node object to upload the image to (passed by reference)
 */
function simport_node_add_cck_file($source, $field_name, &$node, $validate = NULL){

  // get the cck filefield
  $field = content_fields($field_name, $node -> type);
 
  if($validate){
  // validators (can add our own validators if we want)
 $validators = array_merge(filefield_widget_upload_validators($field), imagefield_widget_upload_validators($field));
  }
  // where to store the file
  $files_path = filefield_widget_file_path($field);
  
  $sid = ($node->type == 'vsite') ? $node->nid : key($node->og_groups);
  
  //special case for cv because the node has not been saved yet
 if($node -> type == 'cv'){    
    $sid = $node->og_groups[0];
  }
    
  $vsite = spaces_load('og', $sid);
    
  if ($vsite->purl){    
  simport_create_file_dirs($vsite);    
  
  //modify files path
  $files_path=  $files_path . $vsite->purl . '/files/'; 

  // create the file object
  $file = field_file_save_file($source, $validators, $files_path);

  //set uid to the node -> uid
 // $file -> uid = $node -> uid;

  // attach it to the filefield field
  $node->$field_name = array(
  0 => array(
  'fid' => $file['fid'],
  'uid' => $node -> uid,
  'list' => 1,
    )
  ); 
  
  // save the node (optional)
  node_save($node);
  }
}


function simport_create_file_dirs($vsite){
    //determine site files directory, if set
  $dir = isset($vsite) ? '/'. $vsite->purl : '';
  
  //create path to destination - Need to create dirs one level at a time
  // TODO: should get destination path token/filefield paths in content type settings.  
   $vsite_files_path = variable_get('simport_current_path', '') . '/' . variable_get('file_directory_path', conf_path() .'/files') . $dir ;
  file_check_directory($vsite_files_path, $mode = 1, $form_item = NULL);
   
  $full_dest_path = variable_get('simport_current_path', '') . '/' . variable_get('file_directory_path', conf_path() .'/files') . $dir  . '/files';
  file_check_directory($full_dest_path, $mode = 1, $form_item = NULL);
	
}

/**
 * Helper function to transfer the file and create entry in files table
 * Returns file id
 *
 * @param unknown_type $src_path
 * @param unknown_type $dest_path
 * @param unknown_type $file
 * @param unknown_type $uid
 */
function simport_import_file(&$node, $source, $file = NULL, $vsite = NULL){

  //determine site files directory, if set
  $dir = isset($vsite) ? '/'. $vsite->purl : '';
  
  //create path to destination - Need to create dirs one level at a time
  // TODO: should get destination path token/filefield paths in content type settings.  
   $vsite_files_path = variable_get('simport_current_path', '') . '/' . variable_get('file_directory_path', conf_path() .'/files') . $dir ;
  file_check_directory($vsite_files_path, $mode = 1, $form_item = NULL);
   
  $full_dest_path = variable_get('simport_current_path', '') . '/' . variable_get('file_directory_path', conf_path() .'/files') . $dir  . '/files';
  file_check_directory($full_dest_path, $mode = 1, $form_item = NULL);

  //copy file
  file_copy($source, $full_dest_path, $replace = FILE_EXISTS_REPLACE);

  if ($file){
    //customize a object a little bit
    $file -> uid = $node -> uid;  
    $file-> filepath = variable_get('file_directory_path', conf_path() .'/files') . $dir .  '/files/' . $file-> filename;
    $file -> status = 1;
    $file -> timestamp = time();
  }

  // Get file information from source
  else{
    $file = new stdClass();
    $file -> uid = $node -> uid;
    $file -> filename = basename($source);
    $file -> filepath = dirname($source);
    $file -> filemime = file_get_mimetype($source);
    $file -> filesize = filesize($source);
    $file -> status =1;
    $file -> timestamp = filemtime($source); // TODO: should use modified time as timestamp?
  }

  //write data to files table
  drupal_write_record('files', $file);
   
  //return file object
  return $file;
}



function simport_save_upload_data($file, $node){
  if(!is_object($file)){
    drupal_set_message(t('Error: file variable not object'));
    return;
  }
  //If file had description text add it here
  $file->description =  isset($description) ? $description : $file -> filename;
  $file->list = 1;

 
  //taken from upload_save()
  db_query("INSERT INTO {upload} (fid, nid, vid, list, description, weight) VALUES (%d, %d, %d, %d, '%s', %d)", $file->fid, $node->nid, $node->vid, $file->list, $file->description, $file->weight);
  file_set_status($file, FILE_STATUS_PERMANENT);
}

/**
 * Pass it a vocalulary id and returns array of terms belonging to it
 * @param int $vid- vocabulary id
 */
function simport_import_list_terms($vid){
  $vocab = taxonomy_get_tree($vid);
  foreach ($vocab as $term){    
  $terms[] = strtolower($term -> name);    
  }
  return $terms;
}