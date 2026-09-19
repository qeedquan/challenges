/*

You should write a function that takes a string and a positive integer n, splits the string into parts of length n and returns them in an array. It is ok for the last element to have less than n characters.

If n is not a number or not a valid size (> 0) (or is absent), you should return an empty array.

If n is greater than the length of the string, you should return an array with the only element being the same string.

Examples:

stringChunk('codewars', 2) // ['co', 'de', 'wa', 'rs']
stringChunk('thiskataeasy', 4) // ['this', 'kata', 'easy']
stringChunk('hello world', 3) // ['hel', 'lo ', 'wor', 'ld']
stringChunk('sunny day', 0) // []

*/

func stringChunk(_ string: String, _ length: Int) -> [String] {
    var result = [String]()
    if length < 1 {
        return result
    }

    var current = ""
    var count = 0
    for char in string {
        current += String(char)
        count += 1
        if count >= length {
            result.append(current)
            current = ""
            count = 0
        }
    }
    if count > 0 {
        result.append(current)
    }
    return result
}

assert(stringChunk("codewars", 2) == ["co", "de", "wa", "rs"])
assert(stringChunk("thiskataeasy", 4) == ["this", "kata", "easy"])
assert(stringChunk("hello world", 3) == ["hel", "lo ", "wor", "ld"])
assert(stringChunk("sunny day", 0) == [])
