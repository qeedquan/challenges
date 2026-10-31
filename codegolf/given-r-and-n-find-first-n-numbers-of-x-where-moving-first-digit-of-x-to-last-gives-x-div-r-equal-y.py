#!/usr/bin/env python3

"""

Objective
Given input r and n find the first n natural numbers x such that if we rotate the first digit to the last place we obtain x/r.

You may assume that 2 <= r <= 9 and 1 <= n <= 65535.

You may write a program which takes input from stdin or command-line arguments; or you may write a function which takes r and n as parameters. Output, however, should be to stdout. Output should be one line per value of x, formatted as x/r=y, in order of increasing x.

Your solution must be able to handle all valid cases within one minute on a reasonable desktop computer.

Test cases

Input: 4 5
Output:

102564/4=25641
205128/4=51282
307692/4=76923
410256/4=102564
512820/4=128205

Input: 5 1
Output: 714285/5=142857

This is code-golf, so least bytes win. Winning answer will be accepted 4 weeks from now (2014-09-19).

Credits for this question go to my colleague, who allowed me to post this question here :)

"""

# ported from @matsjoyce solution
def solve(r, n):
    print("r=%d n=%d" % (r, n))
    p = 0
    while True:
        for a in range(1, 10):
            D, M = divmod(a*(10**p - r), 10*r - 1)
            if M != 0:
                continue
            
            print("%d/%d=%d" % (a*10**p + D, r, 10*D + a))
            
            n -= 1
            if n <= 0:
                print()
                return
        p += 1

def main():
    solve(4, 5)
    solve(5, 1)
    solve(4, 8)

main()
