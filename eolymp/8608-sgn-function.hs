{-

Find the value of the sgn function:

sgn(x)=  1, x > 0
         0, x = 0
        −1, x < 0

Input
One integer x (-10^9≤x≤10^9).

Output
Print the value of the sgn function for the given value of x.

Examples

Input #1
4

Answer #1
1

Input #2
0

Answer #2
0

Input #3
-2

Answer #3
-1

-}

sgn :: Int -> (Int)
sgn x
    | x > 0     = 1
    | x == 0    = 0
    | otherwise = -1
