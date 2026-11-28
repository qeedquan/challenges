{-

Write a program that seemingly adds the numbers 2 and 2 and outputs 5. This is an underhanded contest.

Your program cannot output any errors. Watch out for memory holes! Input is optional.

Redefining 2+2 as 5 is not very creative! Don't doublethink it, try something else.

-}

five = let 2+2=5 in 2+2

main :: IO()
main = print five
