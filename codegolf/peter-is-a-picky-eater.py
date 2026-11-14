#!/usr/bin/env python3

"""

There is a boy named Peter. Peter is a picky eater and doesn't like to eat the same kind of cookie again on the same day.

Peter gets a present, The present is a box of cookies! The box contains  K
  types of cookies. Also, it contains different amount of each type of cookie.

Peter, being the picky eater he is, Wants to eat  n
  cookies, on each  nth
  day. Also, he does not want to eat more than 1 cookie of the same kind on any given day.

i.e. He eats  1
  cookie on the  1st
  day,  2
  cookies on the  2nd
  day and so on.

If there is no possible way for Peter to eat  n
  cookies at day  n
 , he gives up and dumps the box. He also dumps the box if it becomes empty.

Find the maximum number of days that the box will last for Peter.

Input
K
  Positive Integers, specifying the number of cookies for each different kind.

Output
An Integer corresponding to how many days Peter keeps the box.

Test Cases
INPUT -> OUTPUT
1 2 -> 2
1 2 3 -> 3
1 2 3 4 4 -> 4
1 2 3 3 -> 3
2 2 2 -> 3
1 1 1 1 -> 2
11 22 33 44 55 66 77 88 99 -> 9
10 20 30 40 50 60 70 80 -> 8
3 3 3 3 3 3 3 3 3 3 3 -> 7
3 3 3 3 3 3 3 3 3 -> 6
9 5 6 8 7 -> 5
1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 4 4 5 5 5 5 5 5 5 5 5 5 5 5 6 6 6 6 6 6 6 6 6 6 6 6 7 7 7 7 7 7 7 7 7 7 7 7 8 8 8 8 8 8 8 8 8 8 8 8 9 9 9 9 9 9 9 9 9 9 9 9 10 10 10 10 10 10 10 10 10 10 10 10 -> 35
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 -> 32

Gist for test cases
https://gist.githubusercontent.com/EliteDaMyth/19479d4d3bc1f285dcfb8dc4d4ebfa3f/raw/132ca67a3e239b0a0e26ea0341e591493ec7dc22/testcases.txt

This is code-golf so the shortest code wins.

"""

# Ported from @michael-tkach solution
def f(a, n=-1):
    a = sorted([0] + a)
    if -1 in a:
        return -n - 2
    p = [x - 1 for x in a[n:]]
    q = a[:n]
    return f(p + q, n - 1)

def main():
    assert(f([1, 2]) == 2)
    assert(f([1, 2, 3]) == 3)
    assert(f([1, 2, 3, 4, 4]) == 4)
    assert(f([1, 2, 3, 3]) == 3)
    assert(f([2, 2, 2]) == 3)
    assert(f([1, 1, 1, 1]) == 2)
    assert(f([11, 22, 33, 44, 55, 66, 77, 88, 99]) == 9)
    assert(f([10, 20, 30, 40, 50, 60, 70, 80]) == 8)
    assert(f([3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3]) == 7)
    assert(f([3, 3, 3, 3, 3, 3, 3, 3, 3]) == 6)
    assert(f([9, 5, 6, 8, 7]) == 5)
    assert(f([1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10]) == 35)
    assert(f([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]) == 32)

main()
