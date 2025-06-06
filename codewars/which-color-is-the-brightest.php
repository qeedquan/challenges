<?php

/*

One of the common ways of representing color is the RGB color model, in which the Red, Green, and Blue primary colors of light are added together in various ways to reproduce a broad array of colors.

One of the ways to determine brightness of a color is to find the value V of the alternative HSV (Hue, Saturation, Value) color model. Value is defined as the largest component of a color:

V = max(R,G,B)
You are given a list of colors in 6-digit hexidecimal notation #RRGGBB. Return the brightest of these colors!

For example,

brightest(["#001000", "#000000"]) == "#001000"
brightest(["#ABCDEF", "#123456"]) == "#ABCDEF"
If there are multiple brightest colors, return the first one:

brightest(["#00FF00", "#FFFF00", "#01130F"]) == "#00FF00"
Note that both input and output should use upper case for characters A, B, C, D, E, F. 
 
*/

function brightest($colors) {
	if (count($colors) == 0)
		return null;

	usort($colors, function($s, $t) {
		list($r0, $g0, $b0) = sscanf($s, "#%02x%02x%02x");
		list($r1, $g1, $b1) = sscanf($t, "#%02x%02x%02x");
		$c0 = max($r0, $g0, $b0);
		$c1 = max($r1, $g1, $b1);
		if ($c0 > $c1)
			return -1;
		if ($c0 == $c1)
			return 0;
		return 1;
	});

	return $colors[0];
}

assert(brightest(["#001000", "#000000"]) == "#001000");
assert(brightest(["#ABCDEF", "#123456"]) == "#ABCDEF");
assert(brightest(["#00FF00", "#FFFF00", "#01130F"]) == "#00FF00");

?>
