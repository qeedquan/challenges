#!/usr/bin/env python3

"""

Tired of those repetitive javascript challenges? Here's a unique hackish one that should keep you busy for a while ;)

There's a mystery function which is already available for you to use. It's a simple function called mystery. It accepts a string as a parameter and outputs a string. The exercise depends on guessing what this function actually does.

You can call the mystery function like this:

my_output = mystery("my_input")
Using your own test cases, try to call the mystery function with different input strings and try to analyze its output in order to guess what is does. You are free to call the mystery function in your own test cases however you want.

When you think you've understood how my mystery function works, prove it by reimplementing its logic in a function that you should call 'solved(x)'. To validate your code, your function 'solved' should return the same output as my function 'mystery' given the same inputs.

Beware! Passing your own test cases doesn't imply you'll pass mine.

Cheaters are welcome :)

Have fun!

Too easy? Then this kata will totally blow your mind:

http://www.codewars.com/kata/mystery-function-number-2

"""

def mystery(s):
    n = len(s)
    r = sorted(s[:n//2] + s[n//2 + n%2:])
    return ''.join(r)

def main():
    assert(mystery("Hello World") == "HWdellloor")
    assert(mystery("foobar") == "abfoor")
    assert(mystery("I see what you did there!") == "     !Iaddeeeehhirsttuwy")
    assert(mystery("") == "")
    assert(mystery("abcd") == "abcd")
    assert(mystery("abcde") == "abde")

main()