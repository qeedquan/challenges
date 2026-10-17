/*

Finish this kata with the unit tests as your only help!

Task:

Implement:
Calculator.GetTotalArea()
Define the different shapes: `Square`, `Rectangle`, `Circle` and `Triangle`

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(GetTotalArea([]Shape{
		&Rectangle{4, 2},
		&Rectangle{3, 4},
		&Circle{1},
		&Square{1},
		&Triangle{10, 5},
	}))
}

type Shape interface {
	Area() float64
}

type Circle struct {
	radius float64
}

type Rectangle struct {
	width, height float64
}

type Square struct {
	side float64
}

type Triangle struct {
	base, height float64
}

type CustomShape struct {
	area float64
}

func (c *Circle) Area() float64      { return c.radius * c.radius * math.Pi }
func (c *Rectangle) Area() float64   { return c.width * c.height }
func (c *Square) Area() float64      { return c.side * c.side }
func (c *Triangle) Area() float64    { return c.base * c.height * 0.5 }
func (c *CustomShape) Area() float64 { return c.area }

func GetTotalArea(shapes []Shape) float64 {
	total := 0.0
	for _, shape := range shapes {
		total += shape.Area()
	}
	return total
}
