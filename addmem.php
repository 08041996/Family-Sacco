<?php
include('config.php');

$fname = $lname =  $email =  $contact =  $username = $password ="";

$fname = $_POST['fname'];
$lname = $_POST['lname'];
$email = $_POST['email'];
$contact = $_POST['contact'];
$username = $_POST ['username'];
$password = sha1($_POST['password']);

$sql = "INSERT INTO members (First_Name, Last_Name, Email, Contact, Username) VALUES ('$fname', '$lname', '$email', '$contact', '$username')";
$result = mysqli_query($con,$sql)or die (mysqli_error($con));

$profile = "INSERT INTO profiles (Username, Password) VALUES('$username','$password')";
$res = mysqli_query($con,$profile)or die (mysqli_error($con));

header("Location: addmember.php");

?>