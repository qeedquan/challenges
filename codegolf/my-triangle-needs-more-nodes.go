/*

Consider the standard equilateral triangle, with nodes labeled using barycentric coordinates:

https://i.stack.imgur.com/URM7b.png

We can turn this 3 node triangle into a 6 node triangle by adding a new line of 3 vertices (one more than was present on a side of the original 3 node triangle), remove any internal edges (but not internal nodes) and re-normalize the coordinates:

https://i.stack.imgur.com/cbF99.png

Repeating the process to go from a 6 node triangle to a 10 node triangle, add a line of 4 vertices (again, one more than was present on a side of the original 6 node triangle), remove any internal edges (but not internal nodes) and re-normalize the coordinates:

https://i.stack.imgur.com/Ff1Zt.png

This process can be repeated indefinitely. The goal of this challenge is given an integer N representing how many times this process has been performed, output all the nodes for the associated triangle in barycentric coordinates.

Input
Your program/function should take as input a single non-negative integer N representing how many times this process has been applied. Note that for N=0, you should output the original triangle with 3 nodes.

The input may come from any source (function parameter, stdio, etc.).

Output
Your program/function should output all the nodes in normalized barycentric coordinates. The order of the nodes does not matter. A number can be specified as a fraction (fraction reduction not required) or a floating point number. You may also output "scaled" vectors to specify a node. For example, all 3 of the following outputs are equivalent and allowed:

0.5,0.5,0

1/2,2/4,0

[1,1,0]/2
If using floating point output, your output should be accurate to within 1%. The output may be to any sink desired (stdio, return value, return parameter, etc.). Note that even though the barycentric coordinates are uniquely determined by only 2 numbers per node, you should output all 3 numbers per node.

Examples
Example cases are formatted as:

N
x0,y0,z0
x1,y1,z1
x2,y2,z2
...
where the first line is the input N, and all following lines form a node x,y,z which should be in the output exactly once. All numbers are given as approximate floating point numbers.

0
1,0,0
0,1,0
0,0,1

1
1,0,0
0,1,0
0,0,1
0.5,0,0.5
0.5,0.5,0
0,0.5,0.5

2
1,0,0
0,1,0
0,0,1
0.667,0,0.333
0.667,0.333,0
0.333,0,0.667
0.333,0.333,0.333
0.333,0.667,0
0,0.333,0.667
0,0.667,0.333

3
1,0,0
0.75,0,0.25
0.75,0.25,0
0.5,0,0.5
0.5,0.25,0.25
0.5,0.5,0
0.25,0,0.75
0.25,0.25,0.5
0.25,0.5,0.25
0.25,0.75,0
0,0,1
0,0.25,0.75
0,0.5,0.5
0,0.75,0.25
0,1,0

Scoring
This is code golf; shortest code in bytes wins. Standard loopholes apply. You may use any built-ins desired.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(0, [][3]float64{
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1},
	})

	test(1, [][3]float64{
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1},
		{0.5, 0, 0.5},
		{0.5, 0.5, 0},
		{0, 0.5, 0.5},
	})

	test(2, [][3]float64{
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1},
		{0.667, 0, 0.333},
		{0.667, 0.333, 0},
		{0.333, 0, 0.667},
		{0.333, 0.333, 0.333},
		{0.333, 0.667, 0},
		{0, 0.333, 0.667},
		{0, 0.667, 0.333},
	})

	test(3, [][3]float64{
		{1, 0, 0},
		{0.75, 0, 0.25},
		{0.75, 0.25, 0},
		{0.5, 0, 0.5},
		{0.5, 0.25, 0.25},
		{0.5, 0.5, 0},
		{0.25, 0, 0.75},
		{0.25, 0.25, 0.5},
		{0.25, 0.5, 0.25},
		{0.25, 0.75, 0},
		{0, 0, 1},
		{0, 0.25, 0.75},
		{0, 0.5, 0.5},
		{0, 0.75, 0.25},
		{0, 1, 0},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r [][3]float64) {
	v := gen(n)
	m := make(map[int]bool)

	assert(len(v) == len(r))
loop:
	for i := range v {
		for j := range r {
			if !m[j] && allclose(v[i], r[j]) {
				m[j] = true
				continue loop
			}
		}
		panic(fmt.Sprint(v[i]))
	}
}

func allclose(x, y [3]float64) bool {
	const eps = 1e-3
	for i := range x {
		if math.Abs(x[i]-y[i]) > eps {
			return false
		}
	}
	return true
}

/*

@TheBikingViking

def f(n):                         Function with input iteration number n
r=range(n+2)                      Define r as the range [0, n+1]
for i in r for j in r for k in r  Length 3 Cartesian product of r
[i/-~n,j/-~n,k/-~n]               Divide each element of each list in the product
                                  by n+1
[x for x in ... if sum(x)==1]     Filter by summation to 1
print(...)                           Print to STDOUT

*/

func gen(n int) [][3]float64 {
	v := [][3]float64{}
	for i := 0; i < n+2; i++ {
		for j := 0; j < n+2; j++ {
			for k := 0; k < n+2; k++ {
				if i+j+k == n+1 {
					v = append(v, [3]float64{
						float64(i) / float64(n+1),
						float64(j) / float64(n+1),
						float64(k) / float64(n+1),
					})
				}
			}
		}
	}
	return v
}
