/*

The set must be associative under the binary operation:
(a*b)*c=a*(b*c)
(given_function(given_function(a,b),c) = given_function(a, given_function(b,c)) )

There must be an identity element i so that for any other element of the set a:
i*a=a=a*i (given_function(i,a)=a=given_function(a,i))

For each element a there must be an inverse element a^-1 in the set, such that: a*a^-1=i=a^-1*a (given_function(a,a^-1)=identity)

The wikipedia page is really useful for a clearer/thorougher understanding. I would also reccomend looking up Cayley tables and designing a function to create one for a group object, makes it much easier to see where you have gone wrong.

https://en.wikipedia.org/wiki/Group_(mathematics)#Definition_and_illustration

*/

package main

import "slices"

func main() {
	set1 := []int{0, 1, 2, 3}
	set2 := []string{"a", "b"}
	mod4 := func(x, y int) int { return (x + y) % 4 }
	add := func(x, y int) int { return x + y }
	binop := func(x, y string) string {
		if x == y {
			return "a"
		}
		return "b"
	}
	assert(isgroup(set1, mod4) == true)
	assert(isgroup(set1, add) == false)
	assert(isgroup(set2, binop) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Element interface {
	comparable
}

type Binary[T Element] func(T, T) T

func isgroup[T Element](x []T, f Binary[T]) bool {
	return isclosed(x, f) && isassoc(x, f) && hasidentity(x, f) && hasinverse(x, f)
}

func isclosed[T Element](x []T, f Binary[T]) bool {
	for _, a := range x {
		for _, b := range x {
			if slices.Index(x, f(a, b)) < 0 {
				return false
			}
		}
	}
	return true
}

func isassoc[T Element](x []T, f Binary[T]) bool {
	for _, a := range x {
		for _, b := range x {
			for _, c := range x {
				if f(f(a, b), c) != f(a, f(b, c)) {
					return false
				}
			}
		}
	}
	return true
}

func hasidentity[T Element](x []T, f Binary[T]) bool {
loop:
	for _, a := range x {
		for _, b := range x {
			if f(a, b) == a && f(b, a) == a {
				continue loop
			}
		}
		return false
	}
	return true
}

func hasinverse[T Element](x []T, f Binary[T]) bool {
	for _, a := range x {
		var (
			i  T
			ok bool
		)
		for _, b := range x {
			if f(a, b) == a && f(b, a) == a {
				i = b
				ok = true
				break
			}
		}
		if !ok {
			return false
		}

		for _, b := range x {
			if f(a, b) == i && f(b, a) == i {
				ok = true
				break
			}
		}
		if !ok {
			return false
		}
	}
	return true
}
