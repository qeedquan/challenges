/*

Introduction
A queue is an abstract data type where elements are added to the front (enqueue) and removed from the back (dequeue). This is also known as the FIFO (First In First Out) principle.

It is best shown with an example:

https://i.stack.imgur.com/ZX7ja.png

Challenge
Given a non-empty array that contains positive integers and elements that indicate a dequeue (removing an element), output the final list of the queue.

Let's say that X denotes a dequeue in this example. Let's take a look at the following list:

[45, X, X, 37, 20, X, 97, X, 85]
This can be translated to the following queue-pseudo code:

                   Queue
Enqueue 45    ->   45
Dequeue       ->
Dequeue       ->              (dequeue on an empty queue is a no-op)
Enqueue 37    ->   37
Enqueue 20    ->   20 37
Dequeue       ->   20
Enqueue 97    ->   97 20
Dequeue       ->   97
Enqueue 85    ->   85 97
You can see that in the end, the result is [85, 97], which is the output for this sequence.

Test cases
Note that you may choose any other symbol or character for X, as long as it's not a positive integer.

[1, X, 2, X, 3, X]      ->     []
[1, 2, X]               ->     [2]
[1, 2, 3]               ->     [3, 2, 1]
[1, 2, X, X, X, 3]      ->     [3]
[1, 2, X, 3, X, 4]      ->     [4, 3]
This is code-golf, so the submission with the least amount of bytes wins!

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{45, 'X', 'X', 37, 20, 'X', 97, 'X', 85}, []int{85, 97})
	test([]int{1, 'X', 2, 'X', 3, 'X'}, []int{})
	test([]int{1, 2, 'X'}, []int{2})
	test([]int{1, 2, 3}, []int{3, 2, 1})
	test([]int{1, 2, 'X', 'X', 'X', 3}, []int{3})
	test([]int{1, 2, 'X', 3, 'X', 4}, []int{4, 3})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []int) {
	p := queue(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func queue(a []int) []int {
	r := []int{}
	for _, x := range a {
		switch x {
		case 'X':
			if len(r) > 0 {
				r = r[1:]
			}

		default:
			r = append(r, x)
		}
	}
	return reverse(r)
}

func reverse(r []int) []int {
	n := len(r)
	for i := 0; i < n/2; i++ {
		r[i], r[n-i-1] = r[n-i-1], r[i]
	}
	return r
}
