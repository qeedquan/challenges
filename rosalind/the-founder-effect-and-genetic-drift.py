#!/usr/bin/env python3

"""

Strength in Numbers

Charles Darwin is known first and foremost for his notion of natural selection, the elegant statistical fact that changes in populations are attributable to the observation that organisms better equipped to handle their environment are more likely to survive and reproduce, thus passing on their beneficial traits to the next generation. As a result of natural selection, populations can change greatly over a long time.

A lesser known aspect of Darwin's evolutionary theory dictates how new species are actually created. Darwin noted that the only way for a population to grow so distinct that it would actually split off and form a new species would be if the population were isolated for a very long period. This notion that isolation forms new species was validated by Darwin's observation that the tiny Galapagos islands in the South Pacific enjoy a diversity of species rivaling that of a much larger ecosystem.

Isolated populations also tend to be small, strengthening the effects of genetic drift. To take an extreme example, consider a population of only 2 organisms that are both heterozygous for a given factor. Note that there is a 1/8 chance that 2 offspring of these organisms will possess only recessive alleles or only dominant alleles for the factor, thus wiping out the other allele completely.

In general, the principle stating that mutations (both positive and negative) can randomly attain higher proportions in small, isolated communities than they would in large populations, is known as the founder effect. An infamous example of the founder effect on human populations occurs in Pennsylvania, where the Amish community is at risk for a much greater incidence of Ellis-van Creveld syndrome, a single gene disorder causing a slew of defects, including additional fingers and toes (polydactyly). The condition has been traced to a single couple in the original Amish settlers, and it is still preserved in elevated percentages because of the community's isolationism.

In this problem, we would like to apply the Wright-Fisher model of genetic drift to understand the power of the founder effect. Specifically, we will quantify the likelihood that an allele will be completely annihilated in a small population after a number of generations.

Problem
Given: Two positive integers N and m, followed by an array A containing k integers between 0 and 2N. A[j] represents the number of recessive alleles for the j-th factor in a population of N diploid individuals.

Return: An m×k matrix B for which Bi,j represents the common logarithm of the probability that after i generations, no copies of the recessive allele for the j-th factor will remain in the population. Apply the Wright-Fisher model.

Sample Dataset
4 3
0 1 2

Sample Output
0.0 -0.463935575821 -0.999509892866
0.0 -0.301424998891 -0.641668367342
0.0 -0.229066698008 -0.485798552456

"""

from math import comb
import numpy as np

def drift(N, m, g):
    q = m / (2*N)
    p = 1 - q

    P = []
    for i in range(1, 2*N + 1):
        P.append(comb(2*N, i) * q**i * p**(2*N - i))

    for _ in range(1, g):
        GP = []
        for t in range(1, 2*N + 1):
            T = []
            for i in range(1, 2*N + 1):
                T.append(comb(2*N, t) * (i/(2*N))**t * (1 - i/(2*N))**(2*N - t))
            GP.append(sum([T[i]*P[i] for i in range(2*N)]))
        P = GP

    return np.log10(1 - sum(P))

def solve(N, m, A):
    k = len(A)
    B = np.zeros([m, k])
    for i in range(m):
        for j in range(k):
            B[i][j] = drift(N, A[j], i + 1)
    return B

def main():
    print(solve(4, 3, [0, 1, 2]))
    print(solve(19, 4, [9, 12]))

main()
