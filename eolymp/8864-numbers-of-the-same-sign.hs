{-

Two nonzero integers n and m are given. Print 1, if numbers n and m have the same sign and 0 otherwise.

Input
Two nonzero integers n and m, no more than 10^9 by absolute value.

Output
Print 1, if numbers n and m have the same sign and 0 otherwise.

Examples

Input #1
7 4

Answer #1
1

Input #2
-2 5

Answer #2
0

-}

sign :: Int -> Int
sign x
    | x >= 0     = 1
    | otherwise  = -1

solve :: Int -> Int -> Int
solve a b = if sign(a) == sign(b) then 1 else 0

