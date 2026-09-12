{-

You are given two integers a and k. Output the number obtained by inverting the kth bit of a.

Input
One line contains two integers a and k (0≤a≤10^9).

Output
Output the number a with its kth bit inverted.

Examples

Input #1
5 1

Answer #1
7

-}

import Data.Bits

solve :: Int -> Int -> Int
solve a k = (a `xor` (1 `shiftL` k))

