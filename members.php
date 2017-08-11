<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>REPORTS --- Members</title>
</head>
<body style= "background-color:lavender">
<h1 style="text-align:center"> SACCO MEMBER INFORMATION DETAILS</h1><br/>

<?php
include("config.php");

$members = "SELECT* FROM regular_members";
$result = mysqli_query($con,$members)or die (mysqli_error($con));
?>
<table border="1" margin="auto">
<thead>
<tr>
<th>Member_id</th>
<th>First Name</th>
<th>Last Name</th>
<th>Contact</th>
<th>Email Address</th>
<th>Status</th>
</tr>
</thead>
<tbody>
<?php
if(mysqli_num_rows($result)>0){
	while($row = mysqli_fetch_assoc($result)){
		echo"<tr>";
		echo"<td>".$row["Member_id"]."</td>";
        echo"<td>".$row["First_Name"]."</td>";
	    echo"<td>".$row["Last_Name"]."</td>";
        echo"<td>".$row["Contact"]."</td>";
        echo"<td>".$row["Email"]."</td>";
		echo"<td>".$row["status"]."</td>";
		echo"</tr>";
		}

	}
else{
	 echo "0 results";
 }

?>

</tbody>
</table>