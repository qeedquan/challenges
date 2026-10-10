#!/usr/bin/env python3

"""

Description:
The [Easy] Challenge was delayed 1 day to be on April's Fools Day this week so the moderators could attempt to be clever and turn things upside down by making a super easy challenge to decode a message to just have people post hello world programs. The responses to that challenge was interesting.

To show how things got turned upside down this week's [Hard] challenge we are gonna make text appear upside down.

Input:
1 to many lines of text to convert

You must read it in from standard input or a file. (No fixed strings hard coded into the program with the input)

Can handle as input by characters for converting [a-z] [A-Z] [ ] [?!.] [0-9] to upside down characters.

Example:
This is some text that I am writing!
Soon it will be just 4 lines of upside down text.
How did they do it?
We will all know soon.
Output:
The text modified to be upside down.

Example:
˙uoos ʍouʞ llɐ llᴉʍ ǝM
 ¿ʇᴉ op ʎǝɥʇ pᴉp ʍoH
˙ʇxǝʇ uʍop ǝpᴉsdn ɟo sǝuᴉl ㄣ ʇsnɾ ǝq llᴉʍ ʇᴉ uooS
¡ƃuᴉʇᴉɹʍ ɯɐ I ʇɐɥʇ ʇxǝʇ ǝɯos sᴉ sᴉɥ┴
Notes:
As part of the [Hard] challenge we leave it to you to figure out how this is possible.

Solutions might limit which languages you can use.

More Challenges
In addition to above look into trying these out:

convert upside down to normal

find conversions for $&@';/><+*=_- if any are possible

given a word search the text count the word matches. Count how many times the word is normal or upside down

Good single line Test String
The quick brown fox jumps over the lazy dog.?! 0 1 2 3 4 5 6 7 8 9

"""

def flip(string):
    normal = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ?!."
    upsidedown = "ɐqɔpǝɟƃɥᴉɾʞlɯuodbɹsʇnʌʍxʎz∀qƆpƎℲפHIſʞ˥WNOԀQɹS┴∩ΛMX⅄Z0ƖᄅƐㄣϛ9ㄥ86 ¿¡˙"
    dictionary = dict(zip(normal, upsidedown))
    return "".join([dictionary[c] for c in reversed(string)])

def main():
    assert(flip("This is some text that I am writing!") == "¡ƃuᴉʇᴉɹʍ ɯɐ I ʇɐɥʇ ʇxǝʇ ǝɯos sᴉ sᴉɥ┴")
    assert(flip("Soon it will be just 4 lines of upside down text.") == "˙ʇxǝʇ uʍop ǝpᴉsdn ɟo sǝuᴉl ㄣ ʇsnɾ ǝq llᴉʍ ʇᴉ uooS")
    assert(flip("How did they do it?") == "¿ʇᴉ op ʎǝɥʇ pᴉp ʍoH")
    assert(flip("We will all know soon.") == "˙uoos ʍouʞ llɐ llᴉʍ ǝM")

main()
