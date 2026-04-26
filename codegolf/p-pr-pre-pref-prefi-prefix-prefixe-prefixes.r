#!/usr/bin/env Rscript

comment <- "

Given some finite list, return a list of all its prefixes, including an empty list, in ascending order of their length.

(Basically implementing the Haskell function inits.)

Details
The input list contains numbers (or another type if more convenient).
The output must be a list of lists.
The submission can, but does not have to be a function, any default I/O can be used.
There is a CW answer for all trivial solutions.
This is code-golf, so the shortest code in bytes wins
Example
[] -> [[]]
[42] -> [[],[42]]
[1,2,3,4] -> [[], [1], [1,2], [1,2,3], [1,2,3,4]]
[4,3,2,1] -> [[], [4], [4,3], [4,3,2], [4,3,2,1]]

"

prefix <- function(L) lapply(0:length(L), head, x=L)

prefix(numeric(0))
prefix(c(42))
prefix(c(1, 2, 3, 4))
prefix(c(4, 3, 2, 1))
