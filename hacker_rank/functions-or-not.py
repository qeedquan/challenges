#!/usr/bin/env python3

"""

Objective
In this problem, we touch upon a basic concept that is fundamental to Functional Programming: identifying a relation which represents a valid function.

Task
You are given a set of unique (x, y) ordered pairs constituting a relation. The x-values form the domain, and the y-values form the range to which they map.
For each of these relations, identify whether they may possibly represent a valid function or not.

Note: You do not have to find the actual function, you just need to determine that the relation may be representative of some valid function.

Input Format

The first line contains an integer, T, denoting the number of test cases. The subsequent lines describe T test cases, and the input for each test case is as follows:

The first line contains an integer, N, the number of  pairs in the test case.
The N subsequent lines each contain two space-separated integers describing the respective x and y values for each ordered pair.

Constraints
1 <= T <= 5
2 <= N <= 100
0 <= x, y <= 500
x and are both integers

Output Format

On a new line for each test case, print YES if the set of ordered pairs represent a valid function, or NO if they do not.

Sample Input

2
3
1 1
2 2
3 3
4
1 2
2 4
3 6
4 8

Sample Output

YES
YES
Explanation

Test Case 0:
N = 3, Ordered Pairs: (1, 1) (2, 2) (3, 3) The set of ordered pairs represents a relation, which could represent a function such as f: N -> N, f(x) = x. Thus, we print YES on a new line.

Test Case 1:
N = 4, Ordered Pairs (1, 2) (2, 4), (3, 6) (4, 8):
The set of ordered pairs represents a relation, which could represent a function such as f: N -> N, f(x) = 2*x. Thus, we print YES on a new line.

"""

def function(p):
    m = {}
    for x, y in p:
        if x not in m:
            m[x] = y
        if m[x] != y:
            return False
    return True

def main():
    assert(function([[1, 1], [2, 2], [3, 3]]) == True)
    assert(function([[1, 2], [2, 4], [3, 6], [4, 8]]) == True)
    assert(function([[1, 1], [2, 2], [2, 3]]) == False)

main()
