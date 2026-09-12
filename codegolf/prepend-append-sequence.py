#!/usr/bin/env python3

"""

Task
The prepend,append-Sequence is defined recursively, like this

a(1) = 1
a(n) = a(n-1).n , if n is even
a(n) = n.a(n-1) , if n is odd
where the . represents an integer concatenation.

So the first few terms are: 1,12,312,3124,53124,531246,7531246,... This is A053064.

Your task is, given an integer a > 0 to return n, such that the nth element in the prepend,append-Sequence is equal to a and if no such n exists return 0, a negative number or error out etc.

Rules
Input can be taken as an integer, string, list of characters/digits etc.
Output can be printed to STDOUT or returned (integer, string etc. is fine)
On invalid input & in the case no such n exists your program may do anything but return a positive integer (eg. loop forever, return 0 etc.)
You may choose to use 0-indexing, but then the output in case no n exists cannot be 0

Test cases
1 -> 1
12 -> 2
21 -> 0
123 -> 0
312 -> 3
213 -> 0
211917151311975312468101214161820 -> 21
2119171513119753102468101214161820 -> 0
333129272523211917151311975312468101214161820222426283031 -> 0
999795939189878583817977757371696765636159575553514947454341393735333129272523211917151311975312468101214161820222426283032343638404244464850525456586062646668707274767880828486889092949698100 -> 100

"""

from functools import lru_cache

# https://oeis.org/A053064
@lru_cache(maxsize=None)
def aps(n):
    if n < 1:
        return 0
    if n == 1:
        return 1
    
    x = aps(n - 1)
    if n&1 == 0:
        return int(str(x) + str(n))
    return int(str(n) + str(x))

def apsi(n):
    i = 0
    while True:
        x = aps(i)
        if x > n:
            return 0
        if x == n:
            return i
        i += 1

def main():
    tab = [1, 12, 312, 3124, 53124, 531246, 7531246, 75312468, 975312468, 97531246810, 1197531246810, 119753124681012, 13119753124681012, 1311975312468101214, 151311975312468101214, 15131197531246810121416, 1715131197531246810121416, 171513119753124681012141618]

    for i in range(len(tab)):
        assert(aps(i + 1) == tab[i])

    assert(apsi(1) == 1)
    assert(apsi(12) == 2)
    assert(apsi(21) == 0)
    assert(apsi(123) == 0)
    assert(apsi(312) == 3)
    assert(apsi(213) == 0)
    assert(apsi(211917151311975312468101214161820) == 21)
    assert(apsi(2119171513119753102468101214161820) == 0)
    assert(apsi(333129272523211917151311975312468101214161820222426283031) == 0)
    assert(apsi(999795939189878583817977757371696765636159575553514947454341393735333129272523211917151311975312468101214161820222426283032343638404244464850525456586062646668707274767880828486889092949698100) == 100)

main()

