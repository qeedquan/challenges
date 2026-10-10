<?php

/*

Write a function which reduces fractions to their simplest form! Fractions will be presented as an array/tuple (depending on the language) of strictly positive integers, and the reduced fraction must be returned as an array/tuple:

input:   [numerator, denominator]
output:  [reduced numerator, reduced denominator]
example: [45, 120] --> [3, 8]

All numerators and denominators will be positive integers.
 
*/

function gcd($a, $b) {
	while ($b != 0) {
		$m = $a % $b;
		$a = $b;
		$b = $m;
	}
	return $a;
}

function simplify($n, $d) {
	$m = gcd($n, $d);
	return [$n/$m, $d/$m];
}

print_r(simplify(45, 120));

?>
