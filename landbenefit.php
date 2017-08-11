<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>REPORTS --- LAND BENEFITS</title>
</head>
<body style= "background-color:lavender">
<h1 style="text-align:center"> SACCO BENEFITS PER INVESTMENT </h1><br/>

<?php
include("config.php");

$land_benefit = "SELECT* FROM benefit_per_investment";
$result = mysqli_query($con,$land_benefit)or die (mysqli_error($con));
?>
<table border="1" margin="auto">
<thead>
<tr>
<th>First Name</th>
<th>Last Name</th>
<th>Shares</th>
<th>Profits</th>
</tr>
</thead>
<tbody>
<?php
if(mysqli_num_rows($result)>0){
	while($row = mysqli_fetch_assoc($result)){
		echo"<tr>";
        echo"<td>".$row["First Name"]."</td>";
	    echo"<td>".$row["Last Name"]."</td>";
		echo"<td>".$row["Shares"]."</td>";
        echo"<td>".$row["Profits"]."</td>";
		echo"</tr>";
		}

	}
else{
	 echo "0 results";
 }

?>

</tbody>
</table>