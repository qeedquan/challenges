#!/usr/bin/env python3

"""

Given 3 positive integers a, b, and n (whose maximum values are the maximum representable integer value in your language), output a truthy value if a ≡ b (mod n), and falsey otherwise. For those unfamiliar with congruency relations, a ≡ b (mod n) is true iff a mod n = b mod n (or, equivalently, (a - b) mod n = 0).

Restrictions
Built-in congruence testing methods are forbidden
Built-in modulo operations are forbidden (this includes operations such as Python's divmod function, which return both the quotient and the remainder, as well as divisibility functions, residue system functions, and the like)

Test Cases
(1, 2, 3) -> False
(2, 4, 2) -> True
(3, 9, 10) -> False
(25, 45, 20) -> True
(4, 5, 1) -> True
(83, 73, 59) -> False
(70, 79, 29) -> False
(16, 44, 86) -> False
(28, 78, 5) -> True
(73, 31, 14) -> True
(9, 9, 88) -> True
(20, 7, 82) -> False
This is code-golf, so shortest code (in bytes) wins, with earliest submission as a tiebreaker.

"""

def congruent(a, b, n):
    return (a - b) % n == 0

def main():
    assert(congruent(1, 2, 3) == False)
    assert(congruent(2, 4, 2) == True)
    assert(congruent(3, 9, 10) == False)
    assert(congruent(25, 45, 20) == True)
    assert(congruent(4, 5, 1) == True)
    assert(congruent(83, 73, 59) == False)
    assert(congruent(70, 79, 29) == False)
    assert(congruent(16, 44, 86) == False)
    assert(congruent(28, 78, 5) == True)
    assert(congruent(73, 31, 14) == True)
    assert(congruent(9, 9, 88) == True)
    assert(congruent(20, 7, 82) == False)

main()
