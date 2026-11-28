/*

Description:
Remove all exclamation marks from the end of sentence.

Examples
remove("Hi!") === "Hi"
remove("Hi!!!") === "Hi"
remove("!Hi") === "!Hi"
remove("!Hi!") === "!Hi"
remove("Hi! Hi!") === "Hi! Hi"
remove("Hi") === "Hi"

*/

func remove(_ string: String) -> String {
    var string = string
    while string.hasSuffix("!") {
        string.removeLast(1)
    }
    return string
}

assert(remove("Hi!") == "Hi")
assert(remove("Hi!!!") == "Hi")
assert(remove("!Hi") == "!Hi")
assert(remove("!Hi!") == "!Hi")
assert(remove("Hi! Hi!") == "Hi! Hi")
assert(remove("Hi") == "Hi")
