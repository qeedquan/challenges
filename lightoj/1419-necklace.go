/*

You are a necklace maker. You like this task because it's challenging, fascinating and of course makes a lot of money. Now, you want to make a necklace consisting of n beads. The beads are connected in the following fashion:
https://static.lightoj.com/images/problem-1419/necklace1-1602925531708.png?rightme

Bead i (1 < i < n) is connected with bead i - 1 and bead i + 1.
The first bead is connected with the second bead and the nth bead.
The nth bead is connected with the first bead and the (n-1)th bead.
Now you have K colors and each bead can be colored using one of the K colors. You have to find the number of possible necklaces you can make using these colors. Two necklaces will be considered same if one can be rotated to another.

For example, say there are 4 beads in the necklace and you have two colors yellow and green, then there are 6 possible necklaces. They are:

https://static.lightoj.com/images/problem-1419/necklace2-1602925827643.png
https://static.lightoj.com/images/problem-1419/necklace3-1602925926983.png
https://static.lightoj.com/images/problem-1419/necklace4-1602925981308.png
https://static.lightoj.com/images/problem-1419/necklace5-1602926028944.png
https://static.lightoj.com/images/problem-1419/necklace6-1602926068704.png
https://static.lightoj.com/images/problem-1419/necklace7-1602926104139.png

Input
Input starts with an integer T (≤ 50), denoting the number of test cases.

Each case starts with a line containing two integers: n and K (1 ≤ n ≤ 1000, 1 ≤ K ≤ 109).

Output
For each case, print the case number and the total number of possible necklaces modulo 1000000007 (109 + 7).

Sample
Input	Output
7
4 2
5 7
5 2
4 8
4 3
5 3
5 5

Case 1: 6
Case 2: 3367
Case 3: 8
Case 4: 1044
Case 5: 24
Case 6: 51
Case 7: 629

*/

package main

func main() {
	assert(necklaces(4, 2) == 6)
	assert(necklaces(5, 7) == 3367)
	assert(necklaces(5, 2) == 8)
	assert(necklaces(4, 8) == 1044)
	assert(necklaces(4, 3) == 24)
	assert(necklaces(5, 3) == 51)
	assert(necklaces(5, 5) == 629)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://handwiki.org/wiki/Necklace_(combinatorics)
func necklaces(n, k int) int {
	r := 0
	for a := 1; a <= n; a++ {
		if n%a == 0 {
			b := n / a
			r += totient(a) * ipow(k, b)
		}
	}
	return r / n
}

// https://oeis.org/A000010
func totient(n int) int {
	if n < 1 {
		return 0
	}

	p := n
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			p -= p / i
			for n%i == 0 {
				n /= i
			}
		}
	}
	if n > 1 {
		p -= p / n
	}
	return p
}

func ipow(x, p int) int {
	r := 1
	for i := 0; i < p; i++ {
		r *= x
	}
	return r
}
