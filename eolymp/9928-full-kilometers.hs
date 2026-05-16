{-

The program receives a natural number m as input, which represents a distance in meters.
Your task is to output the number of complete kilometers in this distance.

Input
A natural number m that does not exceed 10^12.

Output
The result of the calculation.

Examples

Input #1
2341

Answer #1
2

-}

solve :: Int -> Int
solve m = m `div` 1000

