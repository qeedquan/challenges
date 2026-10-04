#!/usr/bin/env python3

"""

Computers like binary. Humans like base 10. Assuming users are humans, why not find the best of both worlds? Your task is to find the first n terms in the sequence A008559 where each term is the binary representation of the previous number interpreted as a base 10 number.

Input
An integer greater than 0. Note that the first value of A008559 is 2.

Output
Just to make it a little more readable, the output should be the number of digits in the Nth term of A008559, which is A242347. Invalid inputs can output whatever, standard sequence rules apply.

Scoring
This is code-golf so shortest bytecount wins, no standard loopholes etc...

Test Cases
2 -> [1,2]
5 -> [1,2,4,10,31]
10 -> [1,2,4,10,31,100,330,1093,3628,12049]
20 -> [1,2,4,10,31,100,330,1093,3628,12049,40023,132951,441651,1467130,4873698,16190071,53782249,178660761,593498199,1971558339]

"""

import sys

# https://oeis.org/A242347
def seq(n):
    if n < 1:
        return []

    r = [1]
    x = 2
    for i in range(n):
        x = int(bin(x)[2:])
        r.append(len(str(x)))
    return r

def main():
    sys.set_int_max_str_digits(0)
    
    tab = [1, 2, 4, 10, 31, 100, 330, 1093, 3628, 12049, 40023, 132951, 441651]
    assert(seq(len(tab) - 1) == tab)

main()
