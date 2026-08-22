{-

Just a simple sorting usage. Create a function that returns the elements of the input-array / list sorted in lexicographical order.

-}

import Data.List

main :: IO ()
main = print (sort [[], [1,2], [1], [1,2,3], [2], [1,3], [2,3], [3]]) >>
       print (sort ["abc", "def"]) >>
       print (sort [-2, -3, 4])
