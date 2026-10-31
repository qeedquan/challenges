/*

Write a program or function that takes as input three positive integers x, y,
and a and returns or outputs the maximum number of whole a✕1 rectangles that can be packed (axis-aligned) into an x✕y rectangle.
Although the result will always be an integer, the program need not give the result using an integer type;
in particular, floating-point outputs are acceptable.
Use of standard loopholes is forbidden.
Answers are scored in bytes including the cost of non-standard compiler flags or other marks.

Sample inputs and outputs:

 x,  y,  a -> result
--------------------
 1,  1,  3 ->      0
 2,  2,  3 ->      0
 1,  6,  4 ->      1
 6,  1,  4 ->      1
 1,  6,  3 ->      2
 6,  1,  3 ->      2
 2,  5,  3 ->      2
 5,  2,  3 ->      2
 3,  3,  3 ->      3
 3,  4,  3 ->      4
 4,  3,  3 ->      4
 4,  4,  3 ->      5
 6,  6,  4 ->      8
 5,  7,  4 ->      8
 7,  5,  4 ->      8
 6,  7,  4 ->     10
 7,  6,  4 ->     10
 5,  8,  3 ->     13
 8,  5,  3 ->     13
12, 12,  8 ->     16
12, 13,  8 ->     18
13, 12,  8 ->     18
 8,  8,  3 ->     21
12, 12,  5 ->     28
13, 13,  5 ->     33

In response to a question in the comments, note that some optimal packings may not be obvious at first glance.
For instance, the case x=8, y=8, and a=3 has solutions that look like this:

||||||||
||||||||
||||||||
---||---
---||---
|| ||---
||------
||------
(8 + 2 + 2 = 12 vertical placements and 2 + 3 + 4 = 9 horizontal placements gives 12 + 9 = 21 placements in total.)

*/

package main

func main() {
	assert(capacity(1, 1, 3) == 0)
	assert(capacity(2, 2, 3) == 0)
	assert(capacity(1, 6, 4) == 1)
	assert(capacity(6, 1, 4) == 1)
	assert(capacity(1, 6, 3) == 2)
	assert(capacity(6, 1, 3) == 2)
	assert(capacity(2, 5, 3) == 2)
	assert(capacity(5, 2, 3) == 2)
	assert(capacity(3, 3, 3) == 3)
	assert(capacity(3, 4, 3) == 4)
	assert(capacity(4, 3, 3) == 4)
	assert(capacity(4, 4, 3) == 5)
	assert(capacity(6, 6, 4) == 8)
	assert(capacity(5, 7, 4) == 8)
	assert(capacity(7, 5, 4) == 8)
	assert(capacity(6, 7, 4) == 10)
	assert(capacity(7, 6, 4) == 10)
	assert(capacity(5, 8, 3) == 13)
	assert(capacity(8, 5, 3) == 13)
	assert(capacity(12, 12, 8) == 16)
	assert(capacity(12, 13, 8) == 18)
	assert(capacity(13, 12, 8) == 18)
	assert(capacity(8, 8, 3) == 21)
	assert(capacity(12, 12, 5) == 28)
	assert(capacity(13, 13, 5) == 33)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@xnor

lambda p,q,n:p/n*q+q/n*(p%n)-min(0,n-p%n-q%n)*(p>n<q)

Adapts the formula given in this paper, which is:
https://www.sciencedirect.com/science/article/pii/0012365X79901158

def f(p,q,n):a=p%n;b=q%n;return(p*q-[a*b,(n-a)*(n-b)][a+b>=n and p>=n and q>=n])/n

*/

func capacity(x, y, n int) int {
	xm := x % n
	ym := y % n
	p := min(0, n-xm-ym) * truth(x > n && n < y)
	return (x/n)*y + (y/n)*xm - p
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}
