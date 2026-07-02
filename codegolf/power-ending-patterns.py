#!/usr/bin/env python3

"""

When you look at the last decimal digit of each power of a non-negative integer a repeating pattern forms. For example, 3:

3^1 =     3
3^2 =     9
3^3 =    27
3^4 =    81
3^5 =   243
3^6 =   729
3^7 =  2187
3^8 =  6561
3^9 = 19683
The last digits go 3971 which repeats indefinitely. In fact any number we choose that ends in 3 has that same pattern because none of the other digits can have an effect on the ones place during repeated multiplication.

What's curious is that some numbers have a much shorter cycle of power-ending digits. For example with 5 the powers all end in 5 so the pattern, written as short as possible, is simply 5.

Looking at the minimal power-ending digits patterns for 0 through 9 we get:

0 -> 0
1 -> 1
2 -> 2486
3 -> 3971
4 -> 46
5 -> 5
6 -> 6
7 -> 7931
8 -> 8426
9 -> 91
(The lengths of these being 11442 repeated is a curious tidbit itself.)

Remember, any numbers above 9 will have the same pattern as their last digit as was explained above with 3.

Challenge
Your challenge here is to write a program that takes in any non-negative integer and outputs its minimal power-ending digit pattern.

The exact output formatting, whether string or list, doesn't matter. For example, here are some potential inputs followed by valid potential outputs:

900 -> [0]
11 -> 1
2 -> 2486
303 -> 3, 9, 7, 1
44 -> 4 6
45 -> 5
666 -> "6"
3857 -> [7 9 3 1]
118 -> '8426'
129 -> [9, 1]

The shortest code in bytes wins.

"""

def pep(n):
    r = []
    for i in range(1, 5):
        r.append((n**i) % 10)
    return list(dict.fromkeys(r))

def main():
    assert(pep(900) == [0])
    assert(pep(11) == [1])
    assert(pep(2) == [2, 4, 8, 6])
    assert(pep(44) == [4, 6])
    assert(pep(45) == [5])
    assert(pep(666) == [6])
    assert(pep(3857) == [7, 9, 3, 1])
    assert(pep(118) == [8, 4, 2, 6])
    assert(pep(129) == [9, 1])

main()
