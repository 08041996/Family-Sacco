<?php
include('config.php');
session_start();

$username =  $password = "";

if (isset($_POST['submit'])) {
    $username = trim($_POST['username']);
    $password = sha1(trim($_POST['password']));
    $query = "SELECT * FROM profiles WHERE Username='$username' AND Password='$password'";
    $result = mysqli_query($con,$query) or die (mysqli_error($con));
    $num_row = mysqli_num_rows($result);
    $row = mysqli_fetch_array($result);
    if($num_row !=0){
        $_SESSION['username']= $username;
        echo "WELCOME";
        header("Location: home.php");
    } 
    else{
        echo "wrong details" ;
    }
    echo "data";
}else{
    echo "None";
}

?>