#!/usr/bin/env python3

"""

A moving median smooths a sequence by taking the median of every complete sliding window. Sorting a window places its middle value or values at known positions.

For an odd window size, use the single middle value. For an even window size, use the average of the two middle values. Return one floating-point median for each complete window.

Examples
Input: values = [1, 3, 5, 7, 9], window_size = 3

Output: [3.0, 5.0, 7.0]

Explanation: The middle values of the three sorted windows are 3, 5, and 7.

Input: values = [1, 2, 3, 4], window_size = 2

Output: [1.5, 2.5, 3.5]

Hint 1
Use sorted on each slice of length window_size.

Hint 2
The middle index is window_size // 2.

Requirements
Sort each complete sliding window.
Use the middle value for an odd window size.
Average the two middle values for an even window size.
Return len(values) - window_size + 1 floats.
Constraints
1 <= window_size <= len(values).
values contains numeric values.
Time limit: 300 ms.

"""

def moving_median(values: list, window_size: int) -> list:
    result = []
    index = 0
    while index+window_size <= len(values):
        window = sorted(values[index:index+window_size])
        if window_size%2 != 0:
            result.append(window[window_size//2])
        else:
            average = (window[window_size//2 - 1] + window[window_size//2]) / 2
            result.append(average)
        index += 1
    return result

print(moving_median([1, 3, 5, 7, 9], 3))
print(moving_median([1, 2, 3, 4], 2))
