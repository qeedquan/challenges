/*

Given a string, determine if it's a valid identifier.

Here is the syntax for valid identifiers:
Each identifier must have at least one character.
The first character must be picked from: alpha, underscore, or dollar sign. The first character cannot be a digit.
The rest of the characters (besides the first) can be from: alpha, digit, underscore, or dollar sign. In other words, it can be any valid identifier character.

Examples of valid identifiers:

i
wo_rd
b2h

Examples of invalid identifiers:

1i
wo rd
!b2h

*/

func isdigit(_ symbol: Character) -> Bool {
    return "0" <= symbol && symbol <= "9"
}

func isletter(_ symbol: Character) -> Bool {
    if "a" <= symbol && symbol <= "z" {
        return true
    }
    if "A" <= symbol && symbol <= "Z" {
        return true
    }
    if symbol == "_" || symbol == "$" {
        return true
    }
    return false
}

func valid(_ ident: String) -> Bool {
    var index = 0
    for symbol in ident {
        if !isletter(symbol) && !(index > 0 && isdigit(symbol)) {
            return false
        }
        index += 1
    }
    return true
}

assert(valid("i") == true)
assert(valid("wo_rd") == true)
assert(valid("b2h") == true)

assert(valid("1i") == false)
assert(valid("wo rd") == false)
assert(valid("!b2h") == false)
