{-

Write a function reverse which reverses a list (or in clojure's case, any list-like data structure)

(the dedicated builtin(s) functionalities are deactivated)

-}

reverseList xs = foldl (\ x y -> y:x) [] xs

