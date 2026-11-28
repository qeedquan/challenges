/*

To introduce the problem think to my neighbor who drives a tanker truck. The level indicator is down and he is worried because he does not know if he will be able to make deliveries. We put the truck on a horizontal ground and measured the height of the liquid in the tank.

Fortunately the tank is a perfect cylinder and the vertical walls on each end are flat. The height of the remaining liquid is h, the diameter of the cylinder base is d, the total volume is vt (h, d, vt are positive or null integers). You can assume that h <= d.

Could you calculate the remaining volume of the liquid? Your function tankvol(h, d, vt) returns an integer which is the truncated result (e.g floor) of your float calculation.

Examples:
tankvol(40,120,3500) should return 1021 (calculation gives about: 1021.26992027)

tankvol(60,120,3500) should return 1750

tankvol(80,120,3500) should return 2478 (calculation gives about: 2478.73007973)
Tank vertical section:

https://imgur.com/wmt0U43

*/

package main

import (
	"math"
)

func main() {
	assert(tankvol(40, 120, 3500) == 1021)
	assert(tankvol(60, 120, 3500) == 1750)
	assert(tankvol(80, 120, 3500) == 2478)
	assert(tankvol(5, 7, 3848) == 2940)
	assert(tankvol(2, 7, 3848) == 907)
	assert(tankvol(2, 8, 5026) == 982)
	assert(tankvol(4, 9, 6361) == 2731)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func tankvol(h, d, vt float64) int {
	r := d / 2
	if h == r {
		return int(vt / 2)
	}

	D := vt / (math.Pi * r * r)
	H := r - h
	if h > r {
		H = r - (d - h)
	}
	S := math.Sqrt(r*r - H*H)
	T := rad2deg(math.Acos(H / r))
	V := vt*(360-2*T)/360 + S*H*D
	if h > r {
		return int(V)
	}
	return int(vt - V)
}

func rad2deg(x float64) float64 {
	return x * 180 / math.Pi
}
