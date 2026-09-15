{-

Find the least common multiple (LCM) of n positive integers.

Input
The first line contains the integer n (1<n<21).The second line contains n positive integers separated by spaces. Each number does not exceed 100.

Output
Print the least common multiple of the given n numbers.

Examples
Input #1
2
2 3

Answer #1
6

-}

solve :: [Int] -> Int
solve a = if length a == 0 then 0 else foldl (lcm) 1 a

