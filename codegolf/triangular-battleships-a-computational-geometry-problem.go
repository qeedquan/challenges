/*

You are the captain of a battleship. The engineering department's been cutting corners with designs this year, so the ship you're on takes the shape of a simple triangle.

You walk out onto the deck and enjoy the sea breeze... though not for long. An enemy has fired at you! — but will the shot hit?

Input
You may write either a function or a full program for this challenge.

Your program will take in 11 integers, ten of which are paired:

The first three pairs of integers (x1, y1), (x2, y2), (x3, y3) will specify the vertices of your ship. The triangle formed will have nonzero area.

The next pair of integers (ex, ey) specifies the location of the enemy's cannon. The enemy cannon will never lie on, or within the boundary of your ship.*

The pair (ax, ay) after that specifies where the enemy aimed at. This will be distinct from (ex, ey).

The final positive integer R specifies the range of the enemy's shot

*You'd be a terrible captain if you didn't even notice that happening!

Output
You must print/return a truthy value (e.g. true, 1) if the battleship will be hit, otherwise a falsy value (e.g. false, 0).

What is a hit?
The enemy shot is a straight line segment of length R from (ex, ey) in the direction of (ax, ay). If this line segment overlaps any part of the interior of your triangular battleship, then this counts as a hit. Otherwise it is not a hit.

Shots which graze along or only reach up to the boundary of the triangle do not count as a hit.

Examples
0 0 0 1 1 0
1 1
0 0
2

https://i.stack.imgur.com/4bR5Rm.jpg

Hit: The enemy has shot right through the centre of your ship!

2 0 0 2 4 4
0 0
1 1
1

https://i.stack.imgur.com/yti7zm.jpg

No hit: The enemy's range is too short, so you are safe.

0 0 1 2 3 0
-4 0
0 0
8

https://i.stack.imgur.com/CE3Kwm.jpg

No hit: The enemy has grazed the side of your ship, so this does not count as a hit. Lucky!

0 0 -1 3 4 -1
-3 -4
3 4
5

https://i.stack.imgur.com/3DNYcm.jpg

No hit: The enemy shot just stops short of the ship, so you are safe. If the enemy's cannon had even slightly better range, then you would have been hit! Phew!

-2 -3 -3 6 7 -2
-6 2
1 -4
7

https://i.stack.imgur.com/7Qu7bm.jpg

Hit: Even though the shot didn't penetrate to the other side, this is still a hit.

-3 2 2 -4 7 -3
-3 -4
-3 0
10

https://i.stack.imgur.com/TN8ofm.jpg

Additional test cases
0 0 6 0 6 8
-6 -8
6 8
20

https://i.stack.imgur.com/plqPbm.jpg

No Hit: This is another graze, but at an angle. (EDIT: CONSIDER THIS A HIT)

0 0 -2 -5 5 3
-3 4
0 0
6

https://i.stack.imgur.com/94V6Hm.jpg

Hit: The shot entered via a vertex of the ship.

Scoring
This is code-golf, so the shortest code in bytes wins. Standard loopholes apply.

*/

package main

import (
	"math"
)

func main() {
	assert(hit(0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 2) == true)
	assert(hit(2, 0, 0, 2, 4, 4, 0, 0, 1, 1, 1) == false)
	assert(hit(0, 0, 1, 2, 3, 0, -4, 0, 0, 0, 8) == false)
	assert(hit(0, 0, -1, 3, 4, -1, -3, -4, 3, 4, 5) == false)
	assert(hit(-2, -3, -3, 6, 7, -2, -6, 2, 1, -4, 7) == true)
	assert(hit(-3, 2, 2, -4, 7, -3, -3, -4, -3, 0, 10) == false)
	assert(hit(0, 0, 6, 0, 6, 8, -6, -8, 6, 8, 20) == true)
	assert(hit(0, 0, -2, -5, 5, 3, -3, 4, 0, 0, 6) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@DLosc

How it works:

Calculate the endpoint of the shot.
Test lots of points along the line from the endpoint to the cannon's location:
Calculate angles from vertex 1 to other two vertices and to test point;
Calculate angles from vertex 2 to other two vertices and to test point;
If the test point angle is between the other two angles, in both cases, then the test point is within the triangle and the ship has been hit.

*/

func hit(a, b, c, d, e, f, g, h, i, j, R float64) bool {
	const dr = 1e-4
	for r := R; r > 0; r -= dr {
		Q := math.Atan2(j-h, i-g)
		k, l := g+r*math.Cos(Q), h+r*math.Sin(Q)
		D := math.Atan2(d-b, c-a)
		E := math.Atan2(f-b, e-a)
		F := math.Atan2(l-b, k-a)
		G := math.Atan2(b-d, a-c)
		H := math.Atan2(f-d, e-c)
		I := math.Atan2(l-d, k-c)
		if (D < F && F < E || E < F && F < D) && (G < I && I < H || H < I && I < G) {
			return true
		}
	}
	return false
}
