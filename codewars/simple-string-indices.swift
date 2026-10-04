/*

In this Kata, you will be given a string with brackets and an index of an opening bracket and your task will be to return the index of the matching closing bracket. Both the input and returned index are 0-based except in Fortran where it is 1-based. An opening brace will always have a closing brace. Return -1 if there is no answer (in Haskell, return Nothing; in Fortran, return 0; in Go, return an error)

Examples
solve("((1)23(45))(aB)", 0) = 10 // the opening brace at index 0 matches the closing brace at index 10
solve("((1)23(45))(aB)", 1) = 3
solve("((1)23(45))(aB)", 2) = -1 // there is no opening bracket at index 2, so return -1
solve("((1)23(45))(aB)", 6) = 9
solve("((1)23(45))(aB)", 11) = 14
solve("((>)|?(*'))(yZ)", 11) = 14
Input will consist of letters, numbers and special characters, but no spaces. The only brackets will be ( and ).

More examples in the test cases.

Good luck!

*/

func charat(_ string: String, _ offset: Int) -> Character {
    let index = string.index(string.startIndex, offsetBy: offset)
    return string[index]
}

func solve(_ string: String, _ start: Int) -> Int {
    if start >= string.count || charat(string, start) != "(" {
        return -1
    }

    var brackets = 0
    for index in start + 1...string.count - 1 {
        switch charat(string, index) {
        case "(":
            brackets += 1
        case ")":
            if brackets == 0 {
                return index
            }
            brackets -= 1
        default:
            break
        }
    }
    return -1
}

assert(solve("((1)23(45))(aB)", 0) == 10)
assert(solve("((1)23(45))(aB)", 1) == 3)
assert(solve("((1)23(45))(aB)", 2) == -1)
assert(solve("((1)23(45))(aB)", 6) == 9)
assert(solve("((1)23(45))(aB)", 11) == 14)
assert(solve("((>)|?(*'))(yZ)", 11) == 14)
assert(solve("(g(At)IO(f)(tM(qk)YF(n)Nr(E)))", 0) == 29)
assert(solve("(>_(va)`?(h)C(as)(x(hD)P|(fg)))", 19) == 22)
assert(solve("(___________", 0) == -1)
