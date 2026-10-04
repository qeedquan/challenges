/*

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi]
represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers,
and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

Example 1:
https://assets.leetcode.com/uploads/2020/01/02/sample_1_1677.png
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

Example 2:
https://assets.leetcode.com/uploads/2020/01/02/sample_2_1677.png
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.

Constraints:

1 <= n <= 10^5
1 <= connections.length <= min(n * (n - 1) / 2, 10^5)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.

Hint 1
As long as there are at least (n - 1) connections, there is definitely a way to connect all computers.

Hint 2
Use DFS to determine the number of isolated computer clusters.

*/

package main

func main() {
	assert(operations(4, [][2]int{{0, 1}, {0, 2}, {1, 2}}) == 1)
	assert(operations(6, [][2]int{{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}}) == 2)
	assert(operations(6, [][2]int{{0, 1}, {0, 2}, {0, 3}, {1, 2}}) == -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func operations(size int, conns [][2]int) int {
	if len(conns) < size-1 {
		return -1
	}

	uf := NewUnionFind(size)
	for _, conn := range conns {
		uf.Union(conn[0], conn[1])
	}
	return uf.Size() - 1
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
