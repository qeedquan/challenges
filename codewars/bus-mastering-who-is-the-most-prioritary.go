/*

When multiple master devices are connected to a single bus (https://en.wikipedia.org/wiki/System_bus), there needs to be an arbitration in order to choose which of them can have access to the bus (and 'talk' with a slave).

We implement here a very simple model of bus mastering. Given n, a number representing the number of masters connected to the bus, and a fixed priority order (the first master has more access priority than the second and so on...), the task is to choose the selected master. In practice, you are given a string inp of length n representing the n masters' requests to get access to the bus, and you should return a string representing the masters, showing which (only one) of them was granted access:

The string 1101 means that master 0, master 1 and master 3 have requested
access to the bus.
Knowing that master 0 has the greatest priority, the output of the function should be: 1000
Examples
* arbitrate("001000101", 9) -> "001000000"

* arbitrate("000000101", 9) -> "000000100"

Notes
The resulting string (char* ) should be allocated in the arbitrate function, and will be free'ed in the tests.

n is always greater or equal to 1.

*/

package main

import "strings"

func main() {
	assert(arbitrate("001000101", 9) == "001000000")
	assert(arbitrate("000000101", 9) == "000000100")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func arbitrate(s string, n int) string {
	i := strings.IndexRune(s, '1')
	if i < 0 {
		return s
	}
	return strings.Repeat("0", i) + "1" + strings.Repeat("0", n-i-1)
}
