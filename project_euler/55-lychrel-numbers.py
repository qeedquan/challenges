#!/usr/bin/env python3

"""

If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome.
A number that never forms a palindrome through the reverse and add process is called a Lychrel number.
Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise.
In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome.
In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?

NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.

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

# https://oeis.org/A023108
def lychrel(n, limit=50):
    for i in range(limit):
        n = n + reverse(n)
        if palindrome(n):
            return i
    return -1

def solve(n):
    c = 0
    for i in range(1, n):
        if lychrel(i) < 0:
            c += 1
    return c

def main():
    print(solve(10000))

main()
