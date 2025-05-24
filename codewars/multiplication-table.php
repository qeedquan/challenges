<?php

/*

Your task, is to create NxN multiplication table, of size provided in parameter.

for example, when given size is 3:

1 2 3
2 4 6
3 6 9
for given example, the return value should be: [[1,2,3],[2,4,6],[3,6,9]] 
 
*/

function table($n) {
	$r = array();
	for ($i = 1; $i <= $n; $i++) {
		$p = array();
		for ($j = 1; $j <= $n; $j++) {
			array_push($p, $i * $j);
		}
		array_push($r, $p);
	}
	return $r;
}

print_r(table(3));

?>
