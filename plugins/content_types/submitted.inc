<?php

$plugin = array(
  'title' => t('Node Submitted (Display Suite)'),
  'description' => t('This is the current submitted information of the node being viewed.'),
  'content_types' => array('submitted'),
  'category' => t('Page Content'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'single' => TRUE,
);

/**
  * This content type prints the submitted of the node. This used in Display Suite layouts to properly handle context.
  */
function panopoly_magic_submitted_content_type_render($subtype, $conf, $panel_args, $context) {
  $pane = new stdClass();
  $node = $context->data;
  $username = (user_access('access user profiles')) ? l($node->name, 'user/' . $node->uid) : $node->name;
  // TODO - run this through relevant preprocess functions to get appropriate submitted text
  $pane->content = t('By !username / !datetime', array('!username' => $username, '!datetime' => format_date($node->created, 'panopoly_day')));
  return $pane;
}
