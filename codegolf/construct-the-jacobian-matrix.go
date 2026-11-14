/*

Take the vector of unkowns u exists in R^n, and apply some generic differentiable function f(u) exist in R^m.
The Jacobian is then given by a matrix J exists R^(m x n) such that:

J[i, j] = df[i](u) / d(u[j])

For example, suppose m=3 and n=2. Then (using 0-based indexing)

u = [u0
     u1]

f(u) = [f0(u)
        f1(u)
        f2(u)]

The Jacobian of f is then

https://i.stack.imgur.com/IIPzw.png

The goal of this challenge is to print this Jacobian matrix.

Input
Your program/function should take as input two positive integers m and n, which represent the number of components of f and u respectively. The input may come from any source desired (stdio, function parameter, etc.). You may dictate the order in which these are received, and this must be consistent for any input to your answer (please specify in your answer).

Output
Something which represents the Jacobian matrix. This representation must explicitly spell out all elements of the Jacobian matrix, but the exact form of each term is implementation defined so long as is unambiguous what is being differentiated and with respect to what, and every entry is outputted in a logical order. Example acceptable forms for representing a matrix:

A list of lists where each entry of the outer list corresponds to a row of the Jacobian, and each entry of the inner list corresponds to a column of the Jacobian.
A string or textual output where each line is a row of the Jacobian, and each delimiter separated entry in a line corresponds to a column of the jacobian.
Some graphical/visual representation of a matrix. Example: what is shown by Mathematica when using the MatrixForm command
Some other dense matrix object where every entry is already stored in memory and can be queried (i.e. you can't use a generator object). Example would be how Mathematica internally represents a Matrix object
Example entry formats:

A string of the form d f_i/d u_j, where i and j are integers. Ex: d f_1/d u_2. Note that these spaces between d and f_1 or x_2 are optional. Additionally, the underscores are also optional.
A string of the form d f_i(u_1,...,u_n)/d u_j or d f_i(u)/d u_j. That is, the input parameters of the function component f_i are optional, and can either be explicitly spelled out or left in compact form.
A formatted graphical output. Ex.: what Mathematica prints when you evaluate the expression D[f_1[u_,u_2,...,u_n],u_1]
You may choose what the starting index for u and f are (please specify in your answer). The output may be to any sink desired (stdio, return value, output parameter, etc.).

Test cases
The following test cases use the convention m,n. Indexes are shown 0-based.

1,1
[[d f0/d u0]]

2,1
[[d f0/d u0],
 [d f1/d u0]]

2 2
[[d f0/d u0, d f0/d u1],
 [d f1/d u0, d f1/d u1]]

1,2
[[d f0/d u0, d f0/d u1]]

3,3
[[d f0/d u0, d f0/d u1, d f0/d u2],
 [d f1/d u0, d f1/d u1, d f1/d u2],
 [d f2/d u0, d f2/d u1, d f2/d u2]]

Scoring
This is code golf; shortest code in bytes wins. Standard loopholes are forbidden. You are allowed to use any built-ins desired.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(1, 1, [][]string{
		{"d f0/d u0"},
	})

	test(2, 1, [][]string{
		{"d f0/d u0"},
		{"d f1/d u0"},
	})

	test(2, 2, [][]string{
		{"d f0/d u0", "d f0/d u1"},
		{"d f1/d u0", "d f1/d u1"},
	})

	test(1, 2, [][]string{
		{"d f0/d u0", "d f0/d u1"},
	})

	test(3, 3, [][]string{
		{"d f0/d u0", "d f0/d u1", "d f0/d u2"},
		{"d f1/d u0", "d f1/d u1", "d f1/d u2"},
		{"d f2/d u0", "d f2/d u1", "d f2/d u2"},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m, n int, r [][]string) {
	j := jacobian(m, n)
	fmt.Println(j)
	assert(reflect.DeepEqual(j, r))
}

func jacobian(m, n int) [][]string {
	j := [][]string{}
	for r := 0; r < m; r++ {
		p := []string{}
		for c := 0; c < n; c++ {
			p = append(p, fmt.Sprintf("d f%d/d u%d", r, c))
		}
		j = append(j, p)
	}
	return j
}
