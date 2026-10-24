<?php

/*

Your task is to write function factorial.

https://en.wikipedia.org/wiki/Factorial 
 
*/

function fact($n) {
	if ($n < 0)
		return 0;

	$r = 1;
	for ($i = 2; $i <= $n; $i++)
		$r *= $i;
	return $r;
}

for ($i = 0; $i <= 10; $i++)
	printf("%d: %d\n", $i, fact($i));

?>
