/*

Create a Vector object that supports addition, subtraction, dot products, and norms. So, for example:

var a = new Vector([1, 2, 3]);
var b = new Vector([3, 4, 5]);
var c = new Vector([5, 6, 7, 8]);

a.add(b);      // should return a new Vector([4, 6, 8])
a.subtract(b); // should return a new Vector([-2, -2, -2])
a.dot(b);      // should return 1*3 + 2*4 + 3*5 = 26
a.norm();      // should return sqrt(1^2 + 2^2 + 3^2) = sqrt(14)
a.add(c);      // throws an error
If you try to add, subtract, or dot two vectors with different lengths, you must throw an error!

Also provide:

a toString method, so that using the vectors from above, a.toString() === '(1,2,3)' (in Python, this is a __str__ method, so that str(a) == '(1,2,3)')
an equals method, to check that two vectors that have the same components are equal
Note: the test cases will utilize the user-provided equals method.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	defer func() { recover() }()
	a := Vector[float64]{1, 2, 3}
	b := Vector[float64]{3, 4, 5}
	c := Vector[float64]{5, 6, 7, 8}
	fmt.Println(a.Add(b))
	fmt.Println(a.Subtract(b))
	fmt.Println(a.Dot(b))
	fmt.Println(a.Norm(b))
	fmt.Println(a.Add(c))
}

type Element interface {
	~int | ~uint | ~float32 | ~float64 |
		~uint8 | ~uint16 | ~uint32 | ~uint64 |
		~int8 | ~int16 | ~int32 | ~int64
}

type Vector[T Element] []T

func (v Vector[T]) Add(u Vector[T]) Vector[T] {
	if len(v) != len(u) {
		panic("vector size mismatch")
	}
	r := Vector[T]{}
	for i := range v {
		r = append(r, v[i]+u[i])
	}
	return r
}

func (v Vector[T]) Subtract(u Vector[T]) Vector[T] {
	if len(v) != len(u) {
		panic("vector size mismatch")
	}
	r := Vector[T]{}
	for i := range v {
		r = append(r, v[i]-u[i])
	}
	return r
}

func (v Vector[T]) Dot(u Vector[T]) T {
	if len(v) != len(u) {
		panic("vector size mismatch")
	}
	var r T
	for i := range u {
		r += u[i] * v[i]
	}
	return r
}

func (v Vector[T]) Norm(u Vector[T]) T {
	return T(math.Sqrt(float64(v.Dot(u))))
}
