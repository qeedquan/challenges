/*

It's pretty straightforward.
Your goal is to create a function that removes the first and last characters of a string.
You're given one parameter, the original string.
You don't have to worry with strings with less than two characters.

*/

func removeChar(_ string: String) -> String {
    var string = string
    if string.count > 0 {
        string.removeFirst()
    }
    if string.count > 0 {
        string.removeLast()
    }
    return string
}

assert(removeChar("") == "")
assert(removeChar("abc") == "b")
