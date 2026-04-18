/*

Gondwanaland Telecom makes charges for calls according to distance and time of day. The basis of the
charging is contained in the following schedule, where the charging step is related to the distance:

Charging Step Day Rate Evening Rate Night Rate
(distance) 8am to 6pm 6pm to 10pm 10pm to 8am
A 0.10 0.06 0.02
B 0.25 0.15 0.05
C 0.53 0.33 0.13
D 0.87 0.47 0.17
E 1.44 0.80 0.30

All charges are in dollars per minute of the call. Calls which straddle a rate boundary are charged
according to the time spent in each section. Thus a call starting at 5:58 pm and terminating at 6:04
pm will be charged for 2 minutes at the day rate and for 4 minutes at the evening rate. Calls less than
a minute are not recorded and no call may last more than 24 hours.
Write a program that reads call details and calculates the corresponding charges.

Input
Input lines will consist of the charging step (upper case letter ‘A’..‘E’), the number called (a string of 7
digits and a hyphen in the approved format) and the start and end times of the call, all separated by
exactly one blank. Times are recorded as hours and minutes in the 24 hour clock, separated by one
blank and with two digits for each number. Input will be terminated by a line consisting of a single ‘#’.

Output
Output will consist of the called number, the time in minutes the call spent in each of the charge
categories, the charging step and the total cost in the format shown below.
Note: The first line of the Sample Output below in not a part of the output, but only to show the
exact tabulation format it must follow.

Sample Input
A 183-5724 17 58 18 04
#

Sample Output
10 16 22 28 31 39
183-5724 2 4 0 A 0.44

*/

package main

import "fmt"

func main() {
	schedule('A', "183-5724", 17, 58, 18, 4)
}

func schedule(step rune, number string, beghour, begmin, endhour, endmin int) {
	array := map[rune][3]int{
		'A': {10, 6, 2},
		'B': {25, 15, 5},
		'C': {53, 33, 13},
		'D': {87, 47, 17},
		'E': {144, 80, 30},
	}

	begin := beghour*60 + begmin
	end := endhour*60 + endmin
	if end <= begin {
		end += 24 * 60
	}

	a, b, c := 0, 0, 0
	for i := range 48 * 60 {
		if begin <= i && i < end {
			if i%(24*60) < 8*60 {
				c++
			} else if i%(24*60) < 18*60 {
				a++
			} else if i%(24*60) < 22*60 {
				b++
			} else {
				c++
			}
		}
	}
	sum := a*array[step][0] + b*array[step][1] + c*array[step][2]
	fmt.Printf("%10s %5d %5d %5d  %c %4d.%02d\n", number, a, b, c, step, sum/100, sum%100)
}
