/*

I once saw on the xkcd fora a format for expressing numbers in an odd way. In this "factor tree" format:

The empty string is 1.
Concatenation represents multiplication.
A number n enclosed in parentheses (or any paired characters) represents the nth prime number, with 2 being the first prime number.
Note that this is done recursively: the nth prime is the factor tree for n in parentheses.
The factors of a number should be ordered from smallest to largest.
For example, here are the factor trees for 2 through 10:

()
(())
()()
((()))
()(())
(()())
()()()
(())(())
()((()))
Your task is to take in a positive integer, and output the factor tree for it.

Test Cases
In addition to the 9 above…

100 => ()()((()))((()))
101 => (()(()(())))
1001 => (()())(((())))(()(()))
5381 => (((((((())))))))
32767 => (()())((((()))))(()()(())(()))
32768 => ()()()()()()()()()()()()()()()

Rules
Characters other than ()[]{}<> are allowed in the output, but ignored.
You should be able to handle any input from 2 to 215 inclusive.
The winner is the shortest answer in bytes.

*/

package main

import (
	"fmt"
	"math/big"
	"strings"
)

func main() {
	assert(factortree(1) == "")
	assert(factortree(2) == "()")
	assert(factortree(3) == "(())")
	assert(factortree(4) == "()()")
	assert(factortree(5) == "((()))")
	assert(factortree(6) == "()(())")
	assert(factortree(7) == "(()())")
	assert(factortree(8) == "()()()")
	assert(factortree(9) == "(())(())")
	assert(factortree(10) == "()((()))")
	assert(factortree(100) == "()()((()))((()))")
	assert(factortree(101) == "(()(()(())))")
	assert(factortree(1001) == "(()())(((())))(()(()))")
	assert(factortree(5381) == "(((((((())))))))")
	assert(factortree(32767) == "(()())((((()))))(()()(())(()))")
	assert(factortree(32768) == "()()()()()()()()()()()()()()()")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// Ported from @ovs solution
func factortree(n int) string {
	return recurse(n, 2, 1)
}

func recurse(n, d, p int) string {
	switch {
	case n <= 1:
		return ""
	case n <= 2:
		return strings.Repeat("()", n-1)
	case n%d != 0:
		return recurse(n, d+1, p+isprime(d+1))
	}
	return fmt.Sprintf("(%s)", factortree(p)) + recurse(n/d, d, p)
}

func isprime(n int) int {
	x := big.NewInt(int64(n))
	if x.ProbablyPrime(2) {
		return 1
	}
	return 0
}
