/*

You are given a string of numbers between 0-9. Find the average of these numbers and return it as a floored whole number (ie: no decimal places) written out as a string. Eg:

"zero nine five two" -> "four"

If the string is empty or includes a number greater than 9, return "n/a"

*/

import Foundation

func averageString(_ string: String) -> String {
    let numbers = [
        "zero": 0,
        "one": 1,
        "two": 2,
        "three": 3,
        "four": 4,
        "five": 5,
        "six": 6,
        "seven": 7,
        "eight": 8,
        "nine": 9,
    ]

    var total = 0
    var length = 0
    for symbol in string.components(separatedBy: " ") {
        let value = numbers[symbol] ?? -1
        if value < 0 {
            return "n/a"
        }
        total += value
        length += 1
    }
    if length == 0 {
        return "n/a"
    }

    let average = total / length
    for (key, value) in numbers {
        if average == value {
            return key
        }
    }
    return "n/a"
}

assert(averageString("zero nine five two") == "four")
assert(averageString("four six two three") == "three")
assert(averageString("one two three four five") == "three")
assert(averageString("five four") == "four")
assert(averageString("zero zero zero zero zero") == "zero")
assert(averageString("one one eight one") == "two")
assert(averageString("") == "n/a")
