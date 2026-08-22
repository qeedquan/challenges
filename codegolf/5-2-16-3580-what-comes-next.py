#!/usr/bin/env python3

"""

Consider the positive integer powers of five in decimal. Here are the first 25, right aligned:

 X                5^X
 1                  5
 2                 25
 3                125
 4                625
 5               3125
 6              15625
 7              78125
 8             390625
 9            1953125
10            9765625
11           48828125
12          244140625
13         1220703125
14         6103515625
15        30517578125
16       152587890625
17       762939453125
18      3814697265625
19     19073486328125
20     95367431640625
21    476837158203125
22   2384185791015625
23  11920928955078125
24  59604644775390625
25 298023223876953125
Notice that the rightmost column of the powers is all 5's. The second column from the right is all 2's. The third column from the right, read from top to bottom, alternates 1, 6, 1, 6, etc. The next column starts 3, 5, 8, 0 and then cycles.

In fact, every column (if we go down far enough) has a cycling sequence of digits whose length is twice that of the previous cycle, except for the initial 5's and 2's cycles.

Calling N the column number, starting with N = 1 at the right, the first few cycles are:

N cycle at column N
1 5
2 2
3 16
4 3580
5 17956240
6 3978175584236200
7 19840377976181556439582242163600
8 4420183983595778219796176036355599756384380402237642416215818000
Challenge
Given a positive integer N, output the decimal digits of the cycle at column N, as described above. For example, the output for N = 4 would be 3580.

The digits may be output as a list such as [3, 5, 8, 0] or in another reasonable format so long as:

The digits are in order as read from top to bottom in the power columns. e.g. 0853 is invalid.
The cycle starts with the top number in its power column. e.g. 5803 is invalid as the 4th column starts with 3 not 5.
Exactly one cycle is output. e.g. 358 or 35803 or 35803580 would all be invalid.
Your code must work for at least N = 1 through 30.

If desired you may assume the columns are 0-indexed instead of 1-indexed. So N = 0 gives 5, N = 1 gives 2, N = 2 gives 16, N = 3 gives 3580, etc.

The shortest code in bytes wins.

Thanks to Downgoat and DJ for challenge support.

"""

"""

@kennytm

The range(2**n/2) uses the observation that each cycle has length r = 2^(n-1) except when n = 0, so we just compute the n-th digits for 5^m to 5^(m + r - 1).

The start of the cycle 5^m is the first number larger than 10n.
Solving 5^m ≥ 10n gives m ≥ n / log10 5. Here we approximate log10 5 ≈ 0.7 which will break down when n = 72. We could add more digits to increase the accuracy:

| approximation             | valid until        | penalty   |
|---------------------------|--------------------|-----------|
| .7                        | n = 72             | +0 bytes  |
| .699                      | n = 137            | +2 bytes  |
| .69897                    | n = 9297           | +4 bytes  |
| .698970004                | n = 29384          | +8 bytes  |
| .6989700043               | n = 128326         | +9 bytes  |
| .6989700043360189         | too large to check | +15 bytes |
| import math;math.log10(5) | same as above      | +23 bytes |
The / 10**n % 10 in the loop simply extract the desired digit. Another alternative solution uses string manipulation. I used the trick ~n == -n-1 here to remove 1 byte.

An mentioned in the comment, the expression 5**(m+i) / 10**n can further be simplified this way, which gives the current 58-byte answer.

(The division x/2**n can be done using bitwise right-shift x>>n. Unfortunately, due to Python's operator precedence this does not save any bytes.) The fraction 3/7 can also be improved in similar mannar:

| approximation                   | valid until         | penalty   |
|---------------------------------|---------------------|-----------|
| n*3/7                           | n = 72              | +0 bytes  |
| n*31/72                         | n = 137             | +2 bytes  |
| n*59/137                        | n = 476             | +3 bytes  |
| n*351/815                       | n = 1154            | +4 bytes  |
| n*643/1493                      | n = 10790           | +5 bytes  |
| n*8651/20087                    | n = 49471           | +7 bytes  |
| int(n*.43067655807339306)       | too large to check  | +20 bytes |
| import math;int(n/math.log2(5)) | same as above       | +26 bytes |

"""

def solve(n):
    n -= 1
    if n < 0:
        return 0

    r = max(2**n // 2, 1)
    m = int(n/0.7 + 1)
    p = 0
    for i in range(r):
        x = (5**(m+i) // 10**n) % 10
        p = (p * 10) + x
    return p

def main():
    assert(solve(1) == 5)
    assert(solve(2) == 2)
    assert(solve(3) == 16)
    assert(solve(4) == 3580)
    assert(solve(5) == 17956240)
    assert(solve(6) == 3978175584236200)
    assert(solve(7) == 19840377976181556439582242163600)
    assert(solve(8) == 4420183983595778219796176036355599756384380402237642416215818000)

main()

