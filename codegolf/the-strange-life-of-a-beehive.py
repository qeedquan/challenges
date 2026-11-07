#!/usr/bin/env python3

"""

Researchers recently discovered an interesting bee colony that lives in an infinite field of honeycomb:

https://i.sstatic.net/1B983.png

Each cell can house a bee or not. In fact, the lives of those creatures appear to be a bit ... chaotic. It could be calculated that a colony always starts with the following pattern:

https://i.sstatic.net/Y0UE6.png

(Bee drawn by Emmanuel Boutet on Wikimedia Commons. This honeycomb-and-bees image thus is released under CC-By-SA. grumbles)

After that the bee's life cycles are divided into so-called generations. Each generation old bees die and new ones hatch and it primarily depends on their cell's neighbors:

If a bee has less than two neighbors it dies due to loneliness.
If a bee has more than three neighbors it dies due to overcrowding.
If a cell has two, three or four living bees in neighboring cells a new bee hatches there in the next generation.
Dying bees don't die until the end of a generation so they still affect surrounding cells that might hatch bees in the next generation.

Now that we know how such a colony works, we can simulate it through any number of generations.

Input

Input is a single number N, given on standard input, terminated by a line break. 0 ≤ N ≤ 150. This is the number of generations to simulate.

Output

Output is a single number, on standard output and optionally followed by a single line break, which represents the number of living bees after N generations.

Additional output on standard error is ignored.

Sample inputs

0
5
42
100
Sample outputs

6
44
1029
5296
Winning condition

Shortest code wins, as is customary in golf. In case of a tie, the earlier solution wins.

Test cases

There are two tests scripts, containing identical test cases:

bash
PowerShell
Invocation is in both cases: <test script> <my program> [arguments], e.g. ./test ruby beehive.rb or ./test.ps1 ./beehive.exe.

I know there are only 22 tests instead of 151 (mainly because solutions are often quite slow). Please refrain from embedding the exact test cases instead of solving the task. These scripts are a convenience for you to test whether a change still causes the program to behave correctly; not that you can adapt your code to the specific test cases.

Another note

This task was part of a golf contest held at my university during 2011-W24. The scores and languages of our contestants were as follows:

336 – C
363 – C
387 – C
389 – Haskell
455 – C
Our own solution was

230 – Ruby

"""

from collections import Counter

# Ported from @Keith Randall solution
def bees(generations):
    points = [0, 2, 3, 1j, 1 + 1j, 1 - 1j]
    steps = (1, -1, 1j, -1j, 1j - 1, 1 - 1j)

    for _ in range(generations):
        candidates = []
        for point in points:
            for step in steps:
                candidates.append(point + step)
        counts = Counter(candidates)

        new_points = []
        for point, count in counts.items():
            offset = 0
            if point in points:
                offset = 1
            
            if 1 < count and count < 5-offset:
                new_points.append(point)
        points = set(new_points)

    return len(points)

def main():
    assert(bees(0) == 6)
    assert(bees(1) == 10)
    assert(bees(2) == 12)
    assert(bees(3) == 26)
    assert(bees(4) == 22)
    assert(bees(5) == 44)
    assert(bees(6) == 34)
    assert(bees(7) == 70)
    assert(bees(8) == 54)
    assert(bees(9) == 100)
    assert(bees(10) == 73)
    assert(bees(15) == 224)
    assert(bees(20) == 276)
    assert(bees(30) == 508)
    assert(bees(42) == 1029)
    assert(bees(75) == 3020)
    assert(bees(99) == 5748)
    assert(bees(100) == 5296)
    assert(bees(125) == 8655)
    assert(bees(140) == 10297)
    assert(bees(149) == 11997)
    assert(bees(150) == 11932)

main()
