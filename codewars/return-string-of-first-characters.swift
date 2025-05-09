/*

In this exercise, a string is passed to a method and a new string has to be returned with the first character of each word in the string.

For example:

"This Is A Test" ==> "TIAT"

Strings will only contain letters and spaces, with exactly 1 space between words, and no leading/trailing spaces.

*/

import Foundation

func makestring(_ string: String) -> String {
    var result = ""
    var initial = true
    for character in string {
        if character.isWhitespace {
            initial = true
        } else if initial {
            result += String(character)
            initial = false
        }
    }
    return result
}

assert(makestring("This Is A Test") == "TIAT")
