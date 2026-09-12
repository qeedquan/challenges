/*

There is a queue of n people to buy tickets to a musical premiere.
Each person wants to buy exactly one ticket.
Only one cashier is serving the whole queue, making the ticket sales very slow and causing people in the queue to become impatient.
The most observant people quickly noticed that, as a rule, the cashier sells several tickets to one person faster than selling those same tickets one by one.
Therefore, they suggested that several people standing in a row give their money to the first one, who will buy the tickets for all of them.

However, to prevent speculators, the cashier sells no more than three tickets per person, so only two or three consecutive people can agree in this way.

It is known that selling one ticket to the i-th person in the queue takes ai seconds,
selling two tickets takes bi seconds, and selling three tickets takes ci seconds.
Write a program that calculates the minimum total time required to serve all customers.

Note that tickets for a united group are always bought by the first person in the group.
Also, nobody buys extra tickets just to speed up the process (i.e., only the required tickets are bought).

Input
The first line contains the number of people in the queue n (1≤n≤5000). Then follow n triples of positive integers ai, bi, ci.
Each of these numbers does not exceed 3600. The people in the queue are numbered starting from the cashier.

Output
Print the minimum total time in seconds to serve all customers.

Examples

Input #1
5
5 10 15
2 10 15
5 5 5
20 20 1
20 1 1

Answer #1
12

Input #2
2
3 4 5
1 1 1

Answer #2
4

*/

package main

import "math"

func main() {
	assert(solve([][3]int{
		{5, 10, 15},
		{2, 10, 15},
		{5, 5, 5},
		{20, 20, 1},
		{20, 1, 1},
	}) == 12)

	assert(solve([][3]int{
		{3, 4, 5},
		{1, 1, 1},
	}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x [][3]int) int {
	n := len(x)
	p := make([][3]int, n+2)
	for i := range p {
		for j := range p[i] {
			p[i][j] = math.MaxInt
		}
	}
	p[0][0] = 0
	p[1][0] = 0

	for i := 2; i < n+2; i++ {
		a, b, c := x[i-2][0], x[i-2][1], x[i-2][2]
		p[i][0] = min(p[i-2][2], p[i-1][1], p[i-1][0]+a)
		p[i][1] = min(p[i-1][0]+b, p[i-1][2])
		p[i][2] = p[i-1][0] + c
	}
	return p[n+1][0]
}
