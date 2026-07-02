#!/usr/bin/env php

<?php

/*

Inspired by this Wikipedia article, which was found in the comments in this video,
I thought it would be cool to come up with a programme which uses the Doomsday algorithm to determine which day of the week a certain date falls on.

Bonus: Now, learn to perform the algorithm mentally, and create a tester programme!
Write another programme which takes parameters (e.g. the desired range of years), give a random date
(e.g. if I input that I want a date this year it may output (5/6/2012);
if I say I want a date between 1900 and 2100 it may output (17/3/2046))
and then ask for you to enter the day of the week and have the programme tell you if you are correct.

Thanks to jedditreddit for the challenge at /r/dailyprogrammer_ideas .. Link
 
*/

function doomsday($date) {
	return date("l", strtotime($date));
}

echo doomsday("10/5/2012") . "\n";
echo doomsday("12/31/1999") . "\n";
echo doomsday("01/01/2000") . "\n";

?>
