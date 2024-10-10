/*

Teering is a little boy. He is trying to draw the national flag of Bangladesh.
Being smart he knows he has to maintain the correct ratio and measurement while drawing the flag.
You know the rules of drawing the national flag, don’t you?
If not, no worries, Teering is here to help you: The national flag of Bangladesh consist of a green rectangle with a red circle inside it.
The ratio of the length and width of the rectangle is 100 : 60 (i.e. if the length is 100 units then the width will be 60 units).
The radius of the circle is 20% of the length (i.e. if the length is 100 units then the radius of the circle will be 20 units).
To get the center of the circle you need to draw a horizontal line dividing the width in equal portion and
draw a vertical line dividing the length in 45 : 55 ratio (i.e. if the length of the rectangle is 100 then 45 units will be in left and 55 units will be on the right side of the line).
The crossing of the two lines will be the center of the circle. Here is an illustrated picture for better understanding.
Now Teering has started to draw a flag. He has already drawn the circle of radius R centered at the origin in a 2D co-ordinate system.
Now he needs to determine the corner of the rectangle so that he can join them to complete the flag. Can you help him?

Input
The first line of input will contain an integer T (T < 101) denoting the number of test cases. Each of
the following T lines will contain an integer R (R < 1001) each denoting the radius of the circle.

Output
For each input output five lines. The first line will contain the case number. The following four lines
will denote the upper left, upper right, lower right and lower left coordinates of the rectangle for
the flag respectively. You have to print x coordinate and y coordinate separated by space in each line.
You may assume that input is given in such that the corners will always be in integer coordinates.
See sample input output for details.

Sample Input
2
20
100

Sample Output

Case 1:
-45 30
55 30
55 -30
-45 -30

Case 2:
-225 150
275 150
275 -150
-225 -150

*/

package main

import (
	"image"
)

func main() {
	assert(dimension(20) == [4]image.Point{
		{-45, 30},
		{55, 30},
		{55, -30},
		{-45, -30},
	})

	assert(dimension(100) == [4]image.Point{
		{-225, 150},
		{275, 150},
		{275, -150},
		{-225, -150},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func dimension(r float64) [4]image.Point {
	w := 1.5 * r
	l := 5 * r
	l1 := .45 * l
	l2 := .55 * l
	return [4]image.Point{
		{int(-l1), int(w)},
		{int(l2), int(w)},
		{int(l2), int(-w)},
		{int(-l1), int(-w)},
	}
}
