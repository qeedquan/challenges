%{

Given the coordinates of n consecutive vertices of a polygon, find its area.

Input
The first line contains the number of vertices n (3≤n≤50000).

Each of the next n lines contains two integers xi and yi (−1000≤xi,yi≤1000) - the coordinates of the consecutive vertices of the polygon.

Output
Print the area of the polygon to exactly 3 decimal places.

Examples

Input #1
3
0 0
0 2
2 0

Answer #1
2.000

%}

polyarea([0 0 2], [0 2 0])
