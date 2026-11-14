package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(interpret([]string{
		"fd 100",
		"lt 120",
		"fd 100",
		"lt 120",
		"fd 100",
	}))
}

func interpret(cmds []string) float64 {
	var x, y, theta float64
	for _, cmd := range cmds {
		var (
			op  string
			val float64
		)
		_, err := fmt.Sscanf(cmd, "%s %f", &op, &val)
		if err != nil {
			continue
		}

		rad := deg2rad(theta)
		switch op {
		case "fd":
			x += val * math.Cos(rad)
			y += val * math.Sin(rad)
		case "bk":
			x -= val * math.Cos(rad)
			y -= val * math.Sin(rad)
		case "rt":
			theta = angle(theta + val)
		case "lt":
			theta = angle(theta - val)
		}
	}
	return math.Hypot(x, y)
}

func angle(theta float64) float64 {
	if theta >= 360 {
		theta -= 360
	} else if theta < 0 {
		theta += 360
	}
	return theta
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}
