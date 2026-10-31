#!/usr/bin/env python3

"""

Input
A non-empty array of positive integers.

Task
Convert each integer to either binary, octal, decimal or hexadecimal in such a way that each digit (0 to F) is used at most once.

Output
The list of bases that were used to solve the puzzle.

Detailed example
The expected output for [ 16, 17 ] is [ octal, decimal ].

Here is why:

We can't simply use decimal for both numbers, because they both contains a 1.
16 cannot be converted to binary, because its representation in this base (10000) contains several 0's.
17 cannot be converted to binary either, because its representation in this base (10001) contains several 0's and several 1's.
17 cannot be converted to hexadecimal, because its representation in this base (11) consists of two 1's.
Let's consider all remaining possibilities:

               +---------+---------+--------+
               | oct(16) | dec(16) | hex(16)|
               | = 20    | = 16    | = 10   |
+--------------+---------+---------+--------+
| oct(17) = 21 | 20,21   | 16,21   | 10,21  |
| dec(17) = 17 | 20,17   | 16,17   | 10,17  |
+--------------+---------+---------+--------+
The only possible solution is to convert 16 in octal (20) and to keep 17 in decimal (17). This way, the digits 0, 1, 2 and 7 are used exactly once.

Clarifications and rules
The input is guaranteed to lead to a unique solution. Your code is not supposed to support arrays that give several solutions or no solution at all.
You may output the bases in any reasonable format, such as [ "bin","oct","dec","hex" ], [ 'b','o','d','h' ], "BODH", [ 2,8,10,16 ], [ 0,1,2,3 ] etc. But it should be clearly explained in your answer.
The order of the bases in the output must match the order of the input integers.
If that helps, you may assume that the input is sorted from lowest to highest, or from highest to lowest.
This is code-golf, so the shortest answer in bytes wins!
Test cases
You do not have to output the conversion results listed below. They are purely informational.

Input                                  | Output          | Conversion result
---------------------------------------+-----------------+------------------------
[ 119 ]                                | O               | 167
[ 170 ]                                | D               | 170
[ 64222 ]                              | H               | FADE
[ 16, 17 ]                             | O/D             | 20/17
[ 14, 64, 96 ]                         | H/H/D           | E/40/96
[ 34, 37, 94 ]                         | O/D/H           | 42/37/5E
[ 2, 68, 82 ]                          | B/D/H           | 10/68/52
[ 22, 43, 96 ]                         | O/O/O           | 26/53/140
[ 3639, 19086, 57162 ]                 | H/D/H           | E37/19086/DF4A
[ 190, 229, 771 ]                      | O/H/O           | 276/E5/1403
[ 2, 44, 69, 99 ]                      | B/H/H/H         | 10/2C/45/63
[ 75, 207, 218, 357, 385 ]             | H/H/H/D/O       | 4B/CF/DA/357/601
[ 12, 28, 46, 78, 154, 188, 222, 240 ] | D/O/O/D/H/H/H/H | 12/34/56/78/9A/BC/DE/F0
The raw input list is available here.

"""

from itertools import *

# ported @lynn solution
def sbu(a):
    r = ""
    for b in product(*['bxdo'] * len(a)):
        s = ''.join(map(format, a, b))
        if len(s) == len(set(s)):
            r = '/'.join(b)
            r = r.replace("b", "B")
            r = r.replace("x", "H")
            r = r.replace("d", "D")
            r = r.replace("o", "O")
            break
    return r

def main():
    assert(sbu([119]) == "O")
    assert(sbu([170]) == "D")
    assert(sbu([64222]) == "H")
    assert(sbu([16, 17]) == "O/D")
    assert(sbu([14, 64, 96]) == "H/H/D")
    assert(sbu([34, 37, 94]) == "O/D/H")
    assert(sbu([2, 68, 82]) == "B/D/H")
    assert(sbu([22, 43, 96]) == "O/O/O")
    assert(sbu([3639, 19086, 57162]) == "H/D/H")
    assert(sbu([190, 229, 771]) == "O/H/O")
    assert(sbu([2, 44, 69, 99]) == "B/H/H/H")
    assert(sbu([75, 207, 218, 357, 385]) == "H/H/H/D/O")
    assert(sbu([12, 28, 46, 78, 154, 188, 222, 240]) == "D/O/O/D/H/H/H/H")

main()

