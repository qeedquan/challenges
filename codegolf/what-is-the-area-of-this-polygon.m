%{

Calculate the area of a polygon.
Inspired by this shoelace algorithm video.

Task
Your job is to create a program or function that calculates the area of a polygon. Program or function is defined according the the default definition in meta.

Input
You will receive the X and Y coordinates of each vertex of the polygon. You can take the input as a list of tuples ([[x1, y1], [x2, y2], etc]), a matrix, or a flat list ([x1, y1, x2, y2, etc]). Two lists containing x and y coordinates respectively are allowed as well. The vertices are numbered counterclockwise and the first vertex is the same as the last vertex provided, thus closing the polygon.

If you want you can take the input without the last vertex (so receive each coordinate just once).

You can assume that the edges of the polygons don't intersect. You can also assume that all vertices have integer coordinates.

Output
The area of the polygon. All standard output methods are allowed. If your language does not allow for float division and the solution would not be an integer, you are allowed to return a fraction. The fraction does not necessarily have to be simplified, so returning 2/4 would be allowed.

Winning criterium
Shortest code wins!

Test cases
[[4,4],[0,1],[-2,5],[-6,0],[-1,-4],[5,-2],[4,4]]
55

https://i.stack.imgur.com/GWDit.png

[[1,1],[0,1],[1,0],[1,1]]
0.5
1/2

https://i.stack.imgur.com/hwdr5.png

%}

@polyarea([4 0 -2 -6 -1 5 4], [4 1 5 0 -4 -2 4])
@polyarea([1 0 1 1], [1 1 0 1])

