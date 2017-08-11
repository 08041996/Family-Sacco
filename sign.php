<!DOCTYPE html>
<html lang="en">
<head> 
<meta charset = "UTF-8">
</head>
<body>

<?php
include('config.php');
$username =  $pass2 = $firstname = $lastname = $email =  $contact = $password = "";
if (isset($_POST['save'])) {
    $username = trim($_POST['username']);
    $password = sha1(trim($_POST['password']));
	$email = trim($_POST['email']);
	$pass2 = sha1(trim($_POST['pass2']));
	$firstname = trim($_POST['firstname']);
	$lastname = trim($_POST['lastname']);
	$contact = trim($_POST['contact']);
	
}
?>
	
	<table border="1" margin="auto">
<thead>
<tr>
<th>Username</th>
<th>Password</th>
<th>Email</th>
<th>First Name</th>
<th>Last Name</th>
<th>Contact</th>
</tr>
</thead>
<tbody>

<?php
		echo"<tr>";
		echo"<td>".trim($_POST['username'])."</td>";
        echo"<td>".sha1(trim($_POST['password']))."</td>";
	    echo"<td>".trim($_POST['email'])."</td>";
        echo"<td>".trim($_POST['firstname'])."</td>";
        echo"<td>". trim($_POST['lastname'])."</td>";
		echo"<td>".trim($_POST['contact'])."</td>";
		echo"</tr>";
		
		Function New_member(){
		$pete = "INSERT INTO members('First Name','Last Name','Email','Username','Contact') VALUES ( 'trim($_POST['firstname'])','trim($_POST['lastname'])','trim($_POST['email'])' ,'trim($_POST['username'])', 'trim($_POST['contact'])'";
		$result = mysqli_query($con,$pete)or die (mysqli_error($con));
        
		
		}
?>


</tbody>
</table>

<input type="submit" onclick= "New_member();">


</body>
</html>


