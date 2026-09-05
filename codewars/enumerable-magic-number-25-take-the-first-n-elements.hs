{-

Create a method take that accepts a list/array and a number n, and returns a list/array array of the first n elements from the list/array.

-}

main :: IO()
main = print (take 3 [1, 2, 3, 4, 5]) >>
       print (take 0 [33, 33, 33])
