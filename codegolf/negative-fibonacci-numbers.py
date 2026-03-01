#!/usr/bin/env python3

"""

You probably all know the fibonacci sequence:

fibonacci(n)=fibonacci(n-1)+fibonacci(n-2)
fibonacci(0)=0
fibonacci(1)=1
Your task is as simple as it could be:

Given integer N compute fibonacci(n)
but here is the twist:

Also do negative N
Wait. What?

fibonacci(1)=fibonacci(0)+fibonacci(-1)
so

fibonacci(-1)=1
and

fibonacci(-2)=fibonacci(0)-fibonacci(1)=-1
and so on...

This is a code-golf so shortest programm in bytes win.
You may submit a function or a full programm
N is in [-100,100]

Testcase(s) in CSV:

-9;-8;-7;-6;-5;-4;-3;-2;-1;0;1;2;3;4;5;6;7;8
34;-21;13;-8;5;-3;2;-1;1;0;1;1;2;3;5;8;13;21

Hint:

n<0 and n&1==0:
fibonacci(n)=fibonacci(abs(n))*-1

"""

import numpy as np

"""

@flawr:

Explanation
This makes use of the fact that the fibonacci sequence f(n) can be written as (this should be a matrix vector notation):

Recursively:

[f(n+1)]  = [1  1] * [f(n)  ]
[f(n)  ]    [1  0]   [f(n-1)]
Explicitly:

[f(n+1)]  = [1  1] ^n * [1]
[f(n)  ]    [1  0]      [0]

This means that the top right entry of this matrix to the power of n is the value f(n) we're looking for. Obviously we can also invert this matrix as it has full rank, and the relationship still describes the same recurrence relation. That means it also works for negative inputs.

"""
def fib(n):
    F = np.matrix([[1, 1], [1, 0]])
    return int((F**n)[0, 1])

def main():
    tab = [34, -21, 13, -8, 5, -3, 2, -1, 1, 0, 1, 1, 2, 3, 5, 8, 13, 21]
    for i in range(len(tab)):
        assert(fib(i - 9) == tab[i])

main()
