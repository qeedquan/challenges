#!/usr/bin/env python3

"""

Since Fibonacci numbers and sequences seems like a popular subject for code golf I thought that it might be a fun challenge to code golf with Keith numbers.

So I propose a challenge that is to create a function that takes an integer and gives back a true or false depending on the number is a Keith number or not.

More about Keith numbers

In recreational mathematics, a Keith number or repfigit number (short for repetitive Fibonacci-like digit) is a number in the following integer sequence: 14, 19, 28, 47, 61, 75, 197, 742, 1104, 1537, 2208, 2580, …

Numberphile has a video explaining how to calculate a Keith number. But basically you take the digits of a number. Add them together and then take the last digits of the original number and add them to the sum of the calculation, rinse and repeat. And example to make it clear.

14
1 + 4 = 5
4 + 5 = 9
5 + 9 = 14

Input
An integer.

Output
True if the number is a Keith number. False if it's not..

"""

# https://en.wikipedia.org/wiki/Keith_number
# https://oeis.org/A007629
def iskeith(x, b=10):
    if x < 0:
        return False

    if x == 0:
        return True

    s = []
    y = x
    while y > 0:
        s.append(y % b)
        y //= b

    d = len(s)
    s.reverse()

    while s[len(s)-1] < x:
        n = 0
        for i in range(0, d):
            n += s[len(s) - d + i]
        s.append(n)

    return s[len(s)-1] == x

def gen(n):
    r = []
    i = 10
    while len(r) < n:
        if iskeith(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [14, 19, 28, 47, 61, 75, 197, 742, 1104, 1537, 2208, 2580, 3684, 4788, 7385, 7647, 7909, 31331, 34285, 34348, 55604, 62662, 86935, 93993, 120284, 129106, 147640, 156146, 174680, 183186, 298320]
    
    assert(gen(len(tab)) == tab)

main()
