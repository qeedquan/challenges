#!/usr/bin/env python3

"""

Your task is to write a program or function which takes a pure brainflak program as input (assume it contains only balanced ()[]{}<>), and output a visually mirrored copy of it.

If you reversed a brainflak program as a string, say ({}()) (add one to an input), you would get ))(}{(, which is not valid.

Instead, you should mirror it, by reversing the direction of the parentheses/brackets/braces/angle-brackets, like what you would see if the program was placed in front of a mirror: ((){}).

Test cases (??? means anything is okay):

()               -> ()
({}[{}])         -> ([{}]{})
()[]             -> []()
<(){}[]>         -> <[]{}()>
([{<()[]{}<>>}]) ->([{<<>{}[]()>}])
(a)              -> ???
{>               -> ???
))(}{(           -> ???
()↵[]            -> ???
This is a code golf challenge, shortest answer per language wins.

"""

"""

Ported from @xnor solution

Python has a convenient string method translate that accepts a translation string s, and maps each character c to s[ord(c)]. So, we just need to make a translation string with the right characters at the positions of ASCII values [40, 41, 60, 62, 91, 93, 123, 125] of ()<>[]{}.

The ideal would be to make the table like '????????'*16, putting the correct character for each ASCII value modulo 8. Unfortunately, the values [40, 41, 60, 62, 91, 93, 123, 125] are not distinct modulo 8, and the first modulus making them distinct is 18, which would mean something like '??????????????????'*6.

However, conveniently, the lowest 6 ASCII values [40, 41, 60, 62, 91, 93] are distinct modulo 6. That lets us handle them with '>]<[)('*20, translating ASCII values 0 through 119. For the remaining two, 123 and 125, we use '}_{'*2 to hit the next 6 ASCII values 120 to 125. Python 3 lets us stop there, unlike Python 2, which requires the translation string to be length 256 exactly.

"""
def mirror(s):
    s = s[::-1]
    s = s.translate('>]<[)('*20 + '}_{'*2)
    return s

def main():
    assert(mirror("()") == "()")
    assert(mirror("({}[{}])") == "([{}]{})")
    assert(mirror("()[]") == "[]()")
    assert(mirror("<(){}[]>") == "<[]{}()>")
    assert(mirror("([{<()[]{}<>>}])") == "([{<<>{}[]()>}])")
    print(mirror("(a)"))
    print(mirror("{>"))
    print(mirror("))(}{("))
    print(mirror("()↵[]"))

main()
