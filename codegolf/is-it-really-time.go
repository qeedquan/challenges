/*

A time in the format hhMMss is represented by six numbers in the range 0..9 (e.g.100203 for 3 seconds after 2 minutes after 10am (10:02.03), or 155603 for three seconds after 56 minutes after 3pm (15:56.03).

Treating these times as integers, these numbers are therefore in the range 000000 to 235959; but not all numbers in that range are valid times.

Normally, though, integers aren't represented with leading 0s, right?

So, this challenge is to take a numeric input (without leading 0s), and say whether it represents a proper time or not when the leading 0s are put back.

Input
Any integer, as a string or an integer type, in the range 0..235959 inclusive. all numbers as strings will be input with no leading 0s (e.g. 2400, not 002400). The time 000000 maps to 0; or exceptionally as  . Inputs outside of this range should return Falsy, but there is no requirement that they are supported.

Output
Truthy/Falsy value - by which I mean there must be a consistent distinction in the output between True and False - e.g. True could be output as 1 and False could be any other output (or even a variable output) - as long as it can be documented how to tell what is True and what is not.

More Challenge Details
Given the input integer, figure out if the number represents a time (Truthy) or not (Falsy).

A number represents a time if a time (hhMMss) with leading 0s removed is the same as the number.

e.g. 00:00.24 is represented by 24
e.g. 00:06.51 is represented by 651
e.g. 00:16.06 is represented by 1606
e.g. 05:24.00 is represented by 52400
e.g. 17:25.33 is represented by 172533

There are therefore some numbers that can't represent times:

e.g. 7520 - this can't represent hhMMss because 00:75:20 isn't a time

As a general rule, the valid numbers fall into the pattern:

trimLeadingZeros([00..23][00..59][00..59]);

The following numbers are the entire set of inputs and the required answers for this challenge

Seconds only (e.g. 00:00.ss, with punctuation and leading 0s removed, -> ss)
0 to 59 - Truthy
60 to 99 - Falsy

Minutes and seconds (e.g. 00:MM.ss, with punctuation and leading zeros removed, -> MMss)
100 to 159 - Truthy
160 to 199 - Falsy
etc, up to:
2300 to 2359 - Truthy
2360 to 2399 - Falsy
2400 to 2459 - Truthy
2460 to 2499 - Falsy
etc, up to:
5900 to 5959 - Truthy
5960 to 9999 - Falsy

Hours 0..9, minutes and seconds (e.g. 0h:MM.ss with punctuation and leading zeros removed -> hMMss)

10000 to 10059 - Truthy
10060 to 10099 - Falsy
etc, up to:
15800 to 15859 - Truthy
15860 to 15899 - Falsy
15900 to 15959 - Truthy
15960 to 19999 - Falsy

20000 to 20059 - Truthy
20060 to 20099 - Falsy
20100 to 20159 - Truthy
20160 to 20199 - Falsy
etc, up to:
25800 to 25859 - Truthy
25860 to 25899 - Falsy
25900 to 25959 - Truthy
25960 to 25999 - Falsy
etc, up to:
95800 to 95859 - Truthy
95860 to 95899 - Falsy
95900 to 95959 - Truthy
95960 to 99999 - Falsy

Hours 10..23, minutes and seconds (e.g. hh:MM.ss with punctuation and leading zeros removed -> hhMMss)

100000 to 100059 - Truthy
100060 to 100099 - Falsy
100100 to 100159 - Truthy
100160 to 100199 - Falsy
etc, up to:
105800 to 105859 - Truthy
105860 to 105899 - Falsy
105900 to 105959 - Truthy
105960 to 109999 - Falsy

This pattern is then repeated up to:

235900 to 235959 - Truthy
(236000 onwards - Falsy, if supported by program)

Leading 0s must be truncated in the input, if strings are used.

Code golf, so least bytes wins - usual rules apply.

*/

package main

func main() {
	test(0, 59, true)
	test(60, 99, false)
	test(100, 159, true)
	test(160, 199, false)
	test(2300, 2359, true)
	test(2360, 2399, false)
	test(2400, 2459, true)
	test(2460, 2499, false)
	test(5900, 5959, true)
	test(5960, 9999, false)
	test(10000, 10059, true)
	test(10060, 10099, false)
	test(15800, 15859, true)
	test(15860, 15899, false)
	test(15900, 15959, true)
	test(15960, 19999, false)
	test(20000, 20059, true)
	test(20060, 20099, false)
	test(20100, 20159, true)
	test(20160, 20199, false)
	test(25800, 25859, true)
	test(25860, 25899, false)
	test(25900, 25959, true)
	test(25960, 25999, false)
	test(95800, 95859, true)
	test(95860, 95899, false)
	test(95900, 95959, true)
	test(95960, 99999, false)
	test(100000, 100059, true)
	test(100060, 100099, false)
	test(100100, 100159, true)
	test(100160, 100199, false)
	test(105800, 105859, true)
	test(105860, 105899, false)
	test(105900, 105959, true)
	test(105960, 109999, false)
	test(235900, 235959, true)
	test(236000, 100000000, false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(t0, t1 int, cond bool) {
	for t := t0; t <= t1; t++ {
		assert(tictoc(t) == cond)
	}
}

// ported from @RGS solution
func tictoc(n int) bool {
	n0 := n % 100
	n1 := (n / 100) % 100
	n2 := n / 4000
	return n1 < 60 && 60 > n0 && n0 < 60 && 60 > n2
}
