#!/usr/bin/env python3

"""

The brilliant engineers at <enter company you love to hate> have struck again. This time they've "revolutionised" the generation of random permutations. "Every great invention is simple" they say and their magical new algorithm is as follows:

Start with a list 1,2,3,...,n of numbers to permute.
For each element x in the list draw a random index in the list and swap x and the element at the random index
Then they "prove" that this is unbiased because each element occurs at each position with equal frequency.

Obviously, their reasoning is flawed because their method has n^n equally likely outcomes which typically is not a multiple of n!

Your task is as follows: Write a program / function that accepts a list / stream / generator / iterator (whatever makes most sense in your language of choice) of permutations and decides whether they are a biased sample as created by the algorithm above or not. If not you may assume that the sample is unbiased.

n will be 3 or more. You can set a minimum sample size as you see fit,

Your program may err on small samples but must converge to the correct answer as the sample size increases.

You may output True/False or any two values (but not groups of values: so for example empty list vs. nonempty list is not allowed unless the nonempty list is always the same)

Apart from that standard rules apply.

This is code-golf, smallest function or program in bytes wins. Different languages compete independently.

Python 3 Test case generator
import random

def f(n,biased=True,repeats=10,one_based=False):
  OUT = []
  for c in range(repeats):
    out = [*range(one_based,n+one_based)]
    OUT.append(out)
    for i in range(n):
      o = random.randint(i-i*biased,n-1)
      out[o],out[i] = out[i],out[o]
  return OUT
Try it online!

Additional hints
Now that @AndersKaseorg has let the cat out of the bag I see no harm in giving a few more hints.

Even though it may look plausible at first sight it is not true that elements are uniformly distributed over positions.

We do know:

Directly after the nth element was swapped with a random position the element at position n is truly uniformly random. In particular, in the final state the last position is uniformly random.

Before that the nth element is guaranteed to be equal or smaller than n

Whatever is swapped downwards from position n to m can only be returned to n at the nth move. In particular, it can't be if the original move was the nth in the first place.

If we rank positions by their expectation after the kth move then positions m and n can overtake each other only at the mth or nth move.

Select values:

The base (i.e. first or zeroth) element's position is uniformly random. This holds after the first swap and remains true from there on.

The next element is over-represented in the first position: Out of n^n possible draws it occurs in (n-1) x n^(n-2) + (n-1)^(n-1) instances.

The last element is under-represented in the first position: Out of n^n possible draws it occurs in 2 x (n-1)^(n-1) instances.

More demo / test code
import random,itertools

def f(n,one_based=False):
  OUT = []
  for c in itertools.product(range(n),repeat=n):
    out = [*range(one_based,n+one_based)]
    OUT.append(out)
    for i in range(n):
      o = c[i]
      out[o],out[i] = out[i],out[o]
  return OUT
 
from numpy import *

def expprop(n,one_based=False):
   out = [(one_based + r_[:n])*n**n]
   for i in range(n):
      out.append(out[-1][i]//n+out[-1]-out[-1]//n+eye(1,n,i,int)[0]*(-out[-1][i]+sum(out[0])//n))
   return array(out)

5 can be used to solve this challenge in a similar but perhaps slightly less golfable way to Anders's answer.

"""

import random

def f(n, biased=True, repeats=10, one_based=False):
    OUT = []
    for c in range(repeats):
        out = [*range(one_based, n + one_based)]
        OUT.append(out)
        for i in range(n):
            o = random.randint(i - i * biased, n - 1)
            out[o], out[i] = out[i], out[o]
    return OUT

"""

Ported from @Anders Kaseorg solution

How it works
Computes the fraction of samples where the first entry is less than the last entry. For unbiased input, this converges to 1/2.

For biased input, the last entry is uniform, but the first entry is less than a uniform one with probability

(3n - 2)*(n - 1)^(n-1) / (2*n^n)

which is 14/27 ~0.518518 at n=3 and increases torward 3/(2*e) ~0.551819 as n -> oo

This calculation ignores a slight anti-correlation between the first and last entries for  n≥4
 , but we can bound it and show that it’s much too small to affect correctness. Here are the exact probabilities computed by dynamic programming.

import numpy as np

def count(n):
    p = np.zeros((n, n), dtype=object)
    p0 = np.zeros(n, dtype=object)
    p1 = np.zeros(n, dtype=object)
    s0 = np.zeros(n, dtype=object)
    s1 = np.zeros(n, dtype=object)
    p[0, n - 1] = (n - 2) ** n
    s0[n - 1] = (n - 2) ** n
    s1[0] = (n - 2) ** n

    for i in reversed(range(n)):
        q0 = (p[i, :] + p0 + p1[i]) // (n - 2)
        q1 = (p[:, i] + p0[i] + p1) // (n - 2)
        r0 = s0 // (n - 2) - (n - 1) * q0 + q1
        r1 = s1 // (n - 2) - (n - 1) * q1 + q0

        p[i, :] += r0
        p[:, i] += r1
        p[np.diag_indices_from(p)] -= q0 + q1
        p[i, i] -= r0[i] + r1[i]
        p0 += q0
        p1 += q1
        s0 += q0 * (n - 1) + np.sum(q1) - q1 + r0
        s0[i] += np.sum(r1) - r0[i] - r1[i]
        s1 += np.sum(q0) - q0 + q1 * (n - 1) + r1
        s1[i] += np.sum(r0) - r0[i] - r1[i]

    return np.sum(np.triu(p + p0[None, :] + p1[:, None]))

for n in range(3, 50):
    print(n, f"{count(n)}/{n**n}")

"""

def sniff(permutations):
    count = 0
    for permutation in permutations:
        if permutation[0] < permutation[-1]:
            count += 1
    return (count / len(permutations)) > 0.51

def main():
    n = 20
    repeats = 10000
    print(sniff(f(n, biased=True, repeats=repeats)))
    print(sniff(f(n, biased=False, repeats=repeats)))

main()
