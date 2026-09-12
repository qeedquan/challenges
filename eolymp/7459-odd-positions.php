<?php

/*

Find the product of the digits of the five-digit number n that are located at odd positions.

Input
The input consists of a single five-digit integer n (positive or negative).

Output
Print the product of the digits at the odd positions.

Examples

Input #1
12345

Answer #1
15
 
*/

function solve($n) {
	$n = abs($n);
	$a = ($n / 10000) % 10;
	$b = ($n / 100) % 10;
	$c = $n % 10;
	return $a * $b * $c;
}

printf("%d\n", solve(12345));

?>
