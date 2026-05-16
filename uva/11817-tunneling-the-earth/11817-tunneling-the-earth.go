package main

import (
	"fmt"
	"math"
)

const EARTH_RADIUS = 6371009

func main() {
	fmt.Println(solve(43.466667, -80.516667, 30.058056, 31.228889))
}

func solve(la1, lo1, la2, lo2 float64) float64 {
	x1, y1, z1 := sph2car(deg2rad(la1), deg2rad(lo1))
	x2, y2, z2 := sph2car(deg2rad(la2), deg2rad(lo2))

	d := dist(x1, x2, y1, y2, z1, z2)
	return arcdist(d) - d
}

func sph2car(la, lo float64) (x, y, z float64) {
	const R = EARTH_RADIUS
	x = R * math.Cos(la) * math.Cos(lo)
	y = R * math.Cos(la) * math.Sin(lo)
	z = R * math.Sin(la)
	return
}

func dist(x1, x2, y1, y2, z1, z2 float64) float64 {
	return math.Sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2))
}

func arcdist(d float64) float64 {
	const R = EARTH_RADIUS
	return R * 2 * math.Asin(d/(2*R))
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}
