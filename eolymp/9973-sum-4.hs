{-

Calculate the sum of the first n terms in the sequence: 1+8+27+64+125+…

Input
A natural number n, where 1≤n≤100.

Output
A single number representing the sum of the first n terms of the sequence.

Examples
Input #1
7

Answer #1
784

-}

solve :: Int -> (Int)
solve n = n^2 * (n + 1)^2 `div` 4

