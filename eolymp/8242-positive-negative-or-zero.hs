{-

One integer n is given. Print whether it is positive, negative, or equal to 0.

Input
One integer n, no more than 10^9 by absolute value.

Output
Print "Positive", "Negative" or "Zero" depending on the value of n.

Examples

Input #1
45

Answer #1
Positive

Input #2
0

Answer #2
Zero

Input #3
-12

Answer #3
Negative

-}

solve :: Int -> (String)
solve x
    | x > 0     = "Positive"
    | x == 0    = "Zero"
    | otherwise = "Negative"

