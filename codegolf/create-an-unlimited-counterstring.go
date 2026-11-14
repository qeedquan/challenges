/*

A counterstring is some sort of self-describing test data that is used in software testing. Not sure it was actually invented by James Bach, but I know it from there.

The idea is as follows: the test data contains many asterisk (*). The number in front of the asterisk tells you how long the test data is at that point. If you need to know a position in the test data that is not an asterisk, find the last asterisk, look at the number before and add the number of digits that follow.

The sequence starts like this:

2*4*6*8*11*14*17*20*23*
             ^
As you can see, the marked asterisk is at position 14.

If a file happens to be truncated as follows

[...]2045*20
then you can derive that there is a limit of 2047 characters somewhere (2045 where the asterisk is plus 2 for 2 and 0).

It's your task to create the shortest (this is code-golf) program that outputs (std::out or file or whatever) an arbitrary long test string of that format. The length in characters is given as argument. The program shall support up to 2 GB test data (input value 2147483647 characters).

"Dangerous" positions in the 2 GB file:

8*11*
98*102*
998*1003*
9998*10004*
99998*100005*
999995*1000003*
9999995*10000004*
99999995*100000005*
999999995*1000000006*
This should answer @Leaky Nun's question if there is a decision to make between 995*999* and 995*1000* or similar: no.

The end of the 2 GB file with input value 2147483647 is:

2147483640*2147483

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(counterstring(23) == "2*4*6*8*11*14*17*20*23*")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func counterstring(n int) string {
	w := new(bytes.Buffer)
	for i := 2; i < 2*n; i += digitlen(i+2) + 1 {
		fmt.Fprintf(w, "%d*", i)
	}
	r := w.String()
	return r[:n]
}

func digitlen(n int) int {
	if n == 0 {
		return 1
	}

	c := 0
	for ; n > 0; n /= 10 {
		c += 1
	}
	return c
}
