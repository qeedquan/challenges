#!/usr/bin/env python3

"""

Baloo, a lazy brown bear, teaches wolf cubs the Law of the Jungle. He is free to wander wherever he pleases, because he eats only nuts, honey, and roots.

This story takes place when the bear Baloo was teaching Mowgli the Law of the Jungle. The large and respected brown bear was proud of his pupil's abilities, as wolf cubs typically learn only what their Pack and tribe require from the Law. But Mowgli, being a human child, needed to know much more.

During arithmetic lessons, Baloo invented the following game. One must obtain the number n starting from 1.
At each step, you may either multiply the current number by 3, or add 4 to the current number.
For each multiplication, Baloo gives 5 cuffs, and for each addition, 2 cuffs. For example,

https://static.e-olymp.com/content/be/bee9bfd85f211a971d795b6bd0b00b65e0d4a42b.jpg

in the first case you get 10 cuffs, and in the second case you get 12 cuffs.

Naturally, Mowgli learned arithmetic best of all and quickly figured out how to solve the problem, obtaining the least number of cuffs.
He also noticed that it is not always possible to complete the task set by the cunning bear...

Input
One integer n (1≤n≤10^9).

Output
Print the minimum number of cuffs required to solve the problem. If the problem cannot be solved, print the number 0.

Examples

Input #1
21

Answer #1
10

Input #2
100

Answer #2
0

"""

from functools import lru_cache

@lru_cache(maxsize=None)
def f(n):
    if n < 2 or n%2 == 0:
        return 0
    if n == 3:
        return 5
    if n == 5:
        return 2

    r = f(n-4) + 2
    if n%3 == 0:
        r = min(r, f(n//3) + 5)
    return r

def solve(n):
    return f(n)

def main():
    assert(solve(21) == 10)
    assert(solve(100) == 0)

main()

