/*

Challenge:
Write a function or program that accepts a list of boolean values and returns all of the ranges of True's.

Test Cases:
f [F]                               = []
f [T]                               = [[0,0]]
f [T,T,F,T]                         = [[0,1],[3,3]]
f [F,T,T,F,F,T,T,T]                 = [[1,2],[5,7]]
f [F,T,T,F,F,F,T,T,T,T]             = [[1,2],[6,9]]
f [T,T,F,F,F,T,T,T,T,T,T,T,T,T,T,F] = [[0,1],[5,14]]
f [F,F,T,T,F,F,F,F,F,F,F,F,T,T,T,T,T,T,T,T,F,F,F,F,F,F,F,F,F,F,F,F,F,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,T,T] = [[2,3],[12,19],[33,54],[93,94]]

Rules:
You may choose how input is encoded, e.g. a list, array, string, etc.
The output must be encoded as a list-like of list-likes or a string showing such, so arrays, lists, tuples, matrices, vectors, etc.
The boolean values must be encoded as constants, but otherwise any simple conversion of T/F to desired constants is allowed
EDIT: eval or similar during runtime IS allowed.
Don't to forget to explain how input is passed to the program/function and give its input/output for the test cases
Conversion to desired input format not counted
Standard loopholes are disallowed
If your language has a function to do this, it's not allowed
I will not accept my own submission
EDIT: Output format is flexible. If not printing a list or similar, range values must be separated by one non-numeric character and separate ranges as well.

Scoring:
Score is in bytes, unless unfit to your language (such as codels in Piet)

Lowest score wins
There's a good bit of flexibility in input and output, but solutions where T/F are replaced with functions that do all the work are disallowed.

Debugging:
If you write yours in Haskell or can call it from Haskell, the following will check your function/program:

import Test.QuickCheck

tf = cycle [True,False]
gen l = foldl (++) [] $ map (\i -> [tf!!i | x<-[1..i]]) l
putIn (a,b) l = zipWith (||) l [(a <= p) && (p <= b) | p <- [0..length l]]
putAllIn rs len = foldr putIn [False|i<-[1..len]] rs
main = print $ quickCheck (check functionNameGoesHere)

*/

package main

import "fmt"

func main() {
	fmt.Println(truthrange([]bool{false}))
	fmt.Println(truthrange([]bool{true}))
	fmt.Println(truthrange([]bool{true, true, false, true}))
	fmt.Println(truthrange([]bool{false, true, true, false, false, true, true, true}))
	fmt.Println(truthrange([]bool{false, true, true, false, false, false, true, true, true, true}))
	fmt.Println(truthrange([]bool{true, true, false, false, false, true, true, true, true, true, true, true, true, true, true, false}))
	fmt.Println(truthrange([]bool{false, false, true, true, false, false, false, false, false, false, false, false, true, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, true}))
}

func truthrange(f []bool) [][2]int {
	r := [][2]int{}
	for i, j := 0, 0; i < len(f); i = j {
		j = i + 1
		for j < len(f) && f[i] == f[j] {
			j += 1
		}
		if f[i] {
			r = append(r, [2]int{i, j - 1})
		}
	}
	return r
}
