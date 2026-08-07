/*

Today's challenge is to implement the solution to a well-known math puzzle involving prisoners and a chessboard. I won't state the puzzle or give the solution here, but you can find many writeups online:

Yet another prisoner puzzle blog post
http://olivernash.org/2009/10/31/yet-another-prisoner-puzzle/index.html

Impossible Escape? blog post
http://datagenetics.com/blog/december12014/index.html

The Almost Impossible Chessboard Puzzle video on Stand-Up Maths: 32 minutes
https://www.youtube.com/watch?v=as7Gkm7Y7h4

You need to know the solution for today's challenge, but you're welcome to look it up, either in those links or others. If you try to find the solution yourself, be warned it's pretty hard!

Challenge
First, assume that there exists a function flip that takes a series of 64 bits (0 or 1) and a number from 0 to 63. This function returns the same series of bits with the corresponding bit flipped. e.g.:

flip([0, 0, 0, 0, ...], 2) => [0, 0, 1, 0, ...]
flip([0, 1, 0, 1, ...], 1) => [0, 0, 0, 1, ...]
Now, you need to write two functions.

Function prisoner1 takes two inputs: a series S of 64 bits, and a number X from 0 to 63 (inclusive). It returns a number Y from 0 to 63.

Function prisoner2 takes one input: a series T of 64 bits. It returns a number from 0 to 63.

Now, you must make it so that if you flip S using the output of prisoner1 and pass the result to prisoner2, you get back the number X. Put another way, the following function must return True for every possible valid input S and X.

def solve(S, X):
    Y = prisoner1(S, X)
    T = flip(S, Y)
    return prisoner2(T) == X
Essentially, prisoner1 is encoding the value X into the sequence with a single flip, and prisoner2 is decoding it. In the puzzle statement, X is the location of the key, Y is the coin that gets flipped, S is the starting state of the board, and T is the state after the flip occurs.

Good luck!

*/

package main

import "math/rand"

func main() {
	for range 10000000 {
		S := make([]int, 64)
		for i := range S {
			S[i] = rand.Intn(2)
		}
		X := rand.Intn(64)
		assert(solve(S, X) == true)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(S []int, X int) bool {
	Y := prisoner1(S, X)
	T := flip(S, Y)
	return prisoner2(T) == X
}

func flip(S []int, X int) []int {
	S[X] ^= 1
	return S
}

func prisoner1(S []int, X int) int {
	for i, s := range S {
		X ^= i * s
	}
	return X
}

func prisoner2(S []int) int {
	return prisoner1(S, 0)
}
