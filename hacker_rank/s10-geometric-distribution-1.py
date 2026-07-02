#!/usr/bin/env python3

"""

Task
The probability that a machine produces a defective product is 1/3. What is the probability that the 1st defect occurs the 5th item produced?

Input Format

The first line contains the respective space-separated numerator and denominator for the probability of a defect, and the second line contains the inspection we want the probability of being the first defect for:

1 3
5

If you do not wish to read this information from stdin, you can hard-code it into your program.

Output Format

Print a single line denoting the answer, rounded to a scale of 3 decimal places (i.e., 1.234  format).

"""

from scipy.stats import geom

"""

Since we have 1/3 probability of a defective product that means we have (1 - 1/3) probability of the product not being defective.
So we want the first 4 days to be successful, then the 5th day to fail.
This gives the equation:

(2/3)^4 * 1/3 (which is a geometric distribution pdf with parameter 1/3 of fail rate evaluated at X=5)

"""

def main():
    print(geom.pmf(5, 1/3))

main()
