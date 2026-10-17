{-

For a given value of n, compute the sum of the harmonic series:

1 + 1/2 + 1/3 + 1/4 + ... 1/n

Input
One positive integer n (1≤n≤10^4).

Output
Print the sum of the harmonic series with 4 decimal places.

Examples

Input #1
3

Answer #1
1.8333

-}

harmonic :: Int -> Double
harmonic n = sum $ take n [1/k | k <- [1..]]

