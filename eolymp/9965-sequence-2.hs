{-

Display the first n numbers of the sequence 1 3 5 7 9 …

Input
A natural number n, where 1≤n≤100

Output
The numbers of the sequence, separated by a space, all on one line.

Examples
Input #1
7

Answer #1
1 3 5 7 9 11 13

-}

import Control.Monad (forM_)

solve :: Int -> IO ()
solve n = do
    forM_ [0..n-1] $ \i -> do
        putStrLn $ show (2*i + 1)

