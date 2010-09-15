<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _scholar_front_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'scholar',
    'attribute' => 'feature',
    'value' => 'front',
    'description' => 'The front page context',
    'path' => array(
      'home' => 'home',
    ),
    'block' => array(
      'views_scholar_events_upcoming-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_events_upcoming-block_1',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Upcoming events',
        'type' => 'context_ui',
      ),
      'views_scholar_announcements-block_1' => array(
        'module' => 'views',
        'delta' => 'scholar_announcements-block_1',
        'weight' => 21,
        'region' => 'right',
        'status' => '0',
        'label' => 'Latest Announcements',
        'type' => 'context_ui',
      ),
      'scholar_reader_my_twitter_feed' => array(
        'module' => 'scholar_reader',
        'delta' => 'my_twitter_feed',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Twitter Feed',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_flag_default_flags().
 */
function _scholar_front_flag_default_flags() {
$flags = array();
// Exported flag: "Save to Front Page".
$flags[] = array (
  'content_type' => 'node',
  'name' => 'scholar_frontpage',
  'title' => 'Save to Front Page',
  'global' => true,
  'types' => 
  array (
  ),
  'flag_short' => 'Save to Front',
  'flag_long' => 'Save post to front page',
  'flag_message' => 'Saved to Front Page!',
  'unflag_short' => 'Remove from Front',
  'unflag_long' => 'Remove post from Front Page',
  'unflag_message' => 'Removed from Front Page',
  'unflag_denied_text' => '',
  'link_type' => 'toggle',
  'roles' => 
  array (
    'flag' => 
    array (
      0 => '2',
    ),
    'unflag' => 
    array (
      0 => '2',
    ),
  ),
  'show_on_page' => false,
  'show_on_teaser' => false,
  'show_on_form' => false,
  'access_author' => '',
  'i18n' => 0,
  'module' => 'scholar_front',
  'locked' => 
  array (
    'types' => 'types',
    'name' => 'name',
    'show_on_page' => 'show_on_page',
    'show_on_teaser' => 'show_on_teaser',
    'show_on_form' => 'show_on_form',
    'global' => 'global',
  ),
  'api_version' => 2,
);
return $flags;
}