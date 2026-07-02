/*

Kinda a short one, but yeah.

Y=MX+C is the equation we all learnt to represent a line... But can you Code Golf it?

Write a program that takes in a list in the format M, C, V, and then returns the first V worth of whole x values. V will always be 1 or greater, M and C can have any (float) value (inc 0).

Examples (these are in python format for readability, use any I/O method you want):

[2,0,5] -> [2,4,6,8,10]
[1,1,15] -> [2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
[0.5,-1,1] -> [-0.5]
[0,0,5] -> [0,0,0,0,0]

Scored with Code-Golf (Least bytes wins), use any language :D

*/

package main

import "fmt"

func main() {
	fmt.Println(gen(2, 0, 5))
	fmt.Println(gen(1, 1, 15))
	fmt.Println(gen(0.5, -1, 1))
	fmt.Println(gen(0, 0, 5))
}

func gen(m, c float64, v int) []float64 {
	r := []float64{}
	for x := 1; x <= v; x++ {
		r = append(r, m*float64(x)+c)
	}
	return r
}
