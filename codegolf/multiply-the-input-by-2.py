#!/usr/bin/env python3

"""

Your goal is to write a program which will take an input and multiply it by 2. However, there are some catches.

You will get an input in one of a few forms:

A number (3, 15.6, etc)
A number which is written in english (five, sixty, one hundred fifty three, etc)
A roman numeral (V, IX, MXXV, etc)
You must multiply it by two and output the result in the same format as the input.

You can take input in whatever format you want, but it must be consistent. E.g.: if you choose a string, all your inputs must be a string. If you choose an array of characters, all your inputs must be an array of characters. Etc.

When constructing your numbers, follow these rules:

Numerals should reflect the input. I.e.: if there is not a decimal point in the input, don't include one in the output. If the input is not an integer but the result is an integer it's up to you if you include a decimal point or not.
Construct your written numbers without and (i.e.: one thousand one hundred fifty three instead of one thousand one hundred and fifty three)
Roman numerals should follow this form: https://en.wikipedia.org/wiki/Roman_numerals#Standard_form

Notes
The only input which could contain a non-integer will be the numeral (2.5 etc). You will never get a number written in English or roman numerals which is not an integer
You only have to handle numbers between 1 and 1000 (inclusive) as an input, regardless of the format. This means your output will be between 2 and 2000.
English written numbers will always be lower case
Roman numerals will always be upper case

Test Cases
2 -> 4
1.5 -> 3.0 or 3
1.6 -> 3.2
1000 -> 2000
1000.0 -> 2000.0 or 2000
one thousand -> two thousand
five hundred sixty eight -> one thousand one hundred thirty six
one -> two
eight -> sixteen
I -> II
IV -> VIII
CCXLV -> CDXC
M -> MM
Answers are scored using code-golf scoring guidelines, where the shortest answer (in each language) wins.

"""

from word2number.w2n import *
from num2words import *
from roman import *

# Ported from @Tegah D Oweh solution
def mul2(s):
    try:
        return 2 * float(s)
    except:
        pass
    
    try:
        return toRoman(2 * fromRoman(s))
    except:
        pass
    
    s = num2words(2 * word_to_num(s))
    s = s.replace(" and ", " ")
    s = s.replace("-", " ")
    s = s.replace(",", "")
    s = s.replace("  ", " ")
    return s

def main():
    print(mul2("2"))
    print(mul2("1.5"))
    print(mul2("1.6"))
    print(mul2("1000"))
    print(mul2("1000.0"))
    print(mul2("one thousand"))
    print(mul2("five hundred sixty eight"))
    print(mul2("one"))
    print(mul2("eight"))
    print(mul2("I"))
    print(mul2("IV"))
    print(mul2("CCXLV"))
    print(mul2("M"))

main()
