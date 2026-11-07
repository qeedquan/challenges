/*

This challenge is based on the idea of Plouffle's Inverter.

Write a program in any language that does the following:

Takes as input a non-negative rational number X written in decimal, for example 34.147425.

Returns a mathematical expression using only non-negative integers, whitespace, parentheses, and the following binary operators:

Addition +
Subtraction -
Multiplication *
Division /
Exponentiation ^
The expression should evaluate to X, or at least agree with all the digits of X. To continue the example, a correct output could be 13 + 20^(5/4) / 2, since 13 + 20^(5/4) / 2 = 34.1474252688...

Output may optionally be written in Polish notation (prefix) or reverse Polish notation (postfix), i.e. + 13 / ^ 20 / 5 4 2 is fine.

The program is subject to the following retrictions:

Standard loopholes are forbidden! In particular, the program cannot read any external lookup table.

The source code of the program must be shorten than 1024 characters.

The program with the lowest average compression ratio will win.

To determine your average compression ratio, you can to use the following Python script, or write your own equivalent program. Here is the list of 1000 random numbers.

import random

def f(x):
    # edit this function so that it will return
    # the output of your program given x as input
    return "1 + 1"

random.seed(666)

S = 1000 # number of samples

t = 0.0

for n in xrange(0, S):
    # pick a random decimal number
    x = random.uniform(0, 1000)

    # compute the compression ratio
    # length of output / length of input
    r = len(f(x).translate(None, " +-* /^()")) / float(len(str(x).translate(None, ".")))
    t += r

print "Your average compression ratio is:", t / S
Good luck!

NOTES:

Whitespaces in the output are not mandatory. Strings like 1+1, 1 +2, or 1 + 2, are all okay. Indeed, the script to compute the score does not count whitespaces and parenthesis in the length of the output. However, note that the use of whitespaces is necessary if you choose Polish or reverse Polish notation.

Regarding the usual infix notation, the precedence rules are the following: first all exponentiation (^), then all divisions (/), then all multiplications (*), then all additions (+) and all subtractions (-). But I do not know how much this could matter, since you can use parentheses.

A way to edit the function f in the script above can be the following, however I think that it depends on your operating system; on GNU/Linux it works. Name your program "inverter" (or "inverter.exe") and place it in the same directory as the Python script. Your program should get X as the first argument of command line and return the expression in STDOUT. Then edit f as follows:

import os
def f(x):
    return os.popen("./inverter " + str(x)).read()
EDIT: As a consequence of the comment of Thomas Kwa, now the operators do not contribute to the length of the expression. The challenge should be more "challenging".

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	fmt.Println(solve("34.147425"))
	fmt.Println(solve("3.1415926"))
}

func solve(s string) *big.Rat {
	r := new(big.Rat)
	x := new(big.Float)
	x.SetPrec(uint(len(s))*100 + 128)
	x.SetString(s)
	x.Rat(r)
	return r
}
