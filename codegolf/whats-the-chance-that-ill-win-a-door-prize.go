/*

My local ACM chapter gives out door prizes to people who come to the meetings. You get an increased chance of winning if you solve the programming puzzle, however (but I always solve that puzzle). Thus, some people have 1 entry, while others have 2. But wait! The way the raffle program works is not by adding in another entry when someone solves the puzzle. Instead, it keeps track of the number of "lives" a person has, decrementing that if that person is chosen in each pass of it's random sampling algorithm. So it works like this:

Doorknob: 1.  xnor: 2.  Justin: 2.  Alex: 1.  Dennis: 2.
Then the program randomly chooses one of [Doorknob, xnor, Justin, Alex, Dennis], decrements the number (say it chooses Justin):

Doorknob: 1.  xnor: 2.  Justin: 1.  Alex: 1. Dennis: 2.
And repeats. If someone's number of "lives" goes to 0 (let's choose Justin again), they're removed from the list:

Doorknob: 1.  xnor: 2.  Alex: 1.  Dennis: 2.
This continues until there's one person left; that person is the winner.

Now the real question is, what was the probability that I would have won?

You will be given two inputs:

n. This is the number of people entered into the challenge
k. This is the number of people (of those n) who have 2 lives. This number always includes you.
So if I had a function p and called p(10, 5), that would be the probability of winning the prize where there are 10 people total, 5 of which only have 1 life, whereas 5 (including you) have 2 lives.

You are expected to output the probability of winning either exactly, or as a decimal. At any rate, answers must be accurate up to and including the 4th decimal place after the decimal point. Whether or not you round to that digit is up to you.

Your solution may be a randomized solution which outputs the answer to the 4th decimal place with high probability. You may assume that the built in RNG you use is truly random, and it must output the correct answer with at least 90% probability.

Furthermore, your code need only work for n, k <= 1000, although I did provide test cases larger than that for those curious.

Test Cases
Note: some of these are general formulae.

n,    k   |  output
----------+---------
1,    1   |  1
2,    2   |  0.5
2,    1   |  0.75
3,    1   |  11/18 = 0.611111111
1000, 1   |  0.007485470860550352
4,    3   |  0.3052662037037037
k,    k   |  1/k
n,    1   |  (EulerGamma + PolyGamma[1 + n])/n    (* Mathematica code *)
          |  (γ + ψ(1 + n))/n
10,   6   |  0.14424629234373537
300,  100 |  0.007871966408910648
500,  200 |  0.004218184180294532
1000, 500 |  0.0018008560286627948
---------------------------------- Extra (not needed to be a valid answer)
5000, 601 |  0.0009518052922680399
5000, 901 |  0.0007632938197806958
For another few checks, take p(n, 1) * n as follows:

n     |  output
------+---------
1     | 1
2     | 1.5
3     | 1.8333333333333335
10    | 2.928968253968254
100   | 5.1873775176396215
-------------------------- Extra (not needed to be a valid answer)
100000| 12.090146129863305

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(1, 1, 1)
	test(2, 2, 0.5)
	test(2, 1, 0.75)
	test(3, 1, 11.0/18)
	test(1000, 1, 0.007485470860550352)
	test(4, 3, 0.3052662037037037)
	test(9, 9, 1.0/9)
	test(10, 6, 0.14424629234373537)
	test(300, 100, 0.007871966408910648)
	test(500, 200, 0.004218184180294532)
	test(1000, 500, 0.0018008560286627948)
	test(5000, 601, 0.0009518052922680399)
	test(5000, 901, 0.0007632938197806958)
	test(1, 1, 1)
	test(2, 1, 1.5/2)
	test(3, 1, 1.8333333333333335/3)
	test(10, 1, 2.928968253968254/10)
	test(100, 1, 5.1873775176396215/100)
	test(100000, 1, 12.090146129863305/100000)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, k int, r float64) {
	x := chance(n, k)
	fmt.Println(x)
	assert(math.Abs(x-r) < 1e-5)
}

var (
	cache = make(map[[2]int]float64)
)

// ported from @Anders Kaseorg solution (algorithm gives an approximate solution)
func chance(n, k int) float64 {
	if n < 1 || k < 0 {
		return 0
	}

	if k == 0 || n == k {
		return 1 / float64(n)
	}

	i := [2]int{n, k}
	if v, ok := cache[i]; ok {
		return v
	}

	N := float64(n)
	K := float64(k)
	x := (1 + (N-K)*((K-1)*chance(n, k-1)+chance(n-1, k)*(N-K+1))) / (N - K + 1) / N

	cache[i] = x
	return x
}
