#!/usr/bin/env pwsh

<#

In UTM, the world is divided into 100 km × 100 km squares and locally, within these squares, the Earth is approximated as if it were flat. Due to the Earth being a sphere (although the validity of this fact appears to be in dispute among those who would prefer to see the human species as the center of the universe), these squares do not perfectly line up, but for most applications, navigation occurs within one of these squares.

Given two points, a 10-figure grid reference are two pairs of five decimal-digit numbers, the first specifying the number of meters from the bottom left corner of the square in the easterly direction, and the next specifying the numbers of meters from the bottom left corner of the square in the northerly direction.

Aside: to help remember that the first number is the east, and the second number is north, the Canadian Forces use the aide-memoire "In the door, up the stairs."

Given two points within the same 100 km square, it may be useful to know the angle from one point to the other, where the angle is described as the number of radians from true north going east. For a 10-figure grid reference, the distance simply uses the inverse tangent function.

For example, the distance between 0523941178 and 0768243596 is

atan( (05239-07682) / (41178-43596) ) ~ 0.7905410927505153

or approximately 45.3°. You can see this in Figure 1.
https://ece.uwaterloo.ca/~ece150/Projects/X.2/img/utm.angle.png

Normally, grid references are written as a 10-digit number, but we will use an array of capacity two where the first number is the distance east, and the second is the distance north.

Write a function that takes two pairs of UTM grid references and returns the angle from the first to the second:

double angle_utm( unsigned int source[2], unsigned int destination[2] );
Note, you will have to use the std::atan or preferably, the std::atan2 function. The issue with the first is that std::atan( a/b ) is equal to std::atan( -a/(-b) ), so it will only give you an angle from -π/2 to π/2.
This will have to be corrected based on the signs of the numerator and denominator.
Additionally, you will have to be careful about a zero in the denominator.
The std::atan2 function takes two arguments, the numerator and denominator separately, and returns an angle from -π to π, although you will have to correct this to give a value between 0 and 2π.

#>

function angle($x1, $y1, $x2, $y2) {
	$dx = $x2 - $x1
	$dy = $y2 - $y1
	[Math]::atan2($dx, $dy)
}

angle 5239 41178 7682 43596
