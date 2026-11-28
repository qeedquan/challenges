/*

In this kata you will be given an array of the dimensions of rectangles (array with width and length) and circles (radius - just a number). Your task is to sort the objects by their area in ascending order and return the sorted array of areas. Round the values of the areas to a maximum of two decimal places.

For example,

var array = [[4.23, 6.43], 1.23, 3.444, [1.342, 3.212]];  // [rectangle, circle, circle, reactangle]
sortByArea(array); // should return [ 4.31, 4.75, 27.2, 37.26 ]

*/

package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	fmt.Println(sortbyarea([][]float64{
		{4.23, 6.43}, {1.23}, {3.444}, {1.342, 3.212},
	}))
}

func sortbyarea(p [][]float64) []float64 {
	r := []float64{}
	for _, x := range p {
		switch len(x) {
		case 2:
			r = append(r, x[0]*x[1])
		case 1:
			r = append(r, math.Pi*x[0]*x[0])
		}
	}
	sort.Float64s(r)
	return r
}
