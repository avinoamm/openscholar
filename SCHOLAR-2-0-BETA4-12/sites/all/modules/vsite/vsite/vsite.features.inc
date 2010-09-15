<?php

/**
 * Implementation of hook_content_default_fields().
 */
function vsite_content_default_fields() {
  module_load_include('inc', 'vsite', 'vsite.defaults');
  $args = func_get_args();
  return call_user_func_array('_vsite_content_default_fields', $args);
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function vsite_imagecache_default_presets() {
  module_load_include('inc', 'vsite', 'vsite.defaults');
  $args = func_get_args();
  return call_user_func_array('_vsite_imagecache_default_presets', $args);
}

/**
 * Implementation of hook_node_info().
 */
function vsite_node_info() {
  module_load_include('inc', 'vsite', 'vsite.features.node');
  $args = func_get_args();
  return call_user_func_array('_vsite_node_info', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function vsite_user_default_permissions() {
  module_load_include('inc', 'vsite', 'vsite.defaults');
  $args = func_get_args();
  return call_user_func_array('_vsite_user_default_permissions', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function vsite_views_default_views() {
  module_load_include('inc', 'vsite', 'vsite.features.views');
  $args = func_get_args();
  return call_user_func_array('_vsite_views_default_views', $args);
}