/*

Description
Simplify square roots in the form (a sqrt(b))/(c sqrt(d)). A simplified radical should have no square roots in the denominator and no number in a square root should have a square factor. For example, the input 2 5 5 10 for a b c d, respectively, should simplify to 1 2 5 where a=1, b=2, and c=5.

Output description
 a b c
(d should not exist after simplifying)

Challenge input
45 1465 26 15
Challenge output
15 879 26

Credit
This challenge was suggested by user u/alchzh on r/dailyprogrammer_ideas, many thanks. If you have an idea, please share it there and we might use it!

*/

package main

import (
	"fmt"
)

func main() {
	test(2, 5, 5, 10)
	test(45, 1465, 26, 15)
}

func test(a, b, c, d int) {
	fmt.Printf("%d[%d] / %d[%d] --> ", a, b, c, d)
	fmt.Println(radical(simplify(a, b, c, d)))
}

func simplify(a, b, c, d int) (int, int, int) {
	b, c = b*d, c*d
	a, b = root(a, b)
	a, c = fraction(a, c)
	return a, b, c
}

func root(a, b int) (int, int) {
	for i := 2; i*i <= b; {
		if b%(i*i) == 0 {
			b /= i * i
			a *= i
		} else {
			i++
		}
	}
	return a, b
}

func fraction(n, d int) (int, int) {
	i := gcd(n, d)
	return n / i, d / i
}

func radical(a, b, c int) string {
	switch {
	case b == 1 && c == 1:
		return fmt.Sprint(a)
	case b == 1:
		return fmt.Sprint(a, "/", c)
	case c == 1:
		return fmt.Sprintf("%d[%d]", a, b)
	default:
		return fmt.Sprintf("%d[%d] / %d", a, b, c)
	}
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
