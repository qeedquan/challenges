#!/usr/bin/env python3

"""

Challenge :
Count the number of ones 1 in the binary representation of all number between a range.

Input :
Two non-decimal positive integers

Output :
The sum of all the 1s in the range between the two numbers.

Example :
4 , 7        ---> 8
4  = 100 (adds one)   = 1
5  = 101 (adds two)   = 3
6  = 110 (adds two)   = 5
7  = 111 (adds three) = 8

10 , 20     ---> 27
100 , 200   ---> 419
1 , 3       ---> 4
1 , 2       ---> 2
1000, 2000  ---> 5938
I have only explained the first example otherwise it would have taken up a huge amount of space if I tried to explain for all of them.

Note :
Numbers can be apart by over a 1000
All input will be valid.
The minimum output will be one.
You can accept number as an array of two elements.
You can choose how the numbers are ordered.
Winning criteria :
This is code-golf so shortest code in bytes for each language wins.

"""

def ones(a, b):
    r = 0
    for i in range(a, b+1):
        r += i.bit_count()
    return r

def main():
    assert(ones(4, 7) == 8)
    assert(ones(10, 20) == 27)
    assert(ones(100, 200) == 419)
    assert(ones(1, 3) == 4)
    assert(ones(1, 2) == 2)
    assert(ones(1000, 2000) == 5938)

main()
