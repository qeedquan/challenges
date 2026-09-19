/*

Description
You get a list that contains points. A "point" is a tuple like (x, y), where x and y are integer coordinates. By connecting three points, you get a triangle. There will be n > 2 points in the list, so you can draw one or more triangles through them.

Your task is to write a program that returns a tuple containing the areas of the largest and smallest triangles, which could be formed by these points.

Example:
Points (-4, 5), (-4, 0), (2, 3), (6, 0) can formate 4 different triangles with following areas:

https://i.postimg.cc/x1bzqbV0/Triangles.png

The largest area is 25 and the smallest is 5. So the correct return value is (25, 5)

Additional information:

In the returned tuple, the first position should be the largest area, and the second is the smallest.
Areas should be rounded to tenths.
You will always get at least 3 points.
If the points create only one triangle or several with the same areas, the returned tuple shoud look like this: (10, 10)
Make your program efficient. With 5 points, you can make 60 triangles, but only 10 of them will be different.
Three points can form a straight line. This doesn't count as a triangle!

*/

package main

import (
	"fmt"
	"math"
	"slices"
)

type Point struct {
	x, y float64
}

func main() {
	fmt.Println(areas([]Point{
		{-4, 5},
		{-4, 0},
		{2, 3},
		{6, 0},
	}))
}

func areas(p []Point) (float64, float64) {
	n := len(p)
	r := []float64{}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				a := area(p[i], p[j], p[k])
				if a > 0 {
					r = append(r, a)
				}
			}
		}
	}
	return slices.Max(r), slices.Min(r)
}

func area(a, b, c Point) float64 {
	return math.Abs((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y)) / 2
}
