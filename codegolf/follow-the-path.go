/*

The challenge is to follow (draw) the path:

^n - up by n lines
vn - down by n lines
>n - right by n character positions
<n - left by n characters positions
n is an integer, greater than zero (i.e. you can't receive a command like >-2).
There're no separators between the commands, the well-formed input looks like this: >5v8<10^3, no other form of input allowed.
The number of commands is unlimited.
No more characters are supposed to creep into the input.
Examples.

Input is an empty string, output:

*
Input is either >3 or <3: note that this doesn't make any difference to the output:

****
Similar for ^3 and v3:

*
*
*
*
Input: >1v2, output:

**
 *
 *
Input: ^4>3v2<1, output:

****
*  *
* **
*
*
If you go back and use the same path, don't draw anything new. E.g. >5<5

******
...though you don't draw anything new, you obviously change the position. Hence, if your input looks like this: >4<2v3, the output is:

*****
  *
  *
  *
This is a more complex example: 1) the path can cross itself 2) note that the last three steps of the last command shift the whole path to the right. Input: v6>4^3<7, output:

   *
   *
   *
********
   *   *
   *   *
   *****
Input:

^2v2>3<3v3>4^5v5>3^5>4v2<4v3>4^3v3>3^5>4v2<4v3>7^5>4v2<4v3>9^3<2^2v2>4^2v2<2v3>8^5>2v4>2^4v5<3>6^5>5<5v2>5<5v2>5<4v1>8^3<1^2v2>1v2>2^3v3>2^2>1^2v2<1v3<3>11^3<2^2v2>4^2v2<2v3>5^5>5<5v2>5<5v2>5<4v1>7^5>4v2<4v3>4^3v3>3^5>4v2<3v1<1v2>3^1>1v1
Output:

*   *  *****  *****  *****  *   *     *** *  ******  *     *    *   *  ******  *****  *****
*   *  *   *  *   *  *   *  *   *     * * *  *       *  *  *    *   *  *       *   *  *   *
*****  *****  *****  *****  *****     * * *  ******  ** * **    *****  ******  *****  *****
*   *  *   *  *      *        *       * * *  *        * * *       *    *       *   *  **
*   *  *   *  *      *        *       * ***  ******   *****       *    ******  *   *  *  **
*******************************************************************************************

*/

package main

import (
	"fmt"
	"regexp"
	"strconv"
)

func main() {
	follow("")
	follow(">3")
	follow("<3")
	follow("^3")
	follow("v3")
	follow(">1v2")
	follow("^4>3v2<1")
	follow(">5<5")
	follow(">4<2v3")
	follow("v6>4^3<7")
	follow("^2v2>3<3v3>4^5v5>3^5>4v2<4v3>4^3v3>3^5>4v2<4v3>7^5>4v2<4v3>9^3<2^2v2>4^2v2<2v3>8^5>2v4>2^4v5<3>6^5>5<5v2>5<5v2>5<4v1>8^3<1^2v2>1v2>2^3v3>2^2>1^2v2<1v3<3>11^3<2^2v2>4^2v2<2v3>5^5>5<5v2>5<5v2>5<4v1>7^5>4v2<4v3>4^3v3>3^5>4v2<3v1<1v2>3^1>1v1")
}

func follow(s string) {
	var (
		re     = regexp.MustCompile(`[\^|v|<|>]\d+`)
		m      = map[[2]int]bool{{0, 0}: true}
		x0, y0 int
		x1, y1 int
		x, y   int
	)

	for _, op := range re.FindAllString(s, -1) {
		n, _ := strconv.Atoi(op[1:])
		dx, dy := 0, 0
		switch op[0] {
		case '^':
			dy = -1
		case 'v':
			dy = 1
		case '>':
			dx = 1
		case '<':
			dx = -1
		}

		for range n {
			x += dx
			i := [2]int{x, y}
			m[i] = true
		}
		for range n {
			y += dy
			i := [2]int{x, y}
			m[i] = true
		}

		x0 = min(x0, x)
		y0 = min(y0, y)
		x1 = max(x1, x)
		y1 = max(y1, y)
	}

	fmt.Printf("%q\n", s)
	for y = y0; y <= y1; y++ {
		for x = x0; x <= x1; x++ {
			i := [2]int{x, y}
			if m[i] {
				fmt.Printf("*")
			} else {
				fmt.Printf(" ")
			}
		}
		fmt.Println()
	}
	fmt.Println()
}
