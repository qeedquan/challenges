#!/usr/bin/env python3

"""

Given a string, str = s1, s2, ..., sn, consisting of n lowercase English characters (a-z), remove all of the characters that occurred previously in the string. Formally, remove all characters, si, for:

j, sj = si and j < i

Input Format

A single line of input containing a string str of length n.

Constraints
1 <= n <= 10^5
si in {a, ..., z} where 1 <= i <= n

Output Format

Print the string after removing all the characters that occurred previously.

Sample Input #00

accabb
Sample Output #00

acb
Sample Input #01

abc
Sample Output #01

abc
Sample Input #02

pprrqq
Sample Output #02

prq
Explanation

Test case #00: For str="accabb", characters at indexes 3, 4, 6 are removed as they have already occurred.
Test case #01: As each character occurs only once, nothing is removed.
Test case #02: For str="pprrqq", each character occurs twice. The second of these characters is removed. Characters at positions 2, 4 and 6 are removed.

"""

def reduce(s):
    d = dict.fromkeys(s)
    return "".join(d)

def main():
    assert(reduce("accabb") == "acb")
    assert(reduce("abc") == "abc")
    assert(reduce("pprrqq") == "prq")

main()
