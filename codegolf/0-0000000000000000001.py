#!/usr/bin/env python3

"""

Notice the pattern in the below sequence:

0.1, 0.01, 0.001, 0.0001, 0.00001 and so on, until reaching 0.{one hundred zeros}1
Then, continued:

0.2, 0.02, 0.002, 0.0002, 0.00002 and so on, until reaching 0.{two hundred zeros}2
Continued:

0.3, 0.03, etc, until 0.{three hundred zeros}3
Continued:

0.4, 0.04, etc, until 0.{four hundred zeros}4
Sped up a bit:

0.10, 0.010, etc.  until 0.{one thousand zeros}10
Sped up some more:

0.100, 0.0100...

You get the idea.

The input your code will receive is an integer, the number of terms, and the output is that many number of terms of the sequence.

Input and output formats are unrestricted, and separators are not required.

Trailing zeros are necessary.

Standard loopholes apply.

The outputs of some nth terms are given below:

nth term -> number
-------------------
1        -> 0.1
102      -> 0.2
303      -> 0.3
604      -> 0.4
1005     -> 0.5
1506     -> 0.6
2107     -> 0.7
2808     -> 0.8
3609     -> 0.9
4510     -> 0.10

"""

def seq(n):
    z = s = 1
    for _ in range(n):
        print("0.%0*d" % (z, s))
        if z > s*100:
            z, s = 1, s + 1
        else:
            z += 1

def main():
    seq(10)

main()
