#!/usr/bin/env python3

r"""

Background
A Davenport-Schinzel sequence has two positive integer parameters d and n. We will denote the set of all Davenport-Schinzel sequences for given parameters by DS(d,n).

Consider all sequences of the natural numbers 1 to n, inclusive, which satisfy:

No two consecutive numbers in the sequence are identical.
There is no subsequence (not necessarily consecutive) of length greater than d, which alternates between two different numbers.
Let L denote the maximum length of such a sequence (given d and n). Then, DS(d,n) is the set of all such sequences with length L.

Some examples might help. Let d = 4, n = 3. The longest possible sequences with these constraints have L = 8. So the following is a member of DS(4,3):

[1, 2, 1, 3, 1, 3, 2, 3]
There are no consecutive identical numbers and there are alternating subsequences of length 4, but not longer ones:

 1  2  1           2
 1  2        1     2
 1        3  1  3
 1        3  1        3
    2     3        2  3
    2           3  2  3
       1  3  1  3
       1  3  1        3
The following examples are not in DS(4,3):

[1, 2, 2, 3, 1, 3, 2, 3]  # Two consecutive 2's.
[1, 2, 1, 3, 1, 3, 2, 1]  # Contains alternating subsequences of length 5.
[1, 2, 1, 3, 1, 3, 2]     # Longer valid sequences for d = 4, n = 3 exist.
For further information see MathWorld and OEIS and the references they list.

The Challenge
Given two positive integers, n and d, generate any Davenport-Schinzel sequence in DS(d,n). Note that these are not generally unique, so output any single valid result.

You may write a program or function, taking input via STDIN (or closest alternative), command-line argument or function argument, and returning the result from the function or printing it to STDOUT (or closest alternative).

You may use any convenient, unambiguous string or list format for output.

This is code golf, so the shortest submission (in bytes) wins.

Sequence Lengths
Since the sequences are not unique, there is not much use for individual examples in this challenge. However, the two general validity problems are fairly easy to check for any output, so the main question is just whether the sequence has the right length (or there's a longer valid sequence). Therefore, here is a list of the known1 L for given d and n:

 \
 d\n 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
   \-----------------------------------------------------------
 1 | 1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1
 2 | 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
 3 | 1  3  5  7  9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39
 4 | 1  4  8 12 17 22 27 32 37 42 47 53 58 64 69 75 81 86 92 98
 5 | 1  5 10 16 22 29 ...
 6 | 1  6 14 23 34 ...
 7 | 1  7 16 28 41 ...
 8 | 1  8 20 35 53 ...
 9 | 1  9 22 40 61 ...
10 | 1 10 26 47 73 ...
You must not hardcode any information from this table into your submission.

1 This table is from 1994, so there may have been more progress since then, but I doubt that any submission will be able to handle even the larger entries in this table in a reasonable amount of time.

"""

from itertools import combinations

"""

https://oeis.org/A002004 (related)

Ported from @Jakube solution

Input is simply in the format 4, 3.

I iteratively create all sequences, which start with 1 and satisfy the two properties, and store them in S.
Since I create them in sorted order (sorted by length [and by values]),
the last entry has to be a Davenport-Schinzel-sequence.
Uses the nice fact, that you can iterate over a list while appending to it.

"""

def DS(d, n):
    r = [[1]]
    for s in r:
        for v in range(1, n + 1):
            if v == s[-1]:
                continue
            for w in combinations(s + [v], d + 1):
                if w[2:] == w[:-2]:
                    break
            else:
                r.append(s+[v])
    return r[-1]

def main():
    for d in range(1, 21):
        for n in range(1, 11):
            print(len(DS(d, n)), end=' ')
        print()

main()
