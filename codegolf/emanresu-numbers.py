#!/usr/bin/env python3

"""

My userid is 100664. In binary this is 11000100100111000.

An interesting property of this number is that it can be created entirely by concatenating strings which are repeated at least twice:

11  000  100100  111  000
The first few such numbers are 3,7,10,12,15,24,28,31,36,40,42,43,45,48,51,53,54,56,58,60,63,80,87,96,99,103,112,115,117,120,122,124,127 (let me know if I've missed any as I worked these out by hand).

Your challenge is to calculate these. (Leading zeros don't count, e.g. 9 = 001001 is not part of the sequence.)

As with all sequence challenges, you may either:

Take a number n and output the nth term
Take a number n and output the first n terms
Take no input and output these forever
Here's a reference implementation courtesy of Bubbler

#print(int('110101',2))
frags = [bin(i)[3:]*j for i in range(2,100) for j in (2,3)]
frags.sort(key=lambda x:(len(x),x))
#print(frags)
begins = [x for x in frags if x[0]=='1']
#print(begins)
ans = []
for _ in range(50):
 a = begins.pop(0)
 print(a, int(a,2), end=' | ')
 ans.append(int(a,2))
 begins += [a + x for x in frags]
 begins = list(set(begins))
 begins.sort(key=lambda x:(len(x),x))
print()
print(ans)

Scoring
This is code-golf, shortest wins!

Testcases
These are 0-indexed.

0 => 3
1 => 7
3 => 12
5 => 24
10 => 42
15 => 53
20 => 63
25 => 103

"""

import re

# ported from @Underslash solution
def emanresu(n):
    r = []
    i = 1
    while len(r) < n:
        if re.match('^((.+)\\2+)+$', bin(i)[2:]):
            r.append(i)
        i += 1
    return r

def main():
    tab = [3, 7, 10, 12, 15, 24, 28, 31, 36, 40, 42, 43, 45, 48, 51, 53, 54, 56, 58, 60, 63, 80, 87, 96, 99, 103, 112, 115, 117, 120, 122, 124, 127]
    
    assert(emanresu(len(tab)) == tab)

main()
