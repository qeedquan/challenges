<?php

/*

A sequel to my earlier post, when working with quadratic graphs, you can use Y=MX²+NX+C to calculate the shapes of a quadratic curve... but can you code-golf it?

I/O is similar to my last post, but the program should now take M, N, C, V, and then returns the first V worth of whole x values. V will always be an integer 1 or greater, but M, N, and C can have any (float) value (inc 0 and negative values).

Good luck, and may your bytes be few!

3 example test cases!

[2,-1,-1,2] -> [0,5]
[-0.001,0,0,3] ->[-0.001,-0.004,-0.009]
[1,0,0,5] -> [1,4,9,16,25] 
 
*/

function gen($a, $b, $c, $n) {
	$r = [];
	for ($x = 1; $x <= $n; $x++)
		array_push($r, $a*$x*$x + $b*$x + $c);
	return $r;
}

print_r(gen(2, -1, -1, 2));
print_r(gen(-0.001, 0, 0, 3));
print_r(gen(1, 0, 0, 5));

?>
