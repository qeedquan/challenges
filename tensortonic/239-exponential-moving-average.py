#!/usr/bin/env python3

"""

The Exponential Moving Average (EMA) is a weighted moving average that gives more importance to recent observations. Unlike the Simple Moving Average which weights all values equally, EMA applies exponentially decreasing weights to older data points, making it more responsive to recent changes.

Given a list of numeric values and a smoothing factor alpha (0 < alpha <= 1), compute the EMA for each position.

Algorithm
Initialize with the first value and apply the recursive formula:

EMA[0] = x[0]
EMA[t] = a*x[t] + (1-a)*EMA[t-1]

Higher alpha values make the EMA respond faster to recent changes, while lower alpha values produce a smoother signal.

Return one EMA value for each input value.

Examples
Input: values = [1, 2, 3, 4, 5], alpha = 0.5

Output: [1, 1.5, 2.25, 3.125, 4.0625]

Explanation: Each new EMA equally weights the current value and the previous EMA.

Input: values = [100, 0, 0, 0], alpha = 0.5

Output: [100, 50.0, 25.0, 12.5]

Hint 1
Initialize the output with the first input value.

Hint 2
Append alpha times the current value plus one minus alpha times the previous EMA.

Requirements
Initialize EMA[0] with the first value in the series
Apply the recursive EMA formula for each subsequent value
Return a list of the same length as the input
Constraints
values has at least 1 element
0 < alpha <= 1
Return a list with the same length as values
Time limit: 300 ms

"""

def exponential_moving_average(values: list, alpha: float) -> list:
    result = []
    ema_prev = values[0]
    for value in values:
        result.append(alpha*value + (1-alpha)*ema_prev)
        ema_prev = result[-1]
    return result

def main():
    print(exponential_moving_average([1, 2, 3, 4, 5], 0.5))
    print(exponential_moving_average([100, 0, 0, 0], 0.5))

main()
