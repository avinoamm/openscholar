<?php

/**
 * Returns array where key is old vid and value is new content type
 * that it will belong to when imported 
 */
function psrimport_vocabulary_defaults(){

  //include these vocabularies
  return array(
  1 => 'page', // 'FAQ Topics', page/FAQ
  3 => 'link', // 'Type of resource', //tags - Links/ Internet Resource or Tip
  6 => 'announcement', //'Opportunity Type' page/Opportunity
  7 => 'event', //tags - Event/ Event
  9 => 'announcement', //tags - annoucements/ News
  5 => 'person',  //tags Profiles
  10 => 'page', // PSR Resouce
  );
}

/**
 * Returns array mapping old content type to new type
 */
function psrimport_type_map(){
  return array(
  'resource' => 'link', //120
  'event' => 'event', //50
  'psr_profile' => 'person', //27
  'page' => 'page', //25
  //'book' => 'page', //18
  'opportunity' => 'announcement', // 'page', //13
  'psr_resource' => 'page', //13
  'faq' => 'page', //12
  'survey_news' => 'announcement', //9
  'project_issue' => 'page', //5
  'education' => 'page', // 4
  'story' => 'page', //1
  //'project_project' => '', //1
  );
}