#!/usr/bin/env python3

"""

The Challenge
Build a N-Leveled Cantor Set.

The Cantor ternary set is created by repeatedly deleting the open middle thirds of a set of line segments.

The program receives one parameter N (a integer number) and then prints (in console or similar way) a Cantor Set of N levels. The print can only contain undescore (_) and whithe spaces characters. The parameter can be positive or negative and the sign indicates the Cantor Set construction orientation: If N > 0 the Cantor Set is constructed downwards and if N < 0 the Cantor Set is constructed upwards. If N = 0 then the program prints a single line (_).

For example:

N = 2

_________
___   ___
_ _   _ _
N = -2

_ _   _ _
___   ___
_________
N = 3

___________________________
_________         _________
___   ___         ___   ___
_ _   _ _         _ _   _ _
N = -3

_ _   _ _         _ _   _ _
___   ___         ___   ___
_________         _________
___________________________
Winning criteria
As it is a code golf challenge, the shortest code wins.

Edited: Modify 0 input by ugoren's suggestion.

"""

# ported from @Steven Rumbalski solution
def cantorset(n):
    print("n=%d" % (n))
    n = -n
    d = -1
    if n > 0:
        d = 1
    for i in range(n*d + 1)[::d]:
        s = "_" * 3**i
        while i < n*d:
            s += " "*len(s) + s
            i += 1
        print(s)
    print()

def main():
    for i in range(2, 4):
        cantorset(i)
        cantorset(-i)

main()
