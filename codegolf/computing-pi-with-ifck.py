#!/usr/bin/env python3

r"""

Objective
Compute \pi using nothing but i (\sqrt{-1}).

Guidelines
ONLY exponentiation and multiplication may be used (i.e. i^i or ii)
No additional symbols may be used (so no addition, subtraction, parentheses)
The result must be real and cannot be complex.
Expressions should use the principal branch for result computation.
If the solution is exceptionally large and repeats certain sequences of i combinations, shorthands can be used (i.e. iiiiii can become i^6), but the total number of i's used for the purpose of scoring must reflect the fully expanded version without any numbers. Same goes for using variables to express large sequences of i's to avoid numbers going off the page.
Scoring
Answers will scored using the formula 10\left(1-\log_{10}\left(\left|x-\pi\right|\right)\right) - \sqrt[3]{N}, where x is the result of your expression and N is the number of i's used.
Highest score wins.

Sample submission
52 bytes, 3 digits, 35.52 points
i^{i^{i}iii}i^{i^{i}iii}i^{i^{i}iii}i^{ii^{ii^{iii^{i}i}}ii}i^{i^{i}i^{ii}i^{i}i^{i}ii}i^{iiii^{ii^{iii}}} \approx 3.1404

"""

def pi():
    i = 1j
    A = i**(i**i * i * i * i)
    B = i**(i * i**(i * i**(i * i * i**i * i)) * i * i)
    C = i**(i**i * i**i * i * i**i * i * i * i * i)
    D = i**(i * i * i * i**(i * i**(i * i *i)))
    return A**3 * B * C * D

def main():
    print(pi())

main()
