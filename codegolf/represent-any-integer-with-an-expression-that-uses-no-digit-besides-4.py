#!/usr/bin/env python3

"""

Fourward (Introduction)
I have an unhealthy obsession with the number 4. I love it so much, in fact, that seeing any other digit is frustrating to me. I therefour wish to create a 'Fourier Transformation': a way to represent any integer value with an expression that uses only the digit 4.

Fourmat (Challenge)
I wish to automate this process so I can use it everywhere. Your code must take any integer and output an expression that evaluates to that integer but which uses no digit other than '4'.

Four example, you might render the natural numbers as follows:

(4-4)
(4/4)
((4/4) + (4/4))
((4) - (4/4))
(4)
((4) + (4/4))
etc.
Any mathematical operation is allowed: you may use addition, multiplication, exponents, roots, logs, or even logical expressions such as AND or bitmasking--so long as no digit other than 4 appears in the output!

The parentheses aren't necessary; you may fourmat the output in whatever way you like, so long as it's readable. Also, because I'm not all that intelligent, the end result must be in base ten (or as I like to call it, base 4+4+(4/4)+(4/4).

Perfourmance (Criteria)
It is vitally important that the expressions each be as efficient as possible; I love the number 4, but I don't want to get sick of it. Submissions will thus be judged on the following, in order:

Efficiency of expressions (i.e. that the expression produced is as short as possible while still following the rules)
Efficiency of code (i.e. that your code is as short as possible)
Beauty of code (this is a tiebreaker; I won't be seeing the code itself so I don't mind non-four digits in there, but between two otherwise equal answers, I will prefer the code that uses the fewest non-four digits)

"""

def four(n):
    if n == 0:
        return "4-4"

    s = ""
    if n < 0:
        s = "-(4//4)*"
        n = -n
    s += "("
    for i in range(n):
        s += "(4//4)"
        if i + 1 < n:
            s += "+"
    s += ")"
    return s

def main():
    for i in range(-1000, 1000):
        assert(i == eval(four(i)))

main()
