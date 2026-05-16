{-

Find the area of a quadrilateral with vertices
A(x1, y1) B(x2, y2) C(x3, y3) D(x4, y4)

The coordinates of the successive vertices of the quadrilateral are given in a single line:
x1 y1 x2 y2 x3 y3 x4 y4

All input values are integers and satisfy
|xi| <= 100 |yi| <= 100 for i = 1..4

Output
Output the area of the quadrilateral, rounded to the nearest integer.

Examples

Input #1
1 4 5 4 4 2 2 1

Answer #1
8

-}

{- https://en.wikipedia.org/wiki/Shoelace_formula -}
solve :: Float -> Float -> Float -> Float -> Float -> Float -> Float -> Float -> Int
solve x1 y1 x2 y2 x3 y3 x4 y4 = round(abs((x1*y2 + x2*y3 + x3*y4 + x4*y1) - (y1*x2 + y2*x3 + y3*x4 + y4*x1)) * 0.5)

