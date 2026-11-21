#!/usr/bin/env python3

"""

It was mentioned in the tasks about modular inverse and modular exponentiation that such operations are popular in cryptography. Now the time has come to see this in details. Revisit page on Modular Arithmetic if some of the following explanations seem vague.

Here is an example of Public Key Cryptography system which you are to hack. Funny thing about such systems is that two different keys are used for encryption and decryption. I.e. even if a person knows the key to encrypt the message he/she still could not (at least easily) decrypt it back.

Obvious use-case for such system is the elimination of the problem of exchanging the encryption key between two sides. Really suppose Alice wants to tell something to Bob privately. She generates two keys - public key and secret key and sends the first of them to Bob. She does not care if attacker (for example, evil Bob's wife Eve) intercepts the key! Bob encrypts his message and sends the cipher back to Alice, who is able to decrypt it since she posess the secret key. But Eve could not do this since she have no idea what this secret key is.

Encryption and Decryption method
The method described below is known as ElGamal encryption named after the Egyptian scientist who proposed it in 1985. In its core it is based on earlier famous Diffie-Hellman key exchange from 1976, which nowadays is a building block of many more security protocols.

Alice and Bob choose some large prime number n to be the modulo of all the following modular operations. This value is not a secret. (i.e. all math described below is performed in Z/nZ field)

Alice then chooses any value p betwen 1 and n-1 and some sufficiently large e not exceeding n-1 also.

She tells Bob values of p and pe = p^e (p raised to power of e mod n) as her public key. Meanwhile the value e remains her secret key (there is no easy way to calculate it from p and p^e).

Bob converts his message to value (or several values) of Z/nZ field (i.e. integers between 0 and n-1) and encrypts each of them separately.

To encrypt the value m he chooses some random (also sufficiently large) k (between 1 and n-1) and calculates

pk = p^k
c = m * (pe)^k
and writes down the pair of these values. Here k is added as a salt to provide randomness in the encrypted message.

To decrypt the message Alice (who do not know k but knows e) uses the following formula on these two values:

m = c * inv((pk)^e)
where inv means a modular inversion function (prove this formula yourself, please!)

Implementation
We will use this method to encrypt several 4-letter words. Each word is converted into value m with the following algorithm:

A*31^3 + B*31^2 + C*31 + D
where A, B, C and D are zero-based indices of the letters (i.e. a is 0, b is 1 and z is 25). So that word math for example is converted into 358088. This encoding allows us to add special symbols for space, some punctuation marks and one additional for switching to digits, for example...

The modulo n for our exercise will be about 1000000 so it allows to encrypt any four-letter word in such manner - and on the other hand allows to use brute-force for hacking! However in real systems this value could be 2048 bits long i.e. about 700 decimal digits!

Input data

the first line will contain the amount of encrypted words;
the following line contains n, p and pe - info published by Alice;
next lines contain a pair pk, c each - encryption of a single word send by Bob.
Answer should contain space separated words which were send by Bob.

Example:

input data:
3
1000133 372453 464079
615510 932705
919640 902107
982800 247781

answer:
pair cake boot

"""

from sympy import discrete_log

def decrypt(n, p, pe, pk, c):
    e = discrete_log(n, pe, p)
    m = c * pow(pow(pk, e, n), -1, n)
    m %= n

    s = ""
    while m > 0:
        s += chr(ord('a') + m%31)
        m //= 31
    return s[::-1]

def main():
    n, p, pe = 1000133, 372453, 464079
    assert(decrypt(n, p, pe, 615510, 932705) == "pair")
    assert(decrypt(n, p, pe, 919640, 902107) == "cake")
    assert(decrypt(n, p, pe, 982800, 247781) == "boot")

main()
