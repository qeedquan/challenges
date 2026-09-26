%{

A binary matrix represents a shape in the plane. 1 means a unit square at that position. 0 means nothing. The background is 0.

For example, the matrix [[0,1,0],[0,0,1],[1,1,1]] represents the following shape:

     o----o
     |////|
     |////|
     o----o----o
          |////|
          |////|
o----o----o----o
|////|////|////|
|////|////|////|
o----o----o----o
There are several equivalent ways to define the Euler characteristic.

One way is finding all the vertices and edges of these squares, and defining the Euler characteristic to be χ=V−E+F,
where V is the number of vertices, E is the number of edges, and F is the number of tiles.

For example, the above shape has 13 vertices, 17 edges, and 5 tiles. So its Euler characteristic is 13−17+5=1.

An equivalent definition is the total number of connected regions in the shape, minus the number of holes that occur inside those regions.
Regions that connected diagonally are considered connected, while holes that are connected diagonally are considered disconnected.

For example, the above shape has 1 connected region, and 0 hole.
So its Euler characteristic is 1−0=1.

Note that there is an alternative but non-equivalent definition of the Euler characteristic,
where regions that connected diagonally are considered disconnected,
while holes that are connected diagonally are considered connected.
The Euler characteristic of the above shape would be 2 using that definition.

Task
Given a binary matrix, find its Euler characteristic.

You can use any two consistent values instead of 0 and 1 for the binary matrix.

This is code-golf, so the shortest code in bytes wins.

Testcases
[[1]] -> 1
[[1,0,1]] -> 2
[[1,0],[0,1]] -> 1
[[0,1,0],[0,0,1],[1,1,1]] -> 1
[[0,1,1,0],[1,0,1,1],[1,1,0,1],[0,1,1,0]] -> -1
[[0,0,1,1,0],[0,1,1,1,1],[1,1,0,1,1],[0,1,1,0,0]] -> 0
[[1,1,1,0,1,1,1],[1,0,1,0,1,0,1],[1,1,1,0,1,1,1]] -> 0
[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]] -> 1

%}

%{

@alephalpha

Based on this blog article.
https://sydney4.medium.com/the-euler-number-of-a-binary-image-1d3cc9e57caa

The Euler characteristic is M1 - M2 - M3,
where M1, M2, M3 are the numbers of 2×2 submatrices of the form (1000), (1110), (0110) respectively.

%}

function r = E(m)
	r = sum(conv2(m, [1, 2; 4, 8])(:) == [1, 6, 7]) * [1; -1; -1];
end

E([[1]])
E([[1, 0, 1]])
E([[1,0]; [0,1]])
E([[0, 1, 0]; [0, 0, 1]; [1, 1, 1]])
E([[0, 1, 1, 0]; [1, 0, 1, 1]; [1, 1, 0, 1]; [0, 1, 1, 0]])
E([[0, 0, 1, 1, 0]; [0, 1, 1, 1, 1]; [1, 1, 0, 1, 1]; [0, 1, 1, 0, 0]])
E([[1, 1, 1, 0, 1, 1, 1]; [1, 0, 1, 0, 1, 0, 1]; [1, 1, 1, 0, 1, 1, 1]])
E([[1, 1, 1, 1, 1]; [1, 0, 0, 0, 1]; [1, 0, 1, 0, 1]; [1, 0, 0, 0, 1]; [1, 1, 1, 1, 1]])

