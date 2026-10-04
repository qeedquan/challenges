{-

You are given a natural number m — the distance in meters.
Output, in a single line separated by a space, the number of full kilometers in this distance and the remaining meters.

Input
natural number m that does not exceed 10^12.

Output
two integers separated by a space: the number of full kilometers and the number of remaining meters.

Examples
Input #1
2341
Answer #1
2 341

-}

solve :: Int -> (Int, Int)
solve m = (m `div` 1000, m `mod` 1000) 

