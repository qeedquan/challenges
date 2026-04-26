#!/usr/bin/env python3

"""

Your task is to generate the nth term of the RATS sequence, where n is the input. The RATS sequence is also known as the Reverse Add Then Sort sequence. This sequence can also be found here: http://oeis.org/A004000.

test cases:

0 > 1
1 > 2
2 > 4
3 > 8
4 > 16
5 > 77
6 > 145
7 > 668
For example, the output for 5 is 77 because 16 + 61 = 77. After this the 77 is sorted.

Shortest submission wins. This is my first challenge so i hope this is not a duplicate or something.

"""

# https://oeis.org/A004000
def rats(n):
    l = [0, 1]
    for n in range(2, n+1):
        x = str(l[n - 1])
        l.append(int(''.join(sorted(str(int(x) + int(x[::-1]))))))
    return l[1:]

def main():
    tab = [1, 2, 4, 8, 16, 77, 145, 668, 1345, 6677, 13444, 55778, 133345, 666677, 1333444, 5567777, 12333445, 66666677, 133333444, 556667777, 1233334444, 5566667777, 12333334444, 55666667777, 123333334444, 556666667777, 1233333334444, 5566666667777, 12333333334444]
    
    assert(rats(len(tab)) == tab)

main()
