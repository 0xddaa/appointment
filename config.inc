<?php
function get_weekday(){
	return array('Sun 日','Mon 一','Tue 二','Wed 三','Thu 四','Fri 五','Sat 六');
}

function get_period_joint(){
	return array('1','2','3','4','Z','5','6','7','8','9','A','B','C','D');
}

function get_period_time(){
	return array('08:00-08:50','09:00-09:50','10:00-10:50','11:00-11:50','12:00-12:50','13:00-13:50','14:00-14:50','15:00-15:50','16:00-16:50','17:00-17:50','18:00-18:50','19:00-19:50','20:00-20:50','21:00-21:50');
}

function get_period(){
	return array('1 08:00-08:50','2 09:00-09:50','3 10:00-10:50','4 11:00-11:50','Z 12:00-12:50','5 13:00-13:50','6 14:00-14:50','7 15:00-15:50','8 16:00-16:50','9 17:00-17:50','A 18:00-18:50','B 19:00-19:50','C 20:00-20:50','D 21:00-21:50');
}
function get_professor_title(){
	return array('教授','副教授','助理教授','榮譽教授');
}

function get_classroom_info($serial,$cid=-1){
  if(check_classroom_valid($serial)==false && $cid==-1)
    exit(0);

  //get classroom info;
  $sql = 'SELECT * FROM as_classroom WHERE serial=\''.$serial.'\' OR cid='.$cid;
  mysql_real_escape_string($sql);
  $clsroom_info = db_query($sql)->fetchObject();  
  return $clsroom_info;
}	

function get_teacher_list(){
  //get teacher list;
  $teachers = array();
  $title = get_professor_title();
  $sql = 'SELECT * FROM `as_teacher`';
  $result = db_query($sql);  
  foreach($result as $row){
    $teachers[$row->tid]=$row->name.' '.$title[$row->title];
  }
  $teachers[0]='其他';
  return $teachers;
}

function get_teacher_info($tid){
  $sql = 'SELECT name,title FROM `as_teacher` WHERE tid='.$tid;
  return db_query($sql)->fetchObject();
}

function check_classroom_valid($serial){
  $result = db_query('SELECT * FROM `as_classroom`');
  foreach($result as $row){
    if($serial == $row->serial)
      return true;
  }
  return false;
}
?>
