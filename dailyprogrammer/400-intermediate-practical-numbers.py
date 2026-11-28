#!/usr/bin/env python3

"""

Background
A practical number is a positive integer N such that all smaller positive integers can be represented as sums of distinct divisors of N. For example, 12 is a practical number because all the numbers from 1 to 11 can be expressed as sums of the divisors of 12, which are 1, 2, 3, 4, and 6. (Wikipedia.) However, 10 is not a practical number, because 4 and 9 cannot be expressed as a sum of 1, 2, and 5. For more detailed explanation and examples, see this recent Numberphile video.

Challenge
Write a function that returns whether a given positive integer is a practical number.

practical(1) => true
practical(2) => true
practical(3) => false
practical(10) => false
practical(12) => true
You should be able to handle numbers up to 10,000 efficiently. The sum of all practical numbers up to 10,000 inclusive is 6,804,107. Test your code by verifying this value.

Optional bonus challenge
Consider the numbers X in the range 1 to 10,000 inclusive. The sum of all X such that 1019 + X is a practical number is 1,451,958. Find the sum of all X such that 1020 + X is a practical number. I found the section Characterization of practical numbers in the Wikipedia article useful here.

I do not have any plans to resume posting here regularly. I just saw the Numberphile video and thought it would make a good challenge.

"""

from sympy import divisors
from itertools import chain, combinations

def powerset(iterable):
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s) + 1))

# https://oeis.org/A005153
def practical(n):
    if n < 1:
        return 0
    x = divisors(n)
    return len(set(map(sum, powerset(x)))) > sum(x)

def main():
    tab = [
        1, 2, 4, 6, 8, 12, 16, 18, 20, 24, 28, 30, 32, 36, 40, 42, 48, 
        54, 56, 60, 64, 66, 72, 78, 80, 84, 88, 90, 96, 100, 104, 108,
        112, 120, 126, 128, 132, 140, 144, 150, 156, 160, 162, 168, 
        176, 180, 192, 196, 198, 200, 204, 208, 210, 216, 220,
        224, 228, 234, 240, 252, 256, 260
    ]

    for n in range(max(tab) + 1):
        if n in tab:
            assert(practical(n) == True)
        else:
            assert(practical(n) == False)

main()
