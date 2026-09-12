{-


Write a program that tries to guess a number. It is known that the number is a positive integer and does not exceed a given number n.

The guesser is allowed to ask only questions of the form:

? A

which means asking: "Is the guessed number greater than A?".
Only one of two answers can be given to this question: "Yes" or "No".
The number of questions asked should be minimal for any number not exceeding n.

Input
The input contains a single positive integer n (1≤n≤2⋅10^9).

Output
Print the minimal possible number of questions for any number not exceeding n.

Examples

Input #1

15
Answer #1
4

-}

solve :: Int -> Int
solve x = ceiling (logBase 2 (fromIntegral x))

