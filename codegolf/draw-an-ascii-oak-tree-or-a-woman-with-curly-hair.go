/*

Task
Your task is to draw these beautiful oak trees:

1 ->
 @@@
@@@@@
@|.|@
_|_|_

2 ->
   @@
 @@@@@@
@@@@@@@@
@@| .|@@
  |  |
__|__|__

3 ->
   @@@@@
 @@@@@@@@@
@@@@@@@@@@@
@@@|   |@@@
  @|  .|@
   |   |
___|___|___

4 ->
      @@
   @@@@@@@@
 @@@@@@@@@@@@
@@@@@@@@@@@@@@
@@@@|    |@@@@
  @@|   .|@@
    |    |
    |    |
____|____|____

5 ->
      @@@@@
   @@@@@@@@@@@
 @@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@
@@@@@|     |@@@@@
  @@@|    .|@@@
     |     |
     |     |
     |     |
_____|_____|_____

6 ->
      @@@@@@@@
   @@@@@@@@@@@@@@
 @@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@
@@@@@@|      |@@@@@@
  @@@@|      |@@@@
     @|     .|@
      |      |
      |      |
      |      |
______|______|______
(that one sandbox commenter felt were similar to women with curly hair!)

The trees are allowed to be surrounded by any extra whitespace your solution creates as long as that doesn't break the tree, of course.

Algorithm
As per the examples above, we take n to represent the width of the trunk and the specs of the tree will be given in terms of that.

Given n:

the height of the trunk is n + 1;
the width of the trunk in space characters is n;
the top row of the trunk is n times the character @, followed by |, n times the space character , another vertical pipe | and then n times @.
from the reference row up to the top of the crown, we only use @ as follows:
there is one row with the same width as the reference row and each subsequent row above is shortened by one @ than the previous shortening;
from the reference row downwards, we chop 2 @ from each side and then each row we go down, we chop one more @ than the previous row;
the last trunk row that is surrounded by a @ has a . immediately to the left of the right vertical pipe |;
the bottom most row has the underscore _ in all the tree width, except where the trunk vertical pipes | are.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	for i := range 7 {
		show(i, oak(i))
	}
}

func oak(n int) []string {
	sep := []string{".", " "}

	w := 3*n + 2
	s := w
	r := []string{}
	for i := 1; s > 1; i++ {
		l := rep(" ", (w-s)/2) + rep("@", s)
		r = append([]string{l}, r...)
		s -= 2 * i
	}

	b := n
	for s, i := n, 2; s > 0; i++ {
		j := 0
		if s-i > 0 {
			j = 1
		}
		r = append(r, rep(" ", n-s)+rep("@", s)+"|"+rep(" ", n-1)+sep[j]+"|"+rep("@", s))
		s -= i
		b -= 1
	}

	for ; b > 0; b-- {
		r = append(r, rep(" ", n)+"|"+rep(" ", n)+"|")
	}
	r = append(r, rep("_", n)+"|"+rep("_", n)+"|"+rep("_", n))

	return r
}

func show(n int, s []string) {
	fmt.Printf("n=%d\n", n)
	for i := range s {
		fmt.Println(s[i])
	}
	fmt.Println()
}

func rep(s string, n int) string {
	if n < 0 {
		return ""
	}
	return strings.Repeat(s, n)
}
