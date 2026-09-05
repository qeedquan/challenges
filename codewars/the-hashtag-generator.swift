/*

The marketing team is spending way too much time typing in hashtags.
Let's help them with our own Hashtag Generator!

Here's the deal:

It must start with a hashtag (#).
All words must have their first letter capitalized.
If the final result is longer than 140 chars it must return false.
If the input or the result is an empty string it must return false.
Examples
" Hello there thanks for trying my Kata"  =>  "#HelloThereThanksForTryingMyKata"
"    Hello     World   "                  =>  "#HelloWorld"
""                                        =>  false

*/

import Foundation

func hashtag(_ input: String) -> Any {
    var output = ""
    for word in input.components(separatedBy: " ") {
        output += word.capitalized
    }

    if input.count == 0 || output.count == 0 {
        return false
    }
    return "#" + output
}

assert(hashtag(" Hello there thanks for trying my Kata") as! String == "#HelloThereThanksForTryingMyKata")
assert(hashtag("    Hello     World   ") as! String == "#HelloWorld")
assert(hashtag("") as! Bool == false)
