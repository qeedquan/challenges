<?php

/*

Implement a function that takes two numbers m and n and returns an array of the first m multiples of the real number n. Assume that m is a positive integer.

Ex.

(3, 5.0) --> [5.0, 10.0, 15.0] 
 
*/

function multiples($m, $n) {
	$r = array();
	for ($i = 0; $i < $m; $i++) {
		array_push($r, $n * ($i + 1));
	}
	return $r;
}

print_r(multiples(3, 5.0));

?>
