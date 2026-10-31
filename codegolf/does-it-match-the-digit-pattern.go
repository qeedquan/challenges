/*

Recently I had a Maths test and noticed that a certain number on the test matched an interesting pattern. The number (28384) matched a generic digit sequence that looks like this

(n)(x)(n+1)(x)(n+2)(x)(n+3) etc...

where n and x are single digit integers. The sequence can begin with either x or n and end with either x or n+y.

Your task is, given a multi digit positive integer, output a truthy or falsey value, depending on whether the input matches the pattern. The input will be between 4 and 18 digits long. You may take input as a string representation of the integer. The input will not begin with a 0 but can contain or end with 0s.

n+y will always be a single digit number (hence why the length limit is 18).

Test Cases
These should output a truthy value

182838485868788898
4344
85868
12223242526

And these should be falsey

12345
6724013635
36842478324836
1222232425
5859510511

As with all code golfs, shortest code wins! Good luck and may the odds, be ever in your favour!

*/

package main

import (
	"fmt"
)

func main() {
	assert(match(182838485868788898) == true)
	assert(match(4344) == true)
	assert(match(85868) == true)
	assert(match(12223242526) == true)
	assert(match(12345) == false)
	assert(match(6724013635) == false)
	assert(match(36842478324836) == false)
	assert(match(1222232425) == false)
	assert(match(5859510511) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func match(n uint64) bool {
	s := fmt.Sprint(n)
	return len(s) >= 4 && (check(s, 0, 1) || check(s, 1, 0))
}

func check(s string, i0, i1 int) bool {
	c := [2]byte{}
	c[i0] = s[i0]
	c[i1] = s[i1]
	for i := range s {
		ip := i & 1
		if s[i] != c[ip] {
			return false
		}
		if i0 == ip {
			c[i0]++
		}
	}
	return true
}
