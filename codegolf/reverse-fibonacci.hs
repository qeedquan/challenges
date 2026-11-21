{-

Your task
You must write a program, to print a reverse Fibonacci series, given a number.

Input
A non-negative integer N.

Output
You must output all the Fibonacci numbers from Fk to F0, where k is the smallest non-negative integer such that Fk ≤ N ≤ Fk+1.

Example
IN: 5

OUT: 5 3 2 1 1 0
If input isn't a Fibonacci number, the series should begin from the closest Fibonacci number less than the input.

IN:  15

OUT: 13 8 5 3 2 1 1 0
If input is 1, the series should be.

IN:  1

OUT: 1 0
Scoring:
This is code-golf, lowest byte count wins.

-}

{- Ported from @shooqie solution -}
p = 0:scanl(+) 1p
f 1 = [1, 0]
f n = reverse$takeWhile(<= n) p

