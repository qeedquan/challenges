#!/usr/bin/env python3

"""

In this challenge you will write a function that takes a list (ordered set) containing real numbers (except for the empty list) and calculates

f(x) = 1        if |x| = 0
       x[1] + 1 if |x| = 1
       log(Sum[n=1, |x|] |x|^(x[n]), base=|x|) otherwise

where |x| is the length of list x and x[n] is the nth item in the list x using 1-based indexing.
But why is this called “logarithmic incrementation”? Because there is an interesting property of the function: f({n,n})=n+1
Amazing, right? Anyways, let’s not go off on a tangent. Just remember, this is code-golf, so the shortest answer wins! Oh, right, I forgot the legal stuff:

Standard loopholes apply.
In a tie, the oldest answer wins.
Only numbers that your language can handle will be input.

Test cases:
[] -> 1
[157] -> 158
[2,2] -> 3
[1,2,3] -> 3.3347175194727926933796024072445284958617665867248313464392241749...
[1,3,3,7] -> 7.0057883515880885509228954531888253495843595526169049621144740667...
[4,2] -> 4.3219280948873623478703194294893901758648313930245806120547563958...
[3,1,4] -> 4.2867991282182728445287736670302516740729127673749694153124324335...
[0,0,0,0] -> 1
[3.14,-2.718] -> 3.1646617321198729888284171456748891928500222706838871308414469486...

Output only needs to be as precise as your language can reasonably do.

"""

from math import *

def loginc(x):
    n = len(x)
    if n == 0:
        return 1
    if n == 1:
        return x[0] + 1
    
    r = 0
    for i in range(n):
        r += n**x[i]
    return log(r, n)

def test(x, r):
    v = loginc(x)
    print(v)
    assert(abs(v - r) < 1e-12)

def main():
    test([], 1)
    test([157], 158)
    test([2, 2], 3)
    test([1, 2, 3], 3.3347175194727926933796024072445284958617665867248313464392241749)
    test([1, 3, 3, 7], 7.0057883515880885509228954531888253495843595526169049621144740667)
    test([4, 2], 4.3219280948873623478703194294893901758648313930245806120547563958)
    test([3, 1, 4], 4.2867991282182728445287736670302516740729127673749694153124324335)
    test([0, 0, 0, 0], 1)
    test([3.14, -2.718], 3.1646617321198729888284171456748891928500222706838871308414469486)

main()
