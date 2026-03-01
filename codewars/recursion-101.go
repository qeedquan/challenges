/*

In this Kata, you will be given two positive integers a and b and your task will be to apply the following operations:

i) If a = 0 or b = 0, return [a,b]. Otherwise, go to step (ii);
ii) If a ≥ 2*b, set a = a - 2*b, and repeat step (i). Otherwise, go to step (iii);
iii) If b ≥ 2*a, set b = b - 2*a, and repeat step (i). Otherwise, return [a,b].
a and b will both be lower than 10E8.

More examples in tests cases. Good luck!

Please also try Simple time difference

*/

package main

import "fmt"

func main() {
	fmt.Println(f(29, 40))
	fmt.Println(f(5, 45))
	fmt.Println(f(100, 200))
}

func f(a, b int) (int, int) {
	switch {
	case a == 0 || b == 0:
		return a, b
	case a >= 2*b:
		return f(a-2*b, b)
	case b >= 2*a:
		return f(a, b-2*a)
	}
	return a, b
}
