<?php
$con = mysqli_connect("localhost","root","","sacco");
if (mysqli_connect_error($con)) {
  echo "Failed to connect to MySQL: " . mysqli_error($con);
}
 
?>