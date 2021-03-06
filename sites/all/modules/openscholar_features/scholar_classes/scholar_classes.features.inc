<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function scholar_classes_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => 1);
  }
  elseif ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function scholar_classes_node_info() {
  $items = array(
    'class' => array(
      'name' => t('Class'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'class_material' => array(
      'name' => t('Class Material'),
      'module' => 'features',
      'description' => t('A post related to a class'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function scholar_classes_views_api() {
  return array(
    'api' => '2',
  );
}

/**
 * Implementation of hook_wysiwyg_fields_icons().
 */
function scholar_classes_wysiwyg_fields_icons() {
  return array(
    drupal_get_path('module', 'scholar_classes') . '/images/wysiwyg_fields',
  );
}