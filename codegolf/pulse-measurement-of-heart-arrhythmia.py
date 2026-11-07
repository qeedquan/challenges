#!/usr/bin/env python3

"""

In this challenge you have to make an ascii pulsing heart with rhythm problems (Heart arrhythmia) and then measure the pulse.Don't worry it's easy!

Making the heart

The heart alternates between these 2 states:
state 1

    ,d88b.d88b,
    88888888888
    `Y8888888Y'
      `Y888Y'
        `Y'
state 2

     d8b d8b
    888888888
    `Y88888P'
     `Y888P'
      `Y8P'
       `Y'
each step has X seconds delay
where X is a Random (Real) number between 0.3 and 1.4 (0.3<=X<=1.4)

Measuring the Pulse

When your arrhythmia-heart starts beating, you have to measure the pulse.
We want to know the heartbeats/min.
But (like many doctors do) you only have to count the heartbeats for 15 sec and then multiply by 4

Final output

Given no input, your code must run for 15 seconds (displaying the beating heart) and then print the heart rate.

Your output should look exactly like this!
(I will run my code 2 times for you to see the different results)

First example run:

https://i.stack.imgur.com/VVTR9.gif

Second example run:

https://i.stack.imgur.com/P2Hjh.gif

you must output one heart
Good Luck!

this is code-golf
shortest answer in bytes wins!

"""

import time
import random

ART1 = """
    ,d88b.d88b,
    88888888888
    `Y8888888Y'
      `Y888Y'
        `Y'
"""

ART2 = """
     d8b d8b
    888888888
    `Y88888P'
     `Y888P'
      `Y8P'
       `Y'
"""

def main():
    t = 0
    i = 0
    while t < 15:
        print("\033c")
        print("t=%f" % (t))
        if i == 0:
            print(ART1)
        else:
            print(ART2)

        dt = random.uniform(0.3, 1.4)
        t += dt
        i = 1 - i
        time.sleep(dt)

main()
