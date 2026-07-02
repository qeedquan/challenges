#!/usr/bin/env python3

r"""

Background
I have a string in Python which I want to convert to an integer. Normally, I would just use int:

>>> int("123")
123
Unfortunately, this method is not very robust, as it only accepts strings that match -?[0-9]+ (after removing any leading or trailing whitespace). For example, it can't handle input with a decimal point:

>>> int("123.45")
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
ValueError: invalid literal for int() with base 10: '123.45'
And it certainly can't handle this:

>>> int("123abc?!")
On the other hand, exactly this behavior can be had without any fuss in Perl, PHP, and even the humble QBasic:

INT(VAL("123abc"))   ' 123
Question
Here's my shortest effort at this "generalized int" in Python. It's 50 bytes, assuming that the original string is in s and the result should end up in i:

n="";i=0
for c in s:
 n+=c
 try:i=int(n)
 except:0
Fairly straightforward, but the try/except bit is ugly and long. Is there any way to shorten it?

Details
Answers need to do all of the following:

Start with a string in s; end with its integer value in i.
The integer is the first run of digits in the string. Everything after that is ignored, including other digits if they come after non-digits.
Leading zeros in the input are valid.
Any string that does not start with a valid integer has a value of 0.
The following features are preferred, though not required:

A single - sign immediately before the digits makes the integer negative.
Ignores whitespace before and after the number.
Works equally well in Python 2 or 3.
(Note: my code above meets all of these criteria.)

Test cases
"0123"   -> 123
"123abc" -> 123
"123.45" -> 123
"abc123" -> 0
"-123"   -> -123 (or 0 if negatives not handled)
"-1-2"   -> -1 (or 0 if negatives not handled)
"--1"    -> 0
""       -> 0

"""

def castint(s):
    i = 0
    p = ""
    if s.startswith("-"):
        s = s[1:]
        p = "-"
    for c in s:
        p += c
        try:
            i = int(p)
        except:
            break
    return i 

def main():
    assert(castint("0123") == 123)
    assert(castint("123abc") == 123)
    assert(castint("123.45") == 123)
    assert(castint("abc123") == 0)
    assert(castint("-123") == -123)
    assert(castint("-1-2") == -1)
    assert(castint("--1") == 0)
    assert(castint("") == 0)

main()
