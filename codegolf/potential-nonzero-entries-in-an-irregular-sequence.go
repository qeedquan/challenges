/*

Background
A338268 is a sequence related to a challenge by Peter Kagey. It defines a two-parameter function T(n,k), which counts the number of integer sequences b1,⋯,bt where b1+⋯+bt=n
and sqrt(b1 + sqrt(b2 + ... sqrt(bt))) = k.
Since k cannot be larger than sqrt(n), the relevant "grid" has an odd shape:

  n\k| 1  2 3 4
  ---+---------
   1 | 1
   2 | 0
   3 | 0
   4 | 0  2
   5 | 0  0
   6 | 0  2
   7 | 0  0
   8 | 0  2
   9 | 0  0 2
  10 | 0  4 0
  11 | 0  0 2
  12 | 0  6 0
  13 | 0  0 2
  14 | 0  8 0
  15 | 0  0 4
  16 | 0 12 0 2

More precisely, n-th row is limited to 1 ≤ k ≤ floor(sqrt(n)).

Furthermore, this part of the grid has many known zero entries, as written in the OEIS page:

T(n,1)=0 for n>1.
T(n,k)=0 if n+k is odd, i.e. n and k have a different parity.
In this challenge, potential nonzero entries means the terms whose (n,k) pair satisfies none of the above, i.e. n+k is even, and either n>1 or (n,k)=(1,1).

Also, every sequence on the OEIS must be linearly laid out, so the numbers are "read by rows" as follows:

1, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 4, 0, 0, 0, 2, 0, 6, 0,
0, 0, 2, 0, 8, 0, 0, 0, 4, 0, 12, 0, 2, ...

In this sequence, the potential nonzero entries are at the following indices:

1-based: 1, 5, 9, 13, 16, 18, 22, 24, 28, 30, 34, 36, 38, ...
0-based: 0, 4, 8, 12, 15, 17, 21, 23, 27, 29, 33, 35, 37, ...

Challenge
Output the 1-based or 0-based version of the sequence above.
sequence I/O methods apply. You may use one of the following I/O methods:

Take no input and output the sequence indefinitely,
Take a (0- or 1-based) index i and output the i-th term, or
Take a non-negative integer i and output the first i terms.
Standard code-golf rules apply. The shortest code in bytes wins.

*/

package main

import (
	"reflect"
)

func main() {
	tab := []int{0, 4, 8, 12, 15, 17, 21, 23, 27, 29, 33, 35, 37, 40, 43, 45, 48, 51, 53, 56, 59}
	assert(reflect.DeepEqual(gen(len(tab)), tab))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@ovs

d=n=k=0
while 1:
  k+=1                      # increment k
  k**=k*k<=n                # k=k**1=k if k*k<=n, else k=k**0=1
  n+=k<2                    # increment n if k is equal to 1
  k+n&1<(k>1%n)!=print(d)   # print index d if k+n&1==0 (same parity) and k>1%n (k>0 for n==1 and k>1 for n>1)
  d+=1                      # increment the index

*/

func gen(l int) []int {
	r := []int{}
	for d, n, k := 0, 0, 0; len(r) < l; d++ {
		if k++; k*k > n {
			k = 1
		}
		if k < 2 {
			n++
		}
		if (k+n)&1 == 0 && ((k > 0 && n == 1) || (k > 1 && n > 1)) {
			r = append(r, d)
		}
	}
	return r
}
