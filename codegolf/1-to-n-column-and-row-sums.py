#!/usr/bin/env python3

"""

Inspiration
There is a problem on the most recent AMC 12B test, the one held on November 16, 2022, which goes like this:

(AMC 12B 2022, Question 17)
How many 4×4 arrays whose entries are 0s and 1s are there such that the row sums (the sum of the entries in each row) are
1, 2, 3, and 4, in some order, and the column sums (the sum of the entries in each column) are also  1, 2, 3, and 4, in some order?

For example, the array
[1 1 1 0]
[0 1 1 0]
[1 1 1 1]
[0 1 0 0]

satisfies the condition.

(If any of you are curious the answer is 576.)

Task
Your task is, given some positive integer N, output all N×N binary matrices such that the row sums are 1,2,…,N in some order, as well as the column sums.

Test Cases
N ->
Output
-------
1 ->
1

2 ->
1 1
1 0

1 1
0 1

1 0
1 1

0 1
1 1

3 ->
1 0 0
1 1 0
1 1 1

1 0 0
1 0 1
1 1 1

0 1 0
1 1 0
1 1 1

0 1 0
0 1 1
1 1 1

0 0 1
1 0 1
1 1 1

0 0 1
0 1 1
1 1 1

1 0 0
1 1 1
1 1 0

1 0 0
1 1 1
1 0 1

0 1 0
1 1 1
1 1 0

0 1 0
1 1 1
0 1 1

0 0 1
1 1 1
1 0 1

0 0 1
1 1 1
0 1 1

1 1 0
1 0 0
1 1 1

1 1 0
0 1 0
1 1 1

1 0 1
1 0 0
1 1 1

1 0 1
0 0 1
1 1 1

0 1 1
0 1 0
1 1 1

0 1 1
0 0 1
1 1 1

1 1 0
1 1 1
1 0 0

1 1 0
1 1 1
0 1 0

1 0 1
1 1 1
1 0 0

1 0 1
1 1 1
0 0 1

0 1 1
1 1 1
0 1 0

0 1 1
1 1 1
0 0 1

1 1 1
1 0 0
1 1 0

1 1 1
1 0 0
1 0 1

1 1 1
0 1 0
1 1 0

1 1 1
0 1 0
0 1 1

1 1 1
0 0 1
1 0 1

1 1 1
0 0 1
0 1 1

1 1 1
1 1 0
1 0 0

1 1 1
1 1 0
0 1 0

1 1 1
1 0 1
1 0 0

1 1 1
1 0 1
0 0 1

1 1 1
0 1 1
0 1 0

1 1 1
0 1 1
0 0 1

Note
The reason why I'm not doing a challenge on simply outputting the number of matrices that satisfy the condition is because there is a pretty simple formula to calculate that number. Brownie points if you can figure out that formula, and why it works!

This is code-golf, so shortest code in bytes wins!

"""

from itertools import *

"""

Ported from @Yousername solution

Based on my comment to this challenge.
First generates a right triangular shaped matrix of 1s, then makes all possible different permutations of rows and columns.
Outputs a list of 2D lists.

"""

def f(n):
    p = [[1]*i + [0]*(n-i) for i in range(1, n+1)]
    return [[[k[l] for l in j] for k in i] for j in permutations(range(n)) for i in permutations(p)]

def main():
    assert(f(1) == [[[1]]])
    assert(f(2) == [[[1, 0], [1, 1]], [[1, 1], [1, 0]], [[0, 1], [1, 1]], [[1, 1], [0, 1]]])
    assert(f(3) == [[[1, 0, 0], [1, 1, 0], [1, 1, 1]], [[1, 0, 0], [1, 1, 1], [1, 1, 0]], [[1, 1, 0], [1, 0, 0], [1, 1, 1]], [[1, 1, 0], [1, 1, 1], [1, 0, 0]], [[1, 1, 1], [1, 0, 0], [1, 1, 0]], [[1, 1, 1], [1, 1, 0], [1, 0, 0]], [[1, 0, 0], [1, 0, 1], [1, 1, 1]], [[1, 0, 0], [1, 1, 1], [1, 0, 1]], [[1, 0, 1], [1, 0, 0], [1, 1, 1]], [[1, 0, 1], [1, 1, 1], [1, 0, 0]], [[1, 1, 1], [1, 0, 0], [1, 0, 1]], [[1, 1, 1], [1, 0, 1], [1, 0, 0]], [[0, 1, 0], [1, 1, 0], [1, 1, 1]], [[0, 1, 0], [1, 1, 1], [1, 1, 0]], [[1, 1, 0], [0, 1, 0], [1, 1, 1]], [[1, 1, 0], [1, 1, 1], [0, 1, 0]], [[1, 1, 1], [0, 1, 0], [1, 1, 0]], [[1, 1, 1], [1, 1, 0], [0, 1, 0]], [[0, 0, 1], [1, 0, 1], [1, 1, 1]], [[0, 0, 1], [1, 1, 1], [1, 0, 1]], [[1, 0, 1], [0, 0, 1], [1, 1, 1]], [[1, 0, 1], [1, 1, 1], [0, 0, 1]], [[1, 1, 1], [0, 0, 1], [1, 0, 1]], [[1, 1, 1], [1, 0, 1], [0, 0, 1]], [[0, 1, 0], [0, 1, 1], [1, 1, 1]], [[0, 1, 0], [1, 1, 1], [0, 1, 1]], [[0, 1, 1], [0, 1, 0], [1, 1, 1]], [[0, 1, 1], [1, 1, 1], [0, 1, 0]], [[1, 1, 1], [0, 1, 0], [0, 1, 1]], [[1, 1, 1], [0, 1, 1], [0, 1, 0]], [[0, 0, 1], [0, 1, 1], [1, 1, 1]], [[0, 0, 1], [1, 1, 1], [0, 1, 1]], [[0, 1, 1], [0, 0, 1], [1, 1, 1]], [[0, 1, 1], [1, 1, 1], [0, 0, 1]], [[1, 1, 1], [0, 0, 1], [0, 1, 1]], [[1, 1, 1], [0, 1, 1], [0, 0, 1]]])

main()
