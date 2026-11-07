#!/usr/bin/env python3

"""

Rachel thinks that 3 is a magic number. In fact she thinks that all numbers which begin with the digit 3 are magic numbers. One day her friend Mark introduced her to different number bases. Mark showed Rachel that some numbers which do not start with a 3 (in base 10) can be written in a different number base so that they do start with a 3. For example, the number 14 (base 10) becomes 32 when written in base 4. Soon, Rachel found that she could turn most non-magic numbers in base 10 into magic numbers in some other number base. In fact, all base 10 numbers which are larger than 11 can be written as numbers starting with 3 in some other number base.

As Rachel investigated this more thoroughly she discovered that there were often several different number bases which would give a resulting number which starts with the digit 3. For example, the number 15 (base 10) can be transformed into a magic number in 2 different ways. In base 4 it becomes 33 and in base 5 it becomes 30.

The number 48 (base 10) can be transformed in 5 different ways. These are: 300 (base 4), 39 (base 13), 36 (base 14), 33 (base 15) and 30 (base 16). In this problem, you will be given several numbers N (all greater than 11). For each N you are to determine how many different number bases will transform the base 10 number N into a magic number (where the leading digit is 3). Note that, for a number N which is already a magic number in base 10, base 10 is counted as one of the bases. For example, the number 30 (base 10) can be written as a magic number in 3 different bases. These are bases 8, 9 and 10.

Input/Output description: The first line of the input data will contain a single integer P, representing the number of problems to solve. P lines will follow. Each of these contains a single digit N. For each N you must find the number of bases which transform N into a magic number. Combine all answers into a single string, separated by spaces.

Example:

input:
9
14
15
25
30
48
768
3843
82532
719985

answer:
1 2 2 3 5 69 328 6903 60072

"""

from math import ceil, floor

def solve(n):
    bases = set()
    k = 1
    while True:
        # If the minimum possible value for this power (3 * 4^k) exceeds N, 
        # no valid base >= 4 can satisfy the condition for this or any larger k.
        if 3*(4**k) > n:
            if k > 1:
                break
        
        # Calculate the theoretical mathematical bounds of B for a given power k
        # Lower bound: B > (n / 4)^(1/k) -> B^k > n / 4
        # Upper bound: B <= (n / 3)^(1/k) -> B^k <= n / 3
        min_B = int(ceil((n/4 + 1e-9) ** (1 / k)))
        max_B = int(floor((n/3) ** (1 / k)))
        
        for B in range(min_B, max_B + 1):
            if B >= 4:
                # Double check the condition holds precisely
                if 3 * (B ** k) <= n < 4 * (B ** k):
                    bases.add(B)
        k += 1
    return len(bases)

def main():
    assert(solve(14) == 1)
    assert(solve(15) == 2)
    assert(solve(25) == 2)
    assert(solve(30) == 3)
    assert(solve(48) == 5)
    assert(solve(768) == 69)
    assert(solve(3843) == 328)
    assert(solve(82532) == 6903)
    assert(solve(719985) == 60072)

main()
