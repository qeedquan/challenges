/*

This one is inspired by Calvin's Hobbies recent multiplication table challenge.

Write a function or program that takes an integer N as input and prints or returns a N-by-N unique multiplication spiral. The code must (in theory) work for N between 0 and 1000 (outputting this can be hard though). The output should be equivalent to the table produced by the following procedure:

Fill out an N-by-N multiplication table. E.g. for N = 3:

1 2 3
2 4 6
3 6 9
Follow a spiral clockwise from the upper left corner, noting the numbers that you visit. When you visit a number which you have already visited, replace it with 0.

A few examples might make it more clear:

n = 0:
0

n = 1:
1

n = 2:       //   Spiral order:
1  2         //   1  2
0  4         //   4  3

n = 3:
1  2  3      //   1  2  3
0  4  6      //   8  9  4
0  0  9      //   7  6  5

n = 4:
1  2  3  4   //   1   2   3   4
0  0  6  8   //  12  13  14   5
0  0  9 12   //  11  16  15   6
0  0  0 16   //  10   9   8   7

n = 5:
1   2   3   4   5
0   0   6   8  10
0   0   9  12  15
0   0   0  16  20
0   0   0   0  25

n = 10:
1   2   3   4   5   6   7   8   9  10
0   0   0   0   0  12  14  16  18  20
0   0   0   0  15   0  21  24  27  30
0   0   0   0   0   0  28  32  36  40
0   0   0   0  25   0  35   0  45  50
0   0   0   0   0   0  42  48  54  60
0   0   0   0   0   0  49  56  63  70
0   0   0   0   0   0   0  64  72  80
0   0   0   0   0   0   0   0  81  90
0   0   0   0   0   0   0   0   0 100
The numbers are found like this:

https://i.sstatic.net/2LFcq.png

Any reasonable output format is accepted, but it must be an N-by-N matrix, it cannot be just a list. Formats such the ones below are accepted, as there are N easily distinguishable 1-by-N columns, or N-by-1 rows:

[[1 2 3][0 4 6][0 0 9]]   <-- OK

[[1 0 0][2 4 0][3 6 9]]   <-- OK

ans =                     <-- OK
    1  2  3
    0  4  6
    0  0  9

*/

package main

import "fmt"

func main() {
	output(spiral(0))
	output(spiral(1))
	output(spiral(2))
	output(spiral(3))
	output(spiral(4))
	output(spiral(5))
	output(spiral(10))
	output(spiral(16))
}

func output(m [][]int) {
	fmt.Printf("n=%d\n", len(m))
	for i := range m {
		for j := range m[i] {
			fmt.Printf("%4d", m[i][j])
		}
		fmt.Println()
	}
	fmt.Println()
}

func spiral(n int) [][]int {
	m := [][]int{}
	s := map[int]bool{}
	for y := 1; y <= n; y++ {
		p := []int{}
		for x := 1; x <= n; x++ {
			v := x * y
			if s[v] {
				v = 0
			} else {
				s[v] = true
			}

			p = append(p, v)
		}
		m = append(m, p)
	}
	return m
}
