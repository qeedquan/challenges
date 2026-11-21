{-

The sides of a triangle are given. Find the perimeter of the triangle.

Input
Consists of multiple tests. Each line contains the lengths of three sides of a triangle. The lengths are positive real numbers.

Output
For each test print in a separate line the perimeter of triangle with 4 decimal digits.

Examples

Input #1
6.23 5.123 7.32141
2.12 4 3.012
3 3 3.033

Answer #1
18.6744
9.1320
9.0330

-}

solve :: Float -> Float -> Float -> Float
solve s1 s2 s3 = s1 + s2 + s3

