#!/usr/bin/env python3

"""

This challenge is inspired by Mathematics is fact. Programming is not.

The mathematical notation for a factorial, or a fact is an exclamation mark !. The exclamation mark is also a common symbol for not in many programming languages.

Challenge:
Take a string, containing numerals, and the characters: + ! as input and output the following:

Everything in front of an exclamation mark should be evaluated as a mathematical expression, so 2+2 would be 4.

Everything after a single exclamation mark should be appended as accessories to whatever is in front of it, so: 2+2!5 should give 45, because 2+2=4, and 5 is an accessory. 2+2!5+5 should give 410.

Since ! also means not, anything that's not an accessory after the fact should not be appended. So, 2+2!!5 should give 4, since 5 is not an accessory. Now, not(not(true))==true, so 2+2!!!5 should give 45. 2+2!!5!5+5 should give: 410, because 2+2=4, then followed by a factorial and !5!5+5. The first 5 is not a fact, but 5+5 is after another exclamation mark, and is therefore a fact, yet again.

Clarifications:

The exclamation marks will not be adjacent to a + on either side.
There will not be leading + for numbers (it's 5, not +5).
You may optionally include a leading zero if that's the result of the expression in front of the first !. Both 4 and 04 are accepted output for input: 0+0!4
Executive summary: evaluate each sum (treating ! as separators). Then discard all numbers that appear after an even number of ! (counting from the start of the string). Then remove all !.

Test cases:

!
   <- Empty string

5
5

12!
12

!87
87

!!5
   <- Empty string

5+5!2+2
104

5+5!!2+2
10

1!2!3!4!5!6!7!8!9
12468

10+10!!2+2!!3+3!4+4
208

2!!3!5
25

2!!3!5!7
25

10!!!!!!!5
105

This is code-golf so the shortest code in bytes (in each language) wins! Explanations are strongly encouraged!

"""

def af(s):
    r = ""
    p = list(s.split("!"))
    for i in range(len(p)):
        if i > 0 and i%2 == 0:
            continue
        try:
            r += str(eval(p[i]))
        except:
            pass
    return r

def main():
    assert(af("2+2") == "4")
    assert(af("2+2!5+5") == "410")
    assert(af("2+2!!!5") == "45")
    assert(af("2+2!!5") == "4")
    assert(af("!") == "")
    assert(af("5") == "5")
    assert(af("12!") == "12")
    assert(af("!87") == "87")
    assert(af("!!5") == "")
    assert(af("5+5!2+2") == "104")
    assert(af("5+5!!2+2") == "10")
    assert(af("1!2!3!4!5!6!7!8!9") == "12468")
    assert(af("10+10!!2+2!!3+3!4+4") == "208")
    assert(af("2!!3!5") == "25")
    assert(af("2!!3!5!7") == "25")
    assert(af("10!!!!!!!5") == "105")

main()
