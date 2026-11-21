/*

A regular dodecahedron is one of the five Platonic solids. It has 12 pentagonal faces, 20 vertices, and 30 edges.

https://i.stack.imgur.com/vx9WU.png

Your task is to output the vertex coordinates of a regular dodecahedron. The size, orientation, and position of the dodecahedron are up to you, as long as it is regular.

You may output the coordinates in any order, and in any reasonable format.

If the edge length of your dodecahedron is a, then the coordinates should be accurate to at least a/1000.

This is code-golf, so the shortest code in bytes wins.

Example output
This is one possible output. Your output does not have to match this.

{-1.37638,0.,0.262866}
{1.37638,0.,-0.262866}
{-0.425325,-1.30902,0.262866}
{-0.425325,1.30902,0.262866}
{1.11352,-0.809017,0.262866}
{1.11352,0.809017,0.262866}
{-0.262866,-0.809017,1.11352}
{-0.262866,0.809017,1.11352}
{-0.688191,-0.5,-1.11352}
{-0.688191,0.5,-1.11352}
{0.688191,-0.5,1.11352}
{0.688191,0.5,1.11352}
{0.850651,0.,-1.11352}
{-1.11352,-0.809017,-0.262866}
{-1.11352,0.809017,-0.262866}
{-0.850651,0.,1.11352}
{0.262866,-0.809017,-1.11352}
{0.262866,0.809017,-1.11352}
{0.425325,-1.30902,-0.262866}
{0.425325,1.30902,-0.262866}

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	v := dodecahedron()
	genobj(v[:])
}

func genobj(v []vec3) {
	for _, v := range v {
		fmt.Printf("v % f % f % f\n", v.x, v.y, v.z)
	}
}

// https://en.wikipedia.org/wiki/Regular_dodecahedron
func dodecahedron() [20]vec3 {
	phi := (1 + math.Sqrt(5)) / 2
	return [20]vec3{
		{-1, -1, -1},
		{-1, -1, 1},
		{-1, 1, -1},
		{-1, 1, 1},
		{1, -1, -1},
		{1, -1, 1},
		{1, 1, -1},
		{1, 1, 1},

		{0, -phi, -1 / phi},
		{0, -phi, 1 / phi},
		{0, phi, -1 / phi},
		{0, phi, 1 / phi},

		{-1 / phi, 0, -phi},
		{-1 / phi, 0, phi},
		{1 / phi, 0, -phi},
		{1 / phi, 0, phi},

		{-phi, -1 / phi, 0},
		{-phi, 1 / phi, 0},
		{phi, -1 / phi, 0},
		{phi, 1 / phi, 0},
	}
}

type vec3 struct {
	x, y, z float64
}
