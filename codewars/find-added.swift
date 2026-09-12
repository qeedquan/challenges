/*

You are given two strings (st1, st2) as inputs. Your task is to return a string containing the numbers in st2 which are not in str1. Make sure the numbers are returned in ascending order. All inputs will be a string of numbers.

Here are some examples:

findAdded('4455446', '447555446666'); // '56667'
findAdded('44554466', '447554466'); // '7'
findAdded('9876521', '9876543211'); // '134'
findAdded('678', '876'); // ''
findAdded('678', '6'); // ''

*/

func findAdded(_ string0: String, _ string1: String) -> String {
    var count0 = [Character: Int]()
    var count1 = [Character: Int]()
    for character in string0 {
        count0[character] = (count0[character] ?? 0) + 1
    }
    for character in string1 {
        count1[character] = (count1[character] ?? 0) + 1
    }

    var result = ""
    for character in "0123456789" {
        let value0 = count0[character] ?? 0
        let value1 = count1[character] ?? 0
        if value0 < value1 {
            result += String(repeating: character, count: value1 - value0)
        }
    }
    return result
}

assert(findAdded("4455446", "447555446666") == "56667")
assert(findAdded("44554466", "447554466") == "7")
assert(findAdded("9876521", "9876543211") == "134")
assert(findAdded("678", "876") == "")
assert(findAdded("678", "6") == "")
