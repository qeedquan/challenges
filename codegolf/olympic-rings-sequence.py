#!/usr/bin/env python3

"""

Challenge:
Given an index integer n, either output the n'th item in this sequence, or output the sequence up to and including index n:

25,25,7,28,29,20,21,22,23,14,35,26,7,28,29,20,16,29,12,15,28,21,14,17,30,13,16,29,12,15,28,21,10,6,12,18,15,11,7,13,19,17,13,9,15,21,18,14,10,16,22,19,15,11,17,23,20,16,12,18,24,21,17,13,19,25,23,19,15,21,27,24,20,16,22,28,25,21,17,23,29,16,13,9,15,21,18,14,10,16,22,20,16,12,18,24,21,17,13,19

How does this sequence work?
NOTE: In this explanation, index n is 1-indexed.
Put the numbers 1 through x on two lines of length n*6 - 1, where x depends on the current iteration and the length of the numbers used, and then sum the digits of the n'th/right-most Olympic Rings of those two lines.

The first number in the sequence is calculated as follows:

The length of the lines are 5 (because 1*6 - 1 = 5):
12345
67891(0)

Then leave the digits in an Olympic Rings pattern:
1 3 5
 7 9

And sum them:
1+3+5+7+9 = 25
So n=1 results in 25.

The second number in the sequence is calculated as follows:

The length of the lines are 11 (because 2*6 - 1 = 11):
12345678910
11121314151(6)

Then leave the digits in the second/right-most Olympic Rings pattern:
      7 9 0
       4 5

And sum them:
7+9+0+4+5 = 25
So n=2 results in 25.

The third number in the sequence is calculated as follows:

The length of the lines are 17 (because 3*6 - 1 = 17):
12345678910111213
14151617181920212(2)

Then leave the digits in the third/right-most Olympic Rings pattern:
            1 2 3
             0 1

And sum them:
1+2+3+0+1 = 7
So n=3 results in 7.

etc.

Challenge rules:
When you output the n'th item in the sequence, you are allowed to take the input as 0-indexed instead of 1-indexed, but keep in mind that the calculations of n*6 - 1 will then become (n+1)*6 - 1 or (n+1)*5 + n.
Single numbers of more than one digit can be split up at the end of the first line when we've reached the length n*5 + n-1, so it is possible that a number with 2 or more digits is partially the trailing part of line 1, and partially the leading part of line 2.
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.
Test cases:
Here is a paste-bin of the test cases 1-1,000, so feel free to choose any of them.

Some additional higher test cases:

1010:   24
1011:   24
2500:   19
5000:   23
7500:   8
10000:  8
100000: 25

"""

def olympic_rings(n):
    if n < 1:
        return 0

    n *= 6
    s = ''
    for i in range(1, n*2):
        s += str(i)

    r = 0
    for p in (n-2, n-4, n-6, n*2 - 4, n*2 - 6):
        r += int(s[p])
    return r

def main():
    tab = [
        25, 25, 7, 28, 29, 20, 21, 22, 23, 14, 35, 26, 7, 28, 29, 20, 16, 29,
        12, 15, 28, 21, 14, 17, 30, 13, 16, 29, 12, 15, 28, 21, 10, 6, 12, 18,
        15, 11, 7, 13, 19, 17, 13, 9, 15, 21, 18, 14, 10, 16, 22, 19, 15, 11,
        17, 23, 20, 16, 12, 18, 24, 21, 17, 13, 19, 25, 23, 19, 15, 21, 27, 24,
        20, 16, 22, 28, 25, 21, 17, 23, 29, 16, 13, 9, 15, 21, 18, 14, 10, 16,
        22, 20, 16, 12, 18, 24, 21, 17, 13, 19, 25, 22, 18, 14, 20, 26, 23, 19,
        15, 21, 27, 24, 20, 16, 22, 28, 26, 22, 18, 24, 30, 27, 23, 19, 25, 31,
        28, 24, 20, 26, 32, 19, 16, 12, 18, 24, 21, 17, 13, 19, 25, 23, 19, 15,
        21, 27, 24, 20, 16, 22, 28, 25, 21, 17, 23, 29, 26, 22, 18, 24, 30, 27,
        23, 19, 25, 31, 29, 25, 21, 27, 33, 30, 26, 22, 28, 34, 31, 27, 23, 29,
        35, 22, 19, 15, 21, 27, 24, 20, 16, 22, 28, 26, 22, 18, 24, 30, 27, 23,
        19, 25, 31, 28, 24, 20, 26, 32, 29, 25, 21, 27, 33, 30, 26, 22, 28, 34,
        32, 28, 24, 30, 36, 33, 29, 25, 31, 37, 34, 30, 26, 32, 38, 25, 22, 18,
        24, 30, 27, 23, 19, 25, 31, 18, 13, 18, 13, 18, 24, 9, 14, 19, 24, 20,
        15, 20, 15, 20, 26, 11, 16, 21, 26, 22, 17, 22, 17, 22, 28, 13, 18, 23,
        28, 24, 19, 24, 20, 25, 31, 16, 21, 26, 31, 17, 13, 18, 13, 18, 24, 9,
        14, 19, 24, 20, 15, 20, 15, 20, 26, 11, 16, 21, 26, 22, 17, 22, 17, 22,
        28, 14, 19, 24, 29, 25, 20, 25, 20, 25, 31, 16, 21, 26, 31, 27, 22, 27,
        22, 27, 33, 18, 23, 28, 33, 19, 15, 20, 15, 20, 26, 11, 16, 21, 26, 23,
        18, 23, 18, 23, 29, 14, 19, 24, 29, 25, 20, 25, 20, 25, 31, 16, 21, 26,
        31, 27, 22, 27, 22, 27, 33, 18, 23, 28, 33, 29, 24, 29, 25, 30, 36, 21,
        26, 31, 36, 22, 18, 23, 18, 23, 29, 14, 19, 24, 29, 25, 20, 25, 20, 25,
        31, 16, 21, 26, 31, 27, 22, 27, 22, 27, 33, 19, 24, 29, 34, 30, 25, 30,
        25, 30, 36, 21, 26, 31, 36, 32, 27, 32, 27, 32, 38, 23, 28, 33, 38, 24,
        20, 25, 20, 25, 31, 16, 21, 26, 31, 28, 23, 28, 23, 28, 34, 19, 24, 29,
        34, 30, 25, 30, 25, 30, 36, 21, 26, 31, 36, 32, 27, 32, 27, 32, 38, 23,
        28, 33, 38, 34, 29, 34, 30, 35, 41, 26, 31, 36, 41, 27, 13, 17, 15, 16,
        27, 15, 19, 14, 21, 13, 23, 22, 25, 11, 17, 10, 19, 19, 31, 18, 13, 17,
        15, 16, 27, 16, 20, 15, 22, 14, 24, 23, 26, 12, 18, 11, 20, 20, 32, 19,
        14, 18, 16, 17, 28, 16, 20, 15, 22, 14, 24, 23, 26, 12, 18, 11, 20, 20,
        32, 20, 15, 19, 17, 18, 29, 17, 22, 18, 24, 17, 26, 26, 28, 15, 20, 14,
        22, 23, 34, 22, 16, 21, 18, 20, 30, 19, 22, 18, 24, 17, 26, 26, 19, 6,
        11, 5, 13, 14, 25, 13, 7, 12, 9, 11, 21, 10, 13, 9, 15, 8, 17, 17, 19,
        6, 11, 5, 13, 14, 25, 13, 7, 12, 9, 11, 21, 11, 14, 10, 16, 9, 18, 18,
        20, 9, 13, 8, 15, 17, 27, 16, 9, 15, 11, 14, 23, 13, 15, 12, 17, 11,
        19, 20, 21, 9, 13, 8, 15, 17, 27, 17, 10, 16, 12, 15, 24, 14, 16, 13,
        18, 12, 20, 21, 22, 10, 14, 9, 16, 18, 28, 17, 10, 16, 12, 15, 24, 14,
        16, 13, 18, 12, 20, 21, 23, 11, 15, 10, 17, 19, 29, 19, 12, 19, 14, 18,
        26, 17, 18, 16, 20, 15, 22, 24, 24, 13, 16, 12, 18, 21, 30, 20, 12, 19,
        14, 18, 26, 18, 19, 17, 21, 16, 23, 25, 25, 14, 17, 13, 19, 22, 31, 21,
        13, 20, 15, 19, 27, 18, 19, 17, 21, 16, 23, 25, 25, 14, 17, 13, 19, 22,
        31, 22, 14, 21, 16, 20, 28, 19, 21, 20, 23, 19, 25, 28, 27, 17, 19, 16,
        21, 25, 33, 24, 15, 23, 17, 22, 29, 21, 21, 20, 23, 19, 25, 28, 28, 18,
        20, 17, 22, 26, 34, 25, 16, 24, 18, 23, 30, 22, 22, 21, 24, 20, 26, 29,
        28, 18, 20, 17, 22, 26, 34, 25, 16, 24, 18, 23, 30, 23, 23, 22, 25, 21,
        27, 30, 29, 21, 22, 20, 24, 29, 36, 28, 18, 27, 20, 26, 32, 25, 24, 24,
        26, 23, 28, 32, 30, 21, 22, 20, 24, 29, 36, 29, 19, 28, 21, 27, 33, 26,
        25, 25, 27, 24, 29, 33, 31, 22, 23, 21, 25, 30, 37, 29, 19, 28, 21, 27,
        33, 26, 25, 25, 27, 24, 29, 33, 32, 23, 24, 22, 26, 31, 38, 31, 21, 31,
        23, 30, 35, 29, 27, 28, 29, 27, 31, 36, 33, 25, 25, 24, 27, 33, 39, 32,
        21, 31, 23, 30, 35, 20, 18, 19, 20, 18, 22, 27, 24, 16, 16, 15, 18, 24,
        30, 23, 12, 22, 14, 21, 26, 20, 18, 19, 20, 18, 22, 27, 24, 16, 16, 15,
        18, 24, 30, 24, 13, 23, 15, 22, 27, 21, 20, 22, 22, 21, 24, 30, 26, 19,
        18, 18, 20, 27, 32, 26, 14, 25, 16, 24, 28, 23, 20, 22, 22, 21, 24, 30,
        27, 20, 19, 19, 21, 28, 33, 27, 15, 26, 17, 25, 29, 24, 21, 23, 23, 22,
        25, 31, 27, 20, 19, 19, 21, 28
    ]

    assert(olympic_rings(1010) == 24)
    assert(olympic_rings(1011) == 24)
    assert(olympic_rings(2500) == 19)
    assert(olympic_rings(5000) == 23)
    assert(olympic_rings(7500) == 8)
    assert(olympic_rings(10000) == 8)
    assert(olympic_rings(100000) == 25)

    for i in range(len(tab)):
        assert(olympic_rings(i+1) == tab[i])

main()
