#!/bin/sh

cat << EOF >/dev/null

In geometry, a cube is a three-dimensional solid object bounded by six square faces, facets or sides, with three meeting at each vertex.The cube is the only regular hexahedron and is one of the five Platonic solids. It has 12 edges, 6 faces and 8 vertices.The cube is also a square parallelepiped, an equilateral cuboid and a right rhombohedron. It is a regular square prism in three orientations, and a trigonal trapezohedron in four orientations.

You are given a task of finding a if the provided value is a perfect cube!

EOF

initbc() {
	funcs=$(cat)
}

initbc << EOF
# http://phodd.net/gnu-bc/code/funcs.bc

define cbrt(x) {
	auto os, d, r, eps;
	if (x < 0)
		return -cbrt(-x)
	if (x == 0)
		return 0
	os = scale
	scale = 0
	eps = A^(scale/3)
	if (x < eps) {
		scale = os
		return 1/cbrt(1/x)
	}
	scale = 5
	r = e(l(x)/3)
	scale = os + 5
	if (scale < 5)
		scale = 5
	d = 1
	eps = A^(3-scale)
	while (d > eps) {
		d = r
		r = (r + r + x/(r*r)) / 3
		d -= r
		if (d < 0)
			d = -d
  	}
	scale = os
	return r/1
}

define floor(x) {
	auto os, xx;
	os = scale
	scale = 0
	xx = x/1
	if (xx > x)
		. = xx--
	scale = os
	return (xx)
}

define iscube(x) {
	c = floor(cbrt(x))
	if (c^3 == x)
		return 1
	return 0
}


EOF

iscube() {
	echo "$funcs; iscube($1)" | bc -l
}

iscube 8
iscube 27
iscube 64
iscube 256
iscube 1729
iscube 200
iscube 666
iscube 10000
iscube 1000000

