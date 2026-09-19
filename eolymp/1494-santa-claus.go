/*

Santa Claus is getting ready for Christmas and plans to give gifts to n children.
His helpers, the Elves, have already packed two bags with gifts for his New Year's journey around the world.
To avoid confusion, the Elves have prepared a list of children whose gifts are already in each of the bags.
Santa wants to assist the Elves by preparing a third bag for the children who still need gifts.

Your task is to help Santa by creating a list of children whose gifts should be placed in the third bag.

Input
The first line of the input contains three integers:
n — the total number of children, m and k — the number of gifts in the first and second bags, respectively (1≤n,m,k≤100; m+k≤n).
The second line contains m integers, representing the numbers of the children whose gifts are in the first bag.
The third line contains k integers, representing the numbers of the children whose gifts are in the second bag.

It is guaranteed that the Elves have placed at most one gift for each child.
The numbers of all children are positive integers not exceeding n.
Every child must receive a gift for Christmas, or Santa will be disappointed.

Output
On the first line, output a single number a — the number of gifts that should be in the third bag.
On the second line, output a numbers in any order — the numbers of the children who should receive these gifts.

Examples
Input #1
7 2 1
7 3
1

Answer #1
4
2 4 5 6

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(7, 2, 1, []int{7, 3, 1}))
}

func solve(n, m, k int, a []int) (int, []int) {
	if n < 0 || m < 0 || k < 0 || m+k == n {
		return 0, []int{}
	}

	p := make([]int, n)
	for i := range m + k {
		p[a[i]-1] = 1
	}

	r := []int{}
	for i := range n {
		if p[i] == 0 {
			r = append(r, i+1)
		}
	}
	return n - m - k, r
}
