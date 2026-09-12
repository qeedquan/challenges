{-

Implement the function f(x) = 1 + x + x^2.

Input
One positive integer x(x≤10^9).

Output
Print the value of the function f(x).

Examples

Input #1
3

Answer #1
13

-}

solve :: Int -> Int
solve x = 1 + x + x*x

