{-

Determine the circumference of a circle, denoted as S, given its radius R. The radius must satisfy the condition 0<R<1000.

Input
A single real number R.

Output
A single real number S, rounded to 3 decimal places.

Examples

Input #1
3.5

Answer #1
21.991

Input #2
1

Answer #2
6.283

-}

solve :: Float -> Float
solve r = 2*pi*r

