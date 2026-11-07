/*

Intro
The Switching sequence is defined like so:

Start with n people standing in a circle (6 for this example).

 1  2
6    3
 5  4
Starting from person 1, the person that is to the left of the "chosen" person is removed.

 1
6    3
 5  4
The removed person can "switch" the removal method up:

If the removed person is even (which it is in this case), the next removed person will be to the right of the next "chosen" person.
If the removed person is odd, the next removed person will be to the left of the next "chosen" person.
The next chosen person is also dependent on the previously removed person.

If the removed person is even, the next chosen person will be to the right of the previous chosen person.
If the removed person is odd, see above, but replace "right" with "left".
So the next chosen person is then 6.

Now we remove the person to the right of 6, which is 5:

 1
6    3
    4
Because 5 is odd, the removed person is now to the left. The new chosen person is 1.

We now remove 3:

 1
6
    4
We continue this process, until we're left with 1 number - in this example, the final number is 1. So therefore S(6) = 1.

The first few numbers are:

 n | S(n)
---------
 1 | 1
 2 | 1
 3 | 3
 4 | 1
 5 | 5
 6 | 1
 7 | 3
 8 | 6
 9 | 5
10 | 6
11 | 9
Task
Your task is to make a program (or a function) that returns S(n) (the nth number in the Switching sequence) when given n, using the least amount of bytes.

Example inputs and outputs:

1  -> 1
10 -> 6
13 -> 13
You are guaranteed to get a positive integer.

This is code-golf, so shortest code in bytes wins!

Note: There is no OEIS sequence (what?), to save you the trouble of searching.

*/

package main

import (
	"slices"
)

func main() {
	tab := []int{1, 1, 3, 1, 5, 1, 3, 6, 5, 6, 9}
	for i := range tab {
		assert(circle(i+1) == tab[i])
	}
	assert(circle(13) == 13)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Jonathan Allan

This just follows the instructions given, I've noticed some pattern, maybe it could be exploited?

The only changes are:

to use 0 based indexing (so even people are odd and vice-versa) - this is saves 5 bytes in the golfed logic and is corrected at the end with +1
to use 1 as left and -1 as right (to use a range - just like everyone is facing outwards instead)
to change the logic of the step where the next chosen individual is found to account for poping from the list making the "pointer" index already step one to the right in the list (or to the left in original terminology).

*/

func circle(n int) int {
	if n < 1 {
		return 0
	}

	p := make([]int, n)
	for i := range p {
		p[i] = i
	}

	d, i := 1, 1
	for n > 1 {
		m := p[i] % 2
		p = slices.Delete(p, i, i+1)

		i -= m + m
		if d == -1 {
			i += 1
		}

		d = -m
		if m == 0 {
			d = 1
		}

		n -= 1
		i = mod(i+d, n)
	}
	return p[0] + 1
}

func mod(x, m int) int {
	x %= m
	if x < 0 {
		x += m
	}
	return x
}
