<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>REPORTS --- loan</title>
</head>
<body style= "background-color:lavender">
<h1 style="text-align:center"> SACCO MEMBER LOAN DETAILS</h1><br/>

<?php
include("config.php");
include("verify.php");



$loan = "SELECT* FROM loan_management WHERE ";
$result = mysqli_query($con,$loan)or die (mysqli_error($con));
?>
<table border="1" margin="auto">
<thead>
<tr>
<th>First Name</th>
<th>Last Name</th>
<th>Date of Loan</th>
<th>Principle</th>
<th>Amount Owed</th>
<th>Settled</th>
<th>Balance</th>
<th>Loan Status</th>
</tr>
</thead>
<tbody>
<?php
if(mysqli_num_rows($result)>0){
	while($row = mysqli_fetch_assoc($result)){
		echo"<tr>";
        echo"<td>".$row["First Name"]."</td>";
	    echo"<td>".$row["Last Name"]."</td>";
		echo"<td>".$row["Date_of_loan"]."</td>";
        echo"<td>".$row["Principle"]."</td>";
        echo"<td>".$row["Total_Payment"]."</td>";
		echo"<td>".$row["Settled"]."</td>";
		echo"<td>".$row["Balance"]."</td>";
		echo"<td>".$row["Loan_Status"]."</td>";
		echo"</tr>";
		}

		$sum = "SELECT SUM(Balance) FROM loan_report";
		echo THE TOTAL IN LOANS IS $sum;
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
else{
	 echo "0 results";
 }

?>

</tbody>
</table>