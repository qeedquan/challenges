/*

Make the 2D list by the sequential integers started by the head number.

See the example test cases for the expected output.

Note:

-10**20 < the head number <10**20
1 <=  the number of rows <= 1000
0 <=  the number of columms <= 1000

*/

package main

import "fmt"

func main() {
	fmt.Println(make2dlist(20, 3, 3))
}

func make2dlist(head, row, col int) [][]int {
	matrix := [][]int{}
	for range row {
		elements := []int{}
		for range col {
			elements, head = append(elements, head), head+1
		}
		matrix = append(matrix, elements)
	}
	return matrix
}
