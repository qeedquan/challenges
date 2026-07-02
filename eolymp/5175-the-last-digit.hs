{-

Print the last digit of a number n.

Input
One positive integer n (1≤n≤10^9).

Output
Print the last digit of the number n.

Examples

Input #1
123

Answer #1
3

Input #2
6578

Answer #2
8

-}

lastdigit :: Int -> Int
lastdigit x = x `mod` 10

