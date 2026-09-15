/*

It is common to start countdowns 100 days prior to an event, probably because of our base 10 system. Examples of this can be found everywhere:

100 days until your birthday
100 days until the wedding
100 days until the election
100 days until our graduation
100 days until her due date
100 days until football season
100 days until you get the Fanatic badge
You get the picture. It seems that the 100th day before an event is second place only to the actual event. So for this challenge, I need to know what the date will be in 100 days, so that I can determine what I should start counting down too.

Input
No input

Output
The date 100 days from the current date based on the standard Gregorian Calendar (Make sure to account for leap years). Output is flexible as long as the date format is human read-able (eg 2016-10-8, 10-8-16, [ 2016, 10, 8 ], 10/8/16 12:00:00 AM).

Winning
Code golf: shortest code in bytes

Examples
100 days from today (Apr 5th, 2017) is Friday, July 14 2017.

Current                Future
-------                ------
01/01/2001 +100        04/11/2001
01/01/2004 +100        04/10/2004
01/01/1900 +100        04/11/1900
01/01/2000 +100        04/10/2000

07/04/2017 +100        10/12/2017
10/31/2017 +100        02/08/2018
12/25/2017 +100        04/04/2018

08/29/1941 +100        12/07/1941
06/03/2001 +100        09/11/2001

*/

package main

import (
	"time"
)

func main() {
	assert(future(1, 1, 2001) == "04/11/2001")
	assert(future(1, 1, 2004) == "04/10/2004")
	assert(future(1, 1, 1900) == "04/11/1900")
	assert(future(1, 1, 2000) == "04/10/2000")

	assert(future(7, 4, 2017) == "10/12/2017")
	assert(future(10, 31, 2017) == "02/08/2018")
	assert(future(12, 25, 2017) == "04/04/2018")

	assert(future(8, 29, 1941) == "12/07/1941")
	assert(future(6, 3, 2001) == "09/11/2001")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func future(month, day, year int) string {
	date := time.Date(year, time.Month(month), day, 0, 0, 0, 0, time.UTC)
	date = date.Add(100 * 24 * time.Hour)
	return date.Format("01/02/2006")
}
