{-

Determine the number of digits in the integer n.

Input
A single integer n.

Output
Answer to the problem.

Examples
Input #1
37

Answer #1
2

-}

solve :: Integer -> Integer
solve n
    | n < 0            = solve(abs(n))
    | 0 <= n && n <= 9 = 1
    | otherwise        = 1 + solve (n `div` 10) 

