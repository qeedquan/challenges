#!/usr/bin/env python3

"""

Covered 7-Segment Speedometer
Your car has a digital speedometer using standard 7-segment digits.

Unfortunately, the lower four segments of every digit are hidden:

 --      visible
|  |

????     hidden
You do not know your exact speed. You can only see the visible part of the display.

Then you see a speed-limit sign showing L.

Police might be nearby, and you don't want to be caught speeding. You decide to slow down, but you can only rely on what the obscured display shows.

How much do you need to slow down so that, after slowing down, the obscured display alone guarantees that your speed is within the limit?

Digit Visibility
With the lower four segments hidden, the following digits become indistinguishable:

1

2,3,7

4

5,6

8,9,0
For example:

2, 3 and 7
all appear as:

 _
  |
while

8, 9 and 0
all appear as:

 _
| |
Thus every digit may be interpreted as any digit in its group.

Task
Given:

your actual speed S
the speed limit L
find the smallest non-negative integer D such that:

your speed becomes S-D,
you have no other source of information than the display,
your knowledge is based on the currently displayed and previously observed values,
the current speed is unequivocally below the limit.
(For example: if speed goes down from 60 to 59 and then 58, you can't tell the difference. When it goes to 57, you know that it has decreased)

Output D.

Note that although S is provided as input, it is not directly visible to the driver. It merely determines which obscured display is shown before and after slowing down.

L may be less than, equal to, or greater than S.

Example
Suppose:

S = 63
L = 65
With no slowing down, the display corresponds to:

63
which could actually be any of:

52
53
57
62
63
67
Since 67 > 65, the display does not guarantee compliance.

Slowing down by 1 gives:

62
but this produces the same obscured display, so the same possibilities remain:

52
53
57
62
63
67
and the speed is still not guaranteed to be legal.

After slowing down by 2:

61
The obscured display could now represent only:

51
61
Since the largest possibility is 61, which is within the limit, the speed is now guaranteed to be legal.

Therefore:

63 65 -> 2
Test Cases
63 65 -> 2
63 61 -> 2
63 60 -> 3 (after seeing 61, 60 can be deduced)
63 59 -> 6 (57 is the first possible unique value below the limit)
63 58 -> 6
63 57 -> 6
63 56 -> 7

63 77 -> 0
63 67 -> 0
63 66 -> 2

70 70 -> 1
70 69 -> 1
70 67 -> 3
70 66 -> 4

88 88 -> 9 (first digit might be 9, unsure until speed is under 80)
88 80 -> 9
88 79 -> 9

49 49 -> 0
49 48 -> 2

31 29 -> 4 (must reach 27 to be sure)

100 100 -> 1
100 99 -> 1

123 123 -> 4 (second digit might be 3, must go under 120)
123 122 -> 4
(all test cases were AI generated and wrong, I think I've fixed them, but please double-check my assumptions)

Rules
Inputs and outputs are integers.
Leading zeros are not used when displaying a speed.
Standard loopholes are forbidden.
This is code-golf, so the shortest answer in bytes wins.

"""

from itertools import product

def alternatives_for_digit(digit):
    DIGIT_GROUPS = ("237", "56", "890")
    for group in DIGIT_GROUPS:
        if digit in group:
            return group
    return digit


def valid_values(number):
    choices = []
    for digit in str(number):
        choices.append(alternatives_for_digit(digit))

    result = []
    for candidate in product(*choices):
        result.append(int(''.join(candidate)))
    return set(result)

"""

Ported from @Ajax1234 solution

"""
def minimum_steps(start, limit):
    current_values = set()
    for current in range(start, -1, -1):
        valid = valid_values(current)
        if not current_values:
            current_values = valid
        else:
            new_values = set()
            for value in current_values | {value - 1 for value in current_values}:
                if value in valid:
                    new_values.add(value)
            current_values = new_values
        if current_values and max(current_values) <= limit:
            return start - current
    return None

def main():
    assert(minimum_steps(63, 65) == 2)
    assert(minimum_steps(63, 61) == 2)
    assert(minimum_steps(63, 60) == 3)
    assert(minimum_steps(63, 59) == 6)
    assert(minimum_steps(63, 58) == 6)
    assert(minimum_steps(63, 57) == 6)
    assert(minimum_steps(63, 56) == 7)

    assert(minimum_steps(63, 77) == 0)
    assert(minimum_steps(63, 67) == 0)
    assert(minimum_steps(63, 66) == 2)

    assert(minimum_steps(70, 70) == 1)
    assert(minimum_steps(70, 69) == 1)
    assert(minimum_steps(70, 67) == 3)
    assert(minimum_steps(70, 66) == 4)

    assert(minimum_steps(88, 88) == 9)
    assert(minimum_steps(88, 80) == 9)
    assert(minimum_steps(88, 79) == 9)

    assert(minimum_steps(49, 49) == 0)
    assert(minimum_steps(49, 48) == 2)

    assert(minimum_steps(31, 29) == 4)

    assert(minimum_steps(100, 100) == 1)
    assert(minimum_steps(100, 99) == 1)

    assert(minimum_steps(123, 123) == 4)
    assert(minimum_steps(123, 122) == 4)

    assert(minimum_steps(31, 30) == 4)

main()
