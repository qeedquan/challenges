#!/usr/bin/env python3

"""

I want an n*n table that is filled with black or white and the following conditions are satisfied in it:

All cells of a 2*2 square in this table should not be the same color.
All black and white cells must be connected horizontally or vertically.

https://i.sstatic.net/J6A9Q.png

Can anyone design a function that takes n as input and generates an acceptable n*n random table?

It is not necessary for the output to be an image, we can use symbols such as 0 and 1 in a two-dimensional array to display the result.

"""

# ported from @Someone solution
def yinyang(n):
    if n < 1:
        return []
    if n < 2:
        return [1]
    return ["1"*n] + [("10"*n)[:n]]*(n-2) + ["0"*n]

def output(m):
    print("n=%d" % (len(m)))
    for s in m:
        print(s)
    print()

def main():
    for i in range(10):
        output(yinyang(i))

main()
