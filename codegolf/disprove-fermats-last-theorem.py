#!/usr/bin/env python3

"""

Write a program, in the language of your choice, that appears to successfully find a counterexample to Fermat's Last Theorem.
That is, find integers a, b, c > 0 and n > 2 such that a^n + b^n = c^n.

Of course, you can't really do it, unless there's a flaw in Andrew Wiles' proof. I mean fake it, by relying on

integer overflow
floating-point rounding error
undefined behavior
data types with unusual definitions of addition, exponentiation, or equality
compiler/interpreter bugs
or something along those lines.
You may hard-code some or all of the variables a, b, c, or n, or search for them by doing loops like for a = 1 to MAX.

This isn't a code golf; it's a contest to find clever and subtle solutions.

"""

# http://www.math.toronto.edu/barbeau/fn41.pdf
def disprove():
    x = 3987**12 + 4365**12
    y = 4472**12
    xi = round(pow(x, 1/12))
    yi = round(pow(y, 1/12))
    assert(xi == yi)

def main():
    disprove()

main()
