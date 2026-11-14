#!/usr/bin/env python3

"""

Definition of long text
Long text usually shows emphasis, for instance, loooooool or yaaaaaaaaaay. Usually the vowel is replicated many times. In this challenge we require:

At least 3 times, which means yaaay and yaaaay are allowed, but yay and yaay are not.

Consistent, which means that shoes can turn out be shoooeees or shooooeeees but not shoooeeees or shooooeees. Of course, it seems that no one would do that, however, this is to reinforce the next law.

Undoubling, which means beeping turns out to be beeepiiing or beeeepiiiing but not beeeeeepiiing or beeeeeeeepiiiing. This is not the case for long text, but such makes this challenge non-trivial.

Thus, the long text might turn out shorter than the original text, that is, aaaaa can turn out to be aaa.

Your challenge
Input
Your input will be a sentence, that is, you may not assume there are only words. We do not guarantee all will be English words, so look out for theeeeeeeeese.

Output
The long text for the input.

Test cases
We assume you repeat 3 times.

The fox yawns...  => Theee fooox yaaawns...

Everything is good!!!!!  => Eeeveeerythiiing iiis goood!!!!!  and NOT EEEveeerythiiing iiis gooooood!!!!!

Eeny, meeny, miny, moe => Eeeeeeny, meeeny, miiiny, moooeee

AAARGH => AaaRGH

Weeeeeeeeheeeeeee => Weeeheee

Note the treatment of capital letters: The first letter remains capital, and the others are lowered. eE will be eeeEee, they won't be the same. "Undoubling" only happens for letters which are of the same case (like ee or AA, but not for Ee)

Only the letters from a, e, i, o, and u are vowels, case insensitive.

"""

import re

# Ported from @loopy walt solution
def longtext(s):
    return re.sub(r"([aeiouAEIOU])\1*", lambda m: m[1] + 2*m[1].lower(), s)

def main():
    assert(longtext("The fox yawns... ") == "Theee fooox yaaawns... ")
    assert(longtext("Everything is good!!!!! ") == "Eeeveeerythiiing iiis goood!!!!! ")
    assert(longtext("Eeny, meeny, miny, moe") == "Eeeeeeny, meeeny, miiiny, moooeee")
    assert(longtext("AAARGH") == "AaaRGH")
    assert(longtext("Weeeeeeeeheeeeeee") == "Weeeheee")

main()
