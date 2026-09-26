/*

Good Evening Golfers!

Your challenge is to completely unsort a series of numbers.

Input
Exactly 100 integers will be fed to your program. Your program may accept the input either as a file, or via stdin. Each integer will be separated by a newline character.

Those 100 integers will range from the minimal to the maximal values of a signed integer in your chosen language.

There will be no duplicate values. The values may be ordered, unordered or partially ordered - your program should be able to handle each case.

Output
The output must be each of the 100 integers, completely unsorted, each separated by a newline character. The output may be via stdout, or to a file.

Completely Unsorted means that no value is adjacent to any value which it would be adjacent to if the list were completely sorted in an ordered sequence.

Score
1 point per character, and lowest score wins. There is a bonus of -100 for any solution using no built in or library sorting functions. There is a bonus of -20 for any solutions using no built in random number functions.

I have tried to define this question as completely as possible. If you have any questions, please ask. If you have any comments on how I could do better next time, please let me know.

Fore!

*/

package main

import (
	"container/heap"
	"fmt"
)

func main() {
	x := make([]int, 100)
	for i := range x {
		x[i] = i + 1
	}
	fmt.Println(unsort(x))
}

/*

@daniero

Removes four lowest elements at a time, then print these four in another order:

*/

func unsort(a []int) []int {
	r := []int{}
	h := append(minheap{}, a...)
	heap.Init(&h)
	for h.Len() >= 4 {
		r = append(r, swaps(&h, 1, 3, 0, 2)...)
	}
	switch h.Len() {
	case 3:
		r = append(r, swaps(&h, 0, 2, 1)...)
	case 2:
		r = append(r, swaps(&h, 1, 0)...)
	case 1:
		r = append(r, swaps(&h, 0)...)
	}
	return r
}

func swaps(h *minheap, l ...int) []int {
	y := []int{}
	for range l {
		x := heap.Pop(h).(int)
		y = append(y, x)
	}

	r := make([]int, len(l))
	for i, j := range l {
		r[i] = y[j]
	}
	return r
}

type minheap []int

func (h minheap) Len() int           { return len(h) }
func (h minheap) Less(i, j int) bool { return h[i] < h[j] }
func (h minheap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *minheap) Push(x any) {
	*h = append(*h, x.(int))
}

func (h *minheap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
