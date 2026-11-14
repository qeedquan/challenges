#!/usr/bin/env python3

"""

That's quite an old puzzle. Just let's add some automation to it!

Brother Sobertino has a task to examine certain barrel of wine in the cellar - whether it is good enough for the upcoming feast or not.

Barrel is very large, and Sobertino got two buckets with him, with volumes of V and U gallons. However, since he is not a drunkard, he only wants to measure small amount of T gallons for examination. The goal is to get exactly this amount by the following manipulations with the buckets:

any of buckets could be filled from the barrel to its full capacity
one of buckets could be used to fill another - in this case either the first should become empty or the second should become full;
at last he can pour any of the buckets back into the barrel.
For example, if he has buckets of 3 and 5 gallons, and wants to measure out just 1 gallon, he can go this sequence:

fill bucket of 3
dump bucket of 3 into bucket of 5 (now first is empty, second is 2 gallons short)
fill bucket of 3 again
dump this bucket of 3 once more into bucket of 5 - only 2 really shall go, leaving 1 gallon in the first bucket.
So it takes 4 operations to measure 1 gallon with two buckets of 3 and 5.

Problem Statement
Please find the minimal number of operations to get T gallons with buckets of U and V gallons.

Input data: just three values, U, V and T in a single line.
Answer should be a single value - required minimum number of operations.

Example:

input:
7 4 2

answer:
8

"""

from math import gcd
from collections import deque

def solve(V, U, T):
    # If the target is unachievable based on GCD rules
    if T > max(V, U) or T%gcd(V, U) != 0:
        return -1
        
    # Queue stores tuples of (current_v, current_u, current_steps)
    queue = deque([(0, 0, 0)])
    visited = set([(0, 0)])
    
    while queue:
        v, u, steps = queue.popleft()
        
        # Check if either bucket holds the target volume
        if v == T or u == T:
            return steps
            
        # Generate all 6 possible next states
        next_states = [
            (V, u),             # Fill V
            (v, U),             # Fill U
            (0, u),             # Empty V
            (v, 0),             # Empty U
            # Pour V into U
            (max(0, v + u - U), min(U, v + u)),
            # Pour U into V
            (min(V, v + u), max(0, v + u - V))
        ]
        
        for nv, nu in next_states:
            if (nv, nu) not in visited:
                visited.add((nv, nu))
                queue.append((nv, nu, steps + 1))

    return -1

def main():
    assert(solve(7, 4, 2) == 8)

main()
