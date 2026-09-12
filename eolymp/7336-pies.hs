{-

A pie in the school cafeteria costs a hryvnias and b kopecks. Determine the total amount in hryvnias and kopecks that Petryk will pay for n pies.

Input
Three natural numbers a, b, n (0≤a,b,n≤100).

Output
Two numbers separated by a space: the total cost in hryvnias and kopecks.

Examples

Input #1
1 25 2

Answer #1
2 50

-}

solve :: Int -> Int -> Int -> (Int, Int)
solve a b n = (a*n, b*n)

