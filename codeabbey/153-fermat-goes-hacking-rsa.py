#!/usr/bin/env python3

"""

If after solving RSA cryptography exercise you still have vague idea of security of the RSA algorithm here is a variation of the same problem.

You are again to decrypt the encoded message but now instead of p and q you are given only their product n, just as a real attacker. Encryption was still performed with e=65537, but unfortunately you have no idea of the decryption exponent d!

However by chance you know that the person who encrypted the message was a perfect noob and used close values of p and q, so you may find a way to factorize n easily enough.

Conversion between string and number is performed in the same way as in the RSA-related exercise mentioned above.

Input data will contain n in the first line.
The second line contains cipher which was generated as a^65537 mod n where a is the original text converted to long integer.
Answer should contain the deciphered text.

Example:

input data:
2005386240811006492510206908835874977464399827995998174235015291258133373258958037573585627
258926557618335589879504876460462075566410747651590614428022205934562315249635550863811428

answer:
EGG EAT SKI SHY ARM EON HIP FUN LOW
Hint: The name of Pierre de Fermat is presented in the title intentionally, so some googling may help...

"""

from math import isqrt

# https://en.wikipedia.org/wiki/Fermat%27s_factorization_method
def fermat_factorization(n):
    a = isqrt(n)
    if a*a < n:
        a += 1
    while True:
        b2 = a*a - n
        b = isqrt(b2)
        if b*b == b2:
            return a + b, a - b
        a += 1

"""

Given the information that the primes P and Q are close to each other,
we can use fermat factorization to factor N=P*Q quickly.

N = A^2 - B^2
N = (A + B) * (A - B)
P = A + B
Q = A - B

Choose the initial guess A to be around sqrt(N).
Then start searching around the neighborhood for the factor B.

"""

def decrypt(n, e, cipher):
    p, q = fermat_factorization(n)
    phi = (p - 1) * (q - 1)
    d = pow(e, -1, phi)
    a = pow(cipher, d, n)
    r = ""
    s = str(a)
    i = 0
    while i+1 < len(s):
        c = int(s[i:i+2])
        if c == 0:
            break
        r += chr(c)
        i += 2
    return r
    
def main():
    n = 2005386240811006492510206908835874977464399827995998174235015291258133373258958037573585627
    cipher = 258926557618335589879504876460462075566410747651590614428022205934562315249635550863811428
    e = 65537
    assert(decrypt(n, e, cipher) == "EGG EAT SKI SHY ARM EON HIP FUN LOW")

main()
