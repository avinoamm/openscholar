<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function scholar_announcements_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'scholar-feature-announcements';
  $context->description = 'Announcements feature context';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        0 => 'announcement',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        0 => 'scholar_announcements',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'menu' => 'announcements',
    'block' => array(
      'blocks' => array(
        'views-scholar_announcements-block_1' => array(
          'module' => 'views',
          'delta' => 'scholar_announcements-block_1',
          'weight' => -21,
          'region' => 'right',
          'status' => '0',
          'label' => 'Latest Announcements',
          'type' => 'context_ui',
        ),
        'vsite_taxonomy-0' => array(
          'module' => 'vsite_taxonomy',
          'delta' => '0',
          'weight' => -20,
          'region' => 'right',
          'status' => '0',
          'label' => 'Scholar site categories',
          'type' => 'context_ui',
        ),
        'vsite_widgets-2' => array(
          'module' => 'vsite_widgets',
          'delta' => '2',
          'weight' => 50,
          'region' => 'right',
          'status' => '0',
          'label' => 'AddThis button',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Announcements feature context');

  $export['scholar-feature-announcements'] = $context;
  return $export;
}