<?php

$plugin = array(
  'title' => t('Read More (Display Suite)'),
  'description' => t('This is a link to read more about the node being viewed.'),
  'content_types' => array('read_more'),
  'category' => t('Page Content'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'single' => TRUE,
);

/**
  * This content type prints the read_more of the node. This used in Display Suite layouts to properly handle context.
  */
function panopoly_magic_read_more_content_type_render($subtype, $conf, $panel_args, $context) {
  $pane = new stdClass();
  $node = $context->data;
  $pane->content = l(t('Read more'), 'node/' . $node->nid, array('attributes' => array('class' => 'read-more')));
  return $pane;
}
