#!/usr/bin/env python3

"""

Write a function which gets as input a number (0 <= n <= 255) stored in 32-bit variable and returns non-zero integer if n is prime number and 0 otherwise.
Considern = 0 and n = 1 as non-primes.

Arrays and pointers are not allowed.

Score:
1 - for | & ^ ~ >> << operators
1.1 - for + - < > <= >= == != ! && || operators and branches & loops
1.2 - for * operator
2 - for / % operators
10 - for casting to/using other types (other than 32-bit integer)
Score for operators inside loops is score * max iterations count.

Answer with lowest score wins. If many answers with identical score, wins first one.

"""

from sympy import isprime

# ported from @ɐɔıʇǝɥʇuʎs solution
def prime(n):
    return (3622934801701902697686555901643181168549895964810913375391936802953324275884 >> n) & 1

def main():
    for i in range(256):
        assert(prime(i) == isprime(i))

main()
