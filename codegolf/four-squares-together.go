/*

Lagrange's four square theorem tells us any natural number can be represented as the sum of four square numbers. Your task is to write a program that does this.

Input: A natural number (below 1 billion)

Output: Four numbers whose squares sum to that number (order doesn't matter)

Note: You don't have to do a brute force search! Details here and here. If there is a function that trivializes this problem (I will determine), it's not allowed. Automated prime functions and square root are allowed. If there is more than one representation any one is fine. If you chose to do brute force, it must run within reasonable time (3 minutes)

sample input

123456789
sample output (either is fine)

10601 3328 2 0
10601 3328 2

*/

package main

import (
	"math"
	"runtime"
	"sync"
)

func main() {
	var (
		wg     sync.WaitGroup
		ncpu   = runtime.NumCPU()
		amount = 100000
		limit  = 100000000
	)

	wg.Add(ncpu)
	for i := 0; i < ncpu; i++ {
		go worker(i*amount, ncpu*amount, amount, limit, &wg)
	}
	wg.Wait()
}

func worker(start, step, amount, limit int, wg *sync.WaitGroup) {
	for i := start; i < limit; i += step {
		for j := 0; j < amount; j++ {
			test(i + j)
		}
	}
	wg.Done()
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int) {
	a, b, c, d := foursquares(n)
	assert(a*a+b*b+c*c+d*d == n)
}

/*

https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem#Algorithms
https://web.archive.org/web/20040405113026/http://www.schorn.ch/howto.html

Ported from @primo solution

*/

func foursquares(n int) (a, b, c, d int) {
	Db := [][]int{
		{0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 2, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 2, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 1, 0, 0, 0, 1, 0},
		{2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
		{3, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 1, 0, 2, 0, 0, 1, 2, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 1, 1, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
		{2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
		{3, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 2, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 2, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 3, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0, 0, 1, 0},
		{2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
		{3, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 1, 0, 2, 0, 0, 1, 2, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
		{1, 1, 0, 0, 1, 1, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
		{2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
		{3, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0},
	}

	Dc := [][]int{
		{0, 0, 1, 0, 0, 1, 3, 0, 2, 0, 1, 1, 0, 2, 1, 0, 0, 1, 3, 0, 2, 6, 1, 1, 6, 0, 1, 0, 0, 2, 3, 0, 4, 0, 1, 1, 0, 1, 1, 0, 2, 4, 3, 0, 2, 3, 1, 1},
		{1, 0, 0, 1, 1, 0, 4, 0, 3, 1, 0, 0, 1, 3, 0, 1, 1, 0, 4, 0, 3, 7, 0, 0, 7, 1, 0, 1, 1, 3, 4, 0, 5, 1, 0, 0, 1, 0, 0, 1, 3, 5, 4, 0, 3, 4, 0, 0},
		{2, 1, 1, 2, 0, 0, 5, 0, 0, 2, 1, 0, 2, 0, 1, 2, 2, 1, 5, 0, 0, 8, 1, 0, 8, 2, 1, 2, 0, 0, 5, 0, 6, 2, 1, 0, 2, 0, 1, 2, 0, 6, 5, 0, 0, 5, 1, 0},
		{3, 2, 2, 0, 1, 1, 0, 0, 1, 0, 0, 1, 3, 0, 2, 0, 3, 2, 0, 0, 1, 9, 0, 1, 9, 0, 2, 0, 1, 1, 0, 0, 7, 3, 0, 1, 3, 1, 2, 0, 1, 7, 0, 0, 1, 0, 0, 1},
		{4, 0, 3, 1, 0, 2, 1, 0, 2, 1, 1, 0, 4, 1, 3, 1, 0, 0, 1, 0, 0, 10, 1, 0, 10, 0, 3, 1, 0, 2, 1, 0, 0, 4, 1, 0, 4, 2, 3, 1, 2, 0, 1, 0, 0, 1, 1, 0},
		{5, 1, 0, 2, 1, 3, 2, 0, 3, 2, 0, 0, 5, 0, 0, 2, 1, 1, 2, 0, 1, 11, 0, 0, 11, 0, 0, 2, 1, 0, 2, 0, 1, 5, 0, 0, 5, 3, 0, 2, 3, 0, 2, 0, 1, 2, 0, 0},
		{6, 2, 1, 0, 0, 4, 3, 0, 4, 3, 1, 1, 0, 0, 1, 0, 2, 2, 3, 0, 2, 0, 1, 1, 0, 1, 1, 0, 0, 1, 3, 0, 2, 6, 1, 1, 0, 0, 1, 0, 0, 1, 3, 0, 2, 0, 1, 1},
		{7, 0, 0, 1, 1, 0, 4, 0, 5, 4, 0, 0, 1, 1, 0, 1, 3, 0, 4, 0, 3, 1, 0, 0, 1, 2, 0, 1, 1, 2, 4, 0, 3, 7, 0, 0, 1, 0, 0, 1, 1, 2, 4, 0, 3, 1, 0, 0},
		{8, 0, 1, 2, 0, 1, 5, 0, 6, 5, 1, 0, 2, 2, 1, 2, 0, 0, 5, 0, 0, 2, 1, 0, 2, 0, 1, 2, 0, 3, 5, 0, 0, 8, 1, 0, 2, 1, 1, 2, 2, 0, 5, 0, 0, 2, 1, 0},
		{9, 0, 2, 0, 1, 2, 0, 0, 7, 6, 0, 1, 3, 3, 2, 0, 1, 1, 0, 0, 1, 0, 0, 1, 3, 1, 2, 0, 1, 4, 0, 0, 1, 0, 0, 1, 3, 0, 2, 0, 3, 1, 0, 0, 1, 3, 0, 1},
		{10, 1, 3, 1, 0, 0, 1, 0, 0, 7, 1, 0, 4, 0, 3, 1, 2, 2, 1, 0, 0, 1, 1, 0, 4, 2, 3, 1, 0, 0, 1, 0, 2, 1, 1, 0, 4, 0, 3, 1, 0, 2, 1, 0, 0, 4, 1, 0},
		{11, 2, 0, 2, 1, 1, 2, 0, 1, 8, 0, 0, 5, 0, 0, 2, 3, 3, 2, 0, 1, 2, 0, 0, 5, 0, 0, 2, 1, 0, 2, 0, 3, 2, 0, 0, 5, 1, 0, 2, 1, 0, 2, 0, 1, 5, 0, 0},
		{0, 0, 1, 0, 0, 2, 3, 0, 2, 0, 1, 1, 0, 1, 1, 0, 0, 4, 3, 0, 2, 3, 1, 1, 6, 0, 1, 0, 0, 1, 3, 0, 4, 0, 1, 1, 0, 2, 1, 0, 2, 1, 3, 0, 2, 6, 1, 1},
		{1, 1, 0, 1, 1, 3, 4, 0, 3, 1, 0, 0, 1, 0, 0, 1, 1, 5, 4, 0, 3, 4, 0, 0, 7, 0, 0, 1, 1, 0, 4, 0, 5, 1, 0, 0, 1, 3, 0, 1, 3, 0, 4, 0, 3, 7, 0, 0},
		{2, 2, 1, 2, 0, 0, 5, 0, 0, 2, 1, 0, 2, 0, 1, 2, 2, 6, 5, 0, 0, 5, 1, 0, 8, 1, 1, 2, 0, 0, 5, 0, 6, 2, 1, 0, 2, 0, 1, 2, 0, 1, 5, 0, 0, 8, 1, 0},
		{3, 0, 2, 0, 1, 1, 0, 0, 1, 3, 0, 1, 3, 1, 2, 0, 3, 7, 0, 0, 1, 0, 0, 1, 9, 2, 2, 0, 1, 1, 0, 0, 7, 0, 0, 1, 3, 0, 2, 0, 1, 2, 0, 0, 1, 9, 0, 1},
		{4, 0, 3, 1, 0, 2, 1, 0, 2, 4, 1, 0, 4, 2, 3, 1, 0, 0, 1, 0, 0, 1, 1, 0, 10, 0, 3, 1, 0, 2, 1, 0, 0, 1, 1, 0, 4, 1, 3, 1, 2, 0, 1, 0, 0, 10, 1, 0},
		{5, 0, 0, 2, 1, 0, 2, 0, 3, 5, 0, 0, 5, 3, 0, 2, 1, 0, 2, 0, 1, 2, 0, 0, 11, 1, 0, 2, 1, 3, 2, 0, 1, 2, 0, 0, 5, 0, 0, 2, 3, 1, 2, 0, 1, 11, 0, 0},
		{6, 1, 1, 0, 0, 1, 3, 0, 4, 6, 1, 1, 0, 0, 1, 0, 2, 1, 3, 0, 2, 0, 1, 1, 0, 2, 1, 0, 0, 4, 3, 0, 2, 3, 1, 1, 0, 0, 1, 0, 0, 2, 3, 0, 2, 0, 1, 1},
		{7, 2, 0, 1, 1, 2, 4, 0, 5, 7, 0, 0, 1, 0, 0, 1, 3, 2, 4, 0, 3, 1, 0, 0, 1, 0, 0, 1, 1, 0, 4, 0, 3, 4, 0, 0, 1, 1, 0, 1, 1, 0, 4, 0, 3, 1, 0, 0},
		{8, 0, 1, 2, 0, 3, 5, 0, 6, 8, 1, 0, 2, 1, 1, 2, 0, 0, 5, 0, 0, 2, 1, 0, 2, 0, 1, 2, 0, 1, 5, 0, 0, 5, 1, 0, 2, 2, 1, 2, 2, 0, 5, 0, 0, 2, 1, 0},
		{9, 1, 2, 0, 1, 4, 0, 0, 7, 0, 0, 1, 3, 0, 2, 0, 1, 1, 0, 0, 1, 3, 0, 1, 3, 0, 2, 0, 1, 2, 0, 0, 1, 6, 0, 1, 3, 3, 2, 0, 3, 1, 0, 0, 1, 0, 0, 1},
		{10, 2, 3, 1, 0, 0, 1, 0, 0, 1, 1, 0, 4, 0, 3, 1, 2, 2, 1, 0, 0, 4, 1, 0, 4, 1, 3, 1, 0, 0, 1, 0, 2, 7, 1, 0, 4, 0, 3, 1, 0, 2, 1, 0, 0, 1, 1, 0},
		{11, 0, 0, 2, 1, 0, 2, 0, 1, 2, 0, 0, 5, 1, 0, 2, 3, 0, 2, 0, 1, 5, 0, 0, 5, 2, 0, 2, 1, 1, 2, 0, 3, 8, 0, 0, 5, 0, 0, 2, 1, 3, 2, 0, 1, 2, 0, 0},
	}

	if n < 1 {
		return
	}

	k := 1
	for n&3 == 0 {
		n >>= 2
		k <<= 1
	}

	odd := n & 1
	n <<= odd

	a = isqrt(n)
	n -= a * a
	for {
		b = isqrt(n)
		b -= Db[b&15][n&31]
		v := n - b*b
		c = isqrt(v)
		c -= Dc[c%24][v%48]
		if c >= 0 {
			v -= c * c
			d = isqrt(v)

			if v == d*d {
				break
			}
		}

		n += (a << 1) - 1
		a -= 1
	}

	if odd != 0 {
		if (a^b)&1 != 0 {
			if (a^c)&1 != 0 {
				b, c, d = d, b, c
			} else {
				b, c = c, b
			}
		}
		a, b, c, d = (a+b)>>1, (a-b)>>1, (c+d)>>1, (c-d)>>1
	}

	a *= k
	b *= k
	c *= k
	d *= k

	return a, b, c, d
}

func isqrt(n int) int {
	return int(math.Sqrt(float64(n)))
}
