#!/usr/bin/env python3

"""

Background

The sequence in the title is A245788 "n times the number of 1's in the binary expansion of n" ("times" here means multiplication), which starts like this:

1,   2,   6,   4,   10,  12,  21,  8,   18,  20,
33,  24,  39,  42,  60,  16,  34,  36,  57,  40,
63,  66,  92,  48,  75,  78,  108, 84,  116, 120,
155, 32,  66,  68,  105, 72,  111, 114, 156, 80,
123, 126, 172, 132, 180, 184, 235, 96,  147, 150,
204, 156, 212, 216, 275, 168, 228, 232, 295, 240, ...
Though it is not immediately obvious, this sequence has some duplicates (same number appearing at least twice).
The first duplicate appears at a(22)=a(33)=66. The next ones are a(39)=a(52)=156, and a(44)=a(66)=132.
Note that the duplicates do not appear in ascending order.

It is easy to prove that there exist infinitely many duplicates in this sequence, and I suspect that there exist infinitely many k-plicates (the numbers that appear at least k times in the sequence) as well.
For the record, the first triplicate entry is a(1236)=a(1545)=a(2060)=6180.

Challenge

Produce the sequence of unique duplicates in A245788, in ascending order.
For example, 156 should appear after 132, and 6180 should appear only once in the sequence.
The following is the list of all 124 terms under 10000, generated using this Python program:

66,   132,  156,  228,  264,  300,  312,  420,  435,  456,
528,  588,  600,  624,  804,  840,  870,  912,  1056, 1100,
1164, 1176, 1200, 1220, 1248, 1545, 1572, 1608, 1635, 1680,
1740, 1824, 2050, 2100, 2112, 2196, 2200, 2244, 2316, 2328,
2340, 2352, 2400, 2440, 2496, 2580, 2628, 2820, 3090, 3108,
3140, 3144, 3216, 3270, 3325, 3360, 3480, 3535, 3648, 3690,
4025, 4098, 4100, 4200, 4224, 4260, 4392, 4400, 4488, 4620,
4632, 4656, 4680, 4704, 4800, 4880, 4914, 4992, 5160, 5256,
5640, 5880, 6125, 6180, 6195, 6216, 6280, 6288, 6432, 6510,
6540, 6650, 6660, 6720, 6960, 7070, 7296, 7380, 7608, 8040,
8050, 8196, 8200, 8220, 8292, 8400, 8448, 8490, 8520, 8580,
8784, 8800, 8976, 9228, 9240, 9264, 9312, 9360, 9408, 9600,
9732, 9760, 9828, 9984

Default I/O methods for sequence are allowed:

Take no input, and output the terms infinitely.
Take n as input, and output the n-th term (0- or 1-indexed).
Take n as input, and output the first n terms.

Standard code-golf rules apply. The shortest code in bytes wins.

"""

def gen(n):
    m = {}
    p = []
    for i in range(1, n+1):
        x = i * bin(i).count('1')
        if x in m:
            p.append(x)
        else:
            m[x] = i
    return sorted(set(x for x in p if x <= n))

def main():
    tab = [
        66, 132, 156, 228, 264, 300, 312, 420, 435, 456, 528, 588, 600, 624, 804,
        840, 870, 912, 1056, 1100, 1164, 1176, 1200, 1220, 1248, 1545, 1572, 1608,
        1635, 1680, 1740, 1824, 2050, 2100, 2112, 2196, 2200, 2244, 2316, 2328,
        2340, 2352, 2400, 2440, 2496, 2580, 2628, 2820, 3090, 3108, 3140, 3144,
        3216, 3270, 3325, 3360, 3480, 3535, 3648, 3690, 4025, 4098, 4100, 4200,
        4224, 4260, 4392, 4400, 4488, 4620, 4632, 4656, 4680, 4704, 4800, 4880,
        4914, 4992, 5160, 5256, 5640, 5880, 6125, 6180, 6195, 6216, 6280, 6288,
        6432, 6510, 6540, 6650, 6660, 6720, 6960, 7070, 7296, 7380, 7608, 8040,
        8050, 8196, 8200, 8220, 8292, 8400, 8448, 8490, 8520, 8580, 8784, 8800,
        8976, 9228, 9240, 9264, 9312, 9360, 9408, 9600, 9732, 9760, 9828, 9984
    ]

    assert(gen(tab[-1]) == tab)

main()
