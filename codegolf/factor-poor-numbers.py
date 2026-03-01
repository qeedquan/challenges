#!/usr/bin/env python3

"""

If a positive integer N>2 has (strictly) less prime factors (without counting multiplicities) than its successor and its predecessor, we will call it a factor-poor number.

In other words, ω(N)<ω(N−1) and ω(N)<ω(N+1), where ω(N) is the number of unique prime factors of N.

Task
You can choose among the following I / O formats:

Take an integer N and output the Nth factor-poor number. In case you choose this one, N can either be 0 or 1 indexed.
Take a positive integer N and output the first N factor-poor numbers.
Print the sequence indefinitely.
You can take input and provide output through any standard method, in any programming language, while taking note that these loopholes are forbidden by default. This is code golf, so the shortest submission that abides to the rules wins.

I won't include separate test cases, because the methods of competing are different, but you can refer to the first 100 terms of this sequence, which is OEIS A101934:

11, 13, 19, 23, 25, 27, 29, 37, 41, 43, 47, 49, 53, 59, 61, 64, 67, 71, 73, 79, 81, 83, 89, 97, 101, 103, 107, 109, 113, 121, 125, 131, 137, 139, 149, 151, 155, 157, 163, 167, 169, 173, 179, 181, 191, 193, 197, 199, 211, 221, 223, 227, 229, 233, 239, 241, 243, 251, 259, 263, 265, 269, 271, 277, 281, 283, 289, 293, 307, 309, 311, 313, 317, 331, 337, 341, 343, 347, 349, 353, 359, 361, 365, 367, 371, 373, 379, 383, 389, 397, 401, 407, 409, 419, 421, 431, 433, 439, 441, 443

As an example, 25
 occurs in this sequence because ω(25)=1(5), ω(26)=2 (2 and 13) and ω(24)=2 (2 and 3), so ω(25)<ω(24) and ω(25)<ω(26).

"""

from sympy import *

# https://oeis.org/A101934
def gen(n):
    r = []
    i = 3
    w1 = factorint(i - 1)
    w2 = factorint(i)
    while len(r) < n:
        w3 = factorint(i + 1)
        if len(w2) < min(len(w1), len(w3)):
            r.append(i)
        
        w1, w2 = w2, w3
        i += 1
    
    return r

def main():
    tab = [11, 13, 19, 23, 25, 27, 29, 37, 41, 43, 47, 49, 53, 59, 61, 64, 67, 71, 73, 79, 81, 83, 89, 97, 101, 103, 107, 109, 113, 121, 125, 131, 137, 139, 149, 151, 155, 157, 163, 167, 169, 173, 179, 181, 191, 193, 197, 199, 211, 221, 223, 227, 229, 233, 239, 241, 243, 251, 259, 263, 265, 269, 271, 277, 281, 283, 289, 293, 307, 309, 311, 313, 317, 331, 337, 341, 343, 347, 349, 353, 359, 361, 365, 367, 371, 373, 379, 383, 389, 397, 401, 407, 409, 419, 421, 431, 433, 439, 441, 443]
    
    assert(gen(len(tab)) == tab)

main()
