#!/usr/bin/env python3

"""

Given a positive integer n, output the 2^n binary sequences of length n sorted in the following precise ordering.

Test cases:

0:

0 or 1 (defining this is a matter of debate)
1:

0
1
2:

00
01
10
11
3:

000
001
010
100
011
101
110
111
4:

0000
0001
0010
0100
1000
0011
0101
1001
0110
1010
1100
0111
1011
1101
1110
1111
etc.

Additionally, the pattern of combinatorics is related to Pascal's Triangle.

0:

1 (this is given regardless of the definition given to 2^0)
1:

1
1
2:

1
2
1
3:

1
3
3
1
4:

1
4
6
4
1
etc.

"""

from itertools import permutations

# Ported from @Daniel solution
def binseq(number):
    results = []
    for ones_count in range(number + 1):
        value = "0"*(number - ones_count) + "1"*ones_count
        unique_permutations = {"".join(chars) for chars in permutations(value)}
        results.extend(sorted(unique_permutations, key=lambda item: item[::-1], reverse=True))
    
    print(number)
    for line in results:
        print(line)
    print()

def main():
    binseq(2)
    binseq(3)
    binseq(4)

main()
