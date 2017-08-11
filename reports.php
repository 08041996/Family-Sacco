<?php
include('config.php');
session_start();








?>
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>SACCO SYSTEM---- REPORTS</title>
<link rel="stylesheet" type="text/css" href="extra.css"/>
<link rel="stylesheet" type="text/css" href="bootstrap.css"/>
<script type="text/javascript" src="jquery-3.2.1-1.js"> </script>
<script type="text/javascript" src="bootstrap.js"> </script>
</head>
<body style="background-color:lavender">
<nav class= "navbar navbar-inverse">
<div class="container-fluid">

<div class="navbar-header">
<button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#main">
<span class="icon-bar"></span>
<span class="icon-bar"></span>
<span class="icon-bar"></span>
</button>
<a href="#" class="navbar-brand">FAMILY SACCO</a>
</div>

<div class="collapse navbar-collapse" id="main">
<ul class="nav navbar-nav"> 
<li class="active"> <a href="home.php">HOME</a> </li>



<li><a href="reports.php">REPORTS</a></li>

<div class="nav navbar-nav navbar-right">
<li><a href="logout.php"class="pull-right"> <strong>logout</strong></a>
</div>


</ul>



</div>

</nav>


<h1 class="page-header"> SAMPLE REPORTS <small>Please select reports to view</small></h1>
<p>

<h6><u> MEMBER DETAILS</u></h6>
<ul>
<li><a href="members.php">Current Members</a><br/></li>
</ul>
<br/><br/>
<h6><u> CONTRIBUTION DETAILS REPORTS </u></h6>
<ul>
<li><a href="contributionrep.php">General Members Contributions</a><br/></li>
<li><a href="indvcontribution.php"> Individual Member Contributions</a><br/></li>
</ul>
<br/><br/>
<h6><u> LOAN DETAILS REPORTS </u></h6>
<ul>
<li><a href="loan_details.php"> Loans Details</a><br/></li>
<li><a href="loans.php">How much is in loans</a><br/></li>
</ul>
<br/><br/>
<h6><u> BENEFITS REPORTS</h6></u>
<ul>
<li><a href="landbenefit.php"> Land Investment Benefits Details</a><br/></li>
</ul>

</div>




</body>
</html>