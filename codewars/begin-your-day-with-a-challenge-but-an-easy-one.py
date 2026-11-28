#!/usr/bin/env python3

"""

There are no explanations. You have to create the code that gives the following results in Python and Ruby:

one_two_three(0) == [0, 0]
one_two_three(1) == [1, 1]
one_two_three(2) == [2, 11]
one_two_three(3) == [3, 111]
one_two_three(19) == [991, 1111111111111111111]
And it should give the following results in Javascript:

oneTwoThree(0) == ['0', '0']
oneTwoThree(1) == ['1', '1']
oneTwoThree(3) == ['3', '111']
oneTwoThree(19) == ['991', '1111111111111111111']q

"""

def one_two_three(n):
    s = "0"
    t = "0"
    if n > 0:
        s = "9"*(n//9)
        t = "1"*n
    if n % 9:
        s += str(n % 9)
    return [int(s), int(t)]

def main():
    assert(one_two_three(0) == [0, 0])
    assert(one_two_three(1) == [1, 1])
    assert(one_two_three(2) == [2, 11])
    assert(one_two_three(3) == [3, 111])
    assert(one_two_three(19) == [991, 1111111111111111111])

main()
