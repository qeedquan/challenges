#!/usr/bin/env python3

"""

One way to approximate π is the following: Start by drawing a 2x2 square with a quarter-circle in it. Then, the area of the quarter-circle is π.

https://i.sstatic.net/HnBxisOym.png

We can approximate this area by filling it with squares. To start, we divide the square into four squares. Only one of these is fully inside the circle, so we colour it in and get a value of π = 1.

https://i.sstatic.net/6HwrlCJBm.png

Next, we repeat the same thing with the other three squares, dividing them into quarters and colouring those fully contained in the quarter-circle. This gives a value of π = 2.

https://i.sstatic.net/yT374t0wm.png

And again, with π = 41/16 ≈ 2.56:

https://i.sstatic.net/BJjZbZzum.png

And again, with π = 183/64 ≈ 2.86:

https://i.sstatic.net/ZPtxnTmSm.png

Once more, with π = 385/128 ≈ 3.007:

https://i.sstatic.net/jI6Hi3Fdm.png

And one last time, because these are pretty, with π = 3149/1024 ≈ 3.075:

https://i.sstatic.net/rU6TWPskm.png

Your challenge is to count the squares in each iteration of this pattern. The first pattern has one red square (total 1), then the next pattern has four orange squares for a total of 5, then the next has nine yellow squares for a total of 14, and so on. The sequence continues 1, 5, 14, 33, 71, 140, 274, 563, 1083... - here's an example python program to calculate the first few terms.

While this specific sequence is not on OEIS, its variations A156790 and A177144 are. (incidentally, this is what you get if you search the first few terms of the sequence). Standard sequence I/O rules apply - you may take a 0/1-indexed n and output the nth / first nterms, or just output the whole sequence indefinitely.

This is code-golf, shortest wins!

"""

from math import *

def squares(m):
    r = 0
    for n in range(m + 1):
        for i in range(1, 2**n):
            a = sqrt(4**n - i*i)
            b = 4*(n//m) - 3
            r += int(a) * b
    return r

def main():
    tab = [0, 1, 5, 14, 33, 71, 140, 274, 563, 1083, 2159, 4293, 8391, 16767, 33326, 66346, 132460, 264579, 528164, 1053929, 2104238]
    for i in range(len(tab)):
        assert(squares(i) == tab[i])

main()
