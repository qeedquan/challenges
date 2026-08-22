/*

Task:

Your task is to create a program that, when given a number of strands and number of iterations of a braid, will tell where each strand goes. Rules are as follows:

The number of strands will always be odd, and between 3 and 6000 (inclusive)
When you start, the strands will be divided into 2 (almost) equal bunches, the left and the right. The left will have one more strand when you start.
For an input of 7:

/ / / / \ \ \
1 2 3 4 5 6 7
Every iteration, the outermost strand of the side with more strands will be put in the center facing the opposite direction. The center is defined as between opposite facing strands: ////middle\\\.
1 iteration of input 7 (strand 1 was moved to the center):

/ / / \ \ \ \
2 3 4 1 5 6 7
Example:

Input:

3 4
Computations:

1 2 3
 \
2 1 3
   /
2 3 1
 \
3 2 1
   /
3 1 2
Output:

3 1 2

Rules:

You do not need to display the slashes for strand direction, only the numbers.
You only need to display the numbers after the last iteration.
Your output will be space-deliminated ids of the strands
Input will be in the form: strands [space] iterations
The number of strands will always be odd, and 3<=x<=6000
This is code-golf, so the shortest code wins!

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	fmt.Println(braid(7, 1))
	fmt.Println(braid(3, 4))
}

func braid(strands, iterations int) []int {
	values := make([]int, strands)
	for index := range values {
		values[index] = index + 1
	}

	for iteration := range iterations {
		index := 0
		if iteration&1 != 0 {
			index = strands - 1
		}

		value := values[index]
		values = slices.Delete(values, index, index+1)
		values = slices.Insert(values, strands/2, value)
	}

	return values
}
