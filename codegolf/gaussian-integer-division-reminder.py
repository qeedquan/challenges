#!/usr/bin/env python3

"""

Gaussian integer is a complex number in the form x+yi, where x,y are integer and i^2=-1.
The task is to perform such operation for Gaussian integers a,b, that a=q⋅b+r and |r|<|b| (q,r are Gaussian integers, |z| is defined as sqrt(a^2+b^2) for a+bi=z).
Need to output only r.
One of possible approaches is here.

Scoring: the fastest in terms of O-notations algorithm wins, though it can consume more time.
By fastest I mean O((f(n))a) is preferred for smaller a and O(loga(log(n))) will be preferred over O(logb(n)), ...over O(nk), ...over O(eαn) and so on.
If there's a tie, fastest implementation wins in terms of benchmark (e.g. 100 000 random 32-bit b and 64-bit a (I mean both real and imaginary part to be 32 or 64 signed integer)) or there can be 2-3 winners.
If unsure about algorithm complexity, leave blank. E.g. I believe Euler's algorithm for integers has O(log(n)) time complexity.

Test cases can be obtained from wolframalpha in the form like Mod[151 + 62 I, 2 + I], but in case there are some:

4 mod (3+3*i) = either of 1+3*i, -2-0*i, 4-0*i, 1-3*i
10000 mod 30*i = either 10 or -20
(3140462541696034439-9109410646169016036*i) mod (-81008166-205207311*i) =
    either -75816304-29775984*i or 129391007+51232182*i
|b| will not exceed 32 bits, but you don't have to code long arithmetic if your selected language doesn't have built-in one.

Good luck. Of course, WolframLanguage is forbidden. )

"""

"""

@xnor

Uses pure integer arithmetic, with no loops or branching or built-in complex numbers.
This should easily complete the benchmark of 100,000 random inputs within a small fraction of a second.
Porting this to a faster language would be straightforward and likely improve performance.

One possible low-level optimization is the Karatsuba algorithm trick to do complex multiplication using 3 rather than 4 integer multiplications.
But, this might not be worth it for such "small" values.

"""

def cmod(a, b):
    # Compute p = a * conj(b)
    a1, a2 = int(a.real), int(a.imag)
    b1, b2 = int(b.real), int(b.imag)
    
    # Compute the norm-squared of b
    p1 = a1*b1 + a2*b2
    p2 = -a1*b2 + a2*b1

    b_nsq = b1**2 + b2**2
    b_nsq_half = b_nsq // 2

    # Do a symmetric mod of d1 and d2 by b_nsq
    # That is, into the interval [-b_nsq_half, +b_nsq_half)
    d1 = (p1 + b_nsq_half) % b_nsq - b_nsq_half
    d2 = (p2 + b_nsq_half) % b_nsq - b_nsq_half

    # Compute r = d / b
    r1 = (d1 * b1 - d2 * b2) // b_nsq
    r2 = (d1 * b2 + d2 * b1) // b_nsq

    return complex(r1, r2)

def test(a, b):
    r = cmod(a, b)
    print(r)

def main():
    test(151 + 62j, 2 + 1j)
    test(10000 + 0j, 30 + 0j)
    test(2 + 2j, 3 + 0j)
    test(1 + 1j, 3 + 0j)
    test(1 + 2j, 3 + 0j)
    test(2 + 1j, 3 + 0j)
    test(2 + 2j, 0 + 3j)
    test(1 + 1j, 0 + 3j)
    test(1 + 2j, 0 + 3j)
    test(2 + 1j, 0 + 3j)

main()
