#!/usr/bin/env python3

"""

Given a nonempty list of positive integers (x,y,z,…), your job is to determine the number of unique values of ±x±y±z±…
For example, consider the list (1,2,2). There are eight possible ways to create sums:

+1+2+2→+5
+1+2−2→+1
+1−2+2→+1
+1−2−2→−3
−1+2+2→+3
−1+2−2→−1
−1−2+2→−1
−1−2−2→−5
There are six unique sums {5,−5,1,−1,3,−3}, so the answer is 6.

Test Cases
[1, 2] => 4
[1, 2, 2] => 6
[s]*n => n+1
[1, 2, 27] => 8
[1, 2, 3, 4, 5, 6, 7] => 29
[3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5] => 45
[1, 7, 2, 8, 3, 1, 6, 8, 10, 9] => 56
[93, 28, 92, 100, 43, 66, 2, 98, 2, 52, 57, 75, 39, 77, 45, 15, 13, 82, 81, 20, 68, 14, 5, 3, 72, 56, 57, 1, 23, 25, 76, 59, 60, 71, 71, 24, 1, 3, 72, 84, 72, 28, 83, 62, 66, 45, 21, 28, 49, 57, 70, 3, 44, 47, 1, 54, 53, 56, 36, 20, 99, 9, 89, 74, 1, 14, 68, 47, 99, 61, 46, 26, 69, 21, 20, 82, 23, 39, 50, 58, 24, 22, 48, 32, 30, 11, 11, 48, 90, 44, 47, 90, 61, 86, 72, 20, 56, 6, 55, 59] => 4728

Reference solution (optimizes for speed and not size).
import Data.List (nub)

expand :: [Int] -> Int -> [Int]
expand xs x = nub $ do n <- xs
                       [n + x, n - x]

solve :: [Int] -> Int
solve = length . foldl expand [0]

main :: IO ()
main = putStr $ unlines $ [show x ++ " => " ++ show (solve x)
                           | x <- [[1, 2],
                                   [1, 2, 2],
                                   [1, 1, 1, 1, 1],
                                   [1, 2, 3, 4, 5, 6, 7],
                                   [93, 28, 92,100, 43, 66,  2, 98,  2, 52, 57, 75, 39, 77, 45, 15, 13, 82, 81, 20,
                                    68, 14,  5,  3, 72, 56, 57,  1, 23, 25, 76, 59, 60, 71, 71, 24,  1,  3, 72, 84,
                                    72, 28, 83, 62, 66, 45, 21, 28, 49, 57, 70,  3, 44, 47,  1, 54, 53, 56, 36, 20,
                                    99,  9, 89, 74,  1, 14, 68, 47, 99, 61, 46, 26, 69, 21, 20, 82, 23, 39, 50, 58,
                                    24, 22, 48, 32, 30, 11, 11, 48, 90, 44, 47, 90, 61, 86, 72, 20, 56,  6, 55, 59]]
                          ]

If you can't handle the last case because you use a brute-force method or similar, that's fine.

Scoring
This is code-golf, so the shortest valid solution (measured in bytes) wins.

"""

"""

@xnor

This answer calculates the unique sums (not sign-swapping) like many other answers. Each bit in k corresponds to a sum. k<<n adds n to each sum. Oring with k stores these new sums in k whilst keeping all the previous ones, and duplicated Sims are not recorded 

"""
def sign_swap_sums(a):
    k = 1
    for v in a:
        k |= k << v
    return bin(k).count('1')

def main():
    assert(sign_swap_sums([1, 2]) == 4)
    assert(sign_swap_sums([1, 2, 2]) == 6)
    assert(sign_swap_sums([4, 4, 4, 4]) == 5)
    assert(sign_swap_sums([1, 2, 27]) == 8)
    assert(sign_swap_sums([1, 2, 3, 4, 5, 6, 7]) == 29)
    assert(sign_swap_sums([3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]) == 45)
    assert(sign_swap_sums([1, 7, 2, 8, 3, 1, 6, 8, 10, 9]) == 56)
    assert(sign_swap_sums([93, 28, 92, 100, 43, 66, 2, 98, 2, 52, 57, 75, 39, 77, 45, 15, 13, 82, 81, 20, 68, 14, 5, 3, 72, 56, 57, 1, 23, 25, 76, 59, 60, 71, 71, 24, 1, 3, 72, 84, 72, 28, 83, 62, 66, 45, 21, 28, 49, 57, 70, 3, 44, 47, 1, 54, 53, 56, 36, 20, 99, 9, 89, 74, 1, 14, 68, 47, 99, 61, 46, 26, 69, 21, 20, 82, 23, 39, 50, 58, 24, 22, 48, 32, 30, 11, 11, 48, 90, 44, 47, 90, 61, 86, 72, 20, 56, 6, 55, 59]) == 4728)

main()
