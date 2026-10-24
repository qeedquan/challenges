#!/usr/bin/env python3

"""

Goats are great. Everybody loves goats.

And they also, for some reason, are an excellent complex ascii art for many languages to have built-ins for. Because of this, I personally feel a catalogue to document just how easily a language can print goats is greatly needed.

The Challenge
Given an integer input via any means print that many Goats separated by Newlines.

Your Goat for reference is:

  ___.
 //  \\
((   ''
 \\__,
/6 (%)\,
(__/:";,;\--____----_
;; :';,:';`;,';,;';`,`_
  ;:,;;';';,;':,';';,-Y\
   ;,;,;';';,;':;';'; Z/
   / ;,';';,;';,;';;'
  / / |';/~~~~~\';;'
 ( K  | |      || |
  \_\ | |      || |
   \Z | |      || |
      L_|      LL_|
      LW/      LLW/
Your particular goat may have more whitespace around it, if required.

Example
Given 3 on input, Output:

  ___.
 //  \\
((   ''
 \\__,
/6 (%)\,
(__/:";,;\--____----_
;; :';,:';`;,';,;';`,`_
  ;:,;;';';,;':,';';,-Y\
   ;,;,;';';,;':;';'; Z/
   / ;,';';,;';,;';;'
  / / |';/~~~~~\';;'
 ( K  | |      || |
  \_\ | |      || |
   \Z | |      || |
      L_|      LL_|
      LW/      LLW/
  ___.
 //  \\
((   ''
 \\__,
/6 (%)\,
(__/:";,;\--____----_
;; :';,:';`;,';,;';`,`_
  ;:,;;';';,;':,';';,-Y\
   ;,;,;';';,;':;';'; Z/
   / ;,';';,;';,;';;'
  / / |';/~~~~~\';;'
 ( K  | |      || |
  \_\ | |      || |
   \Z | |      || |
      L_|      LL_|
      LW/      LLW/
  ___.
 //  \\
((   ''
 \\__,
/6 (%)\,
(__/:";,;\--____----_
;; :';,:';`;,';,;';`,`_
  ;:,;;';';,;':,';';,-Y\
   ;,;,;';';,;':;';'; Z/
   / ;,';';,;';,;';;'
  / / |';/~~~~~\';;'
 ( K  | |      || |
  \_\ | |      || |
   \Z | |      || |
      L_|      LL_|
      LW/      LLW/
The Rules
You must take an integer input where 0 < input < 256, and print that many goats.
Goats may vary in whitespace, as long as the shape of the goat is the same.
You must submit a full program.
This is a catalogue, so any language or language version newer than the challenge is acceptable. Like usual, creating a language that prints N goats in 0 bytes isn't incredibly creative. Also, as this is a catalogue, no answer will be accepted.
This is however code-golf, so shortest answer per language.
If your language of choice is a trivial variant of another (potentially more popular) language which already has an answer (think BASIC or SQL dialects, Unix shells or trivial Brainfuck-derivatives like Alphuck),
consider adding a note to the existing answer that the same or a very similar solution is also the shortest in the other language.

"""

GOAT = """

  ___.
 //  \\\\
((   ''
 \\\\__,
/6 (%)\,
(__/:";,;\--____----_
;; :';,:';`;,';,;';`,`_
  ;:,;;';';,;':,';';,-Y\\
   ;,;,;';';,;':;';'; Z/
   / ;,';';,;';,;';;'
  / / |';/~~~~~\\';;'
 ( K  | |      || |
  \_\ | |      || |
   \Z | |      || |
      L_|      LL_|
      LW/      LLW/
"""

def goats(n):
    for i in range(n):
        print(GOAT)

def main():
    goats(3)

main()
