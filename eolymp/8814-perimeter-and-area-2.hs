{-

Calculate the perimeter and area of a square given the length of its side a.

p = 4a
s = a^2

Input
An integer representing the length of the square's side a.

Output
The perimeter and area of the square.

Examples

Input #1
3

Answer #1
12 9

-}

solve :: Int -> (Int, Int)
solve a = (4*a, a*a)

