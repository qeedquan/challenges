#!/usr/bin/env python3

"""

Breaking the Bonds
In “Perfect Matchings and RNA Secondary Structures”, we considered a problem that required us to assume that every possible nucleotide is involved in base pairing to induce an RNA secondary structure. Yet the only way this could occur is if the frequency of adenine in our RNA strand is equal to the frequency of uracil and if the same holds for guanine and cytosine.

We will therefore begin to explore ways of counting secondary structures in which this condition is not required. A more general combinatorial problem will ask instead for the total number of secondary structures of a strand having a maximum possible number of base pairs.

Problem

The graph theoretical analogue of the quandary stated in the introduction above is that if we have an RNA string s that does not have the same number of occurrences of 'C' as 'G' and the same number of occurrences of 'A' as 'U',
then the bonding graph of s cannot possibly possess a perfect matching among its basepair edges. For example, see Figure 1; in fact, most bonding graphs will not contain a perfect matching.

In light of this fact, we define a maximum matching in a graph as a matching containing as many edges as possible. See Figure 2 for three maximum matchings in graphs.

A maximum matching of basepair edges will correspond to a way of forming as many base pairs as possible in an RNA string, as shown in Figure 3.

Given: An RNA string s of length at most 100.

Return: The total possible number of maximum matchings of basepair edges in the bonding graph of s.

Sample Dataset
>Rosalind_92
AUGCUUC

Sample Output
6

"""

def nfact(n, m):
    r = 1
    for i in range(n, m):
        r *= (i + 1)
    return r

def matchings(s):
    a, c, u, g = 0, 0, 0, 0
    for r in s:
        if r == 'A':
            a += 1
        elif r == 'C':
            c += 1
        elif r == 'U':
            u += 1
        elif r == 'G':
            g += 1

    p = nfact(abs(a - u), max(a, u))
    q = nfact(abs(c - g), max(c, g))
    return p * q

def main():
    assert(matchings("AUGCUUC") == 6)
    assert(matchings("ACCUAGAGUGUCGUAAACCGACUAACAGGUCGACCUGUCCUGAAUUGGGGUAAGAUAAAUAAUGUCACCUAUCAUUGUCAACGAU") == 580955095453861300695296134820659200000000)

main()
