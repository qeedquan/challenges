<?php

/*

Bob needs a fast way to calculate the volume of a cuboid with three values: the length, width and height of the cuboid. Write a function to help Bob with this calculation.
 
*/

function volume($length, $width, $height) {
	return $length * $width * $height;
}

assert(volume(2, 2, 2) == 8);

?>
