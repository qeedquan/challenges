/*

Define a function trim (JavaScript: method String.prototype.trim) which removes all forms of leading and trailing whitespace from a given string. Please refer to the Sample Tests for more examples.

Note: The built-in trim, trimLeft && trimRight methods has been disabled.

*/

import Foundation

extension String {
    func trim() -> String {
        return self.trimmingCharacters(in: .whitespaces)
    }
}

print("    abc    ".trim())
