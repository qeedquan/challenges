{-

Calculate the sum of the first n numbers in the sequence shown in the image.

1/2 + 3/4 + 5/6 + 7/8 + 9/10 + ...

Input
A natural number n, where 1≤n≤100.

Output
Output a single number: the sum of the first n numbers of the sequence rounded to three decimal places.

Examples

Input #1
3

Answer #1
2.083

-}

solve :: Int -> Double
solve n = sum $ take n [(2*k-1)/(2*k) | k <- [1..]]

