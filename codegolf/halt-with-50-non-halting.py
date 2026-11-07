#!/usr/bin/env python3

"""

Create a program that halts exactly 50% of the time. Be original. Highest voted answer wins. By exactly I mean that on each run there is a 50% chance of it halting.

"""

import random

def main():
    if random.random() < 0.5:
        print("HALT")
        return

    print("RUN")
    while True:
        pass

main()
