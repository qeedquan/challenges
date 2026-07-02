<?php

/*

You get a polygon as a list of 2D coordinates defining its vertices. The edges of the polygon are assumed to be drawn between adjacent elements of the list, with the polygon closing by an edge between the last element and the first.

Your task is to determine whether this polygon is convex. Convexity can be defined in several different ways:

All internal angles of the polygon are 180 degrees or smaller.
For each edge, all the vertices of the polygon are on the same side of the line defined by that edge.
If we walk along the edges of the polygon, going through all the vertices, we always turn in the same direction.
Any line drawn through the polygon crosses at most two edges.
For example:

convex [(-1,-1), (-1,1), (1,1), (1,-1)] == True

convex [(0,0), (-1,-1), (-1,1), (1,1), (1,-1)] == False
By convention, we consider a polygon with fewer than 4 vertices to be convex, including the empty polygon. 
 
*/

function cross($p, $q, $r) {
	return ($q[0] - $p[0]) * ($r[1] - $p[1]) - ($q[1] - $p[1]) * ($r[0] - $p[0]);
}

/*

https://stackoverflow.com/questions/471962/how-do-i-efficiently-determine-if-a-polygon-is-convex-non-convex-or-complex

@Jason S

You can make things a lot easier than the Gift-Wrapping Algorithm... that's a good answer when you have a set of points w/o any particular boundary and need to find the convex hull.

In contrast, consider the case where the polygon is not self-intersecting, and it consists of a set of points in a list where the consecutive points form the boundary.
In this case it is much easier to figure out whether a polygon is convex or not (and you don't have to calculate any angles, either):

For each consecutive pair of edges of the polygon (each triplet of points), compute the z-component of the cross product of the vectors defined by the edges pointing towards the points in increasing order.
Take the cross product of these vectors:

 given p[k], p[k+1], p[k+2] each with coordinates x, y:
 dx1 = x[k+1]-x[k]
 dy1 = y[k+1]-y[k]
 dx2 = x[k+2]-x[k+1]
 dy2 = y[k+2]-y[k+1]
 zcrossproduct = dx1*dy2 - dy1*dx2
 
 The polygon is convex if the z-components of the cross products are either all positive or all negative. Otherwise the polygon is nonconvex.

If there are N points, make sure you calculate N cross products, e.g. be sure to use the triplets (p[N-2],p[N-1],p[0]) and (p[N-1],p[0],p[1]).
 
*/

function convex($p) {
	$n = count($p);
	$s = 0;
	for ($i = 0; $i < $n; $i++) {
		$c = cross($p[$i], $p[($i + 1) % $n], $p[($i + 2) % $n]);
		if ($c == 0)
			continue;

		if ($s == 0)
			$s = $c;
		else if ($c * $s < 0)
			return false;
	}
	return true;
}

assert(convex([[0, 0], [0, 1], [1, 1], [1, 0]]) == true);
assert(convex([[0, 0], [0, 10], [10, 10], [10, 0], [5, 5]]) == false);
assert(convex([[-1, -1], [-1, 1], [1, 1], [1, -1]]) == true);
assert(convex([[0, 0], [-1, -1], [-1, 1], [1, 1], [1, -1]]) == false);

?>
