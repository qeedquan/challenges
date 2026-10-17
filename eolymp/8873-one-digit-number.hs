{-

Given an integer n. Print "Ok" if n consists of a single digit, and "No" otherwise.

Input
One integer n (∣n∣≤10^9).

Output
Print "Ok" if n is a single-digit number, and "No" otherwise.

Examples

Input #1
7

Answer #1
Ok

Input #2
-77

Answer #2
No

-}

solve :: Int -> String
solve x = if -9 <= x && x <= 9 then "Ok" else "No"

