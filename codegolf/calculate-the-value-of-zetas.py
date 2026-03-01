#!/usr/bin/env python3

"""

Challenge
Given an integer, s, as input where s≥1 output the value of ζ(s) (Where ζ(x) represents the Riemann Zeta Function).

Further information
ζ(s) is defined as:

ζ(s)=Sum[n=1,inf] 1/n^s
You should output your answer to 5 decimal places (no more, no less). If the answer comes out to be infinity, you should output ∞ or equivalent in your language.

Riemann Zeta built-ins are allowed, but it's less fun to do it that way ;)

Examples
Outputs must be exactly as shown below

Input -> Output
1 -> ∞ or inf etc.
2 -> 1.64493
3 -> 1.20206
4 -> 1.08232
8 -> 1.00408
19 -> 1.00000
Bounty
As consolation for allowing built-ins, I will offer a 100-rep bounty to the shortest answer which does not use built-in zeta functions. (The green checkmark will still go to the shortest solution overall)

Winning
The shortest code in bytes wins.

"""

import numpy as np
import math
from scipy.special import zeta

def main():
    assert(np.allclose(zeta(1), math.inf))
    assert(np.allclose(zeta(2), 1.64493))
    assert(np.allclose(zeta(3), 1.20206))
    assert(np.allclose(zeta(4), 1.08232))
    assert(np.allclose(zeta(8), 1.00408))
    assert(np.allclose(zeta(19), 1.00000))

main()
