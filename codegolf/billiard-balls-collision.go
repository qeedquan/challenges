/*

Given the 2-dimensional positions and velocities of a pair of billiard balls right before impact, calculate their velocities after a perfectly elastic collision. The balls are assumed to be ideal spheres (or equivalently: circles) with the same radius, same mass, uniform density, and no friction.

Input consists of 8 numbers: p0x,p0y,v0x,v0y,p1x,p1y,v1x,v1y where p0x,p0y is the centre of the first ball, v0x,v0y its velocity, and similarly p1x,p1y,v1x,v1y for the second ball. You can accept input in any order and structured in any convenient way, e.g. as a 2x2x2 array, or maybe a 2x2 array for p and two length-2 arrays for v0 and v1. It's also fine to take complex numbers (if your language supports them) instead of xy pairs. However, you should not take input in a coordinate system other than Cartesian, i.e. polar is not allowed.

Note that the radius of a billiard ball is half the distance between p0x,p0y and p1x,p1y, so it's not given as an explicit part of the input.

Write a program or function that outputs or returns 4 numbers in any convenient Cartesian representation: the post-collision values of v0x,v0y,v1x,v1y.

https://i.stack.imgur.com/lNIgt.png

A possible algorithm is:

find the normal line that passes through both centres

find the tangent line that passes through the midpoint between the two centres and is perpendicular to the normal line

change coordinate system and break down v0x,v0y and v1x,v1y into their tangential and normal components v0t,v0n and v1t,v1n

swap the normal components of v0 and v1, preserving their tangential components

change back to the original coordinate system

Tests (results rounded to 5 decimal places):

   p0x   p0y   v0x   v0y   p1x   p1y   v1x   v1y ->      v0x'       v0y'       v1x'       v1y'
[-34.5,-81.8, 34.7,-76.1, 96.2,-25.2, 59.2,-93.3] [  49.05873, -69.88191,  44.84127, -99.51809]
[ 36.9, 77.7,-13.6,-80.8, -7.4, 34.4, 15.1,-71.8] [   5.57641, -62.05647,  -4.07641, -90.54353]
[-51.0, 17.6, 46.1,-80.1, 68.6, 54.0,-35.1,-73.9] [ -26.48927,-102.19239,  37.48927, -51.80761]
[-21.1,-52.6,-77.7, 91.5, 46.0, 94.1, 83.8, 93.7] [ -48.92598, 154.40834,  55.02598,  30.79166]
[ 91.3, -5.3, 72.6, 89.0, 97.8, 50.5, 36.2, 85.7] [  71.73343,  81.56080,  37.06657,  93.13920]
[-79.9, 54.9, 92.5,-40.7,-20.8,-46.9,-16.4, -0.9] [  47.76727,  36.35232,  28.33273, -77.95232]
[ 29.1, 80.7, 76.9,-85.1,-29.3,-49.5,-29.0,-13.0] [  86.08581, -64.62067, -38.18581, -33.47933]
[ 97.7,-89.0, 72.5, 12.4, 77.8,-88.2, 31.5,-34.0] [  33.42847,  13.97071,  70.57153, -35.57071]
[-22.2, 22.6,-61.3, 87.1, 67.0, 57.6,-15.3,-23.1] [ -58.90816,  88.03850, -17.69184, -24.03850]
[-95.4, 15.0,  5.3, 39.5,-54.7,-28.5, -0.7,  0.8] [  21.80656,  21.85786, -17.20656,  18.44214]
[ 84.0,-26.8,-98.6,-85.6,-90.1, 30.9,-48.1, 37.2] [ -89.76828, -88.52700, -56.93172,  40.12700]
[ 57.8, 90.4, 53.2,-74.1, 76.4,-94.4,-68.1,-69.3] [  51.50525, -57.26181, -66.40525, -86.13819]
[ 92.9, 69.8,-31.3, 72.6,-49.1,-78.8,-62.3,-81.6] [-123.11680, -23.48435,  29.51680,  14.48435]
[-10.3,-84.5,-93.5,-95.6, 35.0, 22.6, 44.8, 75.5] [ -11.12485,  99.15449, -37.57515,-119.25449]
[ -3.9, 55.8,-83.3,  9.1, -2.7,-95.6, 37.7,-47.8] [ -82.84144, -48.75541,  37.24144,  10.05541]
[-76.5,-88.4,-76.7,-49.9, 84.5, 38.0,  4.2, 18.4] [   6.52461,  15.43907, -79.02461, -46.93907]
[ 64.2,-19.3, 67.2, 45.4,-27.1,-28.7, 64.7, -4.3] [  59.66292,  44.62400,  72.23708,  -3.52400]
[  9.8, 70.7,-66.2, 63.0,-58.7, 59.5, 83.7,-10.6] [  68.07646,  84.95469, -50.57646, -32.55469]
[ 62.9, 46.4, 85.0, 87.4, 36.3,-29.0,-63.0,-56.3] [  23.53487, -86.82822,  -1.53487, 117.92822]
[ -5.5, 35.6, 17.6,-54.3, -2.2, 66.8,-15.2, 11.8] [  24.15112,   7.63786, -21.75112, -50.13786]
Shortest wins. No loopholes.

thanks @Anush for helping fix the diagram's background colour

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(-34.5-81.8i, 34.7-76.1i, 96.2-25.2i, 59.2-93.3i, 49.05873-69.88191i, 44.84127-99.51809i)
	test(36.9+77.7i, -13.6-80.8i, -7.4+34.4i, 15.1-71.8i, 5.57641-62.05647i, -4.07641-90.54353i)
	test(-51.0+17.6i, 46.1-80.1i, 68.6+54.0i, -35.1-73.9i, -26.48927-102.19239i, 37.48927-51.80761i)
	test(-21.1-52.6i, -77.7+91.5i, 46.0+94.1i, 83.8+93.7i, -48.92598+154.40834i, 55.02598+30.79166i)
	test(91.3-5.3i, 72.6+89.0i, 97.8+50.5i, 36.2+85.7i, 71.73343+81.56080i, 37.06657+93.13920i)
	test(-79.9+54.9i, 92.5-40.7i, -20.8-46.9i, -16.4-0.9i, 47.76727+36.35232i, 28.33273-77.95232i)
	test(29.1+80.7i, 76.9-85.1i, -29.3-49.5i, -29.0-13.0i, 86.08581-64.62067i, -38.18581-33.47933i)
	test(97.7-89.0i, 72.5+12.4i, 77.8-88.2i, 31.5-34.0i, 33.42847+13.97071i, 70.57153-35.57071i)
	test(-22.2+22.6i, -61.3+87.1i, 67.0+57.6i, -15.3-23.1i, -58.90816+88.03850i, -17.69184-24.03850i)
	test(-95.4+15.0i, 5.3+39.5i, -54.7-28.5i, -0.7+0.8i, 21.80656+21.85786i, -17.20656+18.44214i)
	test(84.0-26.8i, -98.6-85.6i, -90.1+30.9i, -48.1+37.2i, -89.76828-88.52700i, -56.93172+40.12700i)
	test(57.8+90.4i, 53.2-74.1i, 76.4-94.4i, -68.1-69.3i, 51.50525-57.26181i, -66.40525-86.13819i)
	test(92.9+69.8i, -31.3+72.6i, -49.1-78.8i, -62.3-81.6i, -123.11680-23.48435i, 29.51680+14.48435i)
	test(-10.3-84.5i, -93.5-95.6i, 35.0+22.6i, 44.8+75.5i, -11.12485+99.15449i, -37.57515-119.25449i)
	test(-3.9+55.8i, -83.3+9.1i, -2.7-95.6i, 37.7-47.8i, -82.84144-48.75541i, 37.24144+10.05541i)
	test(-76.5-88.4i, -76.7-49.9i, 84.5+38.0i, 4.2+18.4i, 6.52461+15.43907i, -79.02461-46.93907i)
	test(64.2-19.3i, 67.2+45.4i, -27.1-28.7i, 64.7-4.3i, 59.66292+44.62400i, 72.23708-3.52400i)
	test(9.8+70.7i, -66.2+63.0i, -58.7+59.5i, 83.7-10.6i, 68.07646+84.95469i, -50.57646-32.55469i)
	test(62.9+46.4i, 85.0+87.4i, 36.3-29.0i, -63.0-56.3i, 23.53487-86.82822i, -1.53487+117.92822i)
	test(-5.5+35.6i, 17.6-54.3i, -2.2+66.8i, -15.2+11.8i, 24.15112+7.63786i, -21.75112-50.13786i)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(p0, v0, p1, v1, rv0p, rv1p complex128) {
	v0p, v1p := collision(p0, v0, p1, v1)
	fmt.Println(v0p, v1p)
	assert(allclose(v0p, rv0p))
	assert(allclose(v1p, rv1p))
}

func allclose(a, b complex128) bool {
	const eps = 1e-5
	return math.Abs(real(a)-real(b)) < eps &&
		math.Abs(imag(a)-imag(b)) < eps
}

func collision(p0, v0, p1, v1 complex128) (v0p, v1p complex128) {
	p01 := p0 - p1
	s := real((v0 - v1) / p01)
	d := complex(s, 0) * p01
	return v0 - d, v1 + d
}
