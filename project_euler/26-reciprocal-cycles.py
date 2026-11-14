#!/usr/bin/env python3

"""

A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

"""

def rmf(n, m):
    c = 0
    while n%m == 0:
        n //= m
        c += 1
    return (n, c)

def period(n):
    if n <= 0:
        return -1

    (n, _) = rmf(n, 2)
    (n, _) = rmf(n, 5)
    
    p = 1
    while True:
        r = 10**p % n
        if r <= 1:
            break
        p += 1
    return p

# https://math.stackexchange.com/questions/377683/length-of-period-of-decimal-expansion-of-a-fraction
# https://tafakuri.net/?p=69
def solve(n):
    r, m = 0, 0
    for i in range(1, n):
        p = period(i)
        if p > m:
            r, m = i, p
    return (r, m)

def main():
    print(solve(11))
    print(solve(1000))

main()
