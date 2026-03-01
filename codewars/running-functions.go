/*

Task
Implement a function which receives a list of values lst and a function fn as its arguments, and returns a new list where the i-th element is the result of left-reducing the first i+1 elements of lst using fn.

Assuming lst[:n] syntax represents taking the first n elements of lst, the function which you should implement must produce the following result:

[
  reduce(lst[:1], fn),
  reduce(lst[:2], fn),
  reduce(lst[:3], fn),
  ...,
  reduce(lst, fn)
]

Reduction
Reduction - the process of combining a list of values into a single value using a function. Assuming lst[-1] represents accessing the last element of a list, the left-reduction is equivalent to the following pseudo-code:

reduce(lst, fn) {
  result = lst[0]
  result = fn(result, lst[1])
  result = fn(result, lst[2])
  result = fn(result, lst[3])
  ...
  result = fn(result, lst[-1])
  return result
}

Examples
running([1,1,1,1], add) = [1,2,3,4]
running([10,3,4,1], sub) = [10,7,3,2]
running([1,9,2,10], max) = [1,9,9,10]
running([1,9,2,10], min) = [1,1,1,1]

*/

package main

import "fmt"

func main() {
	fmt.Println(reduce([]int{1, 1, 1, 1}, add))
	fmt.Println(reduce([]int{10, 3, 4, 1}, sub))
	fmt.Println(reduce([]int{1, 9, 2, 10}, imax))
	fmt.Println(reduce([]int{1, 9, 2, 10}, imin))
}

func reduce(a []int, f func(int, int) int) []int {
	for i := 1; i < len(a); i++ {
		a[i] = f(a[i-1], a[i])
	}
	return a
}

func add(x, y int) int  { return x + y }
func sub(x, y int) int  { return x - y }
func imax(x, y int) int { return max(x, y) }
func imin(x, y int) int { return min(x, y) }
