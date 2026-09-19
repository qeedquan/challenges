{-

The input for the program consists of two integers, a and b, provided on a single line and separated by a space.
Your task is to print these numbers in ascending order, with the smaller number appearing first, followed by the larger one.

Input
Two integers, a and b, are given on a single line, separated by a space.

Output
On one line, print the smaller number first, followed by the larger number.

Examples
Input #1
7 4

Answer #1
4 7

-}

sort2 :: Int -> Int -> (Int, Int)
sort2 a b = (min a b, max a b)
