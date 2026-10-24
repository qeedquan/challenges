#!/usr/bin/env python3

"""

For the series

n
∑k^k
k=1

Find the last ten digits of the n-term of the series (n will be given as the parameter).

If the last ten digits begin with zeros, omit them. For instance, for input n = 10, you should return "405071317" but not "0405071317".

n will always be an integer between 1 and 15000.

Example
n --> output
1     "1"
2     "5"
3     "32"
10    "405071317"

"""

# https://oeis.org/A001923
def power(n):
    m = 10**10
    r = 0
    for k in range(1, n + 1):
        r += pow(k, k, m) % m
    return str(r)

def main():
    tab = [0, 1, 5, 32, 288, 3413, 50069, 873612, 17650828, 405071317]

    assert(power(1) == "1")
    assert(power(2) == "5")
    assert(power(3) == "32")
    assert(power(10) == "405071317")

    for i in range(len(tab)):
        assert(int(power(i)) == tab[i])

main()
