{-

Find the greatest common divisor (GCD) of n numbers.

Input
The first line contains the integer n (1<n<101).The second line contains n positive integers separated by spaces. Each number does not exceed 30000.

Output
Print the least common multiple of the given n numbers.

Examples
Input #1
2
15 25

Answer #1
5

-}

solve :: [Int] -> Int
solve a = if length a == 0 then 0 else foldl (gcd) (head a) a

