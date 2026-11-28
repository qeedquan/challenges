#!/usr/bin/env python3

"""

As a child, my friend had a magic 8 ball that we would ask questions to and see what the fate of that question was.

Challenge
Your challenge is to write a program (or function) that when run (or called), outputs (or returns) a random answer from the possible answers below. (Random being: each output should have a nonzero chance of occurring but they do not need to meet any other criteria)

The possible answers from the Magic 8-ball are (case-insensitive):

It is certain
It is decidedly so
Without a doubt
Yes definitely
You may rely on it
As I see it, yes
Most likely
Outlook good
Yep
Signs point to yes
Reply hazy try again
Ask again later
Better not tell you now
Cannot predict now
Concentrate and ask again
Don't count on it
My reply is no
My sources say no
Outlook not so good
Very doubtful
Input
No input.

Output
A random choice from above. Case does not matter.

Rules
Standard loopholes are not allowed.

This is code-golf, so the shortest code in bytes for each language wins!

"""

import random

def eightball():
    ANSWERS = [
        "It is certain",
        "It is decidedly so",
        "Without a doubt",
        "Yes definitely",
        "You may rely on it",
        "As I see it, yes",
        "Most likely",
        "Outlook good",
        "Yep",
        "Signs point to yes",
        "Reply hazy try again",
        "Ask again later",
        "Better not tell you now",
        "Cannot predict now",
        "Concentrate and ask again",
        "Don't count on it",
        "My reply is no",
        "My sources say no",
        "Outlook not so good",
        "Very doubtful"
    ]

    i = random.randint(0, len(ANSWERS)-1)
    return ANSWERS[i]

def main():
    for i in range(32):
        print(eightball())

main()
