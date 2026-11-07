<?php

/*
 
Your task, is to create a NxN spiral with a given size.

For example, spiral with size 5 should look like this:

00000
....0
000.0
0...0
00000
and with the size 10:

0000000000
.........0
00000000.0
0......0.0
0.0000.0.0
0.0..0.0.0
0.0....0.0
0.000000.0
0........0
0000000000
Return value should contain array of arrays, of 0 and 1, with the first row being composed of 1s. For example for given size 5 result should be:

[[1,1,1,1,1],[0,0,0,0,1],[1,1,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Because of the edge-cases for tiny spirals, the size will be at least 5.

General rule-of-a-thumb is, that the snake made with '1' cannot touch to itself. 
 
*/

function spiralize($n) {
	$m = array_fill(0, $n, array_fill(0, $n, 0));
	for ($y = 0; $y < $n; $y++) {
		for ($x = 0; $x < $n; $x++) {
			if ($y == $x+1 && 2*$y < $n) {
				$m[$y][$x] = $x % 2;
			} else {
				$m[$y][$x] = 1 - (min(min($y, $x), $n-1-max($y, $x)) % 2);
			}
		}
	}
	if ($n%2 == 0) {
		$m[$n/2][$n/2 - 1] = 0;
	}
	return $m;
}

function draw($m) {
	$n = count($m);
	printf("n=%d\n", $n);
	for ($y = 0; $y < $n; $y++) {
		for ($x = 0; $x < $n; $x++) {
			if ($m[$y][$x])
				printf("0");
			else
				printf(".");
		}
		printf("\n");
	}
	printf("\n");
}

draw(spiralize(5));
draw(spiralize(10));
draw(spiralize(50));

?>
