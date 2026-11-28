<?php

/* 
 
Find the total sum of internal angles (in degrees) in an n-sided simple polygon. N will be greater than 2.
 
*/

function internal_angle($n) {
	if ($n < 2)
		return 0;
	return ($n - 2) * 180;
}

for ($i = 2; $i <= 50; $i++)
	printf("%d: %d\n", $i, internal_angle($i));

?>
