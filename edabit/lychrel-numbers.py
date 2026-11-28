#!/usr/bin/env python3

"""

The following is the Lychrel test.

Start with any positive number. Add the number with the number formed by reversing its digits. Is the sum a palindrome? If not, repeat the process.

For most numbers, a palindrome is produced after a few iterations (7 or fewer) of the process above.
Numbers that never reach a palindrome are called Lychrel numbers.
No number in base 10 has been proven to be a Lychrel number, but numbers that don't produce palindromes after an unusually high number of iterations of the reverse-and-add process are said to be Lychrel candidates

Create a function that takes a number and returns True if it is a Lychrel candidate. If it isn't, return the number of reverse-and-add iterations it takes to produce a palindrome. For this challenge, the threshold for a Lychrel candidate is >=500 iterations.

Examples

lychrel(33) ➞ 0
# Already a palindrome.

lychrel(65) ➞ 1
# 65+56 -> 121

lychrel(348) ➞ 3
# 348+843 -> 1191+1911 -> 3102+2013 -> 5115

lychrel(295) ➞ True

Notes

N/A

"""

def digits(n):
    d = []
    while True:
        d.append(n % 10)
        n //= 10
        if n == 0:
            break
    return d

def reverse(n):
    r = 0
    d = digits(n)
    for v in d:
        r = (r * 10) + v
    return r

def palindrome(n):
    m = reverse(n)
    while n != 0 and m != 0:
        if n%10 != m%10:
            return False
        n //= 10
        m //= 10
    return True

"""

The problem description describes an algorithm that is not actually a lychrel test, but rather this other sequence:
https://oeis.org/A033865
Need to add and reverse before checking for palindrome to make it a lychrel test.

"""
def x196(n, limit=500):
    for i in range(limit):
        if palindrome(n):
            return i
        n = n + reverse(n)
    return True

def main():
    assert(x196(33) == 0)
    assert(x196(65) == 1)
    assert(x196(348) == 3)
    assert(x196(196) == True)
    assert(x196(295) == True)
    assert(x196(89) == 24)
    assert(x196(7582) == 4)
    assert(x196(1945) == True)
    assert(x196(3673) == True)
    assert(x196(9485367) == 2)
    assert(x196(695) == 3)
    assert(x196(10911) == 55)

main()
