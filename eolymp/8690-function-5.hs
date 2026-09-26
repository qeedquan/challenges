{-

Implement the function f(x,y,z) = xyz + x + y^2 + z^3.

Input
Three positive integers x, y, z (x,y,z≤10^6).

Output
Print the value of the function f(x,y,z).

Examples

Input #1
1 2 3

Answer #1
38

-}

solve :: Int -> Int -> Int -> Int
solve x y z = x*y*z + x + y*y + z*z*z

