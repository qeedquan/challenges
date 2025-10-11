{-

Debug   function getSumOfDigits that takes positive integer to calculate sum of it's digits. Assume that argument is an integer.

Example
123  => 6
223  => 7
1337 => 14

-}

digsum 0 = 0
digsum n = (n `mod` 10) + digsum(n `div` 10)
