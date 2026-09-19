<?php

/*

Create a function to determine whether or not two circles are colliding. You will be given the position of both circles in addition to their radii:

function collision(x1, y1, radius1, x2, y2, radius2) {
  // collision?
}

If a collision is detected, return true. If not, return false.

Here's a geometric diagram of what the circles passed in represent: 
 
*/


function collision($x1, $y1, $r1, $x2, $y2, $r2) {
	return hypot(($x1 - $x2), ($y1 - $y2)) < $r1+$r2;
}

assert(collision(200, 200, 3000, 100, 300, 400000) == true);
assert(collision(1, 2, 3, 4, 200, 200) == false);

?>
