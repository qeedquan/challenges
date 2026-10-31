#!/usr/bin/env python3

"""

The subfactorial or rencontres numbers (A000166) are a sequence of numbers similar to the factorial numbers which show up in the combinatorics of permutations. In particular the nth subfactorial !n gives the number of derangements of a set of n elements. A derangement is a permutation in which no element remains in the same position. The subfactorial can be defined via the following recurrence relation:

!n = (n-1) (!(n-1) + !(n-2))
In fact, the same recurrence relation holds for the factorial, but for the subfactorial we start from:

!0 = 1
!1 = 0
(For the factorial we'd have, of course, 1! = 1.)

Your task is to compute !n, given n.

Rules
Like the factorial, the subfactorial grows very quickly. It is fine if your program can only handle inputs n such that !n can be represented by your language's native number type. However, your algorithm must in theory work for arbitrary n. That means, you may assume that integral results and intermediate value can be represented exactly by your language. Note that this excludes the constant e if it is stored or computed with finite precision.

The result needs to be an exact integer (in particular, you cannot approximate the result with scientific notation).

You may write a program or a function and use any of the standard methods of receiving input and providing output.

You may use any programming language, but note that these loopholes are forbidden by default.

This is code-golf, so the shortest valid answer – measured in bytes – wins.

Test Cases
n     !n
0     1
1     0
2     1
3     2
4     9
5     44
6     265
10    1334961
12    176214841
13    2290792932
14    32071101049
20    895014631192902121
21    18795307255050944540
100   34332795984163804765195977526776142032365783805375784983543400282685180793327632432791396429850988990237345920155783984828001486412574060553756854137069878601

"""

def memoized(f):
    memo = {}
    def m_fun(*args):
        if args in memo:
            return memo[args]    
        res = f(*args)
        memo[args] = res
        return res
    
    return m_fun

# https://oeis.org/A000166
@memoized
def subfactorial(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    return n*subfactorial(n-1) + (-1)**n

def main():
    assert(subfactorial(0) == 1)
    assert(subfactorial(1) == 0)
    assert(subfactorial(2) == 1)
    assert(subfactorial(3) == 2)
    assert(subfactorial(4) == 9)
    assert(subfactorial(5) == 44)
    assert(subfactorial(6) == 265)
    assert(subfactorial(10) == 1334961)
    assert(subfactorial(12) == 176214841)
    assert(subfactorial(13) == 2290792932)
    assert(subfactorial(14) == 32071101049)
    assert(subfactorial(20) == 895014631192902121)
    assert(subfactorial(21) == 18795307255050944540)
    assert(subfactorial(100) == 34332795984163804765195977526776142032365783805375784983543400282685180793327632432791396429850988990237345920155783984828001486412574060553756854137069878601)

main()
