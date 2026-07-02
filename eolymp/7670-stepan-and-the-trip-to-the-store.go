/*

Stepan is preparing for a visit from his friend Vasyl and needs to make a trip to two nearby stores before the meeting.

https://static.e-olymp.com/content/56/5683c1a51ecc7bb98c898443df309a2210ffe932.png

There are three paths available:

A path from Stepan's house to the first store, measuring d1 meters.

A path from his house to the second store, measuring d2 meters.

A direct path connecting the two stores, measuring d3 meters.

Your task is to help Stepan determine the shortest distance he needs to travel to visit both stores and return home.

Stepan will start his journey from his house. He must visit both stores, using only the three available paths, and return to his house. He doesn't mind revisiting the same store or retracing his steps if it helps minimize the total distance traveled.

Input
The input consists of a single line with 3 integers d1, d2, and d3
(1≤d1,d2,d3≤10^8), representing the lengths of the paths:
d1: the distance from Stepan's house to the first store.
d2 the distance from his house to the second store.
d3: the distance between the two stores.

Output
Print the minimum distance, in meters, that Stepan needs to travel to visit both stores and return home.

Examples

Input #1
10 20 30

Answer #1
60

*/

package main

func main() {
	assert(solve(10, 20, 30) == 60)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b, c int) int {
	r := a + b + c
	r = min(r, 2*(a+c))
	r = min(r, 2*(b+c))
	r = min(r, 2*(a+b))
	return r
}
