<?php

/*

We all use 16:9, 16:10, 4:3 etc. ratios every day. Main task is to determine image ratio by its width and height dimensions.

Function should take width and height of an image and return a ratio string (ex."16:9"). If any of width or height entry is 0 function should throw an exception (or return Nothing). 
 
*/

function gcd($a, $b) {
	while ($b != 0) {
		$c = $b;
		$b = $a % $b;
		$a = $c;
	}
	return $a;
}

function aspect_ratio($w, $h) {
	if ($w < 1 || $h < 1)
		return sprintf("Nothing");
	$n = gcd($w, $h);
	return sprintf("%d:%d", $w/$n, $h/$n);
}

printf("%s\n", aspect_ratio(16, 10));
printf("%s\n", aspect_ratio(16, 9));
printf("%s\n", aspect_ratio(4, 3));
printf("%s\n", aspect_ratio(100, 50));

?>
