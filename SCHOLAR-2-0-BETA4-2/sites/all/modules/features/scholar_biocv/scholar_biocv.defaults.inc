<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _scholar_biocv_content_default_fields() {
  $fields = array();

  // Exported field: field_cv_attach
  $fields[] = array(
    'field_name' => 'field_cv_attach',
    'type_name' => 'cv',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'pdf',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'PDF Upload',
      'weight' => '31',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Translatables
  array(
    t('PDF Upload'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_biocv_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'biocv',
    'description' => 'scholar > biocv',
    'path' => array(
      'biocv' => 'biocv',
    ),
    'block' => array(
      'vsite_taxonomy_0' => array(
        'module' => 'vsite_taxonomy',
        'delta' => '0',
        'weight' => -20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Scholar site categories',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _scholar_biocv_user_default_permissions() {
  $permissions = array();

  // Exported permission: create bio content
  $permissions[] = array(
    'name' => 'create bio content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: create cv content
  $permissions[] = array(
    'name' => 'create cv content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: delete own bio content
  $permissions[] = array(
    'name' => 'delete own bio content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: delete own cv content
  $permissions[] = array(
    'name' => 'delete own cv content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: edit own bio content
  $permissions[] = array(
    'name' => 'edit own bio content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: edit own cv content
  $permissions[] = array(
    'name' => 'edit own cv content',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override bio revision option
  $permissions[] = array(
    'name' => 'override bio revision option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override bio sticky option
  $permissions[] = array(
    'name' => 'override bio sticky option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override cv revision option
  $permissions[] = array(
    'name' => 'override cv revision option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  // Exported permission: override cv sticky option
  $permissions[] = array(
    'name' => 'override cv sticky option',
    'roles' => array(
      '0' => 'scholar admin',
    ),
  );

  return $permissions;
}