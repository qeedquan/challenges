#!/usr/bin/env python3

"""

Description
We all know and love the binary number system, but today we're going to do something a little bit different with it. We're going to break it by adding another number.

The regular binary number system uses two digits, 0 and 1, and the positions they are put in represents different powers of 2, increasing from right to left. So, for example, if you have the binary number 110101, that is equal to

1*25 + 1*24 + 0*23 + 1*22 + 0*21 + 1*20

= 25 + 24 + 22 + 20

= 32 + 16 + 4 + 1

= 53

Easy enough, but now lets have some fun with it.

Imagine that instead of having just the two digits 0 and 1, the binary number system had three digits, 0, 1 and 2 with everything else working exactly the same. This system is known as the "hyperbinary number system".

Lets see an example how the hyperbinary number system works. Lets take the hyperbinary number "1021", and try and figure out what number it represents. Just as before, each position represents a power of 2, but now you can have 0, 1 or 2 of each of them, so the calculation goes like this:

1*23 + 0*22 + 2*21 + 1*20

= 8 + 2*2 + 1

= 8 + 4 + 1

= 13

Interestingly, this is not the only way you can represent the number 13 in hyperbinary, you could also write 13 as "221" and "1101".

In fact, this is a common issue with this number system: most numbers can be written in multiple ways in hyperbinary. Your challenge today is to find every single hyperbinary representation of a given number.

Formal Inputs and Outputs
Input description
The input will be a single line containing a single number (written in regular decimal).

Output description
Your program should print out all possible representations of the input number in hyperbinary, one per line. Every representation should be printed out once and only once. The order of the outputs doesn't matter, and you can use leading zeroes if you want to.

Examples
Input 1
18
Output 1
1122
1202
1210
2002
2010
10002
10010

Input 2
73
Output 2
112121
112201
120121
120201
121001
200121
200201
201001
1000121
1000201
1001001

Challenge inputs
Input 1
128
Input 2
239
Bonus
If you're looking for a stiffer challenge, try this input:

12345678910
I wouldn't recommend printing all the representations of that number out, though, becuse there are quite a few of them.

Have your program generate all the hyperbinary representations of that number, and then count them. Exactly how many are there?

Notes
Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

"""

def hyperbin(n):
    r = set()
    for i in range(n):
        x = int(bin(i)[2:]) + int(bin(n-i)[2:])
        r.add(x)
    return sorted(list(r))

def main():
    assert(hyperbin(18) == [1122, 1202, 1210, 2002, 2010, 10002, 10010])
    assert(hyperbin(73) == [112121, 112201, 120121, 120201, 121001, 200121, 200201, 201001, 1000121, 1000201, 1001001])
    assert(hyperbin(128) == sorted([10000000, 1111200, 1200000, 1112000, 1111112, 2000000, 1111120, 1120000]))
    assert(hyperbin(239) == sorted([10221111, 11021111, 2221111, 11101111]))

main()
