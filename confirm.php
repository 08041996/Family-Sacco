<?php
include('config.php');
$passkey = $_GET['passkey'];
$sql = "UPDATE user SET com_code=NULL WHERE com_code = '$passkey'";
$result = mysqli_query($mysqli,$sql) or die(mysqli_error());
if($result){
echo '<div> your account is now active'. Now <a href="login.php">LOG IN</a></div>;
}
else{
echo "An error has occured";
}
?>