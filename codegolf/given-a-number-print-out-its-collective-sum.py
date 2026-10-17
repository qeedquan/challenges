#!/usr/bin/env python3

"""

Given a number as input, print out its collective sum

What is a collective sum?

Consider the number 13214, the input

Looping through each of the digits starting from the left, we will be able to obtain its collective sum.

1 means look at the first digit, and add it to the sum, sum = 1

3 means look at the "first 3 digits" and add it to the sum, sum = 1 + 132

2 means look at the "first 2 digits" and add it to the sum, sum = 1 + 132 + 13

1 means look at the first digit, and add it to the sum, sum = 1 + 132 + 13 + 1

4 means look at the "first 4 digits" and add it to the sum, sum = 1 + 132 + 13 + 1 + 1321

Total sum = 1468 and this is your output

Special cases:

If we encounter a 0, then clearly we keep the sum the same

The number 1301 would have a sum = 1 + 130 + 1 = 132
If we encounter a number that is larger then the length of the input, we add it all

The number 251 would have a sum = 25 + 251 + 2 = 278
Test cases:

collectiveSum(0) = 0

collectiveSum(2) = 2

collectiveSum(2315) = 23 + 231 + 2 + 2315 = 2571
Shortest amount of bytes wins. Happy golfing!

"""

def collective_sum(n):
    r = 0
    s = str(abs(n))
    for i in s:
        t = s[:int(i)]
        if t == "":
            t = "0"
        r += int(t)
    return r

def main():
    assert(collective_sum(13214) == 1468)
    assert(collective_sum(0) == 0)
    assert(collective_sum(2) == 2)
    assert(collective_sum(2315) == 2571)

main()
