#!/usr/bin/env python3

"""

Task
Write a function that accepts two integers a,b that represent the Gaussian integer z=a+bi (complex number). The program must return true or false depending on whether a+bi is a Gaussian prime or not.

Definition a+bi is a Gaussian prime if and only if it meets one of the following conditions:

a and b are both nonzero and a^2+b^2 is prime
a is zero, |b| is prime and |b|≡3 (mod 4)
b is zero, |a| is prime and |a|≡3 (mod 4)

"""

import matplotlib.pyplot as plt
from sympy.ntheory.primetest import *

def main():
    assert(is_gaussian_prime(9940 + 43833j) == True)
    assert(is_gaussian_prime(4190 + 42741j) == True)
    assert(is_gaussian_prime(9557 + 41412j) == True)
    assert(is_gaussian_prime(1437 + 44090j) == True)
    assert(is_gaussian_prime(0 + 0j) == False)
    assert(is_gaussian_prime(0 + 3j) == True)

    N = 11
    xs = []
    ys = []
    for x in range(-N, N):
        for y in range(-N, N):
            if is_gaussian_prime(x + 1j*y):
                xs.append(x)
                ys.append(y)
    plt.scatter(xs, ys, c='black')
    plt.grid()
    plt.show()

main()
