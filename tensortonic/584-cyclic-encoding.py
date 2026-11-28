#!/usr/bin/env python3

"""

Cyclic features wrap around, so the end of one period is adjacent to its beginning. Encode each value as a point on the unit circle.

First compute its angle:

phase = 2*pi*v/P

Then compute its two coordinates:
encoded(v) = [sin(phase), cos(phase)]

Here, v is an input value and P is period. Return the sine and cosine pair for every value in the original order.

Examples
Input: values = [0, 6, 12, 18], period = 24

Output: [[0.0, 1.0], [1.0, 0.0], [0.0, -1.0], [-1.0, 0.0]]

Explanation: The four values are quarter-period steps and therefore occupy quarter turns on the unit circle.

Input: values = [0, 1, 2, 3], period = 4

Output: [[0.0, 1.0], [1.0, 0.0], [0.0, -1.0], [-1.0, 0.0]]

Hint 1
Use 2 * math.pi * value / period for the angle.

Hint 2
Append math.sin(angle) and math.cos(angle) as a two-item list.

Requirements
Convert every value to an angle using the supplied period.
Return sine first and cosine second for each angle.
Preserve the original value order.
Constraints
period is positive.
values contains nonnegative numbers.
Time limit: 300 ms.

"""

from math import *

def cyclic_encoding(values: list, period: float) -> list:
    result = []
    for value in values:
        phase = (2*pi*value) / period
        result.append((sin(phase), cos(phase)))
    return result

print(cyclic_encoding([0, 6, 12, 18], 24))
print(cyclic_encoding([0, 1, 2, 3], 4))
