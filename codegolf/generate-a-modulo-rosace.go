/*

The cool stuff
The following rosace can help calculate numbers modulo 7.

https://i.stack.imgur.com/6b7cR.png

In order to do that, you must start at 0 and turn clockwise a number of steps given by the first digit. Then, for each successive digit, follow the arrow and then turn clockwise the number of steps given by that digit.

Here is how you proceed for number 294:

You start at circle 0.
You turn clockwise the number of steps given by the first digit (which is a 2, you end up at 2).
You follow the arrow there (you end up at 6).
You turn clockwise the number of steps given by the second digit (which is a 9, you end up at 1).
You follow the arrow there (you end up at 3).
You turn clockwise the number of steps given by the third number (which is 4, you end up at 0).
294 mod 7 = 0 (meaning 294 is multiple of 7).
(Video explanation if you still didn't get it)
https://www.youtube.com/watch?v=vxHrfIom-YA

The goal
Figure out how that works (I know but I won't tell you).

Create a program that takes a number n in parameter and that generates a rosace for mod n.

The rosace can be displayed by any means you want (ASCII, generate PNG, generate SVG, ...) as long as it could be used by a 8 years old child (so no list of rules, I want a picture)!

You can use strait lines, even if it's a bit less clear than what I made for the example, but you must show clearly the numbers that point to themselves with some kind of tail-biting arrow.

Test cases
(I only give the links between the numbers, feel free to edit my question once your program sucessfully generates them)

mod 2:

0 -> 0
1 -> 0
mod 3:

0 -> 0
1 -> 1
2 -> 2
mod 4:

0 -> 0
1 -> 2
2 -> 0
3 -> 2
mod 5:

0 -> 0
1 -> 0
2 -> 0
3 -> 0
4 -> 0
mod 6:

0 -> 0
1 -> 4
2 -> 2
3 -> 0
4 -> 4
5 -> 2
mod 7:

0 -> 0
1 -> 3
2 -> 6
3 -> 2
4 -> 5
5 -> 1
6 -> 4
mod 8:

0 -> 0
1 -> 2
2 -> 4
3 -> 6
4 -> 0
5 -> 2
6 -> 4
7 -> 6
mod 9:

0 -> 0
1 -> 1
2 -> 2
3 -> 3
4 -> 4
5 -> 5
6 -> 6
7 -> 7
8 -> 8
mod 10:

0 -> 0
1 -> 0
2 -> 0
3 -> 0
4 -> 0
5 -> 0
6 -> 0
7 -> 0
8 -> 0
9 -> 0

Rules
This is code-golf, shortest code in bytes wins.

As usual, loopholes and cheats are forbidden.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(2, [][2]int{{0, 0}, {1, 0}})
	test(3, [][2]int{{0, 0}, {1, 1}, {2, 2}})
	test(4, [][2]int{{0, 0}, {1, 2}, {2, 0}, {3, 2}})
	test(5, [][2]int{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}})
	test(6, [][2]int{{0, 0}, {1, 4}, {2, 2}, {3, 0}, {4, 4}, {5, 2}})
	test(7, [][2]int{{0, 0}, {1, 3}, {2, 6}, {3, 2}, {4, 5}, {5, 1}, {6, 4}})
	test(8, [][2]int{{0, 0}, {1, 2}, {2, 4}, {3, 6}, {4, 0}, {5, 2}, {6, 4}, {7, 6}})
	test(9, [][2]int{{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}})
	test(10, [][2]int{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r [][2]int) {
	q := genfsm(n)
	fmt.Println(n, q)
	assert(reflect.DeepEqual(q, r))
}

// https://mindyourdecisions.com/blog/2015/07/26/divisibility-by-7-test-using-a-graph-why-does-it-work-sunday-puzzle/
func genfsm(n int) [][2]int {
	q := make([][2]int, n)
	for i := 0; i < n; i++ {
		q[i] = [2]int{i, (10 * i) % n}
	}
	return q
}
