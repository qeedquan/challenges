<?php

/*

Given a long number, return all the possible sum of two digits of it.

For example, 12345: all possible sum of two digits from that number are:

[ 1 + 2, 1 + 3, 1 + 4, 1 + 5, 2 + 3, 2 + 4, 2 + 5, 3 + 4, 3 + 5, 4 + 5 ]
Therefore the result must be:

[ 3, 4, 5, 6, 5, 6, 7, 7, 8, 9 ] 
 
*/

function d2s($x) {
	$r = array();
	$s = sprintf("%s", $x);
	$n = strlen($s);
	for ($i = 0; $i < $n; $i++) {
		for ($j = $i + 1; $j < $n; $j++) {
			array_push($r, ($s[$i] - '0') + ($s[$j] - '0'));
		}
	}
	return $r;	
}

print_r(d2s(12345));

?>
