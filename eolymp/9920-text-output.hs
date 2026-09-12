{-

The program takes a single line of text as input, such as Integer.
Your task is to output this text three times on one line, with each repetition separated by a plus sign "+".

Input
A single line of text containing only Latin letters.

Output
The required output as specified.

Examples

Input #1
Integer

Answer #1
Integer+Integer+Integer

-}

import Text.Printf

solve :: String -> String
solve s = printf "%s+%s+%s" s s s

