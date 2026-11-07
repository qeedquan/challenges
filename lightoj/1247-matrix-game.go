/*

Given an m x n matrix, where m denotes thenumber of rows and n denotes the number of columns and in each cell a pile of stones is given.
For example, let there be a 2 x 3 matrix, and the piles are:

[2 3 8]
[5 2 7]

That means that in cell(1, 1) there is a pile with 2 stones, in cell(1, 2) there is a pile with 3 stones, and so on.

Now Alice and Bob are playing a strange game in this matrix. Alice starts first and they alternate turns. In each turn, a player selects a row and can draw any number of stones from any number of cells in that row. But he/she must draw at least one stone. For example, if Alice chooses the 2nd row in the given matrix, she can pick 2 stones from cell(2, 1), 0 stones from cell (2, 2), 7 stones from cell(2, 3). Or she can pick 5 stones from cell(2, 1),1 stone from cell(2, 2), 4 stones from cell(2, 3). There are many other ways but she must pick at least one stone from all piles. The player who can't take any stones loses.

Now if both play optimally who will win?

Input
Input starts with an integer T (≤ 100),denoting the number of test cases.

Each case starts with a line containing two integers: mand n (1 ≤ m, n ≤ 50). Each of the next m lines contains n space separated integers that form the matrix. All the integers will be between 0 and 109 (inclusive).

Output
For each case, print the case number and Alice if Alice wins, or Bob otherwise.

Sample
Input	Output
2
2 3
2 3 8
5 2 7
2 3
1 2 3
3 2 1

Case 1: Alice
Case 2: Bob

*/

package main

func main() {
	assert(solve([][]int{
		{2, 3, 8},
		{5, 2, 7},
	}) == "Alice")

	assert(solve([][]int{
		{1, 2, 3},
		{3, 2, 1},
	}) == "Bob")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

We have given a N * M Grid. A player can remove any number of stone from any row.
So a player can remove 1 to all stone from a row.
We can assume all the stone in a row as a single pile of stone.
Then we will get N pile of stone.
Now we can calculate xor-sum of that pile and determine who is winner.

Lets assume now we have 4 pile { 9 , 7 , 11 , 5 }.

Lets convert them in Binary.

1001 = 9
0111 = 7
1011 = 11
0101 = 5

we can see every column has even number of 1.
When a player remove some stones from pile he will remove a 1 from it and the xorsum of the piles will be > 0.
First player will remove 8 stones from the first pile then the binary state will look like

0001
0111
1011
0101

Then 2nd Player can remove 8 stones from 3rd pile and make the xor sum again 0.

As they play the game optimally so when a player gets xorsum>0 he will always win.

*/

func solve(m [][]int) string {
	r := 0
	for i := range m {
		s := 0
		for j := range m[i] {
			s += m[i][j]
		}
		r ^= s
	}
	if r > 0 {
		return "Alice"
	}
	return "Bob"
}
