#!/usr/bin/env python3

"""

The minimal power iteration of a number n is defined as follows:

MPI(n):=nmin(digits(n))

That is, n raised to the lowest digit in n. For example, MPI(32)=322=1024 and MPI(1234)=12341=1234.

The minimal power root of a number n
 is defined as the number obtained from repeatedly applying MPI
 until a fixed point is found. Here is a table of the minimal power roots of numbers between 1 and 25:

   n              MPR(n)
--------------------------
   1                   1
   2                   1
   3              531441
   4                   1
   5                3125
   6 4738381338321616896
   7                   1
   8            16777216
   9                   1
  10                   1
  11                  11
  12                  12
  13                  13
  14                  14
  15                  15
  16                  16
  17                  17
  18                  18
  19                  19
  20                   1
  21                  21
  22                   1
  23              279841
  24                   1
  25                   1

Challenge: Generate the numbers whose minimal power root is not equal to 1 or itself.

Here are the first 50 numbers in this sequence:

3, 5, 6, 8, 23, 26, 27, 29, 35, 36, 39, 42, 47, 53, 59, 64, 72, 76, 78, 82, 83, 84, 92, 222, 223, 227, 228, 229, 233, 237, 239, 254, 263, 267, 268, 269, 273, 276, 277, 278, 279, 285, 286, 287, 289, 296, 335, 338, 339, 342

Rules
You may generate the first n numbers of this sequence (0- or 1-indexed), generate the nth term, create a generator which calculates these terms, output infinitely many of them, etc.
You may take input and give output in any base, but the calculations for MPR must be in base 10. E.g., you may take input ### (in unary) and output ### ##### ###### (in unary)
You must yield numbers. You may not (e.g.) output "3", "5", "6", since those are strings. 3, 5, 6 and 3 5 6 are both valid, however. Outputting 2 3, "23", or twenty-three are all considered invalid representations of the number 23. (Again, you may use any base to represent these numbers.)
This is a code-golf, so the shortest code (in bytes) wins.

"""

def mpr(x):
    m = x**int(min(str(x)))
    if m > x:
        m = mpr(m)
    return m

def gen(n):
    r = []
    x = 1
    while True:
        if len(r) >= n:
            break
        if x < mpr(x):
            r.append(x)
        x += 1
    return r

def main():
    tab = [3, 5, 6, 8, 23, 26, 27, 29, 35, 36, 39, 42, 47, 53, 59, 64, 72, 76, 78, 82, 83, 84, 92, 222, 223, 227, 228, 229, 233, 237, 239, 254, 263, 267, 268, 269, 273, 276, 277, 278, 279, 285, 286, 287, 289, 296, 335, 338, 339, 342]
    
    assert(gen(len(tab)) == tab)

main()
