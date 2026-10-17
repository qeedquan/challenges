/*

Given an integer greater than or equal to 2, output ASCII-art resembling an isometric-perspective cube ring with that side length.

Expected outputs given below for 2, 3. You can imagine the rest. You may alternatively consider the first example to be output for 1, second to be output for 2, etc.

This is code-golf, shortest code wins. Your output may include any additional whitespace that does not impact the presentation of the image.

2

   / \ / \
  |\ /|\ /|
  | | | | |
 / \|/ \|/ \
|\ /|   |\ /|
| | |   | | |
 \|/ \ / \|/
  |\ /|\ /|
  | | | | |
   \|/ \|/

3

     / \ / \ / \
    |\ /|\ /|\ /|
    | | | | | | |
   / \|/ \|/ \|/ \
  |\ /|       |\ /|
  | | |       | | |
 / \|/         \|/ \
|\ /|           |\ /|
| | |           | | |
 \|/ \         / \|/
  |\ /|       |\ /|
  | | |       | | |
   \|/ \ / \ / \|/
    |\ /|\ /|\ /|
    | | | | | | |
     \|/ \|/ \|/

*/

package main

import "fmt"

func main() {
	draw(2)
	draw(3)
}

func draw(n int) {
	fmt.Printf("n=%d\n", n)
	if n < 1 {
		return
	}

	w := 8*n - 3
	h := n*6 - 2
	p := make([][]byte, h)
	for y := range p {
		p[y] = make([]byte, w)
		for x := range p[y] {
			p[y][x] = ' '
		}
	}

	for i := range n {
		r := n*2 - 2 + i*4
		t := (n - i) * 3
		u := w - 5 - 2*i
		cube(p, r, 0)
		cube(p, r, 6*n-6)
		cube(p, 2*i, t-3)
		cube(p, 2*(n-i)-2, h-3*i-4)
		cube(p, u, t-3)
		cube(p, u, h-t-1)
	}

	for y := range p {
		fmt.Printf("%s\n", p[y])
	}
	fmt.Println()
}

func cube(p [][]byte, x, y int) {
	art := []string{
		` / \`,
		`|\ /|`,
		`| | |`,
		` \|/`,
	}
	for i := range art {
		for j := range art[i] {
			p[y+i][x+j] = art[i][j]
		}
	}
}
