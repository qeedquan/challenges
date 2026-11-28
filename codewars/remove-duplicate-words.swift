/*

Your task is to remove all duplicate words from a string, leaving only single (first) words entries.

Example:

Input:

'alpha beta beta gamma gamma gamma delta alpha beta beta gamma gamma gamma delta'

Output:

'alpha beta gamma delta'

*/

import Foundation

func removeDuplicateWords(_ words: String) -> String {
    var result = ""
    var seen = [String: Bool]()
    for word in words.components(separatedBy: " ") {
        if seen[word] != nil {
            continue
        }
        result += word + " "
        seen[word] = true
    }
    if result != "" {
        result.removeLast()
    }
    return result
}

assert(removeDuplicateWords("alpha beta beta gamma gamma gamma delta alpha beta beta gamma gamma gamma delta") == "alpha beta gamma delta")
