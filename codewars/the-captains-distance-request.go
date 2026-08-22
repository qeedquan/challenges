/*

Ahoi!
We are on a big sailing boat off the coast of Croatia. The captain, by the name of Haversine, wants you to help him out: "Arrr, we need to know the distance between these two points on the map, so I know how long we need to wait before we get to our beloved treasure!". As this is the fourth of such requests by your captain, you decide to write a function to calculate the distance between two coordinates.

Complete the function so it returns the distance between two given coordinates. Examples of given coordinates are:

48° 12′ 30″ N, 16° 22′ 23″ E
23° 33′ 0″ S, 46° 38′ 0″ W
58° 18′ 0″ N, 134° 25′ 0″ W
33° 51′ 35″ S, 151° 12′ 40″ E

The returned distance should be in kilometers.
We think about the earth as a sphere with radius 6371 km.
As our captain has a good binocular and the fact, that we are lazy, we don't take precision too serious. So it is sufficient for the result to be precise up to 10 km.
You can expect the delivered coordinates to be valid.
The characters for minutes (′) and seconds (″) are not standard quotation marks, but following Unicode characters:

° - U+00B0 - Degree Sign
′ - U+2032 - Prime
″ - U+2033 - Double Prime
Examples
| From                         | To                            | Approx. distance |
| 48° 12′ 30″ N, 16° 22′ 23″ E | 23° 33′ 0″  S,  46° 38′  0″ W | 10138            |
| 48° 12′ 30″ N, 16° 22′ 23″ E | 58° 18′ 0″  N, 134° 25′  0″ W | 7873             |
| 48° 12′ 30″ N, 16° 22′ 23″ E | 48° 12′ 30″ N,  16° 22′ 23″ E | 0                |
As you try and try and just don't seem to be able to find the solution, the ship's first mate, an old white bearded man gives you a small hint: "There are many ways to tackle the problem. Guess which one's the captain's favourite! His name was not given to him by accident!"

Good luck, navigator!

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test("48° 12′ 30″ N, 16° 22′ 23″ E", "23° 33′ 0″ S,  46° 38′ 0″ W", 10138)
	test("48° 12′ 30″ N, 16° 22′ 23″ E", "58° 18′ 0″ N,  134° 25′ 0″ W", 7873)
	test("48° 12′ 30″ N, 16° 22′ 23″ E", "48° 12′ 30″ N,  16° 22′ 23″ E", 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, t string, r float64) {
	d := distance(s, t)
	fmt.Printf("%.2f\n", d)
	assert(math.Abs(d-r) < 1)
}

// https://eclipse2017.nasa.gov/crow-flies-spherical-planet
func distance(s, t string) float64 {
	const EARTH_RADIUS = 6371

	lat1, lon1 := latlon(s)
	lat2, lon2 := latlon(t)

	s0 := math.Sin(lat1) * math.Sin(lat2)
	c0 := math.Cos(lat1) * math.Cos(lat2) * math.Cos(lon2-lon1)
	return math.Acos(s0+c0) * EARTH_RADIUS
}

// https://edwilliams.org/gccalc.htm
func latlon(s string) (float64, float64) {
	var (
		x, y   [3]float64
		dx, dy rune
	)
	n, err := fmt.Sscanf(s, "%v° %v′ %v″ %c, %v° %v′ %v″ %c", &y[0], &y[1], &y[2], &dy, &x[0], &x[1], &x[2], &dx)
	if n != 8 || err != nil {
		return math.NaN(), math.NaN()
	}

	lat := y[0] + y[1]/60 + y[2]/3600
	lon := x[0] + x[1]/60 + x[2]/3600
	if dy == 'S' {
		lat = -lat
	}
	if dx == 'E' {
		lon = -lon
	}

	lat = deg2rad(lat)
	lon = deg2rad(lon)

	return lat, lon
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}
