#!/usr/bin/env python3

"""

Your task is to write a higher order function for chaining together a list of unary functions. In other words, it should return a function that does a left fold on the given functions.

chained([a,b,c,d])(input)
Should yield the same result as

d(c(b(a(input))))

"""

def f1(x):
    return x * 2

def f2(x):
    return x + 2

def f3(x):
    return x**2

def f4(x):
    return x.split()

def f5(xs):
    return [x[::-1].title() for x in xs]

def f6(xs):
    return "_".join(xs)

def chained(F, n):
    for f in F:
        n = f(n)
    return n

def main():
    assert(chained([f1, f2, f3], 0) == 4)
    assert(chained([f1, f2, f3], 2) == 36)
    assert(chained([f3, f2, f1], 2) == 12)
    assert(chained([f4, f5, f6], "lorem ipsum dolor") == "Merol_Muspi_Rolod")

main()
