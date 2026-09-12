/*

Challenge
Given a positive integer n, count the number of n×n binary matrices (i.e. whose entries are 0 or 1) with exactly two 1's in each rows and two 1's in each column.

Here are a few examples of valid matrices for n=4:

1100        1100        1100
1100        0011        0110
0011        1100        0011
0011        0011        1001

And here are a few invalid matrices:

1100
0011
0111    <-- three 1's in this row
1100
 ^
 `--- three 1's in this column
1111    <-- four 1's in this row
0011
1100
0000    <-- zero 1's in this row

This sequence is catalogued on OEIS as A001499. Here are a few non-bruteforce ways to compute it (an denotes the number of valid n×n binary matrices).

The recursive formula
a[n] = n for 0 <= n < 2
a[n] = (n + 1) * n * (a[n-1] + (n*a[n-2])/2)

The explicit formula

a(n) = 4^(-n) * n!^2 * Sum_{i=0..n} (-2)^i * (2*n - 2*i)! / (i!*(n-i)!^2)

You may find other ways to compute this sequence on the OEIS page linked above. To be clear, bruteforcing is a perfectly valid way of solving this challenge.

Rules
As usual in sequence challenges, your task is to write a program/function which does one of the following (consistently across different inputs).

Take a positive integer n as input and return an as output.
Because of the combinatorial interpretation of this sequence, it has to be 1-indexed (i.e. you are not allowed to take n and return an+1).
If you choose this option, you are not required to handle the input n=0.
Take a positive integer n as input and return the list [a1,a2,…,an] as output.
Optionally, you may instead choose to return [a0,a1,…,an−1] or [a0,a1,…,an], where a0=1 (consistent with the combinatorial interpretation).
The choice has to be consistent across different inputs.
Take no input and return the infinite list/generator [a1,a2,a3,…]. Optionally, you may instead choose to return [a0,a1,a2,…], where a0=1.
Your program/function must theoretically work for arbitrarily large inputs, assuming infinite time, memory and integer/floating point precision. In practice, it's ok if if fails because of integer overflow and/or floating point errors.

Scoring
This is code-golf, so the shortest code in bytes wins.

Testcases
Input                     Output
 1                             0
 2                             1
 3                             6
 4                            90
 5                          2040
 6                         67950
 7                       3110940
 8                     187530840
 9                   14398171200
10                 1371785398200
11               158815387962000
12             21959547410077200
13           3574340599104475200
14         676508133623135814000
15      147320988741542099484000

*/

package main

import "math/big"

func main() {
	tab := []string{
		"0", "1", "6", "90", "2040", "67950", "3110940", "187530840", "14398171200", "1371785398200", "158815387962000", "21959547410077200",
		"3574340599104475200", "676508133623135814000", "147320988741542099484000", "36574751938491748341360000", "10268902998771351157327104000",
	}
	for i := range tab {
		v := count(int64(i))
		assert(v.String() == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A001499
func count(n int64) *big.Int {
	r := recurse(n)
	return r.Num()
}

func recurse(n int64) *big.Rat {
	if n < 1 {
		return big.NewRat(0, 1)
	}
	if n < 2 {
		return big.NewRat(n, 1)
	}

	x := big.NewRat(n+1, 1)
	y := big.NewRat(n, 1)

	z := recurse(n - 1)
	w := recurse(n - 2)
	w.Mul(w, big.NewRat(n, 1))
	w.Quo(w, big.NewRat(2, 1))
	z.Add(z, w)

	r := x
	r.Mul(r, y)
	r.Mul(r, z)
	return r
}
