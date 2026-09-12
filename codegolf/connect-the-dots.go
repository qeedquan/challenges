/*

Given a series of os representing dots, connect them vertically or horizontally

Examples
Input:

o   o

o

Output:

o---o
|
|
o
Input:

o   o    o

    o

Output:

o---o----o
    |
    o
Spec
If you want the input padded with spaces to form a rectangle, please specify this in your answer

There will only be o, spaces, and newlines in the input

There will always be a pair of dots to connect
No two os will be directly adjacent
Dots should be connected with | and -, for vertical and horizontal connections respectively
No dot connections will overlap

*/

package main

import "fmt"

func main() {
	dump(connect([][]byte{
		{'o', ' ', ' ', 'o'},
		{' ', ' ', ' ', ' '},
		{'o', ' ', ' ', ' '},
	}))

	dump(connect([][]byte{
		{'o', ' ', ' ', ' ', 'o', ' ', ' ', ' ', ' ', 'o'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', 'o', ' ', ' ', ' ', ' ', ' '},
	}))

	dump(connect([][]byte{
		{'o', ' ', 'o'},
		{' ', ' ', ' '},
		{'o', ' ', 'o'},
	}))
}

func dump(m [][]byte) {
	for y := range m {
		for x := range m[y] {
			fmt.Printf("%c", m[y][x])
		}
		fmt.Println()
	}
	fmt.Println()
}

func connect(m [][]byte) [][]byte {
	for y := range m {
		for x := range m[y] {
			if m[y][x] == 'o' {
				line(m, x, y, 1, 0)
				line(m, x, y, 0, 1)
			}
		}
	}
	return m
}

func line(m [][]byte, x, y, dx, dy int) {
	px, py := x+dx, y+dy
	for {
		x, y = x+dx, y+dy
		if x < 0 || y < 0 || y >= len(m) || x >= len(m[y]) {
			break
		}

		if m[y][x] == 'o' {
			for ; py < y; py++ {
				m[py][x] = '|'
			}
			for ; px < x; px++ {
				m[y][px] = '-'
			}
			break
		}
	}
}
