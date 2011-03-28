<?php

/**
 * Implementation of hook_strongarm().
 */
function openscholar_front_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_sitewide_page';
  $strongarm->value = COMMENT_NODE_DISABLED;

  $export['comment_sitewide_page'] = $strongarm;
  return $export;
}