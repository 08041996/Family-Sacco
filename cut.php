<?php

$mysqli = mysql("localhost", "root", "", "work");

$filedub="SACCOSYSTEM.txt";
$open =fopen($filedub,"r");
$size=filesize($filedub);
$read=fread($open,$size);

echo $read;
print_r(explode(" ",$read));
$a= explode(" ",$read);

$c=count($a);
for ($i=0; $i < $c; $i++)
 { 
			$ab=explode("\n", $a[$i]);
		if (strcmp($ab[0], "contribution")==0)
		 {
			print_r($ab);
			echo "<br/>";
			 $result = mysql_query("INSERT into pendingtable values ('$ab[1]','$ab[2]','$ab[3]','$ab[4]')");
			
		}
		}
	fclose($open);




?>
