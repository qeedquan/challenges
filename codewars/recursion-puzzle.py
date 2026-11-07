#!/usr/bin/env python3

"""

My 4th kata, define puzzle to pass all the tests by reading the error messages. Click ATTEMPT to start solving. The test will fail at first. The goal is to circumvent all test failures.

Do rank and provide feedback (not sure if this is a nice puzzle idea or a bad one!)

"""

def nested(n):
    r = []
    for i in range(n):
        r = [r]
    return r

def main():
    print(nested(2990))

main()
