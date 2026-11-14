/*

There are many magic squares, but there is just one non-trivial magic hexagon, as Dr. James Grime explained, which is the following:

  18 17  3
 11  1  7 19
9  6  5  2 16
 14  8  4 12
  15 13 10
As it is done in Hexagony this is easiest written as just one line, by just reading it row by row:

18 17 3 11 1 7 19 9 6 5 2 16 14 8 4 12 15 13 10
Of course there are twelve such list representations of this magic hexagon in total, if you count rotations and reflections. For instance a clockwise 1/6 rotation of the above hexagon would result in

9 11 18 14 6 1 17 15 8 5 7 3 13 4 2 19 10 12 16
@Okx asked to list the remaining variants. The remaining lists are:

15 14 9 13 8 6 11 10 4 5 1 18 12 2 7 17 16 19 3
3 17 18 19 7 1 11 16 2 5 6 9 12 4 8 14 10 13 15
18 11 9 17 1 6 14 3 7 5 8 15 19 2 4 13 16 12 10
9 14 15 11 6 8 13 18 1 5 4 10 17 7 2 12 3 19 16
plus all the mentioned lists reversed.

Challenge
Write a program that outputs the magic hexagon as a list. You can choose any of the 12 reflections/rotations of the hexagon.

Please add a few words on how your solution works.

*/

package main

import (
	"fmt"
	"math/rand"
	"slices"
)

func main() {
	for range 50 {
		fmt.Println(solve())
	}
}

func solve() []int {
	tab := [][]int{
		{18, 17, 3, 11, 1, 7, 19, 9, 6, 5, 2, 16, 14, 8, 4, 12, 15, 13, 10},
		{9, 11, 18, 14, 6, 1, 17, 15, 8, 5, 7, 3, 13, 4, 2, 19, 10, 12, 16},
		{15, 14, 9, 13, 8, 6, 11, 10, 4, 5, 1, 18, 12, 2, 7, 17, 16, 19, 3},
		{3, 17, 18, 19, 7, 1, 11, 16, 2, 5, 6, 9, 12, 4, 8, 14, 10, 13, 15},
		{18, 11, 9, 17, 1, 6, 14, 3, 7, 5, 8, 15, 19, 2, 4, 13, 16, 12, 10},
		{9, 14, 15, 11, 6, 8, 13, 18, 1, 5, 4, 10, 17, 7, 2, 12, 3, 19, 16},
	}

	i := rand.Intn(len(tab))
	r := tab[i]
	if rand.Intn(2) == 0 {
		slices.Reverse(r)
	}
	return r
}
