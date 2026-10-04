{-

Swap the first and last digits of a given three-digit positive integer.

Input
One three-digit positive integer n (100≤n≤999).

Output
Print the number obtained after swapping the first and last digits.

Examples

Input #1
198

Answer #1
891

-}

solve :: Int -> Int
solve n =  (n `div` 100) + ((n `mod` 100) `div` 10)*10 + (n `mod` 10)*100

