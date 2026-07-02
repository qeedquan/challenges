{-

Given the radius R of a circle, calculate its area.

0<R<1000

Input
A single real number R.

Output
A single real number with precision to 4 decimal places.

Examples

Input #1
3.5

Answer #1
38.4845

Input #2
1

Answer #2
3.1416

-}

solve :: Float -> Float
solve r = pi*r^2

