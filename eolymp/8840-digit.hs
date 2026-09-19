{-

The program takes a natural number n as input. Your task is to output the rightmost digit, or the units place, of the number n.

Input
A natural number n (1≤n≤10^10).

Output
The digit in the units place of the number n.

Examples
Input #1
27

Answer #1
7

-}

solve :: Int -> (Int)
solve n = (n `mod` 10)
