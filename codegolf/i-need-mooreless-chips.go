/*

If you wanted to compute a very large long problem, that on a machine that you could buy today for an inflation adjusted price, will take some amount of years/decades. The issue is, if you only have that budget, and so can only purchase one machine. So if you purchase the machine now, it may actually take longer to compute than if you purchase one later, for the same inflation adjusted price, because of Moore's Law.

Moore's law states that machines will double in everything every two years, so, theoretically, a problem that takes m years to compute now, will only take m/2 years 2 years from now. The question is, how long should I wait to buy the machine, if I need to compute a problem that takes m years to compute, to get the optimal time of computation, which is inclusive of the time waited to buy the machine, and how much time does it take?

It is assumed both that I gain no money, and make just enough interest on my money to beat inflation, but no more, and also that Moore's Law continues ad infinitum.

some examples:
years 	time-to-wait 	time-it-takes
0 years 	0 seconds, buy now! 	0 years
1 year 	0 seconds, buy now! 	1 year
2 years 	0 seconds, buy now! 	2 years
3 years 	0.1124 years 	2.998 years
4 years 	0.9425 years 	3.828 years
5 years 	1.5863 years 	4.472 years
7 years 	2.557 years 	5.443 years
8 years 	2.942 years 	5.828 years
10 years 	3.586 years 	6.472 years
20 years 	5.586 years 	8.472 years
100 years 	10.23 years 	13.12 years
1000000 years 	38.81 years 	takes 39.70 years

Code-golf, so shortest answer wins.

Desmos example text:

f\left(t\right)=N\cdot\left(\frac{1}{2}^{\frac{t}{2}}\right)+t

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(0, 0, 0)
	test(1, 0, 1)
	test(2, 0, 2)
	test(3, 0.1124, 2.998)
	test(4, 0.9425, 3.828)
	test(5, 1.5863, 4.472)
	test(7, 2.557, 5.443)
	test(8, 2.942, 5.828)
	test(10, 3.586, 6.472)
	test(20, 5.586, 8.472)
	test(100, 10.23, 13.12)
	test(1000000, 36.805, 39.70)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(y, rw, rt float64) {
	const eps = 1e-2
	w, t := mooreless(y)
	fmt.Println(y, w, t)
	assert(math.Abs(w-rw) < eps)
	assert(math.Abs(t-rt) < eps)
}

func mooreless(y float64) (float64, float64) {
	x := max(0, math.Log2(y*math.Ln2)*2-2)
	return x, x + y/math.Pow(2, x/2)
}
