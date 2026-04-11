/*

We have heard a lot recently about the Y2K problem. According to the doom sayers, planes will fall out
of the skies, businesses will crash and the world will enter a major depression as the bugs in software
and hardware bite hard. While this panic is a very satisfactory state of affairs for the computing
profession, since it is leading to lots of lucrative jobs, it will have a tendency to bring the profession into
disrepute when almost no problems occur on 1/1/00. To help avoid this unseemly behaviour on any
future occasion, you must write a program which will give the correct date for (almost) any number of
future days - in particular, it must correctly predict the date N days ahead of any given date, where
N is a number less than 1,000,000,000 and the given date is any date before the year 3000.
Remember that in the standard Gregorian calendar we use there are 365 days in a year, except for
leap years in which there are 366. Leap years are all years divisible by 4 and not divisible by 100, except
for those divisible by 400. Thus 1900 was not a leap year, 1904, 1908 ... 1996 were leap years, 2000 will
be a leap year, 2100 will not be a leap year, etc. The number of days in each month in a normal year
is 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31; in a leap year, the second month has 29 days.

Input
Input will consist of lines containing four numbers, separated by one or more spaces. The first number
on each line will be the number of days you have to predict (between 0 and 999999999), followed by the
date in the format DD MM Y Y Y Y where DD is the day of the month (1 to 31), MM is the month
(1 to 12), and Y Y Y Y is the year (1998 to 2999), all inclusive. The input will be terminated by a line
containing four 0’s.

Output
For each line of input, one output line should be produced. This line should contain the date which is
the required number of days ahead of the input date, written in the same format as the input dates.

Sample Input
1 31 12 2999
40 1 2 2004
60 31 12 1999
60 31 12 2999
146097 31 12 1999
999999 1 1 2000
0 0 0 0

Sample Output
1 1 3000
12 3 2004
29 2 2000
1 3 3000
31 12 2399
27 11 4737

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	assert(y3k(1, 31, 12, 2999) == "1 1 3000")
	assert(y3k(40, 1, 2, 2004) == "12 3 2004")
	assert(y3k(60, 31, 12, 1999) == "29 2 2000")
	assert(y3k(60, 31, 12, 2999) == "1 3 3000")
	assert(y3k(146097, 31, 12, 1999) == "31 12 2399")
	assert(y3k(999999, 1, 1, 2000) == "27 11 4737")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func y3k(n, d, m, y int) string {
	t := time.Date(y, time.Month(m), d, 0, 0, 0, 0, time.UTC)
	t = t.AddDate(0, 0, n)
	return fmt.Sprintf("%d %d %d", t.Day(), t.Month(), t.Year())
}
