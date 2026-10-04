/*

On the surface of the planet, which is a sphere of radius R, two points are given by their latitude and longitude.
Find the minimum path length along the surface of this planet from one point to another.

Input
The first line contains the number R, the second line contains the latitude and longitude of the first point,
the third line contains the latitude and longitude of the second point.

Latitude is in degrees from −90 to 90, longitude in degrees from −180 to 180, 100≤R≤10000, all numbers are real.

Output
Print the length of the path with two digits after the decimal point.

Examples

Input #1
4000
45 120
0 120

Answer #1
3141.59

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(4000, 45, 120, 0, 120))
}

/*

https://en.wikipedia.org/wiki/Haversine_formula
https://www.movable-type.co.uk/scripts/latlong.html
https://community.esri.com/t5/coordinate-reference-systems-blog/distance-on-a-sphere-the-haversine-formula/ba-p/902128
a = sin²((φB - φA)/2) + cos φA * cos φB * sin²((λB - λA)/2)
c = 2 * atan2( √a, √(1−a) )
d = R ⋅ c

*/

func solve(R, la1, lo1, la2, lo2 float64) float64 {
	phi1 := deg2rad(la1)
	phi2 := deg2rad(la2)
	delta_phi := deg2rad(la2 - la1)
	delta_lambda := deg2rad(lo2 - lo1)
	s1 := math.Sin(delta_phi / 2)
	s2 := math.Sin(delta_lambda / 2)
	c1 := math.Cos(phi1)
	c2 := math.Cos(phi2)
	a := s1*s1 + c1*c2*s2*s2
	c := 2 * math.Atan2(math.Sqrt(a), math.Sqrt(1-a))
	d := R * c
	return d
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}
