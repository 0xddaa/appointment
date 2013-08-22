<?php
function get_weekday(){
	return array('Sun','Mon','Tue','Wed','Thu','Fri','Sat');
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

function get_classroom_info($serial,$cid=-1){
	//get classroom info;
  $sql = 'SELECT * FROM classroom WHERE serial=\''.$serial.'\' OR cid='.$cid;
  $clsroom_info = db_query($sql)->fetchObject();  
	return $clsroom_info;
}	

function get_teacher_list(){
	return array(
		'teacher1'=>'teacher1',
		'teacher2'=>'teacher2',
		'teacher3'=>'teacher3'
	);
}
?>
