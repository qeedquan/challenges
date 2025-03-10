#!/usr/bin/env python3

r"""

I'm using a language "MutFk" where the basic operators like "+" and "*" actually modify the left hand side of the expression, and also return the modified version. For example:

> x = 5
> x+3
8
> x
8
> x * 2 - 1
15
> x - 1
14
> 1 + x
15
If the left hand side is an literal, it won't be modified. Order of operations is multiplication, then addition. Both operators are left associative.

Given a expression in a normal language, consisting of:

Single digits numbers
Single letter variables, all the same case (your choice of upper case or lower case)
Multiplication (*) and addition (+)
no parenthesis, no spaces.
In other words, input will match the regular expression (([a-z0-9]\*)*[a-z0-9]\+)*([a-z0-9]\*)*[a-z0-9]).

The output must be an expression in "MutFk" that should produce the same output as the previous expression. Output is free to use addition, subtraction, and parenthesis.

Test Cases
Note there are many possible answers for each input, a few examples are listed below

Test Case	Output 1	Output 2	Output 3
x+1	1+x	0+x+1	x+1
x+1+x	1+x+x	0+x+1+x	x*2+1
x+y	x+y	0+x+y	y+x
x*y+x*2	0+1*x*y+2*x	0+1*x*y+1*x*2	x*2+x*y/2
x*2+x*4+1	1+2*x+4*x	0+1*x*2+1*x*4+1*x	x*6+1
Inspiration
This is how the vector math library I use at work works.

"""

"""

@Jonathan Allan

How?
Prepends each single character variable or single character constant with 1*.
Does not need to find these as they are guaranteed to be every other character.

"""

def modify(expression):
    result = ""
    for char in expression:
        if char.isalpha():
            result += "1*"
        result += char
    return result

def main():
    print(modify("x+1"))
    print(modify("x+1+x"))
    print(modify("x+y"))
    print(modify("x*y+x*2"))
    print(modify("x*2+x*4+1"))

main()
