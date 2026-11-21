#!/usr/bin/env python3

"""

Sometimes I make bad jokes... And a bad joke I like to make involves interpreting exclamation marks in sentences as the factorial sign.

Task
Your task is to write a program that receives a sentence and applies the factorial joke to the sentence.

The "factorial joke" consists of looking for exclamation marks "!" and doing the factorial of whatever is to the left of it. If the thing to the left is an integer, then the usual factorial is used. If the thing to the left is a word (a sequence of characters in [a-zA-Z], delimited by spaces), then we want to concatenate all of the subsequent prefixes of the word.

E.g. if the word was abcd then abcd! = abcdabcaba.

However, there is an exception, which is when the sentence contains a "1!" or "2!", because 1! = 1 and 2! = 2 and the joke doesn't really work. In these cases, your program can do whatever it wants EXCEPT applying the factorial joke or returning the same sentence.

Input
A sentence with characters in the range [a-zA-Z0-9 !] with the restriction that only one exclamation mark "!" is present and to the right of an integer or a "word". This means you don't have to worry with things as "abc4!" as a word here is defined as a sequence of alphabetical characters delimited by spaces.

Output
The same sentence, but with the factorial joke applied to the word or integer on the left of the exclamation mark.

Test cases
You can find a Python reference implementation here
https://tio.run/##hVNNj5swEL3zKx5cFpQPhaRSq0jZWw8rVb20ag8IbRwYgrPERrZZkq72t6fjkKRRVamCA543896b8dAeXa3V4lNrTie5b7Vx2AtXB0FJFXb6hWKbLANAlgesYKdSlXSIozBKOGidMM4@C8cQJ3Ckr2VDsNkNyRGuEPEjVHmX/7jCzNPec0xWSAPP4YX@MGCEdMnsOUP8OnMcCqUXVS7uk2A4VxySCnE6xjwZcgBDrjMKUce@K6mojIbsShTete912hpdxplCpQ2UpzBCbcnzyFGa5ElwR2Sz5c3ZKM3ZnHUm9myJ/87Y6Chd5l6EDgW1Dj9E09FnY7QZPCnqLSs/PEx3Wqq4z5Yq/1u6IQaS8Ww8SZP/yJ/p7pRPjqzzAhnXRT8JjbYOribfa1FjAacxC6Oxh7UR2OhG2Mt5K185j/Dhcn5CL5SjEvMQV2w@QF/IobPYdLIpIWCV7vdCXepYVhiWFo6woUJ0liAdpEUr2E368cavVXNELZhaK/pHNL3GVGGolJuGQjwNkKJXMrBEipeL11iqLRr54pUuLmreHsHoXvzyYKFLwlY3FYpaNDzjLfFg2JS89v9N85TUEX6GKISlK/C9Jjv0xDfdcfERu853cvX3VfOopAv9pM2QmS6igBehNX5Lo/V6zf@Mv@czOV/1@aL8TgwZVfTmI@@YPOLt/Of5Y/LOVfcUp98

We lost the match 3 to 0! -> We lost the match 3 to 1
ora bolas! -> ora bolasbolabolbob
give me 4! -> give me 24
I wanted 2! give me 2 -> undefined
Let us build a snowman! -> Let us build a snowmansnowmasnowmsnowsnosns
We are late because it is past 17! -> We are late because it is past 355687428096000
I only have one! -> I only have oneono
I only have 1! -> undefined
Incredible! I have never seen anything like it -> IncredibleIncrediblIncredibIncrediIncredIncreIncrIncInI I have never seen anything like it
What an amazing code golf challenge this is! -> What an amazing code golf challenge this isi
So many test cases! -> So many test casescasecascac
These are actually just 11! -> These are actually just 39916800
No wait! there are 13 -> No waitwaiwaw there are 13

This is code-golf so shortest submission in bytes, wins! If you liked this challenge, consider upvoting it... And happy golfing!

"""

from math import factorial

def joke(s):
    n = s.index("!")
    p = n
    while s[p] != " " and p >= 0:
        p -= 1

    w = s[p+1:n]
    try:
        i = int(w)
        if i in (1, 2):
            return "undefined"
        return s[:p+1] + str(factorial(i)) + s[n+1:]
    except ValueError:
        news = "".join(w[:n] for n in range(len(w), 0, -1))
        return s[:p+1] + news + s[n+1:]

tests = [
    "We lost the match 3 to 0!",
    "ora bolas!",
    "give me 4!",
    "I wanted 2! give me 2",
    "Let us build a snowman!",
    "We are late because it is past 17!",
    "I only have one!",
    "I only have 1!",
    "Incredible! I have never seen anything like it",
    "What an amazing code golf challenge this is!",
    "So many test cases!",
    "These are actually just 11!",
    "No wait! there are 13"
]

for test in tests:
    print(f"{test} -> {joke(test)}")
