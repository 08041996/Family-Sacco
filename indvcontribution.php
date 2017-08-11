<?php

?>

<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>REPORTS --- Contribution</title>
</head>
<body style= "background-color:lavender">
<h1 style="text-align:center"> SACCO MEMBER CONTRIBUTION DETAILS</h1><br/>

<?php
include("config.php");
include("verify.php");

$user = $_SESSION['username'];
$contribution = "SELECT* FROM contribution WHERE Username = '$user' ";
$res = mysqli_query($con,$contribution)or die (mysqli_error($con));

?>
<table border="1" margin="auto">
<thead>
<tr>
<th>First Name</th>
<th>Last Name</th>
<th>Contribution</th>
<th>Date_of_Contribution</th>
<th>Receppt_No</th>
</tr>
</thead>
<tbody>
<?php
if(mysqli_num_rows($res)>0){
	while($row = mysqli_fetch_assoc($res)){
		echo"<tr>";
        echo"<td>".$row["First Name"]."</td>";
	    echo"<td>".$row["Last Name"]."</td>";
		echo"<td>".$row["Contribution"]."</td>";
        echo"<td>".$row["Date_of_Contribution"]."</td>";
        echo"<td>".$row["Receppt_No"]."</td>";
		echo"</tr>";
		}

	}
else{
	 echo "0 results";
 }

?>

</tbody>
</table>