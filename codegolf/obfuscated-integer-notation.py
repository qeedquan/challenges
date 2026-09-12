#!/usr/bin/env python3

"""

Edit: I will be posting a newer version of this question on meta-golf soon. Stay tooned!

Edit #2: I will no longer be updating the challenge, but will leave it open. The meta-golf version is available here: https://codegolf.stackexchange.com/questions/106509/obfuscated-number-golf

Background:
Most numbers can be written with only 6 different symbols:

e (Euler's Constant)
- (Subtraction, Not Negation)
^ (Exponentiation)
(
)
ln (Natural Logarithm)
For example, you could convert the imaginary number i using this equation:

(e-e-e^(e-e))^(e^(e-e-ln(e^(e-e)-(e-e-e^(e-e)))))
Goal:
Given any integer k through any reasonable means, output the shortest representation possible of that number using only those 6 symbols.

Examples:
0 => "e-e"
1 => "ln(e)"
2 => "ln(ee)"
// Since - cannot be used for negation, this is not a valid solution:
// ln(e)-(-ln(e))
-1 => "e-e-ln(e)"
Notes:
Ending parenthesis count towards the total amount of characters.
ln( only counts as 1 character.
Everything else counts as 1 character.
n^0=1
Order of operations apply
Parenthesis multiplying is acceptable, e.g. (2)(8)=16, 2(5)=10, and eln(e)=e.
ln e is not valid, you must do ln(e)

"""

from itertools import *
from ast import *
from math import *

def valid(expression):
    return 'UnaryOp' not in dump(parse(expression))

def to_eval(expression):
    f = ''.join(expression)
    f = f.replace('L', 'log(')
    f = f.replace(')(', ')*(')
    f = f.replace('^', '**')
    nf = f.replace('ee', 'e*e')
    while nf != f:
        f, nf = nf, nf.replace('ee', 'e*e')
    return nf

def try_length(length, value):
    for equation in product('L()e^-', repeat=length):
        expression = to_eval(equation)
        try:
            if eval(expression) == value and valid(expression):
                result = ''.join(equation)
                result = result.replace('L', 'ln(')
                return result
        except:
            pass
    return None

# ported from @George V. Williams solution
def bruteforce(value, iterations=1000):
    for i in range(iterations):
        result = try_length(i, value)
        if result:
            return (i, result)
    return None

def main():
    print(bruteforce(0))
    print(bruteforce(1))
    print(bruteforce(2))
    print(bruteforce(-1))
    print(bruteforce(3))
    print(bruteforce(4))
    print(bruteforce(5))
    print(bruteforce(6))

main()
