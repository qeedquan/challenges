{-

The program receives a natural number m as input, representing a length in centimeters.
Your task is to output, in a single line and separated by a space, the number of full meters and the remaining centimeters of this length.

Input
A natural number m that does not exceed 10^12.

Output
The solution to the problem.

Examples

Input #1
234

Answer #1
2 34

-}

solve :: Int -> (Int, Int)
solve m = (m `div` 100, m `mod` 100) 

