#!/usr/bin/env python3

"""

A redundant regular expression (regex) is defined here as a regex which has some amount of characters which can be removed while not affecting its functionality -- i.e. it matches the exact same set of strings. For example, code|codegolf is redundant since it can be reduced to code.

You will be given a regular expression consisting only of lowercase letters and vertical bars (i.e. matching ^[a-z|]*$.) You should output a boolean (or equivalent) saying whether the regular expression is redundant.

Note that you don't need to output the redundant part or the "fixed" (non-redundant) regex; all you need to do is say whether it's redundant.

Standard loopholes are forbidden. Shortest code in bytes wins.

Examples
Input	Output
(empty string)	False
code	False
choose|choice	False
a|b|c|d|e|f|g|h|i|j|k|l|m	False
code|code	True
code|codegolf	True
abc|ab|a	True
term|watermelon|melon	True
a|b|c|d|e|f|aa|g|h|i|j|k|l|m	True

-> False
code -> False
choose|choice -> False
a|b|c|d|e|f|g|h|i|j|k|l|m -> False
code|code -> True
code|codegolf -> True
abc|ab|a -> True
term|watermelon|melon -> True
a|b|c|d|e|f|aa|g|h|i|j|k|l|m -> True

"""

"""

@Albert.Lang

Simply checks whether any of the |-delimited parts occurs more than once in the input string.

"""

def redundant(s):
    m = map(s.count, s.split('|'))
    return max(m) > 1

def main():
    assert(redundant("") == False)
    assert(redundant("code") == False)
    assert(redundant("choose|choice") == False)
    assert(redundant("a|b|c|d|e|f|g|h|i|j|k|l|m") == False)
    assert(redundant("code|code") == True)
    assert(redundant("code|codegolf") == True)
    assert(redundant("abc|ab|a") == True)
    assert(redundant("term|watermelon|melon") == True)
    assert(redundant("a|b|c|d|e|f|aa|g|h|i|j|k|l|m") == True)

main()

