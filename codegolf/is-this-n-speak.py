#!/usr/bin/env python3

"""

Inspired by Is it double speak?, I devised a harder challenge. Given a string, determine if the string is n-speak, for any  n≥2.

N-speak is defined by repeating each letter n times. With n=4, the string Hello is transformed to HHHHeeeelllllllloooo.
Your goal is to figure out if the input is a valid output for any n-speak transformation.

It should be noted that any sentence which is valid n-speak, for n=2k, is also valid k-speak.
Thus, the hard parts to solve will be odd values of n.

Input
A string consisting of at least 2 characters. Input could also be a list of characters. Input is case sensitive.

Output
Truthy if the string is n-speak, falsey otherwise.

Examples
True cases
HHeelllloo,,  wwoorrlldd!!
TTTrrriiipppllleee   ssspppeeeaaakkk
QQQQuuuuaaaaddddrrrruuuupppplllleeee    ssssppppeeeeaaaakkkk
7777777-------ssssssspppppppeeeeeeeaaaaaaakkkkkkk
999999999
aaaabb
aaaaaaaabbbbcc
aaaaabbbbb
@@@

If you want to generate additional truthy cases, you can use this MathGolf script.
Place the string within the quotation marks, and the value of n as the input.

False cases
Hello, world!
TTTrrriiipppllleee   speak
aaaaaaaaaaaaaaaab
Ddoouubbllee  ssppeeaakk
aabbab
aaaabbb
a (does not need to be handled)
(empty string, does not need to be handled)
Of course, since this is code golf, get ready to trim some bytes!

"""

def nspeak(s):
    if len(s) < 2:
        return False
    if len(set(s)) == 1:
        return True
    
    for k in range(2, len(s)):
        if s == "".join(i*k for i in s[::k]):
            return True
    return False

def main():
    assert(nspeak("HHeelllloo,,  wwoorrlldd!!") == True)
    assert(nspeak("TTTrrriiipppllleee   ssspppeeeaaakkk") == True)
    assert(nspeak("QQQQuuuuaaaaddddrrrruuuupppplllleeee    ssssppppeeeeaaaakkkk") == True)
    assert(nspeak("7777777-------ssssssspppppppeeeeeeeaaaaaaakkkkkkk") == True)
    assert(nspeak("999999999") == True)
    assert(nspeak("aaaabb") == True)
    assert(nspeak("aaaaaaaabbbbcc") == True)
    assert(nspeak("aaaaabbbbb") == True)
    assert(nspeak("@@@") == True)

    assert(nspeak("Hello, world!") == False)
    assert(nspeak("TTTrrriiipppllleee   speak") == False)
    assert(nspeak("aaaaaaaaaaaaaaaab") == False)
    assert(nspeak("Ddoouubbllee  ssppeeaakk") == False)
    assert(nspeak("aabbab") == False)
    assert(nspeak("aaaabbb") == False)
    assert(nspeak("a") == False)
    assert(nspeak("") == False)

main()
