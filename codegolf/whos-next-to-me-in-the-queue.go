/*

Problem 4 in the 2019 BMO, Round 1 describes the following setup:

There are 2019 penguins waddling towards their favourite restaurant. As the penguins arrive, they are handed tickets numbered in ascending order from 1 to 2019, and told to join the queue.
The first penguin starts the queue. For each n>1 the penguin holding ticket number n finds the greatest m<n which divides n and enters the queue directly behind the penguin holding ticket number m.
This continues until all 2019 penguins are in the queue.

The second part of the question asked candidates to determine the penguins standing directly in front of, and directly behind, penguin 33.
This could be done by examining the patterns in the queue, considering prime factors: see the online video solutions for more information.

The Challenge
Your task is to design a program or function which, given a positive integer k representing the penguin with ticket number k, outputs the ticket numbers of the penguins directly before and after this penguin.

For example, penguin 33, stands directly behind 1760 and directly in front of 99, so the program should output, in some reasonable format, [1760,99].

Rules
The input will be an integer in the range 1<k≤2019.
Your program should output two integers, in any reasonable format, representing the ticket numbers of the penguins before and after.
These can be output in any order, (front first or behind first) but this order must be consistent.
The penguin will not be at the front or back of the queue: so you don't have to handle the edge cases of k=1 or k=1024.
As penguins find it difficult to read human glyphs, your program should be as short as possible. This is a code-golf - so the shortest program (in bytes) wins!

Test Cases
These outputs are given in the format [front, behind].

33   -> [1760, 99]
512  -> [256, 1024]
7    -> [1408, 49]
56   -> [28, 112]
1387 -> [1679, 1241]
2019 -> [673, 1346]
2017 -> [1, 2011]
2    -> [1536, 4]

*/

package main

import (
	"slices"
)

func main() {
	l := newline(2019)
	assert(l.Find(33) == [2]int{1760, 99})
	assert(l.Find(512) == [2]int{256, 1024})
	assert(l.Find(7) == [2]int{1408, 49})
	assert(l.Find(56) == [2]int{28, 112})
	assert(l.Find(1387) == [2]int{1679, 1241})
	assert(l.Find(2019) == [2]int{673, 1346})
	assert(l.Find(2017) == [2]int{1, 2011})
	assert(l.Find(2) == [2]int{1536, 4})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Line struct {
	lut map[int][2]int
}

func newline(n int) *Line {
	q := []int{1}
	for i := 2; i <= n; i++ {
		d := divisor(i)
		x := slices.Index(q, d)
		if x < 0 {
			x = len(q)
		}
		q = slices.Insert(q, x, i)
	}

	l := make(map[int][2]int)
	for i := 1; i < len(q)-1; i++ {
		l[q[i]] = [2]int{q[i+1], q[i-1]}
	}

	return &Line{
		lut: l,
	}
}

func (l *Line) Find(k int) [2]int {
	return l.lut[k]
}

func divisor(n int) int {
	for i := 2; i < n; i++ {
		if n%i == 0 {
			return n / i
		}
	}
	return 1
}
