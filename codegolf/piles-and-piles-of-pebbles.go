/*

My job is stacking pebbles into triangular piles. I've only been doing this for a century and it is already pretty boring. The worst part is that I label every pile. I know how to decompose pebbles into piles of maximal size, but I want to minimize the number of piles. Can you help?

Task
Given an integer, decompose it into the minimum number of triangular numbers, and output that minimum number.

Triangular Numbers
A triangular number is a number which can be expressed as the sum of the first n natural numbers, for some value n. Thus the first few triangular numbers are

1 3 6 10 15 21 28 36 45 55 66 78 91 105
Example
As an example, let's say the input is 9. It is not a triangular number, so it cannot be expressed as the sum of 1 triangular number. Thus the minimum number of triangular numbers is 2, which can be obtained with [6,3], yielding the correct output of 2.

As another example, let's say the input is 12. The most obvious solution is to use a greedy algorithm and remove the largest triangular number at a time, yielding [10,1,1] and an output of 3. However, there is a better solution: [6,6], yielding the correct output of 2.

Test Cases
in out
1 1
2 2
3 1
4 2
5 3
6 1
7 2
8 3
9 2
10 1
11 2
12 2
13 2
14 3
15 1
16 2
17 3
18 2
19 3
20 2
100 2
101 2
5050 1

Rules
The input integer is between 1 and the maximum integer of your language.
I can emulate any language with my pebbles, and I want your code as small as possible because I have nothing but pebbles to keep track of it. Thus this is code-golf, so the shortest code in each language wins.

*/

package main

func main() {
	tab := []int{0, 1, 2, 1, 2, 3, 1, 2, 3, 2, 1, 2, 2, 2, 3, 1, 2, 3, 2, 3, 2, 1, 2, 3, 2, 2, 3, 2, 1, 2, 2, 2, 3, 3, 2, 3, 1, 2, 2, 2, 3, 3, 2, 2, 3, 1, 2, 3, 2, 2, 3, 2, 3, 3, 3, 1, 2, 2, 2, 3, 2, 2, 3, 3, 2, 2, 1, 2, 3, 2, 2, 3, 2, 2, 3, 3, 2, 3, 1, 2, 3, 2, 3, 2, 2, 3, 3, 2, 2, 3, 2, 1, 2, 2, 2, 3, 3, 2, 3, 2, 2, 2, 2, 3, 3}

	for i := range tab {
		assert(pebbles(i) == tab[i])
	}
	assert(pebbles(5050) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

https://oeis.org/A061336

@Arnauld

How?
We use the following properties:

According to Fermat polygonal number theorem, any positive integer can be expressed as the sum of at most 3 triangular numbers.
A number t is triangular if and only if 8t+1 is a perfect square (this can easily be proven by solving t = n(n+1) / 2).
Given a positive integer n, it's enough to test whether we can find:

x > 0 such that 8n+1 = x² (n itself is triangular)
or x > 0 and y > 0 such that 8n+2 = x²+y² (n is the sum of 2 triangular numbers)
If both tests fail, n must be the sum of 3 triangular numbers.

*/

func pebbles(n int) int {
	if n < 1 {
		return 0
	}

	x, y := 0, 0
	for y < n+2 {
		if x*x+y*y == 8*n+2-not(y) {
			return 2 - not(y)
		}
		if x < n+2 {
			x += 1
		} else {
			y += 1
			x = y
		}
	}
	return 3
}

func not(x int) int {
	if x != 0 {
		return 0
	}
	return 1
}
