<?php
include('config.php');

$initiator = $date =  $capital =  $profits =  $losses = "";

$initiator = $_POST['initiator'];
$date = $_POST['date'];
$capital = $_POST['capital'];
$profits = $_POST['profits'];
$losses = $_POST ['losses'];

$sql = "INSERT INTO investment (Initiators, Date_of_investment, Capital, Profits, losses) VALUES ('$initiator', '$date', '$capital', '$profits', '$losses')";
$result = mysqli_query($con,$sql)or die (mysqli_error($con));

header("Location: investment.php");

?>