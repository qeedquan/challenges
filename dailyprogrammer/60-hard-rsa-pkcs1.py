#!/usr/bin/env python3

"""

The basic idea of RSA starts with two large prime numbers of equal bit-length, p and q; their product n becomes the modulus of the cryptosystem.
The totient of n is computed as φ(pq) = (p−1) × (q−1). Then two keys are chosen, the encryption key e and the decryption key d, such that de ≡ 1 (mod φ(pq)) and gcd(e, φ(pq)) = 1.
Then, given a message m, an integer on the range 0 < m <n, the message is encrypted by computing me (mod n) and the resulting cipher-text c is decrypted by computing cd (mod n).

The standard definition of RSA cryptography is known as PKCS #1.
It provides a method for converting a text message to a number m suitable for encryption, and converting it back to the original text message.
It is also possible to use RSA to provide non-forgeable signatures; the basic idea is that the sender encrypts a message hash with his decryption key,
so the receiver can decrypt the message hash with the sender’s public key, which works because only the sender knows his private decryption key.

Your task is to write an RSA key generator and procedures to encrypt and decrypt messages using the RSA algorithm.

Here is the RSA wiki to help you in understanding.
https://en.wikipedia.org/wiki/RSA

"""

from random import randint

# ported from @Cosmologicon solution

nbits = 256

# Fermat primality test
def isprime(n, k=50):
    return all(pow(randint(1, n-1), n-1, n) == 1 for _ in range(k))

# Generate a prime number of nbits length
def prime():
    while True:
        p = randint(1, 1<<nbits)
        if isprime(p):
            return p

# Choose p and q such that gcd(e, phi(pq)) = 1
e = 65537
while True:
    p, q = prime(), prime()
    phi = (p - 1) * (q - 1)
    if phi % e:
        break

# multiplicative inverse inv(a, b) * a = 1 (mod b)
def inv(a, b):
    if a == 0:
        return 0, 1, b
    y, x, g = inv(b % a, a)
    return x - b//a * y, y, g

d, _, _ = inv(e, phi)

encrypt = lambda m: pow(m, e, p*q)
decrypt = lambda c: pow(c, d, p*q)

m = 14045
print(encrypt(m))
print(decrypt(encrypt(m)))

