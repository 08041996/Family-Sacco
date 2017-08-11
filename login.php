<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>SACCO SYSTEM</title>
<link rel="stylesheet" type="text/css" href="extra.css"/>
<link rel="stylesheet" type="text/css" href="bootstrap.css"/>
<script type="text/javascript" src="jquery-3.2.1-1.js"> </script>
<script type="text/javascript" src="bootstrap.js"> </script>
</head>
<body style="background-color:lavender">


<div class="container-fluid">
<h1 style="text-align:center;"> SACCO MANAGEMENT SYSTEM</h1>
<br/><br/><br/>
<div class="text-center text-uppercase">

<button class="btn btn-success" data-toggle="modal" data-target="#loginwindow" align="center"> MEMBER  LOGIN</button>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<button class="btn btn-success" data-toggle="modal" data-target="#adminwindow" align="center"> ADMINISTRATOR LOGIN</button>
<br/><br/><br/>
</div>
<div class="modal fade" id="loginwindow">
<div class="modal-dialog">
<div class="modal-content">
<div class="modal-header">
<button type="button" class="close" data-dismiss="modal">&times;</button>
<h3 class="modal-title">LOG IN</h3>
</div>
<div class="modal-body">
<form role="form" action="verify.php" method="POST">
<div class="form-group">
<input type="text" class="form-control" placeholder="username" name="username">
</div>
<div class="form-group">
<input type="password" class="form-control" placeholder="password" name="password">
</div >
<div class="modal-footer">
<button class="btn btn-primary btn-block" type="submit" value="submit" name="submit"> Log in <button>
</div>
</form>
</div>

</div>
</div>
</div>


<div class="modal fade" id="adminwindow">
<div class="modal-dialog">
<div class="modal-content">
<div class="modal-header">
<button type="button" class="close" data-dismiss="modal">&times;</button>
<h3 class="modal-title">LOG IN</h3>
</div>
<div class="modal-body">
<form role="form" action="verify2.php" method="POST">
<div class="form-group">
<input type="text" class="form-control" placeholder="username" name="username">
</div>
<div class="form-group">
<input type="password" class="form-control" placeholder="password" name="password">
</div >
<div class="modal-footer">
<button class="btn btn-primary btn-block" type="submit" value="submit" name="submit"> Log in <button>
</div>
</form>
</div>

</div>
</div>
</div>




</div>


</div>
</div>
</div>
</div>
</div>
</body>

</html>