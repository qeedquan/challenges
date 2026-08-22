#!/usr/bin/env python3

"""

To check whether a decimal number is divisible by 7:

Erase the last digit. Multiply it by 2 and subtract from what is left. If the result is divisible by 7, the original number is divisible by 7.

(also described e.g. here)

This rule is good for manual divisibility check. For example:

Is 2016 divisible by 7?

Subtract 6*2 from 201; we get 189. Is this divisible by 7? To check it, let's apply the rule again.

Subtract 9*2 from 18; we get 0. Therefore, 2016 is divisible by 7.

In this challenge, you should apply this rule until the divisibility status is obvious, that is, the number is not greater than 70 (however, see below for details). Make a function or a full program.

Input: a positive integer; your code should support inputs up to 32767 (supporting arbitrary-precision integers is a bonus; see below).

Output: an integer (possibly negative), not greater than 70, that is a result of applying the divisibility-by-7 rule zero or more times.

Test cases:

Input                   Output      Alternative output

1                       1
10                      10          1
100                     10          1
13                      13          -5
42                      42          0
2016                    0
9                       9
99                      -9
9999                    -3
12345                   3
32767                   28          -14

---------- Values below are only relevant for the bonus

700168844221            70          7
36893488147419103232    32          -1
231584178474632390847141970017375815706539969331281128078915168015826259279872    8
Where two possible outputs are specified, either result is correct: the second one corresponds to applying the rule one more time. It's forbidden to apply the rule on a single-digit number: if you erase the digit, nothing (not 0) is left.

Bonus: If your algorithm

Supports arbitrary-precision integers
Performs only one pass on the input
Has space complexity o(n) (i.e. less than O(n)); and
Has time complexity O(n),
where n is the number of decimal digits:

Subtract 50% from your code's byte count.

Real bonus:

In addition, if your algorithm reads the input in normal direction, starting from the most significant digit, subtract 50% once again - your score is 25% of your byte count (it seems possible, but I'm not absolutely sure).

"""

def next(n):
    return n//10 - 2*(n%10)

def apply7(n):
    while n > 70:
        n = next(n)
    return n

def main():
    assert(apply7(1) == 1)
    assert(apply7(10) == 10)
    assert(apply7(100) == 10)
    assert(apply7(13) == 13)
    assert(apply7(42) == 42)
    assert(apply7(2016) == 0)
    assert(apply7(9) == 9)
    assert(apply7(99) == -9)
    assert(apply7(9999) == -3)
    assert(apply7(12345) == 3)
    assert(apply7(32767) == 28)
    assert(apply7(700168844221) == 70)
    assert(apply7(36893488147419103232) == 32)
    assert(apply7(231584178474632390847141970017375815706539969331281128078915168015826259279872) == 8)

main()
