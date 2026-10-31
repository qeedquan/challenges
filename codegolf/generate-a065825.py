#!/usr/bin/env python3

"""

(This is A065825.) The sequence defaults apply, so you can pick another format other than this one.

Given an input integer n, find the smallest number k so that there exists an n-item subset of {1,...,k} where no three items form an arithmetic progression.

Procedure
Here, we calculate A065825(9).

We assume you have already looped from 1 to 19, and k=20 (it's just an example).

1. Generate a range from 1 to k.
[1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20]
2. Pick n items from that sequence, following the original order of the sequence.
[1 2 6 7 9 14 15 18 20]
3. No 3 items form an arithmetic progression.
If a sequence has arithmetic progression, it basically means the sequence has the same step between every two consecutive items.

For example, the sequence of positive even numbers ([2 4 6 8 ...]) has a consistent step (i.e. 4-2=2, and 6-4=2, etc.), so it has arithmetic progression.

The Fibonacci sequence ([1 1 2 3 5 8 13 21 ...]) does not have arithmetic progression, since it does not have a consistent step. (3-2=1, 5-3=2, 8-5=3, etc.)

As an example, let's pick 3 items from our generated sequence.

[1 2 6 [7 9 14] 15 18 20]
The picked 3-item sequence does not have arithmetic progression, since the differences are respectively 9-7=2 and 14-9=5.

This has to apply to every 3-item pair:

[[1 2 6] 7 9 14 15 18 20] (2 -1 =1, 6 -2 =4)
[1 [2 6 7] 9 14 15 18 20] (6 -2 =4, 7 -6 =1)
[1 2 [6 7 9] 14 15 18 20] (7 -6 =1, 9 -7 =2)
[1 2 6 [7 9 14] 15 18 20] (9 -7 =2, 14-9 =5)
[1 2 6 7 [9 14 15] 18 20] (14-9 =5, 15-14=1)
[1 2 6 7 9 [14 15 18] 20] (15-14=1, 18-15=3)
[1 2 6 7 9 14 [15 18 20]] (18-15=3, 20-18=2)
Here are some examples of picking non-consecutive items from the output sequence:

[1 [2] 6 [7] 9 [14] 15 18 20] (7-2=5,14-7=7)
[[1] 2 6 [7] [9] 14 15 18 20] (7-1=6,9 -7=2)
If the above is satisfied for k, then k is a valid output for A065825(9).

Test cases
Here is a reference program I use to check my test cases.

n       a(n)
1       1
2       2
3       4
4       5
5       9
6       11
7       13
8       14
9       20

"""

# https://oeis.org/A065825
def find(n):
    if n < 1:
        return 0

    m = 1
    while True:
        b = format(m, "b")
        c = b.count("1")
        for i in range(c//n, m):
            if not ((m >> i) & m & (m << i) < 1):
                break
        else:
            return len(b)
        m += 1

def main():
    tab = [1, 2, 4, 5, 9, 11, 13, 14, 20]

    for i in range(len(tab)):
        assert(find(i + 1) == tab[i])

main()
