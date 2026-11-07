#!/usr/bin/env python3

"""

Background
Often, when storing a number in binary with some maximum,
we simply round the maximum to the next power of two then allocate the number of bits neccesary to store the whole range.
Lets call the result of this method S(x,m) where x is the number and m is the maximum.

While not bad, the naive has a few bits of redundancy since some bit patterns could only lead to a number beyond the max. You can exploit this to create a slightly shorter variable-length representation for numbers.

The format
I will define such a format as follows:

Let x be the number we want to represent and m be the max
Let d the the difference between m and the next smaller power of 2. (in other words with the first 1 chopped of the binary representation)
If m is 0, return the empty string
If x is less than or equal to d:
Output "0" followed by f(x, m)
Otherwise:
Output "1" followed by the log2(m)-bit binary representation of x-d-1.
Python translation:

def d(x): return x-(1<<x.bit_length()-1)

def f(x, m):
    if m==0:
        return ''
    if m==1: # edge cases needed to deal with the fact that binary coding in python produces at least one 0 even if you specify 0 digits
        return f'{x}'
    if x<=d(m):
        return '0'+f(x,d(m))
    else:
        return f'1{x-d(m)-1:0>{m.bit_length()-1}b}')
Challenge
Output a pair of functions f(x,m) and f'(y,m) that convert to and from compressed binary representation for a given maximum.

You may assume m>3 and x<=m.

The binary representation can be as a string, integer, list of ints, decimal coded binary, or anything else reasonable.

If you prefer you can take m+1 as input instead of m. (exclusive maximum)

Test Cases
Rows are X, columns are M

     5      6      7      8      9      10     11     12     13     14     15     16     17     18     19     20     21     22     23
     ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------
    0 00     00     000    0      00     00     000    00     000    000    0000   0      00     00     000    00     000    000    0000
    1 01     010    001    1000   01     010    001    0100   001    0010   0001   10000  01     010    001    0100   001    0010   0001
    2 100    011    010    1001   1000   011    010    0101   0100   0011   0010   10001  10000  011    010    0101   0100   0011   0010
    3 101    100    011    1010   1001   1000   011    0110   0101   0100   0011   10010  10001  10000  011    0110   0101   0100   0011
    4 110    101    100    1011   1010   1001   1000   0111   0110   0101   0100   10011  10010  10001  10000  0111   0110   0101   0100
    5 111    110    101    1100   1011   1010   1001   1000   0111   0110   0101   10100  10011  10010  10001  10000  0111   0110   0101
    6        111    110    1101   1100   1011   1010   1001   1000   0111   0110   10101  10100  10011  10010  10001  10000  0111   0110
    7               111    1110   1101   1100   1011   1010   1001   1000   0111   10110  10101  10100  10011  10010  10001  10000  0111
    8                      1111   1110   1101   1100   1011   1010   1001   1000   10111  10110  10101  10100  10011  10010  10001  10000
    9                             1111   1110   1101   1100   1011   1010   1001   11000  10111  10110  10101  10100  10011  10010  10001
   10                                    1111   1110   1101   1100   1011   1010   11001  11000  10111  10110  10101  10100  10011  10010
   11                                           1111   1110   1101   1100   1011   11010  11001  11000  10111  10110  10101  10100  10011
   12                                                  1111   1110   1101   1100   11011  11010  11001  11000  10111  10110  10101  10100
   13                                                         1111   1110   1101   11100  11011  11010  11001  11000  10111  10110  10101
   14                                                                1111   1110   11101  11100  11011  11010  11001  11000  10111  10110
   15                                                                       1111   11110  11101  11100  11011  11010  11001  11000  10111
   16                                                                              11111  11110  11101  11100  11011  11010  11001  11000
   17                                                                                     11111  11110  11101  11100  11011  11010  11001
   18                                                                                            11111  11110  11101  11100  11011  11010
   19                                                                                                   11111  11110  11101  11100  11011
   20                                                                                                          11111  11110  11101  11100
   21                                                                                                                 11111  11110  11101
   22                                                                                                                        11111  11110
   23                                                                                                                               11111

"""

def d(x):
    return x - (1<<x.bit_length() - 1)

def f(x, m):
    if m == 0:
        return ''

    # edge cases needed to deal with the fact that binary coding in python produces at least one 0 even if you specify 0 digits
    if m == 1:
        return f'{x}'
    
    if x <= d(m):
        return '0' + f(x, d(m))
    return f'1{x - d(m) - 1:0>{m.bit_length()-1}b}'

for r in range(0, 23):
    for c in range(5, 23):
        print(f(r, c), end=' ')
    print()
