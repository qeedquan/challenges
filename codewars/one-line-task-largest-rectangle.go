/*

Task
Among all rectangles that have a perimeter of p, find the dimensions of the one whose area is the largest. Returns its height and width as [height,width].

Code Limit
Strictly less than:

26 characters in JavaScript
47 characters in PHP

Example
For p = 100, the output should be [25,25].

For p = 10, the output should be [2.5,2.5].

*/

package main

import "fmt"

func main() {
	fmt.Println(rectangle(100))
	fmt.Println(rectangle(10))
}

func rectangle(p float64) (float64, float64) {
	return p / 4, p / 4
}
