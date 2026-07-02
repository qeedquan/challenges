#!/usr/bin/env python3

"""

Wikipedia: The regular paperfolding sequence, also known as the dragon curve sequence, is an infinite automatic sequence of 0s and 1s defined as the limit of inserting an alternating sequence of 1s and 0s around and between the terms of the previous sequence:

1

1 1 0

1 1 0 1 1 0 0

1 1 0 1 1 0 0 1 1 1 0 0 1 0 0

...

Note how each intermediate sequence is a prefix of the next.

Define a generator function paperFold that sequentially generates the values of this sequence:

1 1 0 1 1 0 0 1 1 1 0 0 1 0 0 1 1 1 0 1 1 0 0 0 1 1 0 0 1 0 0 ...

It will be tested for up to 1 000 000 values.

"""

def lowestone(n):
    return n & -n

# http://oeis.org/A014577
def dragon(n):
    n &= lowestone(n) << 1
    if n == 0:
        return 1
    return 0

def main():
    tab = [1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0]
    for i in range(len(tab)):
        assert(dragon(i + 1) == tab[i])

main()
