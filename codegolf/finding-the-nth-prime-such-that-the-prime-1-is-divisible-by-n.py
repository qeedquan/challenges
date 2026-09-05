#!/usr/bin/env python3

"""

Problem
The goal is as the title says to find the nth prime such that the prime−1 is divisible by n.

Explanation
Here is an example so you understand the question, this is not necessarily the way it ought to be npm1d. It merely as a way to explain the question

given 3 as an input we would first look at all the primes

 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 ...

Then we select the primes such that  the prime-1 is divisible by n (3 in this case)

 7 13 19 31 37 43 61 67 73 79 97 103 107 109 127 ...

We then select the nth term in this sequence

We would output  19 for an input of  3

Note
We can also think of this as the  n
 th prime in the sequence  {1,n+1,2n+1,3n+1...kn+1}
  where  k
  is any natural number

Test Cases
  1 --> 2
  2 --> 5
  3 --> 19
  4 --> 29
100 --> 39301
123 --> 102337

"""

# https://oeis.org/A077317
def npm1(n):
    if n < 1:
        return 0
    N = n
    m = k = 1
    while N > 0:
        m *= k*k
        k += 1
        if m%k > (k-1)%n:
            N -= 1
    return k

def main():
    tab = [
        2, 5, 19, 29, 71, 43, 211, 193, 271, 191, 661, 277, 937, 463, 691, 769,
        1531, 613, 2357, 1021, 1723, 1409, 3313, 1609, 3701, 2029, 3187, 2437,
        6961, 1741, 7193, 3617, 4951, 3877, 7001, 3169, 10657, 6271, 7879, 5521,
        13613, 3823, 15137, 7349, 9091, 7499
    ]

    assert(npm1(1) == 2)
    assert(npm1(2) == 5)
    assert(npm1(3) == 19)
    assert(npm1(4) == 29)
    assert(npm1(100) == 39301)
    assert(npm1(123) == 102337)

    for i in range(len(tab)):
        assert(npm1(i + 1) == tab[i])

main()
