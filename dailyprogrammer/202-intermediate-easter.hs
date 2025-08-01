{-

Description:
Given the year - Write a program to figure out the exact date of Easter for that year.

Input:
A year.

Output:
The date of easter for that year.

Challenge:
Figure out easter for 2015 to 2025.

-}

import Data.Time.Calendar.Easter
import Data.Time

main = mapM_ (putStrLn . formatTime defaultTimeLocale "%-m/%-d/%Y". gregorianEaster) [2015..2025]
