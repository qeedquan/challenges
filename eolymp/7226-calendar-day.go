/*

As you may know, Programmer's Day is celebrated on the 256th day of the year, which falls on September 13 in a common year and September 12 in a leap year.
Remember to extend your congratulations to your colleagues and mentors.

In a similar fashion, your task is to determine the day and month corresponding to the nth day of the common year 2014.

Input
You will be given a natural number n (1≤n≤365).

Output
Output the day (ranging from 1 to 31) and the month number (ranging from 1 to 12) that correspond to the nth day of the year.

Examples

Input #1
256

Answer #1
13 9

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println(solve(256))
}

func solve(n int) (int, int) {
	t := time.Date(2014, time.January, n, 0, 0, 0, 0, time.UTC)
	return t.Day(), int(t.Month())
}
