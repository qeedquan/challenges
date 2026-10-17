<?php

/*

You must implement a function that returns the difference between the largest and the smallest value in a given list / array (lst) received as the parameter.

lst contains integers, that means it may contain some negative numbers
if lst is empty or contains a single element, return 0
lst is not sorted
[1, 2, 3, 4]   //  returns 3 because 4 -   1  == 3
[1, 2, 3, -4]  //  returns 7 because 3 - (-4) == 7
 
*/

function maxdiff($a) {
	if (count($a) == 0) {
		return 0;
	}
	return max($a) - min($a);
}

assert(maxdiff([1, 2, 3, 4]) == 3);
assert(maxdiff([1, 2, 3, -4]) == 7);
assert(maxdiff([0, 1, 2, 3, 4, 5, 6]) == 6);
assert(maxdiff([-0, 1, 2, -3, 4, 5, -6]) == 11);
assert(maxdiff([0, 1, 2, 3, 4, 5, 16]) == 16);
assert(maxdiff([16]) == 0);
assert(maxdiff([]) == 0);

?>
