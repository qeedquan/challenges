package main

import "fmt"

func main() {
	fmt.Println(score(40, 20))
	fmt.Println(score(20, 40))
}

func score(s, d int) (int, int) {
	x := (s + d) / 2
	y := s - x
	if (s+d)%2 != 0 || x+y != s || abs(x-y) != d || x < 0 || y < 0 {
		return -1, -1
	}
	return max(x, y), min(x, y)
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
