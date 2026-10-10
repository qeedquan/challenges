{-

Given the lengths of three segments, determine if they can form a non-degenerate triangle. A triangle is considered non-degenerate if its area is greater than 0.

Input
Three positive integers a,b,c (1≤a,b,c≤1000) — the lengths of three segments.

Output
Print "YES" if the segments can form a non-degenerate triangle, and "NO" otherwise.

Examples

Input #1
5 6 7

Answer #1
YES

Input #2
3 7 4

Answer #2
NO

-}

solve :: Int -> Int -> Int -> String
solve a b c = if 4*a^2*b^2 - (a^2 + b^2 - c^2)^2 > 0 then "YES" else "NO"

