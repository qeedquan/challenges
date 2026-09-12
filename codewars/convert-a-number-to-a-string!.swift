/*

We need a function that can transform a number into a string.

What ways of achieving this do you know?

Examples:
123 --> "123"
999 --> "999"

*/

func numberToString(_ number: Int) -> String {
    return "\(number)"
}

assert(numberToString(123) == "123")
assert(numberToString(999) == "999")
