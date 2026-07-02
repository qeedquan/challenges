#!/usr/bin/env python3

"""

The binary-square-diagonal-sequence is constructed as follows:

Take the sequence of positive natural numbers:
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, ...
Convert each number to binary:

1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10000, 10001, ...
Concatenate them:

11011100101110111100010011010101111001101111011111000010001 ...
Starting with n=1, generate squares with increasing side-length n which are filled left-to-right, top-to-bottom with the elements of the above sequence:

1
1 0
1 1
1 0 0
1 0 1
1 1 0
1 1 1 1
0 0 0 1
0 0 1 1
0 1 0 1
0 1 1 1 1
0 0 1 1 0
1 1 1 1 0
1 1 1 1 1
0 0 0 0 1
...
Take the diagonal (top left to bottom right) of each square:

1, 11, 100, 1011, 00111, ...
Convert to decimal (ignoring leading zeros):

1, 3, 4, 11, 7, ...
Task
Write a program or function which outputs the sequence in one of the following ways:

Return or print the sequence infinitely.
Given input i, return or print the first i elements of the sequence.
Given input i, return or print the ith element of the sequence (either 0 or 1 indexed).
Please state in your answer which output format you choose.

This is code-golf, the shortest answer in each language wins.

Test cases
Here are the first 50 elements of the sequence:

1,3,4,11,7,29,56,141,343,853,321,3558,8176,3401,21845,17129,55518,134717,151988,998642,1478099,391518,7798320,8530050,21809025,61485963,66846232,54326455,221064493,256373253,547755170,4294967295,1875876391,2618012644,24710258456,6922045286,132952028155,217801183183,476428761596,51990767390,687373028085,1216614609441,7677215985062,15384530216172,22714614479340,15976997237789,0,256145539974868,532024704777005,601357273478135

"""

def gen(n):
    r = []
    i = 1
    x = 1
    s = ""
    while len(r) < n:
        s += bin(i)[2:]
        i += 1
        if s[x*x:]:
            r.append(int(s[:x*x:x+1], 2))
            s = s[x*x:]
            x += 1
    return r

def main():
    tab = [1, 3, 4, 11, 7, 29, 56, 141, 343, 853, 321, 3558, 8176, 3401, 21845, 17129, 55518, 134717, 151988, 998642, 1478099, 391518, 7798320, 8530050, 21809025, 61485963, 66846232, 54326455, 221064493, 256373253, 547755170, 4294967295, 1875876391, 2618012644, 24710258456, 6922045286, 132952028155, 217801183183, 476428761596, 51990767390, 687373028085, 1216614609441, 7677215985062, 15384530216172, 22714614479340, 15976997237789, 0, 256145539974868, 532024704777005, 601357273478135]

    assert(gen(len(tab)) == tab)

main()
