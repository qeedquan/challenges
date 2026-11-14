#!/usr/bin/env python3

"""

Zeckendorf's theorem shows that every positive integer can be uniquely represented as a sum of non-adjacent Fibonacci numbers. In this challenge, you have to compute the sum of two numbers in Zeckendorf representation.

Let Fn be the n-th Fibonacci number where

F1 = 1,
F2 = 2  and
for all k > 2, Fk = Fk - 1 + Fk - 2.

The Zeckendorf representation Z(n) of a non-negative integer n is a set of positive integers such that

n = Σi ∈ Z(n) Fi  and
∀i ∈ Z(n) i + 1 ∉ Z(n).

(in prosa: the Zeckendorf representation of a number n is a set of positive integers such that the Fibonacci numbers for these indices sum up to n and no two adjacent integers are part of that set)

Notably, the Zeckendorf representation is unique. Here are some examples for Zeckendorf representations:

Z(0) = ∅ (the empty set)
Z(1) = {1}
Z(2) = {2}
Z(3) = {3} ({1, 2} is not the Zeckendorf representation of 3)
Z(10) = {5, 2}
Z(100) = {3, 5, 10}

In this challenge, Zeckendorf representations are encoded as bit sets where the least significant bit represents if 1 is part of the set, etc. You may assume that the Zeckendorf representations of both input and output fit into 31 bits.

Your task is to compute Z(n + m) given Z(n) and Z(m). The solution with the shortest length in octets wins.

You can find a reference implementation written in ANSI C here. It can also be used to generate Zeckendorf representations or compute a number from its Zeckendorf representation.

Here are some pairs of sample input and output, where the first two columns contain the input and the third column contains the output:

73865           9077257         9478805
139808          287648018       287965250
34              279004309       279004425
139940          68437025        69241105
272794768       1051152         273846948
16405           78284865        83888256
9576577         4718601         19013770
269128740       591914          270574722
8410276         2768969         11184785
16384           340             16724

"""

from functools import lru_cache

"""

Ported from @Madison Silver solution

Explanation
This program directly manipulates the binary translations of the Zeckendorf representations. The function a(n,m) performs the main calculations, and s(n) is a helper function that gets rid of adjacent numbers contained in the Zeckendorf representation.

Let's start with the function s(n) (expanded for clarity):

def s(n):
    p=1                  #This finds the highest digit of the binary form of n.
    while n>=2*p:
        p*=2
    if n<=p:             #If n is a power of two (i.e, our number is already a Fibonnaci number)...
        return n         #Then return it normally.  This also works for zero. (A)
    if n>=3*p/2:         #If n's first digit is followed by a 1 (i.e, it starts with 11X)
        return s(n+p//2) #Then replace that with 100X (B)
    m = s(n-p)+p         #Otherwise, apply s to the rest of the number (C)
    if m==n:             #If this is out final result, we're done! (D)
        return n
    return s(m)          #Otherwise, reapply it. (E)
For example, the number 107 (1101011 in binary, representing 1+2+5+13+21=42), undergoes the following process:

1+2+5+13+21 [1101011] -> 1+2+5+34 [10001011] (B)
1+2+5+34 [10001011] (C)
 1+2+5 [1011] (C)
  1+2 [11] -> 3 [100] (B)
 ->3+5 [1100] (A/E)
 (E):  3+5 [1100] -> 8 [10000] (B)
->8+34 [10010000] (A/E)
(E): 8+34 [10010000] (C)
->8+34 [10010000] (A/E)

Here is an expanded version of a(n,m):

def a(n,m):
    if m==0:
        return n
    b=n&m
    t=s((n|m)-b%4)              #(A)
    t=a(t,b//4*2)               #(B)
    t=a(t,b//4)                 #(C)
    return s(a(t,b%4*2+b%4//2)) #(D)
This function converts the two Zeckendorf representations into four binary numbers which are easier to combine. Line (A) is the bitwise OR of the two binary Zeckendorf representations--these correspond to one copy of each Fibonacci number in either group. (B) and (C) are the bitwise AND of the two numbers right-shifted 1 and 2 times, respectively. We know that when the corresponding Fibonacci numbers for (B) and (C) are added together, they will be equivalent to the bitwise AND of our n and m because F(n)=F(n-1)+F(n-2).

For example, let's say that we have the binary numbers n=101001 (corresponding to 1+5+13) and m=110110 (2+3+8+13). Then we will have (A)=111111 (1+2+3+5+8+13), which is converted to 1010100 (3+8+21) by our function s, (B)=10000 (8), and (C)=1000 (5). We can check that (1+5+13)+(2+3+8+13)=(3+8+21)+(8)+(5)=45. This process repeats with ((3+8+21)+(8))+(5)=((3+8+21)+(5)+(3))+(5), etc.

The one difficulty with this system is that it doesn't work for the Fibonacci numbers 1 and 2, since they don't obey the property F(n)=F(n-1)+F(n-2) (they're the lowest two numbers)! Because of that, whenever 1 or 2 is contained in both n and m, they are removed from A, B, and C, then their sum placed in D under the property that 1+1=2 and 2+2=1+3. For example, if we add 1+3 (101) + 1+3+5 (1101), we get:

(A): 3+5 (1100) = 8 (10000)

(B): 2 (10)

(C): 1 (1)

(D): 2 (10)

Notice that the 3 and 5 were placed into A, the duplicate 3 was split into 2+1 in B and C, and duplicate 1s were removed from A, B, and C, added together, and put into D. Similarly, if we add 2+3 (110) + 2+3+5 (1110), we get:

(A): 3+5 (1100) = 8 (10000)

(B): 2 (10)

(C): 1 (1)

(D): 1+3 (101)

"""

@lru_cache(maxsize=None)
def s(n):
    p = 1
    while n >= 2 * p:
        p *= 2
    if n <= p:
        return n
    if n >= 3*p/2:
        return s(n + p//2)
    m = s(n - p) + p
    if m == n:
        return n
    return s(m)

@lru_cache(maxsize=None)
def a(n, m):
    if m == 0:
        return n
    b = n & m
    t = s((n | m) - b % 4)
    t = a(t, b // 4 * 2)
    t = a(t, b // 4)
    return s(a(t, b % 4 * 2 + b % 4 // 2))

def main():
    assert(a(73865, 9077257) == 9478805)
    assert(a(139808, 287648018) == 287965250)
    assert(a(34, 279004309) == 279004425)
    assert(a(139940, 68437025) == 69241105)
    assert(a(272794768, 1051152) == 273846948)
    assert(a(16405, 78284865) == 83888256)
    assert(a(9576577, 4718601) == 19013770)
    assert(a(269128740, 591914) == 270574722)
    assert(a(8410276, 2768969) == 11184785)
    assert(a(16384, 340) == 16724)

main()
