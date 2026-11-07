<?php

/*

Given a number 1≤n≤365, output the nth day of the year in "Day-numberth Month" format. For example, given 1, you should output "1st January", without "of".

The Gregorian calendar will be used and the program should not account for leap years, so your program should never output "29th February" in any circumstance.
Any method can be used, as long as it follows the "Day-numberth Month" format mentioned before.
Your program should also output ordinals correctly, meaning it should always output 1st, 2nd, 3rd, should 1, 2 or 3 respectively be the day numbers for any input.
Leading spaces or other indentation are allowed.

This is code golf, so the shortest solution by characters wins.

Test cases:

1 gives 1st January
2 gives 2nd January
3 gives 3rd January
365 gives 31st December
60 gives 1st March
11 gives 11th January
 
*/

function monthday($yearday) {
	return date("jS F", 86399 * $yearday);
}

printf("%s\n", monthday(1));
printf("%s\n", monthday(2));
printf("%s\n", monthday(3));
printf("%s\n", monthday(365));
printf("%s\n", monthday(60));
printf("%s\n", monthday(11));

?>
