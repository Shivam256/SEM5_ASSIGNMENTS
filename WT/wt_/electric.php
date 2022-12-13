<!DOCTYPE html>
<html>
<head>
	<title>Program to calculate electricity bill in PHP</title>
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css">
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script>
</head>
<body>
	<?php
	$amount = '';
	$kwh_usage = '';
	if (isset($_POST['submit'])) {
		$units = $_POST['kwh'];
		if (!empty($units)) {
			$kwh_usage = calculate_electricity_bill($units);
			$amount = '<strong>Total amount of ' . $units . ' units -</strong> ' . $kwh_usage;
		}
	}
	/**
	 * To calculate electricity bill as per unit cost
	 */
	function calculate_electricity_bill($units) {
		$first_unit_cost = 8;
		$second_unit_cost = 12;
		$third_unit_cost = 16;
		$fourth_unit_cost = 20;

		if($units <= 100) {
			$bill = $units * $first_unit_cost;
		}
		else if($units > 100 && $units <= 200) {
			$temp = 100 * $first_unit_cost;
			$remaining_units = $units - 100;
			$bill = $temp + ($remaining_units * $second_unit_cost);
		}
		else if($units > 200 && $units <= 300) {
			$temp = (100 * $first_unit_cost) + (100 * $second_unit_cost);
			$remaining_units = $units - 200;
			$bill = $temp + ($remaining_units * $third_unit_cost);
		}
		else {
			$temp = (100 * $first_unit_cost) + (100 * $second_unit_cost) + (100 * $third_unit_cost);
			$remaining_units = $units - 300;
			$bill = $temp + ($remaining_units * $fourth_unit_cost);
		}
		return number_format((float)$bill, 2, '.', '');
	}
	?>
	<div class="container">
		<h1>Calculate electricity bill in PHP</h1>
		<div class="form-group">
		<form action="" method="post">
		<div class="form-group">
			<input type="number" name="kwh" placeholder="Please enter no. of Units" class="form-control" />
		</div>
		<div class="form-group">		
			<input type="submit" name="submit" class="btn btn-primary" value="Submit" />
		</div>	
		</form>
		</div>
		<div>
		    <?php echo '<br />' . $amount; ?>
		</div>
	</div>
</body>
</html>