{-

Two integers a and k are given. Print the number that is obtained from a by setting the value of the k-th bit to 1.

Input
One line contains two integers a and k (0≤a≤10^9). The least significant bit of a is bit number zero.

Output
Print the number a with the k-th bit set.

Examples

Input #1
5 1

Answer #1
7

-}

import Data.Bits

solve :: Int -> Int -> Int
solve a k = (a .|. (1 `shiftL` k))

