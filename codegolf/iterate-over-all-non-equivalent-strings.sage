#!/usr/bin/env sage

"""

Input
A single positive integer 10≥n≥2

Output
A list of strings, each of length 2n, satisfying the following properties.

Each string will contain each of the first n lowercase letters of the alphabet exactly twice.
No letter can occur twice consecutively. That is abbcac is not allowed.
No two strings that are equivalent can be in the list. Equivalence will be defined below.
All non-equivalent strings satisfying the rules must be in the list.
Equivalence
We say that two strings of the same length are equivalent if there is a bijection from the letters in the first string to the letters in the second string which makes them equal. For example, abcbca and bcacab are equivalent.

Examples
n=2
: abab
n=3
: abacbc abcabc abcacb abcbac abcbca
The length of these lists is A278990.

"""

# https://oeis.org/A278990
def llc(n):
    P.<x> = PowerSeriesRing(QQ, n)
    return P(exp(-1+sqrt(1-2*x))/sqrt(1-2*x)).egf_to_ogf().list()

def main():
    tab = [1, 0, 1, 5, 36, 329, 3655, 47844, 721315, 12310199, 234615096, 4939227215, 113836841041, 2850860253240, 77087063678521, 2238375706930349, 69466733978519340, 2294640596998068569, 80381887628910919255, 2976424482866702081004, 116160936719430292078411]

    assert(llc(len(tab)) == tab)

main()
