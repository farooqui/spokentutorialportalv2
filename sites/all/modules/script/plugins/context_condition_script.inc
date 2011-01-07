<?php 

function user_expert($op,$user=NULL){
	
	switch($op){
		case 'cache':
			return FALSE;
		break;
		case 'process' :
			if(arg(1) == 'add' && arg(2) == 'script'){
				//We found path to add a script. Allow.
				return TRUE;
			}
			if(arg(0)=='node' && arg(1)=='add'){
				return TRUE;
			}
			$nid = arg(1);
			$sql = 'select type from {node} where nid=%d';
			$result = db_fetch_array(db_query($sql,$nid));
			
			if($result['type'] == 'script'){
				$sql = 'select ce.field_software_experts_uid as uid from {content_field_software_experts} ce join {node} n on ce.nid=n.nid join {script_software} ss on n.nid = ss.softwareid where ss.scriptid = %d and ce.vid=n.vid';
				$ruid = db_query($sql,$nid);
				$uid = array();
				while($row = db_fetch_array($ruid)){
					$uid[] = $row['uid'];
				}
				
				if(in_array($user->uid, $uid)){
					return TRUE;
				}
			}
			
			return FALSE;
		break;
	}
}

function user_reviewer($op,$user=NULL){
	
	switch($op){
		case 'cache':
			return FALSE;
		break;
		case 'process' :
			$nid = arg(1);
			$sql = 'select type from {node} where nid=%d';
			$result = db_fetch_array(db_query($sql,$nid));
			
			if($result['type'] == 'script'){
				$sql = 'select ce.field_reviewers_uid as uid from {content_field_reviewers} ce join {node} n on ce.nid=n.nid join {script_software} ss on n.nid = ss.softwareid where ss.scriptid = %d and ce.vid=n.vid';
				$ruid = db_query($sql,$nid);
				$uid = array();
				while($row = db_fetch_array($ruid)){
					$uid[] = $row['uid'];
				}
				
				if(in_array($user->uid, $uid)){
					return TRUE;
				}
			}
			
			return FALSE;
		break;
	}
}
function user_junior($op,$user=NULL){
	
	switch($op){
		case 'cache':
			return FALSE;
		break;
		case 'process' :
			$nid = arg(1);
			$sql = 'select type from {node} where nid=%d';
			$result = db_fetch_array(db_query($sql,$nid));
			
			if($result['type'] == 'script'){
				$sql = 'select ce.field_juniors_uid as uid from {content_field_juniors} ce join {node} n on ce.nid=n.nid join {script_software} ss on n.nid = ss.softwareid where ss.scriptid = %d and ce.vid=n.vid';
				$ruid = db_query($sql,$nid);
				$uid = array();
				while($row = db_fetch_array($ruid)){
					$uid[] = $row['uid'];
				}
				
				if(in_array($user->uid, $uid)){
					return TRUE;
				}
			}
			
			return FALSE;
		break;
	}
}