/*

Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) -
that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

Example 1:

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1

Example 2:

Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
Output: 3

Constraints:

1 <= dominoes.length <= 4 * 10^4
dominoes[i].length == 2
1 <= dominoes[i][j] <= 9

Hint 1
For each domino j, find the number of dominoes you've already seen (dominoes i with i < j) that are equivalent.

Hint 2
You can keep track of what you've seen using a hashmap.

*/

package main

func main() {
	assert(equiv([][2]int{{1, 2}, {2, 1}, {3, 4}, {5, 6}}) == 1)
	assert(equiv([][2]int{{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func equiv(d [][2]int) int {
	c := make(map[[2]int]int)
	for _, v := range d {
		x := min(v[0], v[1])
		y := max(v[0], v[1])
		k := [2]int{x, y}
		c[k] += 1
	}

	r := 0
	for _, v := range c {
		r += v * (v - 1) / 2
	}
	return r
}
