{-

Given the coordinates of the endpoints of a line segment, x1, y1, x2, y2, determine its length.

Input
Four integers: x1, y1, x2, y2 (−1000 < x1, y1, x2, y2 < 1000).

Output
A single real number representing the length of the segment, with precision to hundredths.

Examples

Input #1
2 2 6 5

Answer #1
5.00

-}

solve :: Float -> Float -> Float -> Float -> Float
solve x1 y1 x2 y2 = sqrt((x2 - x1)^2 + (y2 - y1)^2)

