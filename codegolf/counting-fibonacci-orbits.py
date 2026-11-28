#!/usr/bin/env python3

"""

If we define a Fibonacci-like sequence as fk(n) = (fk(n-1) + fk(n-2)) % k, for some integer k (where % is the modulo operator), the sequence will necessarily be cyclic, because there are only k2 different values for (fk(n-1), fk(n-2)). However, this cycle doesn't usually include all possible pairs of values, so depending on the two starting values fk(0) and fk(1), we might get different cycles. For example, for k = 2, we have the following four possibilities, depending on the first two values:

0, 0, 0, 0, 0, 0, 0, 0, 0, ...
0, 1, 1, 0, 1, 1, 0, 1, 1, ...
1, 0, 1, 1, 0, 1, 1, 0, 1, ...
1, 1, 0, 1, 1, 0, 1, 1, 0, ...
Due to the cyclic nature of the sequences, there are really only two fundamentally different sequences here, with orbits (0) and (0, 1, 1). Let's look at k = 3:

0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ...
0, 1, 1, 2, 0, 2, 2, 1, 0, 1, 1, 2, 0, 2, 2, 1, ...
0, 2, 2, 1, 0, 1, 1, 2, 0, 2, 2, 1, 0, 1, 1, 2, ...
1, 0, 1, 1, 2, 0, 2, 2, 1, 0, 1, 1, 2, 0, 2, 2, ...
1, 1, 2, 0, 2, 2, 1, 0, 1, 1, 2, 0, 2, 2, 1, 0, ...
1, 2, 0, 2, 2, 1, 0, 1, 1, 2, 0, 2, 2, 1, 0, 1, ...
2, 0, 2, 2, 1, 0, 1, 1, 2, 0, 2, 2, 1, 0, 1, 1, ...
2, 1, 0, 1, 1, 2, 0, 2, 2, 1, 0, 1, 1, 2, 0, 2, ...
2, 2, 1, 0, 1, 1, 2, 0, 2, 2, 1, 0, 1, 1, 2, 0, ...
Again, there are only two different orbits: (0) and (0, 1, 1, 2, 0, 2, 2, 1).

For higher k we might get more orbits, but they will still fall into a comparably small number of classes. For example k = 4 yields the four orbits (0), (0,1,1,2,3,1), (0, 2, 2), (0, 3, 3, 2, 1, 3) and k = 5 the three orbits (0), (0, 1, 1, 2, 3, 0, 3, 3, 1, 4, 0, 4, 4, 3, 2, 0, 2, 2, 4, 1) and (1, 3, 4, 2).

Your task in this challenge is to compute how many orbits the sequence generates for a given k. This is OEIS A015134. Here are the first 100 values (starting from k = 1):

1, 2, 2, 4, 3, 4, 4, 8, 5, 6, 14, 10, 7, 8, 12, 16, 9, 16, 22, 16,
29, 28, 12, 30, 13, 14, 14, 22, 63, 24, 34, 32, 39, 34, 30, 58, 19,
86, 32, 52, 43, 58, 22, 78, 39, 46, 70, 102, 25, 26, 42, 40, 27, 52,
160, 74, 63, 126, 62, 70, 63, 134, 104, 64, 57, 78, 34, 132, 101, 60,
74, 222, 37, 38, 62, 328, 89, 64, 82, 124, 41, 86, 42, 172, 75, 44,
184, 178, 181, 132, 82, 180, 99, 140, 104, 246, 49, 50, 114, 76
Make sure to check k = 11, which is the first input which yields more than k orbits.

Rules
You're given a positive integer k and should output A015134(k).

You may write a program or a function and use any of the standard methods of receiving input and providing output.

You may use any programming language, but note that these loopholes are forbidden by default.

This is code-golf, so the shortest valid answer – measured in bytes – wins.

"""

"""

Ported from @dylnan solution

https://oeis.org/A015134

"""

def orbit(k):
    cycles = []
    for i in range(k*k):
        a = i // k
        b = i % k
        sequence = [a, b, (a + b) % k]
        while sequence[-2:] != sequence[:2]:
            sequence.append((sequence[-2] + sequence[-1]) % k)

        cycle = sequence[:-2]
        duplicate = any(
            cycle == existing[offset:] + existing[:offset]
            for existing in cycles
            for offset in range(len(existing))
        )
        if not duplicate:
            cycles.append(cycle)

    return len(cycles)

def main():
    table = [
        1, 2, 2, 4, 3, 4, 4, 8, 5, 6, 14, 10, 7, 8, 12, 16, 9, 16, 22, 16, 29,
        28, 12, 30, 13, 14, 14, 22, 63, 24, 34, 32, 39, 34, 30, 58, 19, 86, 32,
        52, 43, 58, 22, 78, 39, 46, 70, 102, 25, 26, 42, 40, 27, 52, 160, 74,
        63, 126, 62, 70, 63, 134, 104, 64, 57, 78, 34, 132, 101, 60, 74, 222
    ]

    for i in range(len(table)):
        assert(orbit(i + 1) == table[i])

main()
