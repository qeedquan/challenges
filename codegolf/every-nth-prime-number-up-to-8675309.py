#!/usr/bin/env python3

"""

Challenge:
The goal of this code-golf is based around the number 8675309...

Your goal is to print out every prime number from 2 to 8675309, starting with the number 2 and then skipping 8 prime numbers, then skipping 6, then skipping 7, etc. In essence, skip a number of primes determined by the next number in the sequence 8675309. Cycling over to 8 once it reaches 9.

Output:
2
29
(skipped 8 to get to the 10th prime)

59
(skipped 6 to get to the 17th prime)

97
(skipped 7 to get to the 25th prime)

Example: (PHP-like pseudo-code where $prime is an array containing all the prime numbers.)

$tn=1;
$c=1;
$na=array(8,6,7,5,3,0,9);
l:
output($prime[$tn]);
if ($prime[$tn]>=8675309) {exit(8675309)};
$c+=1;
if ($c>=8) {$c=1};
$tn+=$na[$c];
goto l;

When I say skip 8 primes, I mean to go from the #1 prime, to the #10 prime (skipping the 8 in between).

Each number must be on a new line.

When you reach the 0 in 8675309, just just print the next prime number without skipping any.

This is code-golf so the shortest code (in-bytes) wins.

"""

from sympy import *

def output():
    skip = [8, 6, 7, 5, 3, 0, 9]
    limit = 8675309
    index = 0
    value = 2
    while value <= limit:
        print(value)
        for _ in range(skip[index] + 1):
            value = nextprime(value)
        index = (index + 1) % len(skip)

def main():
    output()

main()

