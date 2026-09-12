/*

In this challenge you will need to determine whether it's Pi Day, Pi Minute, or Pi Second.

Because Pi is irrational, it wants your code to be as short as possible.

Examples
No input is provided, your program should use the system time. I've just added it for clarity

March 14, 2016 0:00:00
Pi Day
December 25, 2015 3:14:45
Pi Minute
December 29, 2015 0:03:14
Pi Second
January 1, 2016 0:00:00
<No Output>
What is Pi Day / Minute / Second
Pi Day is when the month is March, and the date is the 14th
Pi Minute is when the hour is 3, and the minute is 14
Pi Second is when the minute is 3, and the second is 14
Pi Day should be preferred instead of Pi Minute or Pi Second, and Pi Minute should be preferred instead of Pi Second.
For this challenge you should use 12-hour time (15:14 == 3:14). The date/time used to determine the Pi Day/Minute/Second should be based on system time.

Scoring & Bonus
-15 byte Bonus: If you print "No Pi Time" when it's not Pi time.

As always, standard loopholes are disallowed. This is code-golf shortest code in bytes wins!

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println(pitime())
}

func pitime() string {
	t := time.Now()
	switch {
	case t.Month() == time.March && t.Day() == 14:
		return "Pi Day"
	case t.Hour() == 3 && t.Minute() == 14:
		return "Pi Minute"
	case t.Minute() == 3 && t.Second() == 14:
		return "Pi Second"
	}
	return "No Pi Time"
}
