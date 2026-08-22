/*

Description

Some of Farmer John's N cows (1 ≤ N ≤ 80,000) are having a bad hair day! Since each cow is self-conscious about her messy hairstyle, FJ wants to count the number of other cows that can see the top of other cows' heads.

Each cow i has a specified height hi (1 ≤ hi ≤ 1,000,000,000) and is standing in a line of cows all facing east (to the right in our diagrams). Therefore, cow i can see the tops of the heads of cows in front of her (namely cows i+1, i+2, and so on), for as long as these cows are strictly shorter than cow i.

Consider this example:

        =
=       =
=   -   =         Cows facing right -->
=   =   =
= - = = =
= = = = = =
1 2 3 4 5 6
Cow#1 can see the hairstyle of cows #2, 3, 4
Cow#2 can see no cow's hairstyle
Cow#3 can see the hairstyle of cow #4
Cow#4 can see no cow's hairstyle
Cow#5 can see the hairstyle of cow 6
Cow#6 can see no cows at all!

Let ci denote the number of cows whose hairstyle is visible from cow i; please compute the sum of c1 through cN.For this example, the desired is answer 3 + 0 + 1 + 0 + 1 + 0 = 5.

Input

Line 1: The number of cows, N.
Lines 2..N+1: Line i+1 contains a single integer that is the height of cow i.

Output

Line 1: A single integer that is the sum of c1 through cN.

Sample Input

6
10
3
7
4
12
2

Sample Output

5

Source

USACO 2006 November Silver

*/

package main

func main() {
	assert(cowabunga([]int{10, 3, 7, 4, 12, 2}) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cowabunga(c []int) int {
	var (
		p [][2]int
		r int
	)
	for i := len(c) - 1; i >= 0; i-- {
		v := c[i]
		x := 1
		for {
			n := len(p)
			if n == 0 || v <= p[n-1][0] {
				break
			}
			x += p[n-1][1]
			r += p[n-1][1]
			p = p[:n-1]
		}
		p = append(p, [2]int{v, x})
	}
	return r
}
