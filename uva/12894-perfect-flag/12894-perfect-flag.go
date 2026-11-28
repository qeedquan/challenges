package main

func main() {
	assert(solve(0, 0, 20, 12, 9, 6, 4) == true)
	assert(solve(0, 0, 10, 6, 4, 3, 2) == false)
	assert(solve(1, 1, 21, 13, 10, 7, 4) == true)
	assert(solve(0, 0, 20, 20, 9, 10, 4) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

https://quickgrid.wordpress.com/2015/02/17/uva-problem-12894-perfect-flag-solution/

Here are the key points,

1. length (L) to width ratio of 10:6,
>> length / width = 10 / 6
>> 6 * length = 10 * width
>> 3 * length = 5 * width
2. length (L) to radius ratio of 5:1,

>> length / radius = 5 / 1
>> 1 * length = 5 * radius
3. Example: If the length is 10, then width should be 6 and radius should be 2.
Set these values in our equations above and check if both sides are equal.

4. Its center (Circle’s) will be placed on the intersecting point of thee perpendicular drawn from the nine-twentieth part of the length of the flag,

>> nine-twentieth of length, ( 9 / 20 ) * length
>> Circles x distance on flag = given x position of circle - initial x position
>> 20 * (circle center x - initial x) = 9 * length
5. Horizontal line drawn through the middle of its width,

>> Circle middle y distance = given circle y - initial y
>> middle of width, (1/2) * width
>> 2 * ( given circle y - initial y ) = width

*/

func solve(x0, y0, x1, y1, cx, cy, r int) bool {
	l := x1 - x0
	w := y1 - y0
	return 5*w == 3*l && l == 5*r && 20*(cx-x0) == 9*l && 2*(cy-y0) == w
}
