/*

The Collatz Conjecture
The famous Collatz Conjecture (which we will assume to be true for the challenge) defines a sequence for each natural number, and hypothesizes that every such sequence will ultimately reach 1. For a given starting number N, the following rules are repeatedly applied until the result is 1:

While N > 1:

If N is even, divide by 2
If N is odd, multiply by 3 and add 1
Collatz Encoding
For this challenge, I have defined the Collatz encoding of a number, such that the algorithm specified in the conjecture may be used to map it to another unique number.
To do this, you start with a 1 and at each step of the algorithm, if you divide by 2 then append a 0, otherwise append a 1. This string of digits is the binary representation of the encoding.

As an example we will compute the Collatz Encoding of the number 3, with the appended digits marked. The sequence for 3 goes

(1) 3 ->1 10 ->0 5 ->1 16 ->0 8 ->0 4 ->0 2 ->0 1.

Therefore, our encoding is 208 (11010000 in binary).

The Challenge
Your challenge is to write a function or program which takes an integer (n>0) as input, and returns its Collatz encoding. This is a code golf challenge, so your goal is to minimize the number of bytes in your answer.

For the edge case n=1, your solution should return 1, because no iterations are computed and every encoding starts with a 1.

Floating point inaccuracies in larger results are acceptable if your language cannot handle such numbers accurately (encodings on the order of 10^40 as low as 27)

Test Cases
I have written a reference implementation (Try It Online!) which generates the encodings of the first 15 natural numbers:

  1 | 1
  2 | 2
  3 | 208
  4 | 4
  5 | 48
  6 | 336
  7 | 108816
  8 | 8
  9 | 829712
 10 | 80
 11 | 26896
 12 | 592
 13 | 784
 14 | 174352
 15 | 218128

*/

package main

import (
	"bytes"
	"math/big"
)

func main() {
	tab := []string{
		"1", "2", "208", "4", "48", "336", "108816", "8",
		"829712", "80", "26896", "592", "784", "174352", "218128",
	}

	for i := range tab {
		assert(encode(i+1) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func encode(n int) string {
	w := new(bytes.Buffer)
	w.WriteByte('1')
	for n > 1 {
		if n%2 == 0 {
			n /= 2
			w.WriteByte('0')
		} else {
			n = 3*n + 1
			w.WriteByte('1')
		}
	}

	x := new(big.Int)
	x.SetString(w.String(), 2)
	return x.String()
}
