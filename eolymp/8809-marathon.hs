{-

The running competition was started by a participants, but b of them left the race. How many runners finished?

Input
Two positive integers a and b(a,b≤10^18).

Output
Print the number of runners who finished the race.

Examples

Input #1
12 9

Answer #1
3

-}

solve :: Int -> Int -> Int
solve a b = a - b

