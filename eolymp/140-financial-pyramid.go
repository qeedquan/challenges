/*

Tolya borrowed 2 candies from Seryozha on the first day and ate them with pleasure.
On the second day, he borrowed twice as many candies, then returned half of his total debt, and ate the rest of the candies again.
Each subsequent day, he borrowed twice as many candies as the previous day, gave back the integer part of half of his debt, and ate the remaining candies.

How many candies k will Tolya eat with pleasure on the n-th day? What will be his debt b at the end of the n-th day?

Input
The input contains one integer n (1≤n≤30).

Output
Print two integers — k and b.

Examples
Input #1
4

Answer #1
5 11

*/

package main

import "fmt"

func main() {
	for i := 1; i <= 30; i++ {
		fmt.Println(solve(i))
	}
}

func solve(n int) (int, int) {
	if n < 1 {
		return 0, 0
	}

	k, b, p := 2, 2, 2
	for i := 2; i <= n; i++ {
		p *= 2
		k = p - (b+p)/2
		b += k
	}
	return k, b
}
