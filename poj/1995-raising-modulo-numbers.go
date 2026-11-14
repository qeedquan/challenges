/*

Description

People are different. Some secretly read magazines full of interesting girls' pictures, others create an A-bomb in their cellar, others like using Windows, and some like difficult mathematical games. Latest marketing research shows, that this market segment was so far underestimated and that there is lack of such games. This kind of game was thus included into the KOKODáKH. The rules follow:

Each player chooses two numbers Ai and Bi and writes them on a slip of paper. Others cannot see the numbers. In a given moment all players show their numbers to the others. The goal is to determine the sum of all expressions AiBi from all players including oneself and determine the remainder after division by a given number M. The winner is the one who first determines the correct result. According to the players' experience it is possible to increase the difficulty by choosing higher numbers.

You should write a program that calculates the result and is able to find out who won the game.

Input

The input consists of Z assignments. The number of them is given by the single positive integer Z appearing on the first line of input. Then the assignements follow. Each assignement begins with line containing an integer M (1 <= M <= 45000). The sum will be divided by this number. Next line contains number of players H (1 <= H <= 45000). Next exactly H lines follow. On each line, there are exactly two numbers Ai and Bi separated by space. Both numbers cannot be equal zero at the same time.

Output

For each assingnement there is the only one line of output. On this line, there is a number, the result of expression
(A1^B1 + A2^B2 + ... + AH^BH) mod M.

Sample Input

3
16
4
2 3
3 4
4 5
5 6
36123
1
2374859 3029382
17
1
3 18132

Sample Output

2
13195
13

Source

CTU Open 1999

*/

package main

import "math/big"

func main() {
	assert(raise([]int64{2, 3, 4, 5}, []int64{3, 4, 5, 6}, 16) == 2)
	assert(raise([]int64{2374859}, []int64{3029382}, 36123) == 13195)
	assert(raise([]int64{3}, []int64{18132}, 17) == 13)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func raise(a, b []int64, m int64) int64 {
	d := big.NewInt(m)
	r := new(big.Int)
	for i := range a {
		x := big.NewInt(a[i])
		p := big.NewInt(b[i])
		x.Exp(x, p, d)
		r.Add(r, x)
		r.Mod(r, d)
	}
	return r.Int64()
}
