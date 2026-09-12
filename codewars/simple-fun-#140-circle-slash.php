<?php

/*

Task
Suppose there are n people standing in a circle and they are numbered 1 through n in order.

Person 1 starts off with a sword and kills person 2. He then passes the sword to the next person still standing, in this case person 3. Person 3 then uses the sword to kill person 4, and passes it to person 5. This pattern continues around and around the circle until just one person remains.

What is the number of this person?

Example:
For n = 5, the result should be 3.

 1 kills 2, passes to 3. 3 kills 4, passes to 5. 5 kills 1, passes to 3. 3 kills 5 and wins.

Input/Output
[input] integer n
The number of people. 1 through n standing in a circle.

1 <= n <= 1e9

[output] an integer 
 
*/

// https://oeis.org/A006257
function circleslash($n) {
	if ($n < 1)
		return 0;

	$p = 1;
	while ($p*2 <= $n)
		$p *= 2;
	return 1 + ($n - $p) * 2;
}

function main() {
	$tab = [0, 1, 1, 3, 1, 3, 5, 7, 1, 3, 5, 7, 9, 11, 13, 15, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29];
	for ($i = 0; $i < count($tab); $i++)
		assert(circleslash($i) == $tab[$i]);
}

main();

?>
