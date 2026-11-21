{-

This is a variant of List prime-factorized natural numbers up to N in ascending order, but the solutions can be very different.

Write a program that outputs prime factorizations of all natural numbers in any order. For example, the output could look like:

1:
4: 2^2
8: 2^3
2: 2^1
3: 3^1
5: 5^1
6: 2^1 3^1
21: 3^1 7^1
9: 3^2
...
Requirements:

You cannot just iterate over the numbers and factor each of them. This is too inefficient.
The output should be as in the example above: On each line the number and the list of its prime factors.
There is no given order in which the number appear in the list. However:
Each number must appear exactly once in the list (explain that your code satisfies this condition).
Edit - remark: Of course the program never finishes. But since (4) requires each number to appear in the list, for any n there is time t such that the list produced by the program within time t contains the factorization of n. (We don't care if t is comparable to the age of our universe or anything else.)

Note: This is not code-golf, it's code-challenge. This puzzle is about clever ideas, not code size. So please don't give the shortest solutions, give commented solutions that are easy to read and where the idea is easily understandable.

-}

import Data.List

{- Ported from @John Tromp solution -}
merge :: [[a]] -> [[a]] -> [[a]]
merge [] ys = ys
merge (x:xs) ys = x : merge ys xs

atmostonefromeach :: [[a]]-> [[a]]
atmostonefromeach = foldr weave undefined

weave :: [a] -> [[a]] -> [[a]]
weave pwrs odds = merge (map (:[]) pwrs) $ foldr (\odd -> merge (odd: (map (:odd) (pwrs)))) undefined odds

primes = nubBy (\x y->gcd x y > 1) [2..]

shw factors = show (product (map (\(p,k)->p^k) factors)) ++ ":" ++ concatMap(\(p,k) -> ' ': show p ++ '^': show k) factors

powers p = map (\x->(p,x)) [1..]

main = mapM_ (putStrLn . shw) $ ([]:) $ atmostonefromeach $ map powers primes
