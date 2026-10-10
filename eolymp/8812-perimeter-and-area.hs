{-

Find the perimeter and the area of the rectangle, if we know the lengths of its sides.

Input
Two integers a and b (a, b≤10^9) - the lengths of the rectangle's sides.

Output
Print the perimeter and the area of the rectangle.

Examples

Input #1
3 7

Answer #1
20 21

-}

solve :: Int -> Int -> (Int, Int)
solve a b = (2*(a+b), a*b)

