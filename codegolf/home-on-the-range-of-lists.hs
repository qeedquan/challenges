{-

This challenge is simply to return a list of lists of integers, similar to the Python range function, except that each successive number must be that deep in lists.

Rules:

Create a program or a non-anonymous function
It should return or print the result
The result should be returned in a list (of lists) or array (of arrays)
If the parameter is zero, return an empty list
This should be able to handle an integer parameter 0 <= n < 70.
(recursive solutions blow up pretty fast)
The function should be callable with only the one parameter.
Other behavior is undefined.
This is code golf, so shortest code wins.
Example Call:

rangeList(6)
> [0, [1, [2, [3, [4, [5]]]]]]
Test Cases:

0  => []
1  => [0]
2  => [0, [1]]
6  => [0, [1, [2, [3, [4, [5]]]]]]
26 => [0, [1, [2, [3, [4, [5, [6, [7, [8, [9, [10, [11, [12, [13, [14, [15, [16, [17, [18, [19, [20, [21, [22, [23, [24, [25]]]]]]]]]]]]]]]]]]]]]]]]]]
69 => [0, [1, [2, [3, [4, [5, [6, [7, [8, [9, [10, [11, [12, [13, [14, [15, [16, [17, [18, [19, [20, [21, [22, [23, [24, [25, [26, [27, [28, [29, [30, [31, [32, [33, [34, [35, [36, [37, [38, [39, [40, [41, [42, [43, [44, [45, [46, [47, [48, [49, [50, [51, [52, [53, [54, [55, [56, [57, [58, [59, [60, [61, [62, [63, [64, [65, [66, [67, [68]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
EDIT: isaacg's answer is the shortest so far. I'll update the accepted answer if anyone finds a shorter one in a language that existed at the posting of the challenge. Thanks for playing!

-}

{-

Ported from @ბიმო solution

These nested lists are the same data-structure as rooted Trees, except that they can also be empty.
Hence, we can use a list of them - also called a Forest to represent them.

Explanation
First of all we need to implement the Tree data type:

data Tree = Node [Tree] Int
From there it's just recursion using two parameters m (counting up) and n to keep track when to terminate:

m ! n= [ Node ((m+1)!n) m| m<n ]

-}

data Tree = Node[Tree]Int

ranges = (0!)
m!n = [Node((m + 1) ! n) m | m < n]

instance Show Tree where
    show (Node ts x) = show x ++ " : " ++ show ts

main = mapM_ (print . ranges . read) . lines =<< getContents
