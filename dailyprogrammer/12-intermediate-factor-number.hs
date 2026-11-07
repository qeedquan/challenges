{-

Create a program that will factor a number. for example:

12 = 2 * 2 * 3

14 = 7 * 2

20 = 2 * 2 * 5

thanks to bears_in_bowlers for todays challenge!

-}

factors 1 = []
factors n = let d = head $ filter ((== 0) . mod n) [2..] in d : factors (n `div` d)

