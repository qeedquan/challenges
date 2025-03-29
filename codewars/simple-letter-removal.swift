/*

In this Kata, you will be given a lower case string and your task will be to remove k characters from that string using the following rule:

- first remove all letter 'a', followed by letter 'b', then 'c', etc...
- remove the leftmost character first.
For example:
solve('abracadabra', 1) = 'bracadabra' # remove the leftmost 'a'.
solve('abracadabra', 2) = 'brcadabra'  # remove 2 'a' from the left.
solve('abracadabra', 6) = 'rcdbr'      # remove 5 'a', remove 1 'b'
solve('abracadabra', 8) = 'rdr'
solve('abracadabra',50) = ''
More examples in the test cases. Good luck!

*/

func solve(_ string: String, _ removes: Int) -> String {
    var positions: [[Int]] = []
    var index = 0
    for symbol in string {
        if "a" <= symbol && symbol <= "z" {
            positions.append([Int(symbol.asciiValue!), index])
        }
        index += 1
    }
    positions = positions.sorted { ($0[0], $0[1]) < ($1[0], $1[1]) }

    var skip = [Int: Bool]()
    for index in 0..<min(removes, positions.count) {
        skip[positions[index][1]] = true
    }

    var result = ""
    index = 0
    for symbol in string {
        if skip[index] == nil {
            result += String(symbol)
        }
        index += 1
    }
    return result
}

assert(solve("abracadabra", 1) == "bracadabra")
assert(solve("abracadabra", 2) == "brcadabra")
assert(solve("abracadabra", 6) == "rcdbr")
assert(solve("abracadabra", 8) == "rdr")
assert(solve("abracadabra", 50) == "")
