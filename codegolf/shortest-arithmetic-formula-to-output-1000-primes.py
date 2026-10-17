#!/usr/bin/env python3

"""

Write a formula using only the digits 0-9, +, *, -, /, % and ^ to output a 1000 distinct primes when given input (which can be used as a variable n in the formula) of numbers 1 to 1000. (Note that / will give the quotient as all arithmetic is integer arithmetic.) Solutions can use ( and ) freely and they will not be counted in the length.

The shortest formula wins! The primes only need to be some 1000 primes not necessarily the first 1000.

EDIT

Edited for clarity based on suggestions by Sisyphus and an earlier question on primality testing.

Symbols are meant to work with integers in the "usual" way as follows.

n : Represents a number from 1 to 1000 which is the "input" to the formula. It can be used any number of times in the formula and it will represent the same input.

0-9 : Sequences of digits (terminated by non 0-9 symbols or  ) return the number represented by this decimal representation. Negation of an expression can be represented as (-{expression})

+ : Returns the sum of two numbers

* : Returns the product of two numbers

/ : Returns the integer quotient of two numbers

% : Returns the remainder on division of the first number by the second number. This and / follow Euclidean division conventions.

- : Returns the result of subtracting the second number from the first number.

^ : Returns the power of the first number by the second number. Anything to the power 0 is taken as 1 including 0!

() : Brackets are used in pairs to encapsulate an expression that returns a number using the previous rules.

"""

from sympy import *

# ported from @Anders Kaseorg solution
def prime1000(n):
    return 541**n*743**(n//2)*(-1)**(n//4)*17**(n//8)%2310+297999352693782350435634574256421873511169209139789986107407037031463672744907435566931682004950168827622126589004268258979810886896053712313147567393521260370898856430728936238509646240927399434529133911694916958518274696252190810912239170743768597920487389824644988723446125401158124982957878348425345764310640796665180984553241724855646631162669954988652785474199384658696484753453854147610893664426900411229033105555630617039087023847065224114331551958//67**(n%250)%67*2310

def main():
    for i in range(1, 1001):
        assert(isprime(prime1000(i)))

main()
