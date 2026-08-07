#!/usr/bin/env python3

"""

We already have a challenge about multiplying multiply single-variable polynomials. This challenge is about multiply two polynomials with multiple variables

Your task is given two multi-variable polynomials (for instance given as nested lists) to return their product.

Examples
representing polynomials as nested lists:

Each list is a single variable polynomial with its coefficients begin either integers or polynomials in one less variable:

[[[0,1],[1]],[[1]]] -> "[[0,1],[1]]"*1+"[[1]]"*z -> ("[0,1]"*1+"[1]"*y)*1+"[1]"*1*z -> (x*1+1*y)*1+1*1*z -> x+y+z
// (x²+x+1)(x²+x+1)=x⁴+2x³+3x²+2x+1
[1,1,1], [1,1,1]                                     -> [1, 2, 3, 2, 1]
// (x+y)(x+y)=x²+2xy+y²
[[0,1],[1]], [[0,1],[1]]                             -> [[0, 0, 1], [0, 2], [1]]
// (x+y+z)*(x-y+z) = x²-y²+2xz +z²
[[[0,1],[1]],[[1]]], [[[0,1],[-1]],[[1]]]            -> [[[0, 0, 1], [0], [-1]], [[0, 2]], [[1]]]
// a*a=a²
[[],[[[[[[[[[1]]]]]]]]]], [[],[[[[[[[[[1]]]]]]]]]] -> [[], [], [[[[[[[[[1]]]]]]]]]]

(non-golfed) solution in Python

def asList(p):
  if isinstance(p,list):
    return p
  return [p]
def polyAdd(p,q):
  if isinstance(p,list) or isinstance(q,list):
    p=asList(p)
    q=asList(q)
    r=[0]*max(len(p),len(q))
    for i in range(0,len(p)):
      r[i]=p[i]
    for i in range(0,len(q)):
      r[i]=polyAdd(r[i],q[i])
    i=len(r)
    while i>0 and r[i-1]==0:
      i-=1
    return r[:i]
  return p+q
def polyMult(p,q):
  if isinstance(p,list) or isinstance(q,list):
    p=asList(p)
    q=asList(q)
    r=[0]*(len(p)+len(q)-1)
    for i in range(0,len(p)):
      for j in range(0,len(q)):
        r[i+j]=polyAdd(r[i+j],polyMult(p[i],q[j]))
    return r
  return p*q

Rules
You can Input/Output the polynomials in any convenient format (as long as each output can only represent one polynomial)
Input and Output have to use the same format for polynomials
You can assume that all coefficients are integers
If you take input as lists you can assume that all numbers in both inputs appear in the nesting depth
You are allowed to omit zero coefficients in the output (as long as the output value are unambiguous)
You can use the empty list to represent zero/the zero polynomial
If your language has a built-in for multi-variable polynomial multiplication consider adding a non-built-in solution as well
This is code-golf the shortest solution wins

"""

def aslist(p):
    if isinstance(p, list):
        return p
    return [p]


def polyadd(p, q):
    if isinstance(p, list) or isinstance(q, list):
        p = aslist(p)
        q = aslist(q)
        r = [0] * max(len(p), len(q))
        for i in range(0, len(p)):
            r[i] = p[i]
        for i in range(0, len(q)):
            r[i] = polyadd(r[i], q[i])
        i = len(r)
        while i > 0 and r[i - 1] == 0:
            i -= 1
        return r[:i]
    return p + q


def polymul(p, q):
    if isinstance(p, list) or isinstance(q, list):
        p = aslist(p)
        q = aslist(q)
        r = [0] * (len(p) + len(q) - 1)
        for i in range(0, len(p)):
            for j in range(0, len(q)):
                r[i + j] = polyadd(r[i + j], polymul(p[i], q[j]))
        return r
    return p * q

def main():
    assert(polymul([1, 1, 1], [1, 1, 1]) == [1, 2, 3, 2, 1])
    assert(polymul([[0, 1], [1]], [[0, 1], [1]]) == [[0, 0, 1], [0, 2], [1]])
    assert(polymul([[[0, 1], [1]], [[1]]], [[[0, 1], [-1]], [[1]]] ) == [[[0, 0, 1], [], [-1]], [[0, 2], []], [[1]]])
    assert(polymul([[], [[[[[[[[[1]]]]]]]]]], [[], [[[[[[[[[1]]]]]]]]]]) == [[], [], [[[[[[[[[1]]]]]]]]]])

main()
