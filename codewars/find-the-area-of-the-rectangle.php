<?php

/*

Find the area of a rectangle when provided with one diagonal and one side of the rectangle. If the input diagonal is less than or equal to the length of the side, return "Not a rectangle". If the resultant area has decimals round it to two places.

This kata is meant for beginners. Rank and upvote to bring it out of beta!
 
*/

function area($side, $diagonal) {
	if ($diagonal <= $side)
		return "Not a rectangle";
	return sqrt($diagonal*$diagonal - $side*$side);
}

printf("%.2f\n", area(4, 5));
printf("%.2f\n", area(5, 13));

?>
