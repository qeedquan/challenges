#!/usr/bin/env Rscript

comment <- "

Here's the challenge. Write some code to output all the integers in a range. Sounds easy, but here's the tricky part. It will start with the lowest number, then the highest. Then the lowest number which isn't yet in the array. Then the highest which isn't yet in it.
Example:

Lets take 1 to 5 as our start

The numbers are [1, 2, 3, 4, 5].

We take the first, so [1]. Remaining numbers are [2, 3, 4, 5]. We take the last, new array is [1, 5]. Remaining numbers are [2, 3, 4]. We take the first, new array is [1, 5, 2]. Remaining numbers are [3, 4]. We take the last, new array is [1, 5, 2, 4]. Remaining numbers are [3]. We take the first, new array is [1, 5, 2, 4, 3]. No numbers remaining, we're done. Output [1, 5, 2, 4, 3]
Rules:

    This is code golf, write it in the fewest bytes, any language.
    No standard loopholes.
    Links to an online interpreter, please? (E.g. https://tio.run/)
    Two inputs, both integers. Low end of range, and high end of range.
    I don't mind what the data type of the output is, but it must show the numbers in the correct order.

Examples

Low: 4 High: 6 Result: 4 6 5

Low: 1 High: 5 Result: 1 5 2 4 3

Low: -1 High: 1 Result: -1 1 0

Low: -1 high: 2 Result: -1 2 0 1

Low: -50 High: 50 Result: -50 50 -49 49 -48 48 -47 47 -46 46 -45 45 -44 44 -43 43 -42 42 -41 41 -40 40 -39 39 -38 38 -37 37 -36 36 -35 35 -34 34 -33 33 -32 32 -31 31 -30 30 -29 29 -28 28 -27 27 -26 26 -25 25 -24 24 -23 23 -22 22 -21 21 -20 20 -19 19 -18 18 -17 17 -16 16 -15 15 -14 14 -13 13 -12 12 -11 11 -10 10 -9 9 -8 8 -7 7 -6 6 -5 5 -4 4 -3 3 -2 2 -1 1 0

Happy golfing!

"

x465 <- function(a, b) {
	return rbind(a:b, b:a)[a:b-a+1]
}


