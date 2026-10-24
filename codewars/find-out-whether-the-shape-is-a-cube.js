/*

To find the volume (centimeters cubed) of a cuboid you use the formula:

volume = Length * Width * Height

But someone forgot to use proper record keeping, so we only have the volume, and the length of a single side!

It's up to you to find out whether the cuboid has equal sides (= is a cube).

Return true if the cuboid could have equal sides, return false otherwise.

Return false for invalid numbers too (e.g volume or side is less than or equal to 0).

Note: side will be an integer

*/

var assert = require('assert');

function iscube(volume, side) {
	if (volume < 1 || side < 1)
		return false;
	return side * side * side == volume;
}

function main() {
	assert(iscube(1, 1) == true);
	assert(iscube(8, 2) == true);

	assert(iscube(2, 1) == false);
	assert(iscube(6, 3) == false);
	assert(iscube(-8, -2) == false);
	assert(iscube(0, 0) == false);
	assert(iscube(200, 4) == false);
}

main();
