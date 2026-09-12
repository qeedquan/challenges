/*

Write a function to split a string and convert it into an array of words. For example:

"Robin Singh" ==> ["Robin", "Singh"]

"I love arrays they are my favorite" ==> ["I", "love", "arrays", "they", "are", "my", "favorite"]

*/

import Foundation

func split(_ string: String) -> [String] {
    return string.components(separatedBy: " ")
}

assert(split("Robin Singh") == ["Robin", "Singh"])
assert(split("I love arrays they are my favorite") == ["I", "love", "arrays", "they", "are", "my", "favorite"])
