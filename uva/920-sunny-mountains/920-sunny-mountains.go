package main

import (
	"fmt"
	"math"
	"sort"
)

type Point struct {
	x, y float64
}

func main() {
	test([]Point{
		{1100, 1200},
		{0, 500},
		{1400, 100},
		{600, 600},
		{2800, 0},
		{400, 1100},
		{1700, 600},
		{1500, 800},
		{2100, 300},
		{1800, 700},
		{2400, 500},
	}, 1446.34)

	test([]Point{
		{0, 1000},
		{1000, 0},
	}, 1414.21)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(mountain []Point, expected float64) {
	result := solve(mountain)
	fmt.Println(result)
	assert(math.Abs(result-expected) < 1e-2)
}

func solve(mountain []Point) float64 {
	sort.SliceStable(mountain, func(i, j int) bool {
		return mountain[i].x >= mountain[j].x
	})

	result := 0.0
	maxy := 0.0
	for i := 1; i < len(mountain); i++ {
		if mountain[i].y > maxy {
			result += distance(mountain[i], mountain[i-1]) * (mountain[i].y - maxy) / (mountain[i].y - mountain[i-1].y)
			maxy = mountain[i].y
		}
	}
	return result
}

func distance(p1, p2 Point) float64 {
	return math.Hypot(p1.x-p2.x, p1.y-p2.y)
}
