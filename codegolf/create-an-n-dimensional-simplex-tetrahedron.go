/*

The Simplest N-Dimensional shape one can create for any dimension is a Simplex, and this is a set of N+1 points that are all equal distance away from eachother.

For 2 dimensions, this is an equilateral triangle, for 3 dimensions, this is an regular tetrahedron, at 4 dimensions is the 5-Cell and so on.

The Challenge
Given an Integer dimension N as input, output an Array/List/Stack/Whatever of N Dimensional points that represent a Simplex of this dimension. That is, N+1 vertexes that are equal and non-zero distance from eachother.

Reference implementation in Lua
function simplex(n)
	if n == 0 then
		return {{0}}
	else
		local o = simplex(n-1)
		o[n+1] = {}
		for i=1, n do
			o[i][n] = 0
		end
		for c=1, n-1 do
			for i=1, n do
				o[n+1][c] = (o[n+1][c] or 0) + (o[i][c]) / n
			end
		end
		local t = 0
		for c=1, n-1 do
			t = t + o[n+1][c]^2
		end
		o[n+1][n] = math.sqrt(1 - t)

		return o
	end
end


function printT(...)
	local a = {...}
	io.write"{"
	for i, t in ipairs(a) do
		if(type(t)=='table')then
			printT(table.unpack(t))
		else
			io.write(tostring(t))
		end
		if i < #a then
			io.write', '
		end
	end
	io.write"}"
end

Examples
1 -> [[0], [1]]
2 -> [[0, 0], [1, 0], [0.5, 0.866...]]
4 -> [[0, 0, 0, 0], [1, 0, 0, 0], [0.5, 0.866..., 0, 0], [0.5, 0.288..., 0.816..., 0], [0.5, 0.288..., 0.204..., 0.790...]]

Notes
Input is a number in any standard format, and will always be an integer greater than 1 and less than 10
Hardcoding is allowed for input of 1, but nothing higher.
Reasonable error is allowed in the output. Issues with floating point arithmetic or trig may be ignored.
Any transformation of the N dimensional simplex is allowed, aslong as it remains Regular and Non-zero.
Standard Loopholes are forbidden.
This is code-golf, so fewest bytes wins.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	for i := range 11 {
		fmt.Println(i, simplex(i))
	}
}

/*

@PattuX

[i*[0]+[1]+(n+~i)*[0]for i in range(n)] creates identity matrix. All points have distance sqrt(2) from each other. (thanks to Rod for improving)

Now we need a n+1-th point with the same distance to all other points. We have to choose (x, x, ... x).

Distance from (1, 0, ...  ) to (x, x, ... x) is sqrt((x-1)²+x²+...+x²). If we want an n dimensional simplex this turns out to be sqrt((x-1)²+(n-1)x²), as we have one 1 and n-1 0s in the first point. Simplify a bit: sqrt(x²-2x+1+(n-1)x²) = sqrt(nx²-2x+1)

We want this distance to be sqrt(2).

sqrt(2) = sqrt(nx²-2x+1)
2 = nx²-2x+1
0 = nx²-2x-1
0 = x²-2/n*x+1/n

Solving this quadratic equation (one solution, other one works fine, too):

x = 1/n+sqrt(1/n²+1/n) = 1/n+sqrt((n+1)/n²) = 1/n+sqrt(n+1)/n = (1+sqrt(n+1))/n

Put that in a list n times, put that list in a list and join with identity matrix.

*/

func simplex(n int) [][]float64 {
	if n < 0 {
		return [][]float64{}
	}
	if n == 0 {
		return [][]float64{{0}}
	}

	m := make([][]float64, n+1)
	for i := range n + 1 {
		m[i] = make([]float64, n)
	}

	x := float64(n)
	for i := range n {
		m[i][i] = x
		m[n][i] = 1 + math.Sqrt(x+1)
	}

	return m
}
