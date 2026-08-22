{-

Given two matrices A and B. Find their sum C=A+B.

Input
The first line contains the dimensions of the matrices — two integers n and m (1≤n,m≤100).

Then follow n lines with m integers each, describing matrix A. After that comes an empty line, followed by matrix B given in the same format.

Output
Print matrix C: n lines with m integers.

Examples
Input #1
3 4
3 4 5 6
1 2 3 4
7 6 5 4

0 0 -3 -2
-1 3 4 5
5 6 1 2

Answer #1
3 4 2 4
0 5 7 9
12 12 6 6

-}

add :: Num a => [[a]] -> [[a]] -> [[a]]
add = zipWith (zipWith (+))

a = [[3, 4, 5, 6], [1, 2, 3, 4], [7, 6, 5, 4]]
b = [[0, 0, -3, -2], [-1, 3, 4, 5], [5, 6, 1, 2]]

main = print (add a b)
