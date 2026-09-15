#!/usr/bin/env python3

"""

Write a program that, given an ASCII binary matrix of 0's and 1's like this:

0000000000000000
0000000000000000
0000011001110000
0000001111010000
0000011001110000
0000011011100000
0000000000110000
0000101000010000
0000000000000000
0000000000000000
0000000000000000
Outputs the smallest cropped sub-matrix that still contains all 1's (that is, remove all borders of 0's):

01100111
00111101
01100111
01101110
00000011
10100001

"""

def trim(bins):
    rows = bins.split('\n')
    ones = [i for i in range(len(rows)) if rows[i].find('1') > -1]
    ymin = min(ones)
    ymax = max(ones) + 1
    rows = rows[ymin:ymax]
    xmin = min([row.find('1') for row in rows])
    xmax = max([row.rfind('1') for row in rows]) + 1
    return '\n'.join([row[xmin:xmax] for row in rows])

print(trim("""
0000000000000000
0000000000000000
0000011001110000
0000001111010000
0000011001110000
0000011011100000
0000000000110000
0000101000010000
0000000000000000
0000000000000000
0000000000000000
"""))

