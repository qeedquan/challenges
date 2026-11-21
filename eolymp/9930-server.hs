{-

The server was started at midnight and turned off after h hours. Determine the day number from the start on which the server was stopped.

Input
The input contains a single natural number h (1≤h≤10^12).

Output
Print a single natural number representing the ordinal day on which the server was stopped.

Examples

Input #1
57

Answer #1
3

-}

solve :: Int -> Int
solve h = ceiling ((fromIntegral h) / 24)

