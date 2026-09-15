#!/usr/bin/env python3

"""

If you're not familiar with some of the background topics for today's challenge, you'll need to do some reading on your own. Feel free to ask if you're lost, but try to figure it out yourself first. This is a difficult challenge.

Implement the RSA key generation process following the specification on Wikipedia, or some other similar specification. Randomly generate 256-bit or larger values for p and q, using the Fermat primality test or something similar. Use e = 65537. Provide functions to encrypt and decrypt a whole number representing a message, using your selected n. Verify that when you encrypt and then decrypt the input 12345, you get 12345 back.

It's recommended that you use a large-number library for this challenge if your language doesn't support big integers.

(This is a repost of Challenge #60 [difficult], originally posted by u/rya11111 in June 2012.)

"""

from sympy import randprime

def exgcd(a, m):
    u1, u2, u3 = 1, 0, a
    v1, v2, v3 = 0, 1, m
    while v3 != 0:
        q = u3 // v3
        v1, v2, v3, u1, u2, u3 = u1 - q*v1, u2 - q*v2, u3 - q*v3, v1, v2, v3
    return u1 % m

class RSA:
    def __init__(self, bits):
        assert bits > 8
        while True:
            p = randprime(2**bits, 2**(bits + 1))
            q = randprime(2**bits, 2**(bits + 1))
            if p != q:
                break

        self.n = p * q
        self.e = 65537
        self.d = exgcd(self.e, (p - 1) * (q - 1))

    def encrypt(self, m):
        return pow(m, self.e, self.n)

    def decrypt(self, c):
        return pow(c, self.d, self.n)

def main():
    key = RSA(256)
    print(f"n\t0x{key.n:x}")
    print(f"e\t0x{key.e:x}")
    print(f"d\t0x{key.d:x}")
    pt = 0xdeadbeef
    print(f"pt\t0x{pt:x}")
    ct = key.encrypt(pt)
    print(f"ct\t0x{ct:x}")
    dt = key.decrypt(ct)
    print(f"dt\t0x{dt:x}")

main()
