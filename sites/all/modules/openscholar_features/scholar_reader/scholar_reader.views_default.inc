<?php

/**
 * Implementation of hook_views_default_views().
 */
function scholar_reader_views_default_views() {
  $views = array();

  // Exported view: scholar_reader
  $view = new view;
  $view->name = 'scholar_reader';
  $view->description = 'scholar > reader';
  $view->tag = 'features';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'feed_nid' => array(
      'label' => 'feeds_data_scholar_feed_importer.feed_nid -> node.nid',
      'required' => 1,
      'id' => 'feed_nid',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'feed_nid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'url' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'url',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'url',
      'relationship' => 'none',
    ),
    'timestamp' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'time ago',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'timestamp',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'timestamp',
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => '[url]',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'description' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '250',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'truncate' => '0',
      'filter_html' => 'strip_html',
      'allowed_tags' => '',
      'exclude' => 0,
      'id' => 'description',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'description',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('sorts', array(
    'timestamp' => array(
      'id' => 'timestamp',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'timestamp',
    ),
  ));
  $handler->override_option('arguments', array(
    'feed_nid' => array(
      'id' => 'feed_nid',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'feed_nid',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'feed' => 'feed',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'status_extra' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status_extra',
      'table' => 'node',
      'field' => 'status_extra',
      'relationship' => 'none',
    ),
    'current' => array(
      'operator' => 'all',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'current',
      'table' => 'spaces',
      'field' => 'current',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'spaces_feature',
    'spaces_feature' => 'scholar_reader',
    'perm' => 'access content',
  ));
  $handler->override_option('cache', array(
    'type' => 'os_views_content_cache',
    'keys' => array(
      'comment' => array(
        'changed' => 0,
      ),
      'node' => array(
        'feed' => 'feed',
        'feed_item' => 'feed_item',
        'announcement' => 0,
        'blog' => 0,
        'book' => 0,
        'class' => 0,
        'class_material' => 0,
        'event' => 0,
        'feed_fast' => 0,
        'gallery' => 0,
        'image' => 0,
        'link' => 0,
        'page' => 0,
        'person' => 0,
        'presentation' => 0,
        'profile' => 0,
        'biblio' => 0,
        'vsite' => 0,
        'sitewide_page' => 0,
        'scholar_software_project' => 0,
        'scholar_software_release' => 0,
        'vsite_users_profile' => 0,
        'bio' => 0,
        'cv' => 0,
      ),
      'os_og' => array(
        'current' => 'current',
        'user' => 0,
      ),
    ),
    'results_min_lifespan' => '-1',
    'results_max_lifespan' => '-1',
    'output_min_lifespan' => '-1',
    'output_max_lifespan' => '3600',
  ));
  $handler->override_option('use_pager', '1');
  $handler->override_option('row_options', array(
    'inline' => array(
      'url' => 'url',
      'timestamp' => 'timestamp',
      'title' => 'title',
      'description' => 'description',
    ),
    'separator' => '',
    'hide_empty' => 0,
  ));
  $handler = $view->new_display('page', 'all feeds', 'page_1');
  $handler->override_option('relationships', array(
    'feed_nid' => array(
      'label' => 'feeds_data_scholar_feed_importer.feed_nid -> node.nid',
      'required' => 0,
      'id' => 'feed_nid',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'feed_nid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'timestamp' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'timestamp',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'timestamp',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array());
  $handler->override_option('distinct', 1);
  $handler->override_option('row_plugin', 'node');
  $handler->override_option('row_options', array(
    'relationship' => 'none',
    'build_mode' => 'teaser',
    'links' => 1,
    'comments' => 0,
  ));
  $handler->override_option('path', 'reader');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Feeds',
    'description' => 'Feed reader',
    'weight' => '0',
    'name' => 'features',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler = $view->new_display('node_content', 'teaser view', 'node_content_1');
  $handler->override_option('sorts', array(
    'timestamp' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'timestamp',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'timestamp',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'nid' => array(
      'default_action' => 'not found',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '3' => 0,
        '4' => 0,
      ),
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'blog' => 0,
        'announcement' => 0,
        'bio' => 0,
        'cv' => 0,
        'book' => 0,
        'class' => 0,
        'class_material' => 0,
        'event' => 0,
        'gallery' => 0,
        'image' => 0,
        'link' => 0,
        'page' => 0,
        'feed' => 0,
        'software' => 0,
        'vsite' => 0,
        'feature_request' => 0,
        'support_answer' => 0,
        'support_question' => 0,
        'vsite_users_profile' => 0,
        'biblio' => 0,
        'profile' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '92' => 0,
        '2' => 0,
        '84' => 0,
        '55' => 0,
        '32' => 0,
        '15' => 0,
        '85' => 0,
        '23' => 0,
        '94' => 0,
        '38' => 0,
        '45' => 0,
        '7' => 0,
        '81' => 0,
        '25' => 0,
        '97' => 0,
        '9' => 0,
        '35' => 0,
        '67' => 0,
        '59' => 0,
        '50' => 0,
        '90' => 0,
        '106' => 0,
        '28' => 0,
        '69' => 0,
        '77' => 0,
        '41' => 0,
        '79' => 0,
        '56' => 0,
        '40' => 0,
        '44' => 0,
        '5' => 0,
        '60' => 0,
        '11' => 0,
        '63' => 0,
        '37' => 0,
        '98' => 0,
        '20' => 0,
        '70' => 0,
        '4' => 0,
        '58' => 0,
        '91' => 0,
        '76' => 0,
        '95' => 0,
        '74' => 0,
        '66' => 0,
        '14' => 0,
        '78' => 0,
        '27' => 0,
        '61' => 0,
        '51' => 0,
        '87' => 0,
        '53' => 0,
        '83' => 0,
        '86' => 0,
        '75' => 0,
        '88' => 0,
        '105' => 0,
        '62' => 0,
        '3' => 0,
        '1' => 0,
        '46' => 0,
        '107' => 0,
        '48' => 0,
        '21' => 0,
        '96' => 0,
        '64' => 0,
        '43' => 0,
        '57' => 0,
        '52' => 0,
        '6' => 0,
        '22' => 0,
        '101' => 0,
        '10' => 0,
        '99' => 0,
        '68' => 0,
        '73' => 0,
        '31' => 0,
        '13' => 0,
        '80' => 0,
        '39' => 0,
        '26' => 0,
        '18' => 0,
        '8' => 0,
        '104' => 0,
        '103' => 0,
        '16' => 0,
        '42' => 0,
        '71' => 0,
        '24' => 0,
        '34' => 0,
        '29' => 0,
        '89' => 0,
        '30' => 0,
        '102' => 0,
        '93' => 0,
        '33' => 0,
        '19' => 0,
        '49' => 0,
        '17' => 0,
        '82' => 0,
        '12' => 0,
        '65' => 0,
        '36' => 0,
        '72' => 0,
        '100' => 0,
        '47' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_node_flag_name' => '*relationship*',
      'validate_argument_node_flag_test' => 'flaggable',
      'validate_argument_node_flag_id_type' => 'id',
      'validate_argument_user_flag_name' => '*relationship*',
      'validate_argument_user_flag_test' => 'flaggable',
      'validate_argument_user_flag_id_type' => 'id',
      'validate_argument_is_member' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('items_per_page', 3);
  $handler->override_option('types', array(
    'feed' => 'feed',
  ));
  $handler->override_option('modes', array(
    '0' => 'teaser',
  ));
  $handler->override_option('argument_mode', 'nid');
  $handler->override_option('default_argument', '');
  $handler->override_option('show_title', 0);
  $handler = $view->new_display('node_content', 'Full Node View', 'node_content_2');
  $handler->override_option('fields', array(
    'url' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'url',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'url',
      'relationship' => 'none',
    ),
    'timestamp' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'time ago',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'timestamp',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'timestamp',
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => '[url]',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'description' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '250',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'truncate' => '0',
      'filter_html' => '0',
      'allowed_tags' => '',
      'exclude' => 0,
      'id' => 'description',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'description',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('sorts', array(
    'timestamp' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'timestamp',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'timestamp',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'nid' => array(
      'default_action' => 'not found',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '3' => 0,
        '4' => 0,
      ),
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'blog' => 0,
        'announcement' => 0,
        'bio' => 0,
        'cv' => 0,
        'book' => 0,
        'class' => 0,
        'class_material' => 0,
        'event' => 0,
        'gallery' => 0,
        'image' => 0,
        'link' => 0,
        'page' => 0,
        'feed' => 0,
        'software' => 0,
        'vsite' => 0,
        'feature_request' => 0,
        'support_answer' => 0,
        'support_question' => 0,
        'vsite_users_profile' => 0,
        'biblio' => 0,
        'profile' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '92' => 0,
        '2' => 0,
        '84' => 0,
        '55' => 0,
        '32' => 0,
        '15' => 0,
        '85' => 0,
        '23' => 0,
        '94' => 0,
        '38' => 0,
        '45' => 0,
        '7' => 0,
        '81' => 0,
        '25' => 0,
        '97' => 0,
        '9' => 0,
        '35' => 0,
        '67' => 0,
        '59' => 0,
        '50' => 0,
        '90' => 0,
        '106' => 0,
        '28' => 0,
        '69' => 0,
        '77' => 0,
        '41' => 0,
        '79' => 0,
        '56' => 0,
        '40' => 0,
        '44' => 0,
        '5' => 0,
        '60' => 0,
        '11' => 0,
        '63' => 0,
        '37' => 0,
        '98' => 0,
        '20' => 0,
        '70' => 0,
        '4' => 0,
        '58' => 0,
        '91' => 0,
        '76' => 0,
        '95' => 0,
        '74' => 0,
        '66' => 0,
        '14' => 0,
        '78' => 0,
        '27' => 0,
        '61' => 0,
        '51' => 0,
        '87' => 0,
        '53' => 0,
        '83' => 0,
        '86' => 0,
        '75' => 0,
        '88' => 0,
        '105' => 0,
        '62' => 0,
        '3' => 0,
        '1' => 0,
        '46' => 0,
        '107' => 0,
        '48' => 0,
        '21' => 0,
        '96' => 0,
        '64' => 0,
        '43' => 0,
        '57' => 0,
        '52' => 0,
        '6' => 0,
        '22' => 0,
        '101' => 0,
        '10' => 0,
        '99' => 0,
        '68' => 0,
        '73' => 0,
        '31' => 0,
        '13' => 0,
        '80' => 0,
        '39' => 0,
        '26' => 0,
        '18' => 0,
        '8' => 0,
        '104' => 0,
        '103' => 0,
        '16' => 0,
        '42' => 0,
        '71' => 0,
        '24' => 0,
        '34' => 0,
        '29' => 0,
        '89' => 0,
        '30' => 0,
        '102' => 0,
        '93' => 0,
        '33' => 0,
        '19' => 0,
        '49' => 0,
        '17' => 0,
        '82' => 0,
        '12' => 0,
        '65' => 0,
        '36' => 0,
        '72' => 0,
        '100' => 0,
        '47' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_node_flag_name' => '*relationship*',
      'validate_argument_node_flag_test' => 'flaggable',
      'validate_argument_node_flag_id_type' => 'id',
      'validate_argument_user_flag_name' => '*relationship*',
      'validate_argument_user_flag_test' => 'flaggable',
      'validate_argument_user_flag_id_type' => 'id',
      'validate_argument_is_member' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('items_per_page', 25);
  $handler->override_option('types', array(
    'feed' => 'feed',
  ));
  $handler->override_option('modes', array(
    '0' => 'full',
  ));
  $handler->override_option('argument_mode', 'nid');
  $handler->override_option('default_argument', '');
  $handler = $view->new_display('block', 'Feeds subscriptions', 'block_1');
  $handler->override_option('relationships', array());
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'changed' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'changed',
      'table' => 'node',
      'field' => 'changed',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array());
  $handler->override_option('title', 'Feed subscriptions');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $handler = $view->new_display('block', 'Latest feed items', 'block_2');
  $handler->override_option('fields', array(
    'url' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'url',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'url',
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => '[url]',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'timestamp' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'timestamp',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'timestamp',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'feed_nid' => array(
      'id' => 'feed_nid',
      'table' => 'feeds_data_scholar_feed_importer',
      'field' => 'feed_nid',
    ),
  ));
  $handler->override_option('title', 'Latest news');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);

  $views[$view->name] = $view;

  return $views;
}
