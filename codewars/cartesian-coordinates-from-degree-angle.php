<?php

/*

Write a simple function that takes polar coordinates (an angle in degrees and a radius) and returns the equivalent cartesian coordinates (rounded to 10 places).

For example:

coordinates(90,1)
=> (0.0, 1.0)

coordinates(45, 1)
=> (0.7071067812, 0.7071067812) 
 
*/

function coordinates($d, $r) {
	$t = deg2rad($d);
	return array($r*cos($t), $r*sin($t));
}

print_r(coordinates(90, 1));
print_r(coordinates(45, 1));

?>
