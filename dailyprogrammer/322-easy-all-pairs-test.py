#!/usr/bin/env python3

"""

Description
In the world of software testing there is a combinatorial shortcut to exhaustive testing called "All Pairs" or "Pairwise Testing". The gist of this kind of testing is based on some old research that found for a given scenario1 -- a web form, for example -- most errors were caused either by 1 element, or the interaction of a pair of elements. So, rather than test every single combination of possible inputs, if you carefully chose your test cases so that each possible combination of 2 elements appeared at least once in the test cases, then you'd encounter the majority of the problems. This is helpful because for a form with many inputs, the exhaustive list of combinations can be quite large, but doing all-pairs testing can reduce the list quite drastically.

Say on our hypothetical web form, we have a checkbox and two dropdowns.

The checkbox can only have two values: 0 or 1

The first dropdown can have three values: A B or C

The second dropdown can have four values: D E F or G

For this form, the total number of possible combinations is 2 x 3 x 4 = 24. But if we apply all pairs, we can reduce the number of tests to 12:

0 A G
0 B G
0 C D
0 C E
0 C F
1 A D
1 A E
1 A F
1 B D
1 B E
1 B F
1 C G
Note: Depending on how you generate the set, there can be more than one solution, but a proper answer must satisfy the conditions that each member of the set must contain at least one pair which does not appear anywhere else in the set, and all possible pairs of inputs are represented somewhere in the set. For example, the first member of the set above, 0AG contains the pairs '0A' and 'AG' which are not represented anywhere else in the set. The second member, '0BG' contains 'OG' and 'BG' which are not represented elsewhere. And so on and so forth.

So, the challenge is, given a set of possible inputs, e.g. [['0', '1'], ['A', 'B', 'C'], ['D', 'E', 'F', 'G']] output a valid all-pairs set such that the conditions in bold above is met.

1 There are some restrictions as to where this is applicable.

Challenge Inputs
[['0', '1'], ['A', 'B', 'C'], ['D', 'E', 'F', 'G']]
[['0', '1', '2', '3'], ['A', 'B', 'C', 'D'], ['E', 'F', 'G', 'H', 'I']]
[['0', '1', '2', '3', '4'], ['A', 'B', 'C', 'D', 'E'], ['F', 'G', 'H', 'I'], ['J', 'K', 'L']]
Challenge Outputs
(Because there are multiple valid solutions, this is the length of the output set - bonus points if you find a valid set with a lower length than one of these answers.)

12
34
62
Additional Reading
Wikipedia: All-pairs testing

DevelopSense -- for hints on how to generate the pairs, and more info on testing, its limitations and stuff

Credit
This challenge was suggested by user u/abyssalheaven, many thanks! If you have an idea for a challenge, please share it in r/dailyprogrammer_ideas and there's a good chance we'll use it.

"""

from itertools import product, combinations

# ported from @speakerforthe solution
def allpairs(testcase):
    pairs = set()
    tests = []
    for threshold in range(len(testcase), 0, -1):
        for possible_test in product(*testcase):
            new_pairs = { frozenset(pair) for pair in combinations(possible_test, 2) }
            if len(new_pairs - pairs) >= threshold:
                tests.append(possible_test)
                pairs |= new_pairs
    assert (sum(len(a)*len(b) for a, b in combinations(testcase, 2)) == len(pairs))
    return tests

def main():
    test1 = [['0', '1'], ['A', 'B', 'C'], ['D', 'E', 'F', 'G']]
    test2 = [['0', '1', '2', '3'], ['A', 'B', 'C', 'D'], ['E', 'F', 'G', 'H', 'I']]
    test3 = [['0', '1', '2', '3', '4'], ['A', 'B', 'C', 'D', 'E'], ['F', 'G', 'H', 'I'], ['J', 'K', 'L']]

    print(allpairs(test1))
    print(allpairs(test2))
    print(allpairs(test3))

main()
