<?php

$plugin = array(
  'title' => t('Node Title (Display Suite)'),
  'description' => t('This is the current title of the node being viewed.'),
  'content_types' => array('title'),
  'category' => t('Page Content'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'single' => TRUE,
);

/**
  * This content type prints the title of the node. This used in Display Suite layouts to properly handle context.
  */
function panopoly_magic_title_content_type_render($subtype, $conf, $panel_args, $context) {
  $pane = new stdClass();
  $pane->content = '<h2 class="node-title">' . l($context->data->title, 'node/' . $context->data->nid) . '</h2>';
  return $pane;
}
