package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(lid(12, 25))
	fmt.Println(lid(10, 33))
}

func lid(h, V float64) float64 {
	return 4 * math.Sqrt((3*282*V)/(7*math.Pi*h))
}
