/*

Take a look at the sevens multiplication table from 7×0 to 7×9:

0, 7, 14, 21, 28, 35, 42, 49, 56, 63
If we just look at the digits in the one's place we get a permutation of the digits 0 through 9:

0, 7, 4, 1, 8, 5, 2, 9, 6, 3
Consider taking some positive decimal integer N and replacing each digit D in N with the the digit in the one's place of 7×D.

For example, 15209 becomes 75403 because 1 maps to 7, 5 maps to 5, 2 maps to 4, 0 maps to 0, and 9 maps to 3.

Now lets repeat this process with this new decimal integer until we see a cycle, i.e. until an integer we've already seen comes up.

For example, with 15209 we get the cycle

15209 -> 75403 -> 95801 -> 35607 -> 15209 -> repeats...
                                      ^
                                      |
                             cycle restarts here
As another example, 505 has the short cycle

505 -> 505 -> repeats...
        ^
        |
cycle restarts here
It turns out that for any N these cycles will always contain exactly 1 or 4 distinct integers. (I'll leave it to you to figure out why that is.) What's interesting is that if you sum all the distinct integer in a cycle, you almost always get a decimal integer that only consists of 2's and 0's.

For example, 15209 + 75403 + 95801 + 35607 = 222020.

N = 505 is one of the exceptions. The only integer in the cycle is 505 so the total sum is 505 itself.

Here are the sums of the cycles for N = 1 to 60:

N sum
1 20
2 20
3 20
4 20
5 5
6 20
7 20
8 20
9 20
10 200
11 220
12 220
13 220
14 220
15 220
16 220
17 220
18 220
19 220
20 200
21 220
22 220
23 220
24 220
25 220
26 220
27 220
28 220
29 220
30 200
31 220
32 220
33 220
34 220
35 220
36 220
37 220
38 220
39 220
40 200
41 220
42 220
43 220
44 220
45 220
46 220
47 220
48 220
49 220
50 50
51 220
52 220
53 220
54 220
55 55
56 220
57 220
58 220
59 220
60 200
We'll call this the Seven's Cycle Sum Sequence.

Challenge
Write a program or function that takes in a positive decimal integer N and prints or returns, in decimal, the corresponding term of the Seven's Cycle Sum Sequence.

For example, if the input is 95801, the output should be 222020. If the input is 505, the output should be 505. If the input is 54, the output should be 220.

The shortest code in bytes wins.

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	tab := []int{
		20, 20, 20, 20, 5, 20, 20, 20, 20, 200, 220, 220, 220,
		220, 220, 220, 220, 220, 220, 200, 220, 220, 220, 220,
		220, 220, 220, 220, 220, 200, 220, 220, 220, 220, 220,
		220, 220, 220, 220, 200, 220, 220, 220, 220, 220, 220,
		220, 220, 220, 50, 220, 220, 220, 220, 55, 220, 220,
		220, 220, 200,
	}

	for i := range tab {
		assert(f(i+1) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@xnor

The function is simple to describe:

If n consists of only 0's and 5's, output it unchanged.
Otherwise, replace each digit of n with 2, except 0 stays 0, and tack on a 0 to the end.
The golfing can be improved, I'm mostly posting to share the method. A language with native regex should allow a short solution.

An alternative statement of the function is

In n, replace each digit with a 5, except 0 stays as 0
If this changed n (it had a digit other than 0 or 5), multiply the result by 4

*/

func f(n int) int {
	if n < 0 {
		return 0
	}

	b := []byte(fmt.Sprint(n))
	for i := range b {
		if b[i] == '0' || b[i] == '5' {
			continue
		}

		for j := range b {
			if b[j] != '0' {
				b[j] = '2'
			}
		}
		b = append(b, '0')

		break
	}

	x, _ := strconv.Atoi(string(b))
	return x
}
