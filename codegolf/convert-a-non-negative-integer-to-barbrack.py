#!/usr/bin/env python3

"""

Barbrack
Your task is to write a program or function that takes a non-negative integer (in decimal or any other convenient base for your language), and output a number in the numbering system Barbrack.

What's that?
Barbrack is a numbering system I made up that can represent non-negative integers. Zero is represented with an empty string or an underscore, one is represented with [], and all other positive integers can be represented with a brack.

A brack is delimited with brackets [] and works as follows (with an example of 84):

Take your number a and find its prime factorization. In this case, the prime factorization of 84 is 22*31(*50)*71.
Find the indices of these primes, where the index of 2 is 1. In this case, the index of 3 is 2, since it's the prime right after 2; and the index of 7 is 4, since it's the fourth prime.
Take the exponents of each prime, and put them in brackets in increasing order of the size of the prime, with consecutive exponents being separated by bars (|). So the general format is [exponent of 2|exponent of 3|exponent of 5…]—in this case, [2|1|0|1]. Minimize the number of cells!
Recursively calculate the exponents in Barbrack, remembering that 0 is the empty string and 1 is []. So [2|1|0|1] => [[1]|[]||[]] => [[[]]|[]||[]].
Output the final result.

Test inputs
0     -> (nothing)
1     -> []
2     -> [[]]
5     -> [||[]]
27    -> [|[|[]]]
45    -> [|[[]]|[]]
54    -> [[]|[|[]]]
84    -> [[[]]|[]||[]]
65535 -> [|[]|[]||||[](48 bars)[]]
65536 -> [[[[[]]]]]
(sidenote: (48 bars) means 48 consecutive bars in the actual output)

Rules
Standard loopholes apply.
No input in Barbrack! This isn't a cat challenge!
You may replace [] with any other paired delimeter, like () or {}. However, the vertical bars need to be actual vertical bars.
Whitespace is not allowed within the number, but is allowed outside of it (for example, a trailing newline).
The program should be able to fully parse any number given infinite time and memory.

Scoring
Scores are counted by minimum bytes on a per-language basis.

"""

# ported from @ovs solution
def int2barbrack(n):
    if n < 1:
        return ""

    r = ""
    p = 2
    i = 2
    while n > 1:
        w = 1
        while n%i < 1:
            n //= i
            w += 1
        r += "|"*(p % i) + int2barbrack(w - 1)
        p *= i * i * 2
        i += 1
    return "[%s]" % (r * n)

def main():
    assert(int2barbrack(0) == "")
    assert(int2barbrack(1) == "[]")
    assert(int2barbrack(2) == "[[]]")
    assert(int2barbrack(5) == "[||[]]")
    assert(int2barbrack(45) == "[|[[]]|[]]")
    assert(int2barbrack(84) == "[[[]]|[]||[]]")
    assert(int2barbrack(65535) == "[|[]|[]||||[]||||||||||||||||||||||||||||||||||||||||||||||||[]]")
    assert(int2barbrack(65536) == "[[[[[]]]]]")

main()
