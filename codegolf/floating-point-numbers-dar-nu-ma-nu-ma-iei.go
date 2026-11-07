/*

When you leave, my challenges fade to grey, 0A0AE16, 0A0A0AE16...

A while ago, I made this programming language (https://esolangs.org/wiki/Dragostea_din_tei) which uses an interesting number system. It is base two for integers, but for decimals it divides a base two integer by a power of ten.

The input should be a floating point number, negative, positive or zero.

The output should be "the" standard representation for, that number, in the programming language, which should follow these steps:

Start with the absolute value of that number. Now multiply the result by the smallest power of ten to make it an integer (for example, 123.45 -> multiply by 100 to make 12345) and call it a.
Write Ma-ia hii + a newline (literally, push the number zero).
Write a in base two, with Ma-ia huu + a newline for ones, and Ma-ia hoo + a newline for 0's.
Now, if the original number (not a) has any decimal places, write Ma-ia haha + a newline for every digit after the decimal point, for example twice for 123.45.
If the original number is negative, write Vrei sa pleci dar.
You can add or omit trailing and leading newlines if you want.

DONE. Now, here are some good ol' examples: -10 is:

Ma-ia hii
Ma-ia huu
Ma-ia hoo
Ma-ia huu
Ma-ia hoo
Vrei sa pleci dar
256 is:

Ma-ia hii
Ma-ia huu
Ma-ia hoo
Ma-ia hoo
Ma-ia hoo
Ma-ia hoo
Ma-ia hoo
Ma-ia hoo
Ma-ia hoo
Ma-ia hoo
And 3.14 is:

Ma-ia hii
Ma-ia huu
Ma-ia hoo
Ma-ia hoo
Ma-ia huu
Ma-ia huu
Ma-ia huu
Ma-ia hoo
Ma-ia huu
Ma-ia hoo
Ma-ia haha
Ma-ia haha
And finally for -3.14:

Ma-ia hii
Ma-ia huu
Ma-ia hoo
Ma-ia hoo
Ma-ia huu
Ma-ia huu
Ma-ia huu
Ma-ia hoo
Ma-ia huu
Ma-ia hoo
Ma-ia haha
Ma-ia haha
Vrei sa pleci dar

This is code-golf, so fewest bytes wins!

*/

package main

import (
	"fmt"
	"math/big"
	"strings"
)

func main() {
	rep("-10")
	rep("256")
	rep("3.14")
	rep("-3.14")
}

func rep(s string) {
	var (
		zero = big.NewInt(0)
		one  = big.NewInt(1)
	)

	f := 0
	i := strings.Index(s, ".")
	if i >= 0 {
		i = len(s) - i - 1
	}
	s = strings.Replace(s, ".", "", -1)

	x := new(big.Int)
	x.SetString(s, 10)
	if x.Cmp(zero) < 0 {
		x.Abs(x)
		f |= 1
	}

	fmt.Println("Ma-ia hii")

	d := []int{}
	for x.Cmp(zero) != 0 {
		y := new(big.Int)
		y.And(x, one)
		if y.Cmp(one) == 0 {
			d = append(d, 1)
		} else {
			d = append(d, 0)
		}
		x.Rsh(x, 1)
	}

	for n := len(d) - 1; n >= 0; n-- {
		if d[n] != 0 {
			fmt.Println("Ma-ia huu")
		} else {
			fmt.Println("Ma-ia hoo")
		}
	}

	for range i {
		fmt.Println("Ma-ia haha")
	}

	if f&1 != 0 {
		fmt.Println("Vrei sa pleci dar")
	}

	fmt.Println()
}
