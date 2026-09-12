{-

Given two integers a and k.
Print the value of the k-th bit (starting from the least significant bit and counting from zero) of the number a.
The answer is either 0 or 1.

Input
Two integers a and k (0≤a≤10^9) are given in a single line.

Output
Print the value of the k-th bit of a.

Examples

Input #1
179 0

Answer #1
1

-}

import Data.Bits

solve :: Int -> Int -> Int
solve a k = if ((a .&. (1 `shiftL` k)) /= 0) then 1 else 0

