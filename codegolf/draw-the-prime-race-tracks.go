/*

Odd prime numbers are either in the form of 4k+1 or 4k+3 where k is a non-negative integer. If we divide the set of odd prime numbers into two such groups like this:

4k+3  |   3     7  11          19  23      31          43  47      59      67  71
      |
4k+1  |      5         13  17          29      37  41          53      61          73
we can see that the two groups are kind of racing with each other. Sometimes the so-called 'upper' group wins and sometimes the 'lower' one is on track. In fact, Chebyshev discovered that in this race, the upper group wins slightly more often.

The problem
Let's assume that we are interested in knowing the shape of this race track up to a certain number. Something like this:

prime race track

The upper and lower horizontal lines indicate that the next prime stays in the same group, while the slanted lines indicate a 'jump' from one group to the other.

Now assume that the underline character _ represents a lower horizontal line and the overline character ‾ (U+203E) represents an upper one. The slanted lines are represented by slash / or backslash \ characters.

Challenge
Write a program or function that gets a number N as input, and draws this prime race track up to N, in a kind of ASCII-art-form described as above (Well, it's not an actual ASCII-art since it would contain a non-ASCII character).

Rules
N is an integer and not necessarily a prime number. Draw the race path for the primes up to, (and maybe including) N.
For a valid N as input, the output shall only be composed of these four characters ‾_/\. No other character, space or separator is allowed (except maybe at the end of output).
The output can either be in a text file or stdout or wherever supports displaying those characters. But an actual plot (like the blue figure above) is not desired.
This is code-golf, so the shortest code in bytes wins.
Examples
Here is a list of possible inputs and their acceptable outputs.

N < 5        no output or maybe an error message whatsoever
N = 5        \
N = 20       \/‾\_/
N = 100      \/‾\_/‾\/\_/‾\/\/‾\/‾\_

Trivia
The resulting plots of this challenge may actually resemble the derivative of the plots shown in there.
https://www.makethebrainhappy.com/2018/10/chebyshev-bias.html

*/

package main

import (
	"bytes"
	"fmt"
	"math/big"
)

func main() {
	assert(primetrack(4) == ``)
	assert(primetrack(5) == `\`)
	assert(primetrack(20) == `\/‾\_/`)
	assert(primetrack(100) == `\/‾\_/‾\/\_/‾\/\/‾\/‾\_`)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func primetrack(n int) string {
	w, l, t, k := new(bytes.Buffer), -1, 0, 0
	for {
		x, d := 4*k+1, 0
		if t == 1 {
			x, k, d = x+2, k+1, 1
		}
		if x > n {
			break
		}
		t ^= 1

		if !isprime(x) {
			continue
		}

		if l < 0 {
			l = d
			continue
		}

		switch {
		case l < d:
			fmt.Fprintf(w, "/")
		case l == d:
			if l == 1 {
				fmt.Fprintf(w, "‾")
			} else {
				fmt.Fprintf(w, "_")
			}
		case l > d:
			fmt.Fprintf(w, "\\")
		}
		l = d
	}
	return w.String()
}

func isprime(n int) bool {
	x := big.NewInt(int64(n))
	return x.ProbablyPrime(2)
}
