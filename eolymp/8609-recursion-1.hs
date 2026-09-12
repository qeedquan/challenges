{-

Implement the recursive function:

f(n) = 0             n = 0
       f(n - 1) + n  n > 0

Input
One integer n (0≤n≤1000).

Output
Print the value of f(n).

Examples

Input #1
5

Answer #1
15

-}

solve :: Integer -> Integer
solve 0 = 0
solve n = n + solve (n - 1)

