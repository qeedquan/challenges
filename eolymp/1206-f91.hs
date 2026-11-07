{-

McCarthy is a well-known computer science theorist. In one of his works, he defined a recursive function called f91,
which is defined for any positive integer n as follows:

If n≤100, then f91(n)=f91(f91(n+11));

If n≥101, then f91(n)=n−10.

Input
A positive integer n not greater than 1000000.

Output
The value of f91(n).

Examples

Input #1
91

Answer #1
91

-}

f91 :: Int -> Int
f91 n = if n <= 100 then 91 else n - 10

