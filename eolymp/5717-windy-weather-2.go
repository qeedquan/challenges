/*

Piglet, lying on the lawn, watched the swaying grass.
He realized that the grass was swaying because the wind was blowing, and then he came up with an idea of how to measure the strength of the wind using the grass.
The wind strength, by Piglet's definition, is the height that appears most frequently among all the blades of grass.
If there are several such heights, then the lowest height among them should be taken as the strength of the wind —
there's nothing you can do, because Piglet liked to walk more in calm weather.

Input
The first line contains one number n — the number of grass blades observed by Piglet. The next line contains n numbers — the heights of the grass blades.

All input data are positive integers not exceeding 100, as Piglet does not like to count much and could not do it for a very simple reason:
he had never encountered numbers larger than 100 in his life.

Output
Print one number — the strength of the wind according to Piglet's definition.

Examples
Input #1
14
3 6 5 3 5 5 4 5 4 3 2 3 6 4

Answer #1
3

*/

package main

func main() {
	assert(solve([]int{3, 6, 5, 3, 5, 5, 4, 5, 4, 3, 2, 3, 6, 4}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(w []int) int {
	c := make(map[int]int)
	for _, i := range w {
		c[i] += 1
	}

	r := 0
	m := 0
	for k, v := range c {
		if v > m {
			m = v
			r = k
		}
	}
	return r
}
