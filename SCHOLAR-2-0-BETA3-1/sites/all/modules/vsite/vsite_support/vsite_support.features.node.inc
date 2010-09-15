<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _vsite_support_node_info() {
  $items = array(
    'feature_request' => array(
      'name' => t('Feature request'),
      'module' => 'features',
      'description' => t(''),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
    ),
    'support_answer' => array(
      'name' => t('Answer'),
      'module' => 'features',
      'description' => t(''),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
    ),
    'support_question' => array(
      'name' => t('Question'),
      'module' => 'features',
      'description' => t(''),
      'has_title' => '1',
      'title_label' => t('Question'),
      'has_body' => '1',
      'body_label' => t('Description'),
    ),
  );
  return $items;
}