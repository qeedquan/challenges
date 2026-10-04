/*

There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature.
For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C.
And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class.
If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not.
And you have to output the total number of friend circles among all the students.

Example 1:

Input:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle.
The 2nd student himself is in a friend circle. So return 2.

Example 2:

Input:
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends,
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:

N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.

*/

package main

func main() {
	assert(circles([][]int{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) == 2)
	assert(circles([][]int{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func circles(matrix [][]int) int {
	size := len(matrix)
	uf := NewUnionFind(size)
	for i := range matrix {
		for j := range matrix[i] {
			if matrix[i][j] != 0 && i != j {
				uf.Union(i, j)
			}
		}
	}
	return uf.Size()
}

type UnionFind struct {
	set  []int
	size int
}

func NewUnionFind(size int) *UnionFind {
	uf := &UnionFind{
		set:  make([]int, size),
		size: size,
	}
	for i := range uf.set {
		uf.set[i] = i
	}
	return uf
}

func (uf *UnionFind) Find(x int) int {
	if uf.set[x] != x {
		uf.set[x] = uf.Find(uf.set[x])
	}
	return uf.set[x]
}

func (uf *UnionFind) Union(x, y int) bool {
	xroot := uf.Find(x)
	yroot := uf.Find(y)
	if xroot == yroot {
		return false
	}

	root := min(xroot, yroot)
	uf.set[root] = max(xroot, yroot)
	uf.size -= 1
	return true
}

func (uf *UnionFind) Size() int {
	return uf.size
}
