/*

Inspired by the emojify custom Python module.

You are given a string made up of chains of emotes separated by 1 space each, with chains having 2 spaces in-between each.

Each emote represents a digit:

:)  | 0
:D  | 1
>(  | 2
>:C | 3
:/  | 4
:|  | 5
:O  | 6
;)  | 7
^.^ | 8
:(  | 9

Each emote chain represents the digits of the ASCII/Unicode code for a character, e.g. :( ;) is 97, which is the ASCII code for 'a'.

Given a such string of emotes, find the string it represents. Example:

':D :) :/  :D :) :|' is 2 chains: ':D :) :/' and ':D :) :|'.

These represent ASCII codes 104 and 105 respectively, translating to 'hi'.

Input will always be valid. Chains may start with leading zeroes; these are valid and do not change the chain's value.

*/

import Foundation

func deemojify(_ string: String) -> String {
    let table = [
        ":)": 0,
        ":D": 1,
        ">(": 2,
        ">:C": 3,
        ":/": 4,
        ":|": 5,
        ":O": 6,
        ";)": 7,
        "^.^": 8,
        ":(": 9,
    ]

    var result = ""
    for chain in string.components(separatedBy: "  ") {
        var value = 0
        for emoji in chain.components(separatedBy: " ") {
            value = (value * 10) + (table[emoji] ?? 0)
        }
        result += String(UnicodeScalar(value) ?? "?")
    }
    return result
}

assert(deemojify(":D :) :/  :D :) :|") == "hi")
assert(deemojify(";) >(  :D :) :D  :D :) ^.^  :D :) ^.^  :D :D :D  >:C >(  :D :D :(  :D :D :D  :D :D :/  :D :) ^.^  :D :) :)  >:C >:C") == "Hello world!")
assert(deemojify(":)") == "\u{0}")
