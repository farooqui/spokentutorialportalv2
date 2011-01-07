<?php
// $Id: core.inc,v 1.1 2010/06/03 05:48:25 coreyp1 Exp $

/**
 * Implementation of hook_virtual_roles().
 */
function node_virtual_roles() {
  return array(
    'node_user_is_author' => array(
      'title' => t("User is node's author"),
      'callback' => 'node_user_is_author',
      'file' => 'node_user_is_author.inc',
      'path' => drupal_get_path('module', 'virtual_roles') .'/modules/node',
    ),
  );
}

