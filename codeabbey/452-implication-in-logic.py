#!/usr/bin/env python3

"""

Implication is a binary logic function, similar to AND, OR, XOR, NAND, NOR etc. However it is asymmetric. Here comes its "truth table" (where 0 means false while 1 stands for true):

  X   Y  |  X->Y
------------------
  0   0  |   1
  0   1  |   1
  1   0  |   0
  1   1  |   1
The function is usually denoted by -> operator and could be pronounced X implies Y or Y follows from X. It may look a bit unexpected that where X is false result is true for any Y - but we may think of it like "from lie anything may follow". The only false in the results column is because lie couldn't follow from truth.

As an example, regard two facts: "Pupil is ill" and "Pupil skips school". If the first is true, the second follows to be true also. However if the first is false, the second could be either false or true (healthy pupil may skip school for other reasons).

The goal of the exercise is to encode such function in Verilog language. Let the module be called implic with x and y as inputs and output called z. I.e. your code is likely to look that way:

module implic(input x, input y, output z);
  // ...
endmodule
This problem doesn't require input and answer box also is not needed. Just submit your code - checker will run it using suitable "testbench" and will tell if anything is wrong.

Hint on implementation in ROT13: hfr nffvta fgngrzrag jvgu fhvgnoyr ybtvp rkcerffvba bs k naq l ba gur evtug.

"""

def implic(x, y):
    return (~x | y) & 1

def main():
    assert(implic(0, 0) == 1)
    assert(implic(0, 1) == 1)
    assert(implic(1, 0) == 0)
    assert(implic(1, 1) == 1)

main()
