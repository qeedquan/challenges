/*

Challenge
Given a list of integers and a velocity, v, implement a sorting algorithm which simulates a program sorting the list from smallest to biggest at the given velocity.

Einstein's Theory of Special Relativity
What do I mean? Well assume your program takes a time, T, to sort a particular list.
If you ran the program again at a higher velocity, v, according to a stationary observer your program would run slower and would take a different time, T′, to sort the same list.

How do you relate T to T′? You use the equation for time dilation:

T′=T1/sqrt(1-v^2)
If we use geometrised units where v is a fraction of the speed of light, and 0≤v<1.

So you must change your program's running time by a factor of

1/sqrt(1-v^2)

Output
You must output the sorted list

Rules
You are allowed an error of ±0.1 s
The length of the list, l, will be in the range 1≤l≤50
The list will contain only integers
The velocity will be given in geometrised units
You may sort the list then wait before outputting
Examples
For these examples, assume my program takes a time of T=l2 s to run, where l is the length of the list, regardless of the contents of the list:

List, Velocity > Sorted list, Time taken
[9,8,7,6,5,4,3,2,1], 0.5 > [1,2,3,4,5,6,7,8,9], 93.5307
[8,0,0,5,6], 0.1 > [0,0,5,6,8], 25.1259
[7,7,7,7,7,7,7], 0.99 > [7,7,7,7,7,7,7,7], 453.684

Your timings do not need to be as accurate.

Winning
Shortest code wins.

*/

package main

import (
	"fmt"
	"math"
	"sort"
	"time"
)

func main() {
	fmt.Println(einsteinsort([]int{9, 8, 7, 6, 5, 4, 3, 2, 1}, 0.5))
	fmt.Println(einsteinsort([]int{8, 0, 0, 5, 6}, 0.1))
	fmt.Println(einsteinsort([]int{7, 7, 7, 7, 7, 7, 7, 7}, 0.99))
}

func einsteinsort(a []int, v float64) ([]int, float64) {
	n := len(a)
	t := float64(n*n) / math.Sqrt(1-v*v)
	d := time.Duration(math.Round(t)) * time.Millisecond

	c := make(chan bool)
	go func() {
		sort.Slice(a, func(i, j int) bool {
			return a[i] < a[j]
		})
		c <- true
	}()
	time.Sleep(d)
	<-c

	return a, t
}
