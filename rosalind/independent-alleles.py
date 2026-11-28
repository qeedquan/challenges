#!/usr/bin/env python3

"""

Mendel's Second Law

Recall that Mendel's first law states that for any factor, an individual randomly assigns one of its two alleles to its offspring.
Yet this law does not state anything regarding the relationship with which alleles for different factors will be inherited.

After recording the results of crossing thousands of pea plants for seven years, Mendel surmised that alleles for different factors are inherited with no dependence on each other.
This statement has become his second law, also known as the law of independent assortment.

What does it mean for factors to be "assorted independently?" If we cross two organisms,
then a shortened form of independent assortment states that if we look only at organisms having the same alleles for one factor,
then the inheritance of another factor should not change.

For example, Mendel's first law states that if we cross two Aa organisms, then 1/4 of their offspring will be aa, 1/4 will be AA, and 1/2 will be Aa.
Now, say that we cross plants that are both heterozygous for two factors, so that both of their genotypes may be written as Aa Bb.
Next, examine only Bb offspring: Mendel's second law states that the same proportions of AA, Aa, and aa individuals will be observed in these offspring.
The same fact holds for BB and bb offspring.

As a result, independence will allow us to say that the probability of an aa BB offspring is simply equal to the probability of an aa offspring times the probability of a BB organism, i.e., 1/16.

Because of independence, we can also extend the idea of Punnett squares to multiple factors, as shown in Figure 1. We now wish to quantify Mendel's notion of independence using probability.

Problem

Two events A and B are independent if Pr(A and B) is equal to Pr(A)×Pr(B).
In other words, the events do not influence each other, so that we may simply calculate each of the individual probabilities separately and then multiply.

More generally, random variables X and Y are independent if whenever A and B are respective events for X and Y, A and B are independent (i.e., Pr(A and B)=Pr(A)×Pr(B)).

As an example of how helpful independence can be for calculating probabilities, let X and Y represent the numbers showing on two six-sided dice.
Intuitively, the number of pips showing on one die should not affect the number showing on the other die.
If we want to find the probability that X+Y is odd, then we don't need to draw a tree diagram and consider all possibilities. We simply first note that for X+Y to be odd, either X is even and Y is odd or X is odd and Y is even.
In terms of probability, Pr(X+Y is odd)=Pr(X is even and Y is odd)+Pr(X is odd and Y is even).
Using independence, this becomes [Pr(X is even)×Pr(Y is odd)]+[Pr(X is odd)×Pr(Y is even)], or (1/2)^2 + (1/2)^2 = 1/2. You can verify this result in Figure 2, which shows all 36 outcomes for rolling two dice.

Given: Two positive integers k (k≤7) and N (N≤2^k).
In this problem, we begin with Tom, who in the 0th generation has genotype Aa Bb.
Tom has two children in the 1st generation, each of whom has two children, and so on. Each organism always mates with an organism having genotype Aa Bb.

Return: The probability that at least N Aa Bb organisms will belong to the k-th generation of Tom's family tree (don't count the Aa Bb mates at each level).
Assume that Mendel's second law holds for the factors.

Sample Dataset
2 1
Sample Output
0.684

"""

from math import comb

def solve(k, n):
    p = 0
    m = 2**k
    for i in range(n, m + 1):
        p += comb(m, i) * 0.25**i * 0.75**(m - i)
    return p

def main():
    print(solve(2, 1))
    print(solve(7, 37))

main()
