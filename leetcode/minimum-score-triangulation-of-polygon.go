/*

You have a convex n-sided polygon where each vertex has an integer value.
You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.

Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon.
Note that no other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles.

You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices.
The total score of the triangulation is the sum of these weights over all n - 2 triangles.

Return the minimum possible score that you can achieve with some triangulation of the polygon.

Example 1:
https://assets.leetcode.com/uploads/2025/10/23/ex0-2.png
Input: values = [1,2,3]

Output: 6

Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

Example 2:
https://assets.leetcode.com/uploads/2025/10/23/ex1-2.png
Input: values = [3,7,4,5]

Output: 144

Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.

Example 3:
https://assets.leetcode.com/uploads/2025/10/23/ex2.png

Input: values = [1,3,1,4,1,5]

Output: 13

Explanation: The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.

Constraints:

n == values.length
3 <= n <= 50
1 <= values[i] <= 100

Hint 1
Without loss of generality, there is a triangle that uses adjacent vertices A[0] and A[N-1] (where N = A.length).
Depending on your choice K of it, this breaks down the triangulation into two subproblems A[1:K] and A[K+1:N-1].

*/

package main

import "math"

func main() {
	assert(triangulation([]int{1, 2, 3}) == 6)
	assert(triangulation([]int{3, 7, 4, 5}) == 144)
	assert(triangulation([]int{1, 3, 1, 4, 1, 5}) == 13)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func triangulation(a []int) int {
	n := len(a)
	if n == 0 {
		return 0
	}

	r := make([][]int, n)
	for i := range r {
		r[i] = make([]int, n)
	}

	for p := 3; p <= n; p++ {
		for i := 0; i+p-1 < n; i++ {
			j := i + p - 1
			r[i][j] = math.MaxInt
			for k := i + 1; k < j; k++ {
				r[i][j] = min(r[i][j], r[i][k]+r[k][j]+a[i]*a[j]*a[k])
			}
		}
	}
	return r[0][n-1]
}
