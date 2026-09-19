{-

Display the first n numbers of the sequence 1 4 9 16 25 …

Input
A natural number n, where 1≤n≤100

Output
The numbers of the sequence, separated by a space, all on one line.

Examples
Input #1
7

Answer #1
1 4 9 16 25 36 49

-}

import Control.Monad (forM_)

solve :: Int -> IO ()
solve n = do
    forM_ [1..n] $ \i -> do
        putStrLn $ show (i*i)

