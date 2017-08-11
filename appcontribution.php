<?php
$txt_file = file_get_contents('./contributions.txt',FILE_USE_INCLUDE_PATH);
$rows = explode("\n", $txt_file);
array_shift($rows);

foreach($rows as $row => $data){
	$row_data = explode('^',$data);
	
	$info[$row]['CONTRIBUTION'] = $row_data[0];
	$info[$row]['First_Name'] = $row_data[1];
	$info[$row]['Last_Name'] = $row_data[2];
	$info[$row]['amount'] = $row_data[3];
	$info[$row]['date'] = $row_data[4];
	
	echo 'Row' . $row . 'CONTRIBUTION' . $info[$row]['CONTRIBUTION'] . '<br/>';
	echo 'Row' . $row . 'First_Name' . $info[$row]['First_Name'] . '<br/>';
	echo 'Row' . $row . 'Last_Name' . $info[$row]['Last_Name'] . '<br/>';
	echo 'Row' . $row . 'amount' . $info[$row]['amount'] . '<br/>';
	echo 'Row' . $row . 'date' . $info[$row]['date'] . '<br/>';
	
	ECHO '<BR/>';
}

?>