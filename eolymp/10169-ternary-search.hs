{-

Find the minimum of the function f(x) = x^2 + ax + b.

Input
Two integers a and b (∣a∣,∣b∣≤10^6).

Output
Print the value of x for which the function f(x) attains its minimum.
Print the answer with exactly two digits after the decimal point.
It is guaranteed that ∣x∣≤100.

Examples

Input #1
-2 -35

Answer #1
1.00

-}

solve :: Int -> Int -> (Float)
solve a b = ((fromIntegral (-a)) * 0.5)

