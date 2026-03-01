/*

In genetic algorithms, a crossover allows 2 chromosomes to exchange part of their genes.

For more details, you can visit these wikipedia links : Genetic algorithm and Crossover.

A chromosome is represented by a list of genes.
Consider for instance 2 chromosomes :

   xs (with genes [x,x,x,x,x,x])  and  ys (with genes [y,y,y,y,y,y])
A single-point crossover at index 2 would give :

new chromosome1 = []int { x,x,y,y,y,y } and new chromosome2 = []int { y,y,x,x,x,x }
A two-point crossover at indices 1 and 3 would give :

new chromosome1 = []int { x,y,y,x,x,x } and new chromosome2 = []int { y,x,x,y,y,y }
We want to generalize this to the notion of n-point crossover, and create a generic function with the following signature :

func Crossover(ns []int, xs []int,ys []int) ([]int, []int)
where ns would be a list of cross-point indices.

We could compute a triple-point crossover of 2 chromosomes xs and ys the following way :

Crossover(int[] { 2, 5, 21 }, xs, ys)
The transformed first chromosome must appear at the first position of the tuple. the second one at the second position. Therefore :

Crossover([]int { 1 }, []int {1,2,3}, []int {11,12,13}) should be ([]int { 1,12,13 }, int[] { 11,2,3 })
If a cross-point index is repeated, it should be considered only once. Indices can also be provided unordered, so your function could be called with the following indices :

Crossover(int[] { 7,5,3,5 }, xs, ys)
In this case, you would have to consider only indices [7,5,3] and deal with the fact they are unordered.

Chromosome indices are 0-based and you can also assume that :

(length xs) == (length ys)
crossover indices will never exceed the length of xs or ys.

*/

package main

import (
	"reflect"
	"sort"
)

func main() {
	test(
		[]int{1}, []int{'a', 'b', 'c'}, []int{'x', 'y', 'z'},
		[]int{'a', 'y', 'z'}, []int{'x', 'b', 'c'},
	)

	test(
		[]int{}, []int{1, 1, 1, 1, 1}, []int{2, 2, 2, 2, 2},
		[]int{1, 1, 1, 1, 1},
		[]int{2, 2, 2, 2, 2},
	)

	test(
		[]int{1}, []int{1, 1, 1, 1, 1}, []int{2, 2, 2, 2, 2},
		[]int{1, 2, 2, 2, 2},
		[]int{2, 1, 1, 1, 1},
	)

	test(
		[]int{1, 1}, []int{1, 1, 1, 1, 1}, []int{2, 2, 2, 2, 2},
		[]int{1, 2, 2, 2, 2},
		[]int{2, 1, 1, 1, 1},
	)

	test(
		[]int{1, 3}, []int{1, 1, 1, 1, 1}, []int{2, 2, 2, 2, 2},
		[]int{1, 2, 2, 1, 1},
		[]int{2, 1, 1, 2, 2},
	)

	test(
		[]int{1, 3, 5}, []int{1, 1, 1, 1, 1, 1, 1}, []int{2, 2, 2, 2, 2, 2, 2},
		[]int{1, 2, 2, 1, 1, 2, 2},
		[]int{2, 1, 1, 2, 2, 1, 1},
	)

	test(
		[]int{3, 5, 1, 1, 3}, []int{1, 1, 1, 1, 1, 1, 1}, []int{2, 2, 2, 2, 2, 2, 2},
		[]int{1, 2, 2, 1, 1, 2, 2},
		[]int{2, 1, 1, 2, 2, 1, 1},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(p, x, y, r1, r2 []int) {
	c1, c2 := crossover(p, x, y)
	assert(reflect.DeepEqual(c1, r1))
	assert(reflect.DeepEqual(c2, r2))
}

func crossover(p, x, y []int) (c1, c2 []int) {
	p = append(uniqsort(p), len(x))
	prev := 0
	flip := false
	for _, p := range p {
		if !flip {
			c1 = append(c1, x[prev:p]...)
			c2 = append(c2, y[prev:p]...)
		} else {
			c1 = append(c1, y[prev:p]...)
			c2 = append(c2, x[prev:p]...)
		}

		flip = !flip
		prev = p
	}
	return
}

func uniqsort(p []int) []int {
	r := []int{}
	m := make(map[int]bool)
	for _, v := range p {
		if !m[v] {
			r = append(r, v)
			m[v] = true
		}
	}
	sort.Ints(r)
	return r
}
