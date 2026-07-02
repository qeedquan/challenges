<?php

/*

This series of katas will introduce you to basics of doing geometry with computers.

Vector objects (struct in C) have x, y, and z attributes.

Write a function calculating cross product of Vector a and Vector b.

You can read more about cross product on Wikipedia.

Tests round answers to 6 decimal places. 
 
*/

class Vec3 {
	public $x, $y, $z;

	public function __construct($x, $y, $z) {
		$this->x = $x;
		$this->y = $y;
		$this->z = $z;
	}
};

function cross($a, $b) {
	$v = new Vec3(0, 0, 0);
	$v->x = $a->y * $b->z - $a->z * $b->y;
	$v->y = $a->z * $b->x - $a->x * $b->z;
	$v->z = $a->x * $b->y - $a->y * $b->x;
	return $v;
}

print_r(cross(new Vec3(1, 0, 0), new Vec3(0, 1, 0)));
print_r(cross(new Vec3(0, 0, 1), new Vec3(0, 1, 0)));
print_r(cross(new Vec3(0, 1, 0), new Vec3(0, 0, 1)));

?>
