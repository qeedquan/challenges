#!/usr/bin/env python3

"""

The Corpus are a fictional faction from the popular video game Warframe who have a somewhat interesting language.

Whilst other factions in the game such as the Grineer have some logic behind their language, the Corpus is simply a lossy substitution of the English language.

All Corpus words are the same as their English counterparts, except with the following alphabetical mappings:

English to Corpus mapping

This causes some problems with pronunciation as:

yes becomes yey
say becomes yay
yay becomes yay
sassy becomes yayyy
case becomes yaye

Here's a text version of the mappings:

a -> a
b -> t
c -> y
d -> p
e -> e
f -> t
g -> j
h -> k
i -> i
j -> t
k -> k
l -> p
m -> s
n -> t
o -> o
p -> k
q -> r
r -> t
s -> y
t -> p
u -> u
v -> t
w -> j
x -> k
y -> y
z -> b
The challenge
Given text using the English alphabet, output its Corpus translation.

For example, the text Hello, World! becomes Keppo, Jotpp! in Corpus

The Rules
Input will only consist of ASCII printable characters
Input text may contain whitespace and punctuation, these must be preserved
Capitalization of letters must be preserved
This is code-golf so naturally, fewest bytes wins!
The Testcases
Test cases are separated with <===========>, with a blank line between input and expected output

Hello, World!

Keppo, Jotpp!
<===========>
Yes

Yey
<===========>
TestcaSe

PeypyaYe
<===========>
Programming Puzzles and Code Golf

Ktojtassitj Kubbpey atp Yope Jopt
<===========>
This text has a
newline in it

Pkiy pekp kay a
tejpite it ip
<===========>
Corpus language best language

Yotkuy patjuaje teyp patjuaje
<===========>
Strip the flesh! Salt the wounds!

Yptik pke tpeyk! Yapp pke joutpy!
<===========>
"Install Warframe" they said, "It'll be fun" they said

"Itypapp Jatttase" pkey yaip, "Ip'pp te tut" pkey yaip
<===========>
What the **** did you just ****ing say about me, you little *****?
I'll have you know I graduated top of my class in the Navy Seals,
and I've been involved in numerous secret raids on Al-Quaeda,
and I have over 300 confirmed kills.

Jkap pke **** pip you tuyp ****itj yay atoup se, you pipppe *****?
I'pp kate you ktoj I jtapuapep pok ot sy ypayy it pke Taty Yeapy,
atp I'te teet ittoptep it tusetouy yeytep taipy ot Ap-Ruaepa,
atp I kate otet 300 yottitsep kippy.
The Bonus
If you also include an audio recording (or video with audio) of you pronouncing each of the testcase's Corpus translations, you may multiply your bytecount by 1 as a reward.

"""

def eng2corp(s):
    m = {
        'a': 'a',
        'b': 't',
        'c': 'y',
        'd': 'p',
        'e': 'e',
        'f': 't',
        'g': 'j',
        'h': 'k',
        'i': 'i',
        'j': 't',
        'k': 'k',
        'l': 'p',
        'm': 's',
        'n': 't',
        'o': 'o',
        'p': 'k',
        'q': 'r',
        'r': 't',
        's': 'y',
        't': 'p',
        'u': 'u',
        'v': 't',
        'w': 'j',
        'x': 'k',
        'y': 'y',
        'z': 'b',
    }

    p = ""
    for c in s:
        k = c.lower()
        if k in m:
            if c.isupper():
                c = m[k].upper()
            else:
                c = m[k]
        p += c
    return p

def main():
    assert(eng2corp("Hello, World!") == "Keppo, Jotpp!")
    assert(eng2corp("Yes") == "Yey")
    assert(eng2corp("TestcaSe") == "PeypyaYe")
    assert(eng2corp("Programming Puzzles and Code Golf") == "Ktojtassitj Kubbpey atp Yope Jopt")
    assert(eng2corp("This text has a\nnewline in it") == "Pkiy pekp kay a\ntejpite it ip")
    assert(eng2corp("Corpus language best language") == "Yotkuy patjuaje teyp patjuaje")
    assert(eng2corp("Strip the flesh! Salt the wounds!") == "Yptik pke tpeyk! Yapp pke joutpy!")
    assert(eng2corp("\"Install Warframe\" they said, \"It'll be fun\" they said") == "\"Itypapp Jatttase\" pkey yaip, \"Ip'pp te tut\" pkey yaip")
    assert(eng2corp("What the **** did you just ****ing say about me, you little *****?\nI'll have you know I graduated top of my class in the Navy Seals,\nand I've been involved in numerous secret raids on Al-Quaeda,\nand I have over 300 confirmed kills.") == "Jkap pke **** pip you tuyp ****itj yay atoup se, you pipppe *****?\nI'pp kate you ktoj I jtapuapep pok ot sy ypayy it pke Taty Yeapy,\natp I'te teet ittoptep it tusetouy yeytep taipy ot Ap-Ruaepa,\natp I kate otet 300 yottitsep kippy.")

main()
