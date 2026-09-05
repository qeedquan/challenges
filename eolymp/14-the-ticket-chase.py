#!/usr/bin/env python3

"""

At a trolleybus stop, N passengers, including Petryk and Ivanko, board the trolleybus.
Petryk buys the first ticket, whose number is a prime.
Ivanko notices this and decides he also wants to get a ticket with a prime number.
Tickets are issued sequentially, starting from Petryk's ticket number, and there is only one roll of consecutively numbered tickets for all passengers.

Input
The input contains two numbers: N — the number of passengers, and the ticket number on Petryk's ticket.
The ticket number contains at most 6 digits.

Output
Output the number of passengers Ivanko must let go ahead of him to obtain a ticket with a prime number.
If it is impossible for Ivanko to get such a ticket before the tickets run out, output −1.

Examples

Input #4
6 23

Answer #4
-1

Input #1
5 11

Answer #1
1

"""

from sympy import nextprime

def solve(a, n):
    p = nextprime(n)
    if p > n + a - 1:
        return -1
    return p - n - 1

def main():
    assert(solve(6, 23) == -1)
    assert(solve(5, 11) == 1)

main()
