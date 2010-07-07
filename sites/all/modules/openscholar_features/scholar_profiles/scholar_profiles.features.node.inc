<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _scholar_profiles_node_info() {
  $items = array(
    'person' => array(
      'name' => t('Person'),
      'module' => 'features',
      'description' => t('Represents a profile / person'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Short bio'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}