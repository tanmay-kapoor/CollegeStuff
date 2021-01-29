<?php
$server = "localhost";
$user = "root";
$password = "";
$db = "football_turf";

$con = mysqli_connect($server , $user , $password , $db , "3308");

if(!$con){
	?>
	<script >
		alert ("connection error");
	</script>
	<?php
}

?>