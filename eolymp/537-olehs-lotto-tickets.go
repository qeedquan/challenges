/*

Oleh loves playing the lottery. When he does, he buys many tickets.
Each ticket contains 6 unique numbers in the range from 1 to 49 inclusive.
Oleh wants to "cover all the bases." This means that each set of lottery tickets must include every number from 1 to 49 at least once on some ticket.
Write a program to help Oleh check whether his tickets "cover all the bases."

Input
The input file consists of several test cases.
Each case starts with an integer N (1≤N≤100), indicating the number of tickets Oleh has purchased.
The next N lines contain the tickets, one per line.
Each ticket contains exactly 6 integers, all in the range from 1 to 49 inclusive.
No ticket has duplicate numbers, but the numbers on a ticket may be in any order.
The input ends with a line containing only "0".

Output
Print a list of answers for the input sets, one per line.
Print the word "Yes" if every number from 1 to 49 inclusive appears on some lottery ticket in the set, and "No" otherwise.
Print these words exactly as shown. Do not print any blank lines between outputs.

Examples

Input #1
1
1 2 3 4 5 6
9
1 2 3 4 5 6
10 9 8 7 12 11
13 14 15 16 17 18
19 20 21 22 23 24
25 26 27 28 29 30
31 32 33 34 35 36
37 38 39 40 41 42
43 44 45 46 47 48
49 19 34 27 25 13
0

Answer #1
No
Yes

*/

package main

func main() {
	assert(solve([][6]int{
		{1, 2, 3, 4, 5, 6},
	}) == "No")

	assert(solve([][6]int{
		{1, 2, 3, 4, 5, 6},
		{10, 9, 8, 7, 12, 11},
		{13, 14, 15, 16, 17, 18},
		{19, 20, 21, 22, 23, 24},
		{25, 26, 27, 28, 29, 30},
		{31, 32, 33, 34, 35, 36},
		{37, 38, 39, 40, 41, 42},
		{43, 44, 45, 46, 47, 48},
		{49, 19, 34, 27, 25, 13},
	}) == "Yes")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(m [][6]int) string {
	c := make(map[int]bool)
	for i := range m {
		for _, t := range m[i] {
			c[t] = true
		}
	}
	if len(c) == 49 {
		return "Yes"
	}
	return "No"
}
