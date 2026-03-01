/*

You have an equilateral triangle with side length n that is divided into n² smaller unit equilateral triangles. The large triangle has n rows (indexed from 1), where row i contains 2i - 1 unit triangles. Each unit triangle is identified by coordinates (i, j) where i is the row number and j ranges from 1 to 2i - 1.

Two unit triangles are considered neighbors if they share a common side. For example:

    Triangles (1,1) and (2,2) are neighbors
    Triangles (3,2) and (3,3) are neighbors
    Triangles (2,2) and (3,3) are NOT neighbors (they don't share a side)

Initially, all unit triangles are white. You need to select k triangles and color them red, then run this algorithm:

    Find a white triangle that has at least 2 red neighbors
        If no such triangle exists, stop
    Color that triangle red
    Return to step 1

The goal is to find the minimum value of k and determine which k triangles to initially color red such that when the algorithm completes, all unit triangles become red.

Return a 2D list containing the coordinates [i, j] of the triangles to initially color red. If multiple valid solutions exist with the minimum k, return any one of them.

*/

package main

import "fmt"

func main() {
	for i := range 10 {
		fmt.Println(colorred(i))
	}
}

func colorred(n int) [][2]int {
	if n < 1 {
		return [][2]int{}
	}

	r := [][2]int{{1, 1}}
	p := 0
	for y := n; y > 1; y-- {
		switch p {
		case 0:
			for x := 1; x < y*2; x += 2 {
				r = append(r, [2]int{y, x})
			}

		case 1:
			r = append(r, [2]int{y, 2})

		case 2:
			for x := 3; x < y*2; x += 2 {
				r = append(r, [2]int{y, x})
			}

		default:
			r = append(r, [2]int{y, 1})
		}
		p = (p + 1) & 3
	}
	return r
}
