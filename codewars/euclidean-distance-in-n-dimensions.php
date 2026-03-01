<?php

/*

Implement a function to calculate the distance between two points in n-dimensional space. The two points will be passed to your function as arrays of the same length.

Round your answers to two decimal places.
 
*/

function distance($a, $b) {
	$d = 0;
	for ($i = 0; $i < count($a); $i++) {
		$d += pow($a[$i] - $b[$i], 2);
	}
	return sqrt($d);
}

printf("%f\n", distance([-1], [2]));
printf("%f\n", distance([-1, 2], [2, 4]));
printf("%f\n", distance([-1, 2, 5], [2, 4, 9]));

?>
