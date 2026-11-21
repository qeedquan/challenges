#!/usr/bin/env python3

"""

A void list is a list that at no level contains any non-list objects. Or if you prefer a recursive definition

The empty list is void

A list containing only other void lists is void

All void lists have a finite depth.

Here are some examples of void lists (using python syntax):

[]
[[]]
[[],[]]
[[[]]]
[[[]],[]]
[[],[[]]]
Here are some examples of things that are not void lists:

["a"]
[[...]]
[1]
2
[[],([],[])]
Task
Write two separate functions (or programs if you prefer). One should take a positive integer (you may also include zero if you wish) as an argument and return a void list the other should take a void list and return it an integer. These two functions should always be inverses of each other. That is if you pass the output of f into g you should get the original input of f as the result of g. This means the mapping must be 1:1, i.e. for every integer, there may only exist exactly one void list for which g gives that integer and for every void list there should be exactly one integer for which f gives that void list.

You are essentially creating a Bijection

You may choose to use a string representation of a void list (with or without commas and spaces) instead of your languages native list type.

Scoring
Your score will be the lengths of your two functions together. This is code-golf so you should aim to minimize this sum.

"""

"""

Ported from @xnor solution

"""
def f(l):
    if len(l) == 0:
        return 0
    return (f(l[0])*2 + 1) << f(l[1:])

def g(n):
    return n*[g] and [g(n//(n & -n)//2)] + g(len(bin(n & -n)) - 3)

for i in range(30):
	print(i, f(g(i)), g(i))
print()

a = [[[], []], [[[], []]]]
print(f(a))
print(g(f(a)))
print(a)
