<?php

/*

Create an addition function that does not utilize the + or - operators.

Anti-cheat tests
You may not use any of these symbols: +-[].'"`

Moreover, Math, Array, eval, new Function, with and such have been disabled.
 
*/

function add($x, $y) {
	if ($y == 0)
		return $x;
	return add($x ^ $y, ($x & $y) << 1);
}

for ($x = 0; $x < 10; $x++) {
	for ($y = 0; $y < 10; $y++) {
		printf("%d %d\n", add($x, $y), $x + $y);
	}
}

?>
