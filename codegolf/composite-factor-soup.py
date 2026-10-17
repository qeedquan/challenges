#!/usr/bin/env python3

"""

Per the fundamental theorem of arithmetic, for a given number n, it is possible to find it's prime factors, and they are unique.
Let's imagine we talk only of  n that is non-prime (composite).

We can also find the factors of all the composite numbers smaller than  n. For example if  n is 10, then it has factors 5 and 2. 9 has 3 and 3. 8 has 2, thrice. 6 has 3 and 2. 4 has 2 and 2. So for the number 10, all the prime factors of all the composite numbers smaller than 10 would be listed as 2,3, and 5.

Now if you put a lot of vegetables in a pot for soup, often the largest will rise to the top. So if we put all of these factors in a big pot, which one will be the largest and rise to the top? For 10 soup, that answer is 5.

"Silly", you might think, "the number n itself will have the largest factors, larger than the factors of numbers smaller than  n". But this is where you are wrong my friend!

For example, the factors of 16 are all 2, repeated four times. The factors of 15 are 5 and 3, now, I don't have to be a mathematician to tell that 15 is smaller than 16, but 5 is bigger than 2!

Your challenge is to explore how this works for bigger  n. For any number given input number  n, assumed natural, composite,
and less than 2^32, find out which is the "largest factor" of all the prime factors of all the composite numbers less than or equal to n.

Good luck and have fun!

Smallest byte count wins.

"""

from sympy import prevprime

"""

@xnor and @Sanchises:

largest prime ≤ 1/2 * n.

The smallest composite number given some prime p is 2p.
Therefore, a larger prime than n/2 cannot give a composite number less or equal to n (upper bound).
Conversely, the largest prime less or equal to n/2 will give have at least one composite number less or equal to n, namely, 2p (existence)

"""

def largest_factor(n):
    return prevprime(n//2 + 1)

def main():
    assert(largest_factor(999) == 499)
    assert(largest_factor(10) == 5)

main()
