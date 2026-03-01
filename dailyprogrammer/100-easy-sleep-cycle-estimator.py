#!/usr/bin/env python3

"""

This challenge comes to us from nagasgura

The human body goes through 90 minute sleep cycles during the night, and you feel more refreshed if you wake up at the end of a sleep cycle than if you wake up during a sleep cycle. The challenge is to make a program that takes a wake-up time and outputs the possible times to fall asleep so that you will wake up at the end of a sleep cycle.

Example:

Input (Wake-up time): 6:15 AM

Output (when to go to sleep): 9:15 PM, 10:45 PM, 12:15 AM, or 1:45 AM

Bonus 1: Be able to input a sleep time and output potential wake-up times

Bonus 2: Account for how long it takes to fall asleep

"""

from datetime import datetime, timedelta

# ported from @sch1zo solution
def cycle(w):
    w = datetime.strptime(w, '%I:%M %p') + timedelta(0, 0, 0, 0, 0, 12)
    s = [w + (timedelta(0, 0, 0, 0, 90) * i) for i in range(2, 6)]
    return [t.strftime('%I:%M %p') for t in s]

def main():
    print(cycle('06:15 AM'))

main()
