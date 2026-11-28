/*

Introduction
The Robber Language (Rövarspråket) is a Swedish cant used by children to mislead people not familiar with the language. It's used by kids in several screenplays created by Astrid Lindgren ( https://en.wikipedia.org/wiki/Astrid_Lindgren ).

The idea is that every consonant in a sentence is duplicated, with an o inserted in between (b becomes bob). Vowels are left untouched (a remains an a). It's quite hard for an untrained ear to understand a conversation encoded in this manner, especially if spoken rapidly.

Example
In this example, the consonants f, b and r are modified. The vowels o and a are left untouched.

'foo bar' => 'fofoo bobaror' (`fof-o-o bob-a-ror`)

Note: The dashes - in the example are added for readability and should not be included in the output.

The Assignment
Your task is to implement a function function robberEncode(sentence) which takes in a string sentence and returns the result, converted into robber language, as a string.

Notes
Only consonants should be modified; leave all other characters unchanged.
Both upper and lower case characters will be tested.
The case of the o character and the neighboring consonants should match (F => FOF and f => fof).
For the purpose of this kata, a character is considered a consonant if it's equal to one of the letters BCDFGHJKLMNPQRSTVWXYZ.

Testing
The tests will challenge your function with sentences of length 0-255, ASCII characters between 32-126 and nothing else.

Links
Check out these links for more information:

https://en.wikipedia.org/wiki/R%C3%B6varspr%C3%A5ket

*/

import Foundation

func robber(_ string: String) -> String {
    var result = ""
    for symbol in string {
        result += String(symbol)

        let upper = symbol.uppercased()
        if "BCDFGHJKLMNPQRSTVWXYZ".contains(upper) {
            if symbol.isUppercase {
                result += "O" + String(symbol)
            } else {
                result += "o" + String(symbol)
            }
        }
    }
    return result
}

assert(robber("foo bar") == "fofoo bobaror")
assert(robber("hello world") == "hohelollolo wowororloldod")
assert(robber("coding is fun") == "cocododinongog isos fofunon")
assert(robber("follow the white rabbit") == "fofolollolowow tothohe wowhohitote rorabobbobitot")
assert(robber("S.O.S") == "SOS.O.SOS")
