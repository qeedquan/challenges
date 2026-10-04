{-

Given a, b, c, compute the value of a^b mod c (1 ≤ a, b, c < 2^63).

Input
Contains multiple test cases. Each test case is given in one line and contains three integers a, b, and c.

Output
For each test case, print on a separate line the value of a^b mod c.

Examples

Input #1
3 2 4
2 10 1000

Answer #1
1
24

-}

import Data.Bits

{- https://en.wikipedia.org/wiki/Exponentiation_by_squaring -}
modexp :: Integer -> Integer -> Integer -> Integer
modexp b 0 m = 1
modexp b e m = t * modexp ((b * b) `mod` m) (shiftR e 1) m `mod` m
               where t = if testBit e 0 then b `mod` m else 1

