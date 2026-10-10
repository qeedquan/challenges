#!/usr/bin/env python3

"""

You all know about O'Neill's algorithm
https://www.cs.hmc.edu/~oneill/papers/Sieve-JFP.pdf

write a program such that you compute primes for a given input by the user using it.

edit: if anyone has any suggestions for the subreddit, kindly post it in the feedback thread posted a day before. It will be easier to assess. Thank you.

"""

from heapq import *
from itertools import *
 
def oneill():
    yield 2
    yield 3
 
    queue = []
    next_composite, skip = 9, 6 
    for odd_number in count(5, 2):
        if odd_number < next_composite:
            yield odd_number
            heappush(queue, (odd_number**2, 2*odd_number))
        else:
            while odd_number == next_composite:
                next_composite, skip = heappushpop(queue, (next_composite+skip, skip))
 
def primes(n):
    return list(islice(oneill(), n))

def main():
    print(primes(100))

main()
