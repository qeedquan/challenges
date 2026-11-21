{-

Given some numbers. Find the biggest number that divides all these numbers.

Input
One line contains some integers (1≤number of integers≤1000, 1≤each number≤10^9).

Output
Print the biggest number that divides all the given numbers.

Examples

Input #1
18 30 21

Answer #1
3

-}

solve :: Integral a => [a] -> a
solve xs = foldl gcd 0 xs

