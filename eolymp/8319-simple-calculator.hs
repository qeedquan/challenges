{-

A simple calculator accepts the following types of expressions as input:

num+num

num−num

num∗num

num/num

where num is a positive integer between 1 and 10000 inclusive.

Find the value produced by the given expression. Here +, −, ∗, and / denote addition, subtraction, multiplication, and division respectively. All operations are performed on integers, so "5/3" is equal to 1.

Input
One string containing a valid expression that the simple calculator can compute.

Output
Print the result of the given expression.

Examples

Input #1
3 * 12

Answer #1
36

Input #2
16 + 45

Answer #2
61

Input #3
19 / 7

Answer #3
2

-}

solve :: Int -> Char -> Int -> Int
solve x op y
    | op == '+'  = x + y
    | op == '-'  = x - y
    | op == '*'  = x * y
    | op == '/'  = x `div` y
    | otherwise  = 0
