#!/usr/bin/env python3

"""

Inspired by this, print an ascii diamond pattern built using 0-9.

Rules

Input n should be between 0-9, anything outside that range is undefined
The diamond should be padded with spaces
The middle line should always have no padding and be the only line to contain n, in the center
Print to stdout
As always, this is code-golf

Test Cases

n = 0
0

n = 1, print
 0
010
 0

n = 2, print
  0
 010
01210
 010
  0

n = 9, print
         0
        010
       01210
      0123210
     012343210
    01234543210
   0123456543210
  012345676543210
 01234567876543210
0123456789876543210
 01234567876543210
  012345676543210
   0123456543210
    01234543210
     012343210
      0123210
       01210
        010
         0

"""

def diamondium(n):
    s = n*2 + 1
    print(f"n={n}")
    for y in range(s):
        for x in range(s):
            cx = abs(x - s//2)
            cy = abs(y - s//2)
            if cx + cy <= n:
                v = n - cx - cy
                print(f'{v}', end='')
            else:
                print(' ', end='')
        print()
    print()

def main():
    for i in range(0, 10):
        diamondium(i)

main()
