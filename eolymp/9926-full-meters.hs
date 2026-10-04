{-

The program receives a natural number m as input, which represents a length in centimeters.
Your task is to output the number of full meters contained in this length.

Input
A natural number m, m≤10^12.

Output
Answer to the problem.

Examples

Input #1
234

Answer #1
2

-}

solve :: Int -> Int
solve m = m `div` 100

