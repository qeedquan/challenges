{-

Since the start of the day, s seconds have elapsed. What time is currently displayed on the clock in terms of hours, minutes, and seconds?

Input
An integer s that is less than 86400.

Output
Three integers on a single line, separated by spaces.

Examples

Input #1
3723

Answer #1
1 2 3

-}

solve :: Int -> (Int, Int, Int)
solve s = (s `div` 3600 `mod` 12, s `div` 60 `mod` 60, s `mod` 60) 

