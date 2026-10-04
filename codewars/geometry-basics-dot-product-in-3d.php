<?php

/*

This series of katas will introduce you to basics of doing geometry with computers.

Vector objects have x, y, and z attributes.

Write a function calculating dot product of Vector a and Vector b.

You can read more about dot product on Wikipedia. ( https://en.wikipedia.org/wiki/Dot_product )
 
*/

class Vec3 {
	public $x, $y, $z;

	public function __construct($x, $y, $z) {
		$this->x = $x;
		$this->y = $y;
		$this->z = $z;
	}
};

function dot($a, $b) {
	return $a->x*$b->x + $a->y*$b->y + $a->z*$b->z;
}

printf("%f\n", dot(new Vec3(1, 1, 1), new Vec3(1, 1, 1)));
printf("%f\n", dot(new Vec3(0, 0, 1), new Vec3(1, 0, 0)));

?>
