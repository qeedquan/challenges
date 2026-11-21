#!/usr/bin/env python3

"""

MUD's rats reproduce fast! They reach sexual maturity in 35 days and give birth to 14 pups every 21 days. If you took one newborn rat home with you, how many rats would you have after 98 days?

Such a riddle is encountered in MUD1 - probably the oldest game of "multi-user dungeon" type (a kind of text quest) which is still playable, particularly at british-legends.com.

Not regarding the answer to the original puzzle, let's capitalize on it, turning it into general programming problem (supposing these rats reproduce in "vegetative" manner, just like gremlins)...

Input data consist of 4 numbers:

M is number of days for newborn rat to reach maturity (in other words, beget first offsprings)
P is breeding period
N is how many children are born each time
D is the observation time, after which we want to count all rats
For example if we, given M=35, P=21, N=14 would observe them for D=70 days, it is easy to find that on day 35 we found ourselves lucky owners of 15 rats instead of single one, situation worsens on day 56 when they become 29 in number but real feast comes on day 70 when the 3-rd generation comes, bringing total to 225.

Answer is expected to contain a single value - total amount of rats at the last day of experiment.

Example

input:
35 21 14 98

answer:
645

"""

def count_rats(maturity_days, breeding_period, pups_per_litter, total_days):
    # Track the number of rats born on any given day
    # Day 0 starts with the 1 newborn rat you took home
    births_on_day = [0] * (total_days + 1)
    births_on_day[0] = 1
    
    # Iterate through each day to calculate new births
    for day in range(1, total_days + 1):
        new_pups_today = 0
        
        # Check all previous days to see which past litters are giving birth today
        for past_day in range(day):
            age = day - past_day
            
            # A rat gives birth if it is mature AND hits its periodic breeding day
            if age >= maturity_days and (age - maturity_days) % breeding_period == 0:
                new_pups_today += births_on_day[past_day] * pups_per_litter
                
        births_on_day[day] = new_pups_today

    # The total number of rats is the sum of all rats born across all days
    return sum(births_on_day)

def main():
    assert(count_rats(35, 21, 14, 98) == 645)

main()
