#!/usr/bin/env python3

"""

Let f be the function that maps a bitfield ({0 1}) of size n+1 to bitfield of size n by applying XOR to the ith and i+1th bit and writing the result in the new bitfield.

Example: f("0101") = "111"

Informal calculation:

0 XOR 1 = 1

1 XOR 0 = 1

0 XOR 1 = 1
Let f_inverse be the inverse function of f. Since the inverse is not unique, f_inverse returns one valid solution.

Input: bitfield as string (i.e. "0101111101011") and a given natural number k

Output: bitfield as string, so that the string contains the result if f_inverse is applied k times to the input bitfield. (i.e. f_inverse(f_inverse(f_inverse(input))) )

Winning criteria: fewest Characters

Bonus:

-25 Characters if f_inverse is not applied recursively/iteratively, instead the output string is directly calculated

Testscript:

a = "011001"
k = 3

def f(a):
    k = len(a)
    r = ""
    for i in xrange(k-1):
        r += str(int(a[i]) ^ int(a[i+1]))
    return r

def iterate_f(a, k):
    print "Input ", a
    for i in xrange(k):
        a = f(a)
        print "Step " + str(i+1), a

iterate_f(a, k)
You can paste it for example here and then try it.

"""

"""

ported from @kennytm solution

Note that we expect k not being too large, since for code-golfing purpose the inner loop will run for O(2k) times.

I think we usually call this operation "xorshift" or something. If we express the input as big-endian integers, then the function f is simply:

f(x) = x xor (x >> 1)
If we apply f twice we will get:

f^2(x) = x xor (x >> 2)
However applying 3 times will have a different pattern:

f^3(x) = x xor (x >> 1) xor (x >> 2) xor (x >> 3)
Applying 4 times get back to the basic form:

f^4(x) = x xor (x >> 4)
And so on:

f^2k(x) = x xor (x >> 2k)
Note that if we choose a big-enough 2k, then (x >> 2k) = 0, meaning f^2k(x) = x, and the inverse is trivially the identity function!

So the strategy for finding f^-k(x) without calling f^-1(x) at all is:

Find K such that:

K ≥ k
K > log2 x
K is a power of 2
Express f^-k(x) = f^[-K + (K-k)](x) = f^-K*f^[K-k](x) = f^[K-k](x)

Thus, the result is f called K-k times

"""

def invxor(s, k):
    l = int(s, 8)
    t = len(s) + k
    while k < 1<<t:
        l ^= l//8
        k += 1
    return "%0*o" % (t, l)

def main():
    print(invxor("111", 3))

main()
