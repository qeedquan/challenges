{-


Write a function that takes two arguments, x and y, which are two strings containing Roman Numerals without prefix subtraction (so for instance, 14 is represented as XIIII, not XIV). The function must return true if and only if the number represented by x is less than the number represented by y. Do it without actually converting the Roman numerals into regular numbers.

Challenge: handle prefix subtraction as well.

Thanks to cosmologicon for the challenge at r/dailyprogrammer_ideas ! LINK .. If you think you got any challenge worthy for this sub submit it there!

-}

import Data.List

roman _ [] = False
roman [] _ = True
roman (x:xs) (y:ys)
    | index' x == index' y = roman xs ys
    | index' x < index' y  = True
    | index' x > index' y  = False
        where index' x = head $ elemIndices x "IVXLCDM" 

main = do
    print $ roman "X" "VIIII"
    print $ roman "CX" "MX"
    print $ roman "MDX" "MDXI"
    print $ roman "MDX" "MDV"
    print $ roman "MDV" "MDV"

