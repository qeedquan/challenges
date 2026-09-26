/*

In this problem, we assume that the Earth is shaped like a cube, with each face being a square of size m×m, divided into cells measuring 1×1.

Initially, n ants are positioned on the top face of this cube. Each ant faces one of four directions: north, south, west, or east.

At a certain moment, the ants start moving in straight lines, each continuing in its initial direction. When an ant reaches the edge of the cube, it crosses over to the next face and continues moving perpendicularly to the edge it crossed.

This movement goes on indefinitely. Your task is to determine how many cells on the cube are never visited by any ant during this process.

Input
The first line of the input contains two natural numbers n and m, representing the number of ants on Earth and the length of each side of the cube (1≤n≤100000; 1≤m≤15000).

Each of the following n lines provides the initial position of an ant. Each line contains two natural numbers x and y, indicating the coordinates of the ant on the top face, followed by a character representing the ant's direction: 'N', 'S', 'W', or 'E'. The numbers and the character are separated by exactly one space.

The coordinate axes and the directions of the cube's sides are shown in the figure. All coordinates range from 1 to m inclusive.

Multiple ants can occupy the same cell at the initial moment or any other time, without affecting their movement paths.

Output
Output a single number: the count of cells that are never visited by the ants.

https://static.e-olymp.com/content/a9/a9cda1ad995458d253c1a989915664db22c4d690.jpg

Examples

Input #1
2 4
2 2 N
4 3 W

Answer #1
66

*/

package main

func main() {
	assert(solve(2, 4, [][3]int{
		{2, 2, 'N'},
		{4, 3, 'W'},
	}) == 66)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, m int, a [][3]int) int {
	x := make(map[int]bool)
	y := make(map[int]bool)
	for _, p := range a {
		switch p[2] {
		case 'N', 'S':
			x[p[0]] = true
		case 'W', 'E':
			y[p[1]] = true
		}
	}
	return m*m*6 - len(x)*m*4 - len(y)*m*4 + len(x)*len(y)*2
}
