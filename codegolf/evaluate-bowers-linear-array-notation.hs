{-

Background
Bowers' Linear Array Notation (https://googology.fandom.com/wiki/Array_notation) is a very large number notation.
It consists of zero or more positive integers separated by commas inside curly braces, e.g.  {3,4,1,1,2}.
Here are the rules, where # represents an arbitrary sequence of positive integers (an entry is a number in an array):

1.{}=1
2.{a}=a
3.{a,b}=ab
4.{#,1}={#}
5.{a,1,#}=a
6.{a,b,1,…,1,c,#}={a,a,…,a,{a,b−1,1,…,1,c,#},c−1,#}

(if the third entry is  1, all entries before the last 1 preceding non-1 entry c become the first entry,
the last of the  1's becomes the original array with the second entry decreased by 1 and the said non-1
entry is decreased by 1)

7. If none of the rules apply, then  (c>1){a,b,c,#}={a,{a,b−1,c,#},c−1,#}

Task
Given a (possibly empty) list of positive integers, interpret it as Bowers' Linear Array Notation and evaluate it into a single number.

It is OK if your program gives wrong answers for large values due to the limits (bounds and/or precision) of your language's number type, as long as the underlying algorithm is correct.

Standard code-golf rules apply. The shortest code in bytes wins.

-}

import Data.List

-- https://googology.fandom.com/wiki/Array_notation
an :: [Integer] -> Integer
-- Rule 1.
an [a] = a 
an [a,b] = a^b 
-- Rule 2.
an l | last l == 1 = an (init l)
-- Rule 3.
an (a:1:_) = a
-- Rule 4.
an (a:b:1:l) = an (a:a:map (const a) ones ++ [an (a:b-1:l)] ++ [c-1] ++ rest)
  where
    (ones,c:rest) = span (==1) l
-- Rule 5.
an (a:b:c:l) = an (a:an (a:b-1:c:l):c-1:l)

main :: IO ()
main = do
  let exampleList = [2, 3, 1, 4]
  let result = an exampleList
  putStrLn $ show exampleList ++ " = " ++ show result
