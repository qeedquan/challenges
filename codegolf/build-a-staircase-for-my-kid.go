/*

The other day, my son asked me to build him a staircase using Lego-ish blocks. And I came up with something like this:

https://i.sstatic.net/EzQUOm.jpg

Then my kid asked me for a program using the least number of bytes that generated a similar staircase in a computer screen. I am not that good at code-golf, so I need your help. I need a program that:

Receives a positive integer with the number of levels the staircase needs to have.
Outputs a drawing of a staircase, with the pattern you see in the image.
The output will be in text format but the bricks can be distinguished one from another. For instance, you may use the '█' character as half a block and paint it in any color you want, or just choose any character of your choice.

Restrictions:

Blocks need to be of three different colors, which will be used as long as possible (if input is 1 or 2 there are not enough blocks to use all three colors). If you want, you may use the '░▒▓' characters, for instance, or just select three different characters.
No two blocks of the same color or pattern can be side to side in a single row.
My son does not really care about trailing spaces or new lines as long as a staircase is drawn.

Examples (sorry for the bad choice of characters):

Input: 1
Output:
██

Input: 2
Output:
██
 ▓▓

Input: 3
Output:
██
 ▓▓
██░░

Input: 5
Output:
██
 ██
██░░
 ██░░
██░░▓▓

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	for i := range 6 {
		staircase(i)
	}
}

/*

@xnor

Prints rows of increasing length i=2,3,.. by creating a space for odd lengths, repeating the pattern i times, and trunctating to length i.
The pattern is 2244 for all rows except the first one i=2 for which it's 0.
This is achieved with the arithmetic expression 2%i*1122.

*/

func staircase(n int) {
	fmt.Printf("n=%d\n", n)
	if n < 1 {
		return
	}
	for i := 2; i <= n+1; i++ {
		x := fmt.Sprintf("%d", (2%i)*1122)
		s := strings.Repeat(" ", i&1) + strings.Repeat(x, i)
		s = s[:i]
		s = strings.Replace(s, "0", "█", -1)
		s = strings.Replace(s, "2", "▓", -1)
		s = strings.Replace(s, "4", "░", -1)
		fmt.Println(s)
	}
	fmt.Println()
}
