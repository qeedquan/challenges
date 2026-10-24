/*

The cross product is a peculiarly 3-dimensional phenomenon. There are multiple ways of generalizing it, but each of them have trade offs.

If you require that a cross product be a product of two vectors v1×v2 such that it is:

linear, av1×v2=a(v1×v2) and (v1+v2)×v3=(v1×v3)+(v2×v3)
anticommutative, (v1×v2)+(v2×v1)=0
orthogonal, (v1×v2)⋅v1=0

not everywhere zero
Then there are two dimensions that have cross products:

There is the ordinary cross product in 3D.
There is also a cross product in 7D.
Today our challenge is to implement this 7-dimensional cross product.

Definition
Although the above is technically unambiguous, I will give a complete definition of the 7D cross product here which you can readily implement as an algorithm.

In order to determine the cross product of two vectors you only need to know the behavior on the basis vectors. You can write each vector as a combination of basis vectors, e.g.

[a,b,c,d,e,f,g]⊤=ae1 + be2 + ce3 + de4 + ee5 + fe6 + ge7

Since the product is linear you can distribute until any cross product is written as the sum of products of basis vectors

×	e1	e2	e3	e4	e5	e6	e7
e1	0	e3	−e2	e5	−e4	−e7	e6
e2	−e3	0	e1	e6	e7	−e4	−e5
e3	e2	−e1	0	e7	−e6	e5	−e4
e4	−e5	−e6	−e7	0	e1	e2	e3
e5	e4	−e7	e6	−e1	0	−e3	e2
e6	e7	e4	−e5	−e2	e3	0	−e1
e7	−e6	e5	e4	−e3	−e2	e1	0

Rules
This is code-golf so the goal is to minimize the size of your source code as measured in bytes.

You should take input as two vectors. You may approximate real numbers in any reasonable manner.

You may choose to take input in a way that permutes the basis vectors, so long as it satisfies the definition of the cross product above. There are 7!=480
 permutations of the multiplication table, which are all perfectly fine.

Test cases
The table above provides 49 basic test cases. In addition I suggest you test the two linearity properties with random vectors. If your product is bilinear and satisfies the multiplication table above then it must be correct.

That is:

Take two random vectors and two random real numbers and test that av1×bv2=ab(v1×v2)
Take 3 random vectors and test that (v1+v2)×v3=(v1×v3)+(v2×v3)

*/

package main

import (
	"fmt"
)

type vec7 [7]float64

func main() {
	e1 := vec7{1, 0, 0, 0, 0, 0, 0}
	e2 := vec7{0, 1, 0, 0, 0, 0, 0}
	e3 := vec7{0, 0, 1, 0, 0, 0, 0}
	e4 := vec7{0, 0, 0, 1, 0, 0, 0}
	e5 := vec7{0, 0, 0, 0, 1, 0, 0}
	e6 := vec7{0, 0, 0, 0, 0, 1, 0}
	e7 := vec7{0, 0, 0, 0, 0, 0, 1}

	E := [7]vec7{e1, e2, e3, e4, e5, e6, e7}
	for i := range E {
		for j := range E {
			fmt.Printf("%+ v", cross7(E[i], E[j]))
		}
		fmt.Println()
	}
}

/*

https://en.wikipedia.org/wiki/Seven-dimensional_cross_product

In 7 dimensions, the cross product is not unique.
Unlike three dimensions, there are many tables because every pair of unit vectors is perpendicular to five other unit vectors,
allowing many choices for each cross product.

The version of the multiplication table we use below:

×	e1	e2	e3	e4	e5	e6	e7
e1	0	e4	e7	−e2	e6	−e5	−e3
e2	−e4	0	e5	e1	−e3	e7	−e6
e3	−e7	−e5	0	e6	e2	−e4	e1
e4	e2	−e1	−e6	0	e7	e3	−e5
e5	−e6	e3	−e2	−e7	0	e1	e4
e6	e5	−e7	e4	−e3	−e1	0	e2
e7	e3	e6	−e1	e5	−e4	−e2	0

Note that this multiplication table is different from the table above

These multiplication tables are characterized by the Fano plane.
Just as the 3-dimensional cross product can be expressed in terms of the quaternions, the 7-dimensional cross product can be expressed in terms of the octonions.

In three dimensions the cross product is invariant under the action of the rotation group, SO(3),
so the cross product of x and y after they are rotated is the image of x × y under the rotation.
But this invariance is not true in seven dimensions; that is, the cross product is not invariant under the group of rotations in seven dimensions, SO(7).
Instead it is invariant under the exceptional Lie group G2, a subgroup of SO(7).

*/

func cross7(x, y vec7) vec7 {
	x1, x2, x3, x4, x5, x6, x7 := x[0], x[1], x[2], x[3], x[4], x[5], x[6]
	y1, y2, y3, y4, y5, y6, y7 := y[0], y[1], y[2], y[3], y[4], y[5], y[6]
	return vec7{
		x2*y4 - x4*y2 + x3*y7 - x7*y3 + x5*y6 - x6*y5,
		x3*y5 - x5*y3 + x4*y1 - x1*y4 + x6*y7 - x7*y6,
		x4*y6 - x6*y4 + x5*y2 - x2*y5 + x7*y1 - x1*y7,
		x5*y7 - x7*y5 + x6*y3 - x3*y6 + x1*y2 - x2*y1,
		x6*y1 - x1*y6 + x7*y4 - x4*y7 + x2*y3 - x3*y2,
		x7*y2 - x2*y7 + x1*y5 - x5*y1 + x3*y4 - x4*y3,
		x1*y3 - x3*y1 + x2*y6 - x6*y2 + x4*y5 - x5*y4,
	}
}
