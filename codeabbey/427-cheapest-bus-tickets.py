#!/usr/bin/env python3

"""

Galina, a girl from provincial town, have come to study in a Big University in some Big City. Campus is large, a number of majestic old buildings along the street - and sometimes she needs to travel between them quickly, so she rides a bus. Being practical, she wonders about the way to minimize ticket cost. But it is not an easy matter for there are several types of tickets:

one-ride ticket for 5 kopecks
two-day unlimited ticket for 18 kopecks
three day ticket limited to 6 rides for 22 kopecks
So we are given an array of numbers, representing how many times Galina should travel each day in the upcoming month. So there are 28 to 31 values, all of them comparatively small. We want to know lowest possible cost of tickets for the month.

Input: the first line gives D - number of days in the month.
Next line contains corresponding amount of small integers - rides on every day.

Answer: should give a single value - minimum possible cost of tickets.

Example:

input:
30
2 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 4 3 4

answer:
51

"""

def solve(rides):
    size = len(rides)
    rides = [0] + rides
    dp = [0] * (size + 1)
    for i in range(1, size + 1):
        # Option 1: Buy single-ride tickets for all of today's rides
        cost_single = dp[i - 1] + (rides[i] * 5)
        
        # Option 2: Buy a 2-day unlimited ticket covering day i-1 and day i
        prev_2_days = dp[max(0, i - 2)]
        cost_2day = prev_2_days + 18
        
        # Option 3: Buy a 3-day (max 6 rides) ticket covering days i-2, i-1, and i
        prev_3_days = dp[max(0, i - 3)]
        # Sum total rides over the 3-day window (handling boundary cases if i < 3)
        total_3day_rides = 0
        for j in range(max(1, i - 2), i + 1):
            total_3day_rides += rides[j]
        
        # 22 kopecks base + 5 kopecks for every ride over the 6-ride limit
        excess_rides = max(0, total_3day_rides - 6)
        cost_3day = prev_3_days + 22 + (excess_rides * 5)
        
        # Choose the optimal (cheapest) strategy for day i
        dp[i] = min(cost_single, cost_2day, cost_3day)

    return dp[size]

def main():
    assert(solve([2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 4]) == 51)

main()
