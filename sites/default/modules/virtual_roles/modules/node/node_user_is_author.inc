<?php
// $Id: node_user_is_author.inc,v 1.1 2010/06/03 05:48:25 coreyp1 Exp $

/**
 * Callback defined by node_virtual_roles() in core.inc
 */
function node_user_is_author($op, $user = NULL) {
  switch ($op) {
    case 'cache' :
      if (arg(0) == 'node' && is_numeric(arg(1))) {
        global $user;
        $nid = arg(1);
        return "node_user_is_author:$user->uid:$nid";
      }
      return NULL;
      break;
    case 'process' :
      $nid = arg(1);
      $sql = "SELECT n.uid FROM {node} n WHERE n.nid = %d LIMIT 1";
      $resource = db_query($sql, $nid);
      if ($result = db_result($resource)) {
        return $result == $user->uid;
      }
      return FALSE;
      break;
  }
}

