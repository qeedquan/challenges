/*

Write a function called multiFilter which receives a variable number of filter functions. The function should return a function that receives one element (a compound filter function).

That is, if we have two functions:

function isEven(el){
  return el % 2 === 0;
}
and

function isGTten(el){
  return el > 10;
}
then

[1,2,3,4,10,11,12,20,21,22].filter(multiFilter(isEven, isGTten));
should return [12,20,22]

Additional Rules
multiFilter can't be implemented using loops like:

for
while
do while
WARNING: Using ES6 features may break these rules because Babel can introduce some for loops when transpiling your code. Please, open an issue if it happens.

*/

package main

import "fmt"

type predfn[T any] func(T) bool

func main() {
	fmt.Println(filter([]int{1, 2, 3, 4, 10, 11, 12, 20, 21, 22}, multifilter(iseven, isgtten)))
}

func filter[T any](x []T, f predfn[T]) []T {
	r := []T{}
	for i := range x {
		if f(x[i]) {
			r = append(r, x[i])
		}
	}
	return r
}

func multifilter[T any](f ...predfn[T]) predfn[T] {
	return func(x T) bool {
		for _, f := range f {
			if !f(x) {
				return false
			}
		}
		return true
	}
}

func iseven(x int) bool  { return x%2 == 0 }
func isgtten(x int) bool { return x > 10 }
