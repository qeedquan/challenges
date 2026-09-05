#!/usr/bin/env python3

"""

In the programming language Uiua, there is a higher-order function called tuples which is a generalization of getting the permutations or combinations of an array.
Tuples takes a list a, a sample size r, and a function f taking two numbers representing indices of a and returning a boolean.
It returns the list of all length-r combinations of items from a whose pairs of indices all pass f.
Essentially, facts as a filter for which combinations will be returned.

This may seem like a strange abstraction, but it allows the use of simple comparison operators to determine which combinations should be given.

For the sake of simplicity, we will consider a version which does not take a list a but instead takes an object count n, which would be the length of said list.

Consider a call to tuples with six objects, sample size three, and f checking that the first index is less than the second.
If you look at all possible combinations of three nonnegative integers less than six, you will find that there are twenty for which all pairs where the first comes before the second (i.e. a,b and a,c and b,c but not b,a or c,a or c,b) pass f:

   0 1 2        0 1 3        0 1 4        0 1 5
0<1,0<2,1<2  0<1,0<3,1<3  0<1,0<4,1<4  0<1,0<5,1<5

   0 2 3        0 2 4        0 2 5        0 3 4
0<2,0<3,2<3  0<2,0<4,2<4  0<2,0<5,2<5  0<3,0<4,3<4

   0 3 5        0 4 5        1 2 3        1 2 4
0<3,0<5,3<5  0<4,0<5,4<5  1<2,1<3,2<3  1<2,1<4,2<4

   1 2 5        1 3 4        1 3 5        1 4 5
1<2,1<5,2<5  1<3,1<4,3<4  1<3,1<5,3<5  1<4,1<5,4<5

   2 3 4        2 3 5        2 4 5        3 4 5
2<3,2<4,3<4  2<3,2<5,3<5  2<4,2<5,4<5  3<4,3<5,4<5

These are the increasing combinations without replacement. Using the same values for n and r, but replacing f with a comparison that the first index is greater than or equal to the second gives 56 -- the decreasing combinations with replacement (showing only two of the three comparisons for demonstrative purposes):

0≥0≥0  1≥0≥0  1≥1≥0  1≥1≥1  2≥0≥0  2≥1≥0  2≥1≥1  2≥2≥0
2≥2≥1  2≥2≥2  3≥0≥0  3≥1≥0  3≥1≥1  3≥2≥0  3≥2≥1  3≥2≥2
3≥3≥0  3≥3≥1  3≥3≥2  3≥3≥3  4≥0≥0  4≥1≥0  4≥1≥1  4≥2≥0
4≥2≥1  4≥2≥2  4≥3≥0  4≥3≥1  4≥3≥2  4≥3≥3  4≥4≥0  4≥4≥1
4≥4≥2  4≥4≥3  4≥4≥4  5≥0≥0  5≥1≥0  5≥1≥1  5≥2≥0  5≥2≥1
5≥2≥2  5≥3≥0  5≥3≥1  5≥3≥2  5≥3≥3  5≥4≥0  5≥4≥1  5≥4≥2
5≥4≥3  5≥4≥4  5≥5≥0  5≥5≥1  5≥5≥2  5≥5≥3  5≥5≥4  5≥5≥5

Tuples is usually used with the comparison operations <, ≤, >, ≥, and ≠, as these are generally the most useful, but it can work with any function of two nonnegative integers to a boolean.
For example, a function that ignores both inputs and returns a random boolean is perfectly valid.

Your task is to implement this tuples function. You may assume r will be greater than or equal to 2.
f can be taken as an anonymous function argument, as some reasonable string representation of the function source in your language, or if in your language you cannot take an anonymous function argument you may assume that there is a named function called f already defined.
Rather than taking the number n, you may choose to take a list of length n and output its corresponding combinations based on its indices.
Each length-r list should be ordered, but the collection of these tuples which you output may be unordered.

In the below test cases, f is represented as an infix expression assuming x is the first index and y is the second.

n  r  f     output

4  3  x>y   2 1 0 ; 3 1 0 ; 3 2 0 ; 3 2 1
3  3  x≥y   0 0 0 ; 1 0 0 ; 1 1 0 ; 1 1 1 ; 2 0 0 ; 2 1 0 ; 2 1 1 ; 2 2 0 ; 2 2 1 ; 2 2 2
3  3  x≠y   0 1 2 ; 0 2 1 ; 1 0 2 ; 1 2 0 ; 2 0 1 ; 2 1 0
4  3  y>1   0 2 2 ; 0 2 3 ; 0 3 2 ; 0 3 3 ; 1 2 2 ; 1 2 3 ; 1 3 2 ; 1 3 3 ; 2 2 2 ; 2 2 3 ; 2 3 2 ; 2 3 3 ; 3 2 2 ; 3 2 3 ; 3 3 2 ; 3 3 3
3  2  x≠y   0 1 ; 0 2 ; 1 0 ; 1 2 ; 2 0 ; 2 1
5  2  x>2   3 0 ; 3 1 ; 3 2 ; 3 3 ; 3 4 ; 4 0 ; 4 1 ; 4 2 ; 4 3 ; 4 4
5  2  y>2   0 3 ; 0 4 ; 1 3 ; 1 4 ; 2 3 ; 2 4 ; 3 3 ; 3 4 ; 4 3 ; 4 4
3  4  x=y   0 0 0 0 ; 1 1 1 1 ; 2 2 2 2

"""

from itertools import product, combinations

def tuples(n, r, f):
    t = []
    for p in product(*[range(n)] * r):
        for x, y in combinations(p, 2):
            if not f(x, y):
                break
        else:
            t.append(p)
    return tuple(t)

def main():
    assert(tuples(4, 3, lambda x, y: x > y) == ((2, 1, 0), (3, 1, 0), (3, 2, 0), (3, 2, 1)))
    assert(tuples(3, 3, lambda x, y: x >= y) == ((0, 0, 0), (1, 0, 0), (1, 1, 0), (1, 1, 1), (2, 0, 0), (2, 1, 0), (2, 1, 1), (2, 2, 0), (2, 2, 1), (2, 2, 2)))
    assert(tuples(3, 3, lambda x, y: x != y) == ((0, 1, 2), (0, 2, 1), (1, 0, 2), (1, 2, 0), (2, 0, 1), (2, 1, 0)))
    assert(tuples(4, 3, lambda x, y: y > 1) == ((0, 2, 2), (0, 2, 3), (0, 3, 2), (0, 3, 3), (1, 2, 2), (1, 2, 3), (1, 3, 2), (1, 3, 3), (2, 2, 2), (2, 2, 3), (2, 3, 2), (2, 3, 3), (3, 2, 2), (3, 2, 3), (3, 3, 2), (3, 3, 3)))
    assert(tuples(3, 2, lambda x, y: x != y) == ((0, 1), (0, 2), (1, 0), (1, 2), (2, 0), (2, 1)))
    assert(tuples(5, 2, lambda x, y: x > 2) == ((3, 0), (3, 1), (3, 2), (3, 3), (3, 4), (4, 0), (4, 1), (4, 2), (4, 3), (4, 4)))
    assert(tuples(5, 2, lambda x, y: y > 2) == ((0, 3), (0, 4), (1, 3), (1, 4), (2, 3), (2, 4), (3, 3), (3, 4), (4, 3), (4, 4)))
    assert(tuples(3, 4, lambda x, y: x == y) == ((0, 0, 0, 0), (1, 1, 1, 1), (2, 2, 2, 2)))

main()

