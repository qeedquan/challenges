#!/usr/bin/env python3

"""

Write a function that transforms a string into title case. This mostly means: capitalizing only every first letter of every word in the string. However, there are some non-obvious exceptions to title case which can't easily be hard-coded. Your function must accept, as a second argument, a set or list of words that should not be capitalized. Furthermore, the first word of every title should always have a capital leter. For example:

exceptions = ['jumps', 'the', 'over']
titlecase('the quick brown fox jumps over the lazy dog', exceptions)
This should return:

The Quick Brown Fox jumps over the Lazy Dog
An example from the Wikipedia page:

exceptions = ['are', 'is', 'in', 'your', 'my']
titlecase('THE vitamins ARE IN my fresh CALIFORNIA raisins', exceptions)
Returns:

The Vitamins are in my Fresh California Raisins

"""

def titlecase(s, m):
    r = ""
    i = 0
    f = 0
    while i < len(s):
        while i < len(s) and s[i].isspace():
            r += s[i]
            i += 1
        
        t = ""
        while i < len(s) and not s[i].isspace():
            t += s[i].lower()
            i += 1

        if t not in m or f == 0:
            r += t[0].upper() + t[1:]
            f = 1
        else:
            r += t
    return r

def main():
    assert(titlecase('the quick brown fox jumps over the lazy dog', {'jumps': True, 'the': True, 'over': True}) == 'The Quick Brown Fox jumps over the Lazy Dog')
    assert(titlecase('THE vitamins ARE IN my fresh CALIFORNIA raisins', {'are': True, 'is': True, 'in': True, 'your': True, 'my': True}) == 'The Vitamins are in my Fresh California Raisins')

main()
