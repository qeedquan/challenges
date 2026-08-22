#!/usr/bin/env Rscript

comment <- "

Related: Validate a stem-and-leaf plot

Input
A non-empty list of positive integers. If needed, they can be taken as strings. You cannot assume it is sorted.

Output
A stem-and-leaf plot of the numbers. In a this stem-and-leaf plot, numbers are ordered into stems by tens, then all numbers that fit into that stem have their ones value placed into the stem, and then all are sorted. In this challenge, newlines separate the stems, and spaces separate the stems from the leaves.

You may either include or exclude all empty stems that are between non-empty stems.

Test Cases
(lists can be taken in your language's list default, I used JSON for the below)

Including empty stems:

[1, 2, 3, 3, 3, 3, 3, 10, 15, 15, 18, 1, 100]

0 11233333
1 0558
2
3
4
5
6
7
8
9
10 0

[55, 59, 49, 43, 58, 59, 54, 44, 49, 51, 44, 40, 50, 59, 59, 59]

4 034499
5 0145899999

[10000, 10100]

1000 0
1001
1002
1003
1004
1005
1006
1007
1008
1009
1010 0
Excluding empty stems:

[1, 2, 3, 3, 3, 3, 3, 10, 15, 15, 18, 1, 100]

0 11233333
1 0558
10 0

[55, 59, 49, 43, 58, 59, 54, 44, 49, 51, 44, 40, 50, 59, 59, 59]

4 034499
5 0145899999

[10000, 10100]

1000 0
1010 0

"

stem(c(1, 2, 3, 3, 3, 3, 3, 10, 15, 15, 18, 1, 100), scale=2)
stem(c(55, 59, 49, 43, 58, 59, 54, 44, 49, 51, 44, 40, 50, 59, 59, 59), atom=6)
stem(c(10000, 10100), scale=4)
stem(c(1, 2, 3, 3, 3, 3, 3, 10, 15, 15, 18, 1, 100), scale=2)
stem(c(55, 59, 49, 43, 58, 59, 54, 44, 49, 51, 44, 40, 50, 59, 59, 59), atom=6)
stem(c(10000, 10100))
