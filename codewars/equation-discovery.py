#!/usr/bin/env python3

"""

In this kata, you'll be given a function representing an equation, and you'll have to determine the type and parameters of said equation. All equations will be in one of the following forms:

Constant: f(x) = c
Linear: f(x) = bx + c
Quadratic: f(x) = ax² + bx + c
And your solution will have to return an object of the following form:

Test.assertDeepEquals(discover((x) => 3), {
  'type': 'constant',
  'c': 3
});
Test.assertDeepEquals(discover((x) => 10 * x), {
  'type': 'linear',
  'b': 10,
  'c': 0
});
Test.assertDeepEquals(discover((x) => 5 * x*x + 3 * x + 1), {
  'type': 'quadratic',
  'a': 5,
  'b': 3,
  'c': 1
});
As you'll notice from the example tests, the passed functions will not have coefficients hardcoded -- you can't just parse f.toString() to solve this! Think functional analysis.

For your convenience, all parameters are guaranteed to be integers, although they won't necessarily be positive.

Good luck!

"""

from numpy.polynomial.polynomial import polyfit

def discover(f):
    p = polyfit([1, 2, 3], [f(1), f(2), f(3)], 2)
    for i in range(len(p)):
        p[i] = round(p[i])

    if p[2] == 0 and p[1] == 0:
        return { "type": "constant", "c": p[0] }
    if p[2] == 0 and p[1] != 0:
        return { "type": "linear", "b": p[1], "c": p[0] }
    return { "type": "quadratic", "a": p[2], "b": p[1], "c": p[0] }

def main():
    print(discover(lambda x: 3))
    print(discover(lambda x: 10*x))
    print(discover(lambda x: 5*x*x + 3*x + 1))

main()
