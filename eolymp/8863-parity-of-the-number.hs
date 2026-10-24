{-

Check the given integer n for parity.

Input
One integer n.

Output
Print 1 if the number n is even and 0 otherwise.

Examples
Input #1
7

Answer #1
0

Input #2
-2

Answer #2
1

-}

import Data.Bits

parity :: Int -> (Int)
parity n = ((n .&. 1) `xor` 1)

