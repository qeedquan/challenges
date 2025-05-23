/*

The Ackermann function is a famous function that played a big role in computability theory as the first example of a total computable function that is not primitive recursive.

Since then the function has been a bit simplified but is still of good use. Due to its definition in terms of extremely deep recursion it can be used as a benchmark of a compiler's ability to optimize recursion.

The goal of this kata is to code a function which will be given two inputs, m and n, and will return the Ackermann number A(m,n) defined by:

A(m,n) = n+1                          if m=0
A(m,n) = A(m-1,1)                     if m>0 , n=0
A(m,n) = A(m-1,A(m,n-1))              if m,n > 0
m,n should be non-negative integers, the function should return null (Javascript, Dart), None (Python), or nil (Ruby) for other type, non-integer and negative numbers. In C, input is restricted to integer type.

*/

package main

func main() {
	assert(ackermann(1, 1) == 3)
	assert(ackermann(4, 0) == 13)
	assert(ackermann(0, 4) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func ackermann(m, n int) int {
	switch {
	case m == 0:
		return n + 1
	case n == 0:
		return ackermann(m-1, 1)
	}
	return ackermann(m-1, ackermann(m, n-1))
}
