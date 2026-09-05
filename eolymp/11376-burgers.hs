{-

A burger machine has been installed at ADA University.
To produce one burger, one bun and one cutlet should be put into the machine.
Huseyn has n buns and m cutlets.
What is the largest number of burgers Huseyn can make?

Input
Two integers n and m (n,m≤10^9).

Output
Print the maximum number of burgers that Huseyn can make.

Examples

Input #1
3 5

Answer #1
3

-}

solve :: Int -> Int -> Int
solve n m = min n m

