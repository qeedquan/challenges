{-

Reverse the digits of the given natural number n.

Input
A natural number n.

Output
The number n with its digits in reverse order.

Examples

Input #1
27

Answer #1
72

-}

revdig :: Integer -> Integer
revdig n = go n 0
  where
    go 0 acc = acc
    go x acc = go (x `div` 10) (acc*10 + (x `mod` 10))

