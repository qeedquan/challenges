/*

Description

Farmer John has been informed of the location of a fugitive cow and wants to catch her immediately. He starts at a point N (0 ≤ N ≤ 100,000) on a number line and the cow is at a point K (0 ≤ K ≤ 100,000) on the same number line. Farmer John has two modes of transportation: walking and teleporting.

* Walking: FJ can move from any point X to the points X - 1 or X + 1 in a single minute
* Teleporting: FJ can move from any point X to the point 2 × X in a single minute.

If the cow, unaware of its pursuit, does not move at all, how long does it take for Farmer John to retrieve it?

Input

Line 1: Two space-separated integers: N and K

Output

Line 1: The least amount of time, in minutes, it takes for Farmer John to catch the fugitive cow.

Sample Input

5 17

Sample Output

4
Hint

The fastest way for Farmer John to reach the fugitive cow is to move along the following path: 5-10-9-18-17, which takes 4 minutes.

Source

USACO 2007 Open Silver

*/

package main

func main() {
	assert(catch(5, 17) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func catch(start, target int) int {
	visited := make(map[int]bool)
	queue := []int{start}
	level := 0

loop:
	for {
		size := len(queue)
		if size == 0 {
			break
		}

		for i := 0; i < size; i++ {
			node := queue[0]
			queue = queue[1:]
			if node == target {
				break loop
			}

			if !visited[node-1] {
				queue = append(queue, node-1)
				visited[node-1] = true
			}

			if !visited[node+1] {
				queue = append(queue, node+1)
				visited[node+1] = true
			}

			if !visited[node*2] {
				queue = append(queue, node*2)
				visited[node*2] = true
			}
		}

		level++
	}

	return level
}
