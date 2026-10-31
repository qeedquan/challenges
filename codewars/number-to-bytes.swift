/*

In this kata, your task is to write a function to_bytes(n) (or toBytes(n) depending on language) that produces a list of bytes that represent a given non-negative integer n.
Each byte in the list is represented by a string of '0' and '1' of length 8.
The most significant byte is first in the list.
The example test cases should provide you with all the details.
You may assume that the argument n is valid.

*/

import Foundation

func tobytes(_ number: UInt) -> [String] {
    var result = [String]()
    var number = number
    while true {
        var string = String(number & 0xff, radix: 2)
        if string.count < 8 {
            string = String(repeating: "0", count: 8 - string.count) + string
        }

        result.append(string)
        number >>= 8
        if number == 0 {
            break
        }
    }
    result = result.reversed()
    return result
}

assert(tobytes(0) == ["00000000"])
assert(tobytes(1) == ["00000001"])
assert(tobytes(257) == ["00000001", "00000001"])
assert(tobytes(65535) == ["11111111", "11111111"])
assert(tobytes(65537) == ["00000001", "00000000", "00000001"])
assert(tobytes(0x1020304) == ["00000001", "00000010", "00000011", "00000100"])
assert(tobytes((1 << 24) + 1) == ["00000001", "00000000", "00000000", "00000001"])
assert(tobytes((1 << 31) + 1) == ["10000000", "00000000", "00000000", "00000001"])
assert(tobytes((1 << 32) - 1) == ["11111111", "11111111", "11111111", "11111111"])
