<?php

/**
 * Provides theme selection for each site
 */
class vsite_design_settings_theme implements space_setting {
  var $id;
  var $parent_menu = 'appearance';
  var $weight = 10;

  function __construct($id = NULL) {
    if ($id) {
      $this->id = $id;
    }
    else {
      $this->id = 'theme';
    }
  }

  /**
   * Include JS and CSS Files needed for this form
   */
  private function include_externals(){
    drupal_add_css(drupal_get_path('module', 'vsite_design') . '/theme/vsite_design_theme_picker.css');
    drupal_add_js(drupal_get_path('module', 'vsite_design') . '/theme/vsite_design-sliding-container.js');
    drupal_add_js(drupal_get_path('module', 'vsite_design') . '/theme/vsite_design_theme_picker.js');

    //Showing and hiding the flavors
    ctools_include('dependent');
    ctools_include('form');

    //For changing the screenshot
    ctools_include('ajax');
    ctools_add_js('ajax-responder');
  }

  function form($space, $value = array()){
  	if(is_string($value)) $value = array('maintheme' => $value); //Backwards Compatibility

  	if($space->group->og_theme != $value['maintheme']) $value['maintheme'] = $space->group->og_theme;

  	$this->include_externals();

    // all the enabled themes
    vsite_include('vsiteapi');
    $enabled = vsite_vsite_themes();
    if (count($enabled) > 0) {
      ksort($enabled);
    }

    $form = array('#title' => 'Theme', '#theme' => 'vsite_design_theme_form');

    $options = array(); //Radio Options

    foreach ( $enabled as $theme_obj ) {
      $info = $theme_obj->info;
      $info['theme_name'] = $theme_obj->name;
      $theme_flavors = vsite_design_get_flavors($theme_obj->name);

      //show flavors if there is more than the default theme flavor defined
      if (isset($theme_flavors) && is_array($theme_flavors) && count($theme_flavors)) {
      	$a_options = array('' => $info['flavor_name'] . " (Default)");
      	foreach ($theme_flavors as $s_key => $a_info) $a_options[$s_key] = $a_info['name'];

        $form[$info['theme_name'] . '_flavor'] = array(
          '#type' => 'select',
          '#title' => 'Flavor',
          '#options' => $a_options,
          '#default_value' => strval($value['flavor']),
          '#process' => array(
            'ctools_dependent_process'
          ),
          '#dependency' => array(
            'radio:settings[theme][maintheme]' => array(
              $info['theme_name']
            )
          )
        );

        //Screenshot callback
        if($info['screenshot']) ctools_ajax_associate_url_to_element($form, $form[$info['theme_name'] . '_flavor'], url('cp/settings/theme/swap_screenshot/'.$info['theme_name']),'ctools-use-ajax-onchange');
      }

      $options[$info['theme_name']] = $info['theme_name'];
    }

    $form['maintheme'] = array(
      '#enabled_themes' => $enabled,
      '#type' => 'radios',
      '#options' => $options,
      '#default_value' => $value['maintheme'] ? $value['maintheme'] : 'scholar_airstream',
      '#tree' => TRUE
    );

    $form['#prefix'] = theme('vsite_design_theme_subnav', count($enabled));

    return $form;
  }

  function validate($space, $value){
    $this->include_externals();

  }

  function submit($space, $value){
  	$this->include_externals();

    $save = array(
      'maintheme' => $value['maintheme'],
      'flavor' => $value[$value['maintheme'] . '_flavor'],
    );

    $space->group->og_theme = $save['maintheme'];
    spaces_save($space);
    return $save;
  }
}