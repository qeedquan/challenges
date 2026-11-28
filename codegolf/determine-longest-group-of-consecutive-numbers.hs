{-

INPUT:

10 random numbers
each number is greater than 0 and less than 100
list of numbers is presorted, lowest to highest
the list will not contain any duplicate numbers
CHALLENGE:

Write a function that would take in the numbers, and return the count of the longest group of consecutive numbers.

EXAMPLE OUTPUT:

1 2 33 44 55 66 77 88 90 98 => return of the function would be 2
1 3 23 24 30 48 49 70 75 80 => return of the function would be 2
6 9 50 51 52 72 81 83 90 92 => return of the function would be 3

-}

import Data.List

{- Ported from @JB solution -}
longestGroup = maximum.map length.group.zipWith(-)[1..]

