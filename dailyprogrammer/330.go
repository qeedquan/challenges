/*
Description
In this challenge, you will be given a set of circles, defined by their centers and radii. Your goal is to find the bounding rectangle which will contain all of the circles completely.

Write a program that determines the vertices of the bounding rectangle with sides parallel to the axes.
*/

package main

import (
	"fmt"
	"math"
)

type circle struct {
	x, y, r float64
}

type rect struct {
	x0, y0, x1, y1 float64
}

type vertex struct {
	x, y float64
}

func (v vertex) String() string {
	return fmt.Sprintf("(%.3f, %.3f)", v.x, v.y)
}

func (r rect) Vertices() []vertex {
	return []vertex{
		{r.x0, r.y0},
		{r.x0, r.y1},
		{r.x1, r.y1},
		{r.x1, r.y0},
	}
}

func main() {
	c := []circle{
		{1, 1, 2},
		{2, 2, 0.5},
		{-1, -3, 2},
		{5, 2, 1},
	}
	cbox(c)
}

func cbox(c []circle) {
	x0 := math.MaxFloat64
	y0 := math.MaxFloat64
	x1 := -math.MaxFloat64
	y1 := -math.MaxFloat64
	for _, c := range c {
		x0 = math.Min(x0, c.x-c.r)
		x1 = math.Max(x1, c.x+c.r)
		y0 = math.Min(y0, c.y-c.r)
		y1 = math.Max(y1, c.y+c.r)
	}
	r := rect{x0, y0, x1, y1}
	v := r.Vertices()
	for i := range v {
		fmt.Printf("%v", v[i])
		if i+1 < len(v) {
			fmt.Printf(", ")
		}
	}
	fmt.Println()
}
