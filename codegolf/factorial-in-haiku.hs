{-

Task
Create a program that calculates the factorial of a number using no built-in factorial functions. Easy? The catch is that you must write your entire program (including testing it) in haiku form.

https://xkcd.com/554/

You can use as many haikus as you need, but when pronounced, they must follow the 5-7-5 syllable format.

Scoring
This is a popularity-contest, so you must get the most upvotes to win. Your program must consist of at least one full haiku, and all haikus must be complete.

When reading code, the first line of each haiku will have 5 syllables, the second will have 7, and the third will have 5.

-}

fact :: Int -> Int          -- fact is Int to Int
fact x = product (range x)  -- fact x is product range x
range x = [1..x]            -- range x is 1 [pause] x

