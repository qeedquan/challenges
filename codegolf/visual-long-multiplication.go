/*

There is a nice way to perform long multiplication for two integers without having to do anything but counting, which occasional gets shared around the internet. You write the digits of each number as a bunch of slanted lines, with the two numbers at a 90 degree angle. Then you can simply count the intersections in the separate columns that arise. A diagram will probably clarify this. Here is an example for calculating 21 * 32:

https://i.sstatic.net/YTK7c.png

If you google for "visual/graphical long multiplication" you'll find a lot more examples.

In this challenge, you are to generate these diagrams using ASCII art. For the same example, the output would look like this:

   \ /
    X /
 \ / X /
\ X / X
 X X / \ /
/ X X   X /
 / X \ / X
  / \ X / \
     X X
    / X \
     / \
It's probably easiest to figure out the construction rules for these from some examples (see below), but here some details:

Intersecting segments are X, non-intersecting segments of the lines are / or \.
There should be exactly one segment after the outermost intersections.
There should be exactly one segment between intersections belonging to different digits. If there are zero-digits, these will result in consecutive / or \ segments.
You have to support any positive input (at least up to some reasonable limit like 216 or 232), and any digits from 0 to 9. However, you may assume that there neither leading nor trailing 0s.
You must not print extraneous leading whitespace or leading or trailing empty lines.
You may print trailing whitespace but it must not exceed the diagram's axis-aligned bounding box.
You may optionally print a single trailing newline.
You may choose in which order you take the two input numbers. However, it you must support arbitrary numbers for either orientation, so you can't choose something like "The larger number is given first".
If you're taking input as a string, you can use any non-digit separator between the two numbers.
You may write a program or function, taking input via STDIN (or closest alternative), command-line argument or function argument and outputting the result via STDOUT (or closest alternative), function return value or function (out) parameter.

This is code golf, the shortest answer (in bytes) wins.

Examples
1*1
\ /
 X
/ \

2*61
 \ /
\ X /
 X X /
/ X X /
 / X X /
  / X X /
   / X X
    / X \ /
     / \ X
        X \
       / \

 45*1
         \ /
        \ X
       \ X \
      \ X \
     \ X \
      X \
   \ / \
  \ X
 \ X \
\ X \
 X \
/ \

21001*209
       \ /
        X /
       / X
      / / \
   \ / /   \ /
    X /     X /
 \ / X     / X /
\ X / \   / / X /
 X X   \ / / / X /
/ X \   X / / / X /
 / \ \ / X / / / X /
    \ X / X / / / X /
     X X / X / / / X /
    / X X / X / / / X
     / X X / X / / / \
      / X X / X / /
       / X X / X /
        / X X / X
         / X X / \
          / X X
           / X \
            / \

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	vismul(1, 1)
	vismul(2, 61)
	vismul(45, 1)
	vismul(21001, 209)
	vismul(21, 32)
	vismul(5, 9)
	vismul(16, 27)
	vismul(7, 24)
	vismul(123, 543)
	vismul(735, 21)
}

func vismul(x, y uint) [][]byte {
	const sym = ` \/x`

	a := lens(x)
	b := lens(y)
	slices.Reverse(b)

	l := lines(len(a) + len(b))
	for i := range a {
		for j := range b {
			l[i+j][j-i+len(a)] = sym[a[i]+2*b[j]]
		}
	}

	fmt.Printf("%d*%d\n", x, y)
	for i := range l {
		fmt.Printf("%s\n", l[i])
	}
	return l
}

func lines(n int) [][]byte {
	l := make([][]byte, n)
	for i := range l {
		l[i] = make([]byte, n)
		for j := range l[i] {
			l[i][j] = ' '
		}
	}
	return l
}

func lens(n uint) []int {
	r := []int{0}
	for {
		for i := uint(0); i < n%10; i++ {
			r = append(r, 1)
		}
		r = append(r, 0)

		if n /= 10; n == 0 {
			break
		}
	}
	return r
}
