/*

Task
Businesses like to have memorable telephone numbers. One way to make a telephone number memorable is to have it spell a memorable word or phrase.

For example, you can call the University of Waterloo by dialing the memorable TUT-GLOP. Sometimes only part of the number is used to spell a word. When you get back to your hotel tonight you can order a pizza from Gino's by dialing 310-GINO.

The standard form of a telephone number is seven decimal digits with a hyphen between the third and fourth digits (e.g. 888-1200). The keypad of a phone supplies the mapping of letters to numbers, as follows:

A, B, and C map to 2
D, E, and F map to 3
G, H, and I map to 4
J, K, and L map to 5
M, N, and O map to 6
P, R, and S map to 7
T, U, and V map to 8
W, X, and Y map to 9
letters can be uppercase or lowercase
There is no mapping for Q(q) or Z(z). Hyphens are not dialed, and can be added and removed as necessary. The standard form of TUT-GLOP is 888-4567, the standard form of 310-GINO is 310-4466, and the standard form of 3-10-10-10 is 310-1010.

Two telephone numbers are equivalent if they have the same standard form. (They dial the same number.)

Given a list phoneNumbers, your task is to find the duplicate telephone number in the list. Return an array like this:

["310-1010:2","487-3279:4","888-4567:3"]

The form of each element is standard form + : + numbers of duplicate

Input/Output
[input] string array phoneNumbers
The list of the telephone numbers. Each telephone number consists of a string composed of decimal digits, letters (excluding Q and Z) and hyphens. Exactly seven of the characters in the string will be digits or letters.

[output] a string array
The duplicate telephone number list. Arrange the output string by telephone number in ascending lexicographical order. If there are no duplicates in the input return [].

Example
For phoneNumbers:

[
"7399425",
"SEXY-GAL",
"Sexy-GAL",
"sexy-gal",
"SEXY-425",
"S-E-X-Y-G-A-L"
]
The output should be:

["739-9425:6"]

*/

func getPhoneNumber(_ number: String) -> String {
    var result = ""
    for symbol in number {
        switch symbol.uppercased() {
        case "0":
            result += "0"
        case "1":
            result += "1"
        case "A", "B", "C", "2":
            result += "2"
        case "D", "E", "F", "3":
            result += "3"
        case "G", "H", "I", "4":
            result += "4"
        case "J", "K", "L", "5":
            result += "5"
        case "M", "N", "O", "6":
            result += "6"
        case "P", "R", "S", "7":
            result += "7"
        case "T", "U", "V", "8":
            result += "8"
        case "W", "X", "Y", "9":
            result += "9"
        default:
            continue
        }
    }
    if result.count != 7 {
        return "invalid"
    }
    return result.prefix(3) + "-" + result.suffix(4)
}

func findDuplicatePhoneNumbers(_ numbers: [String]) -> [String] {
    var count = [String: Int]()
    for number in numbers {
        let phone = getPhoneNumber(number)
        count[phone] = (count[phone] ?? 0) + 1
    }

    var result = [String]()
    for number in count {
        if number.value > 1 {
            result.append(number.key + ":" + String(number.value))
        }
    }
    return result.sorted(by: <)
}

func main() {
    assert(
        findDuplicatePhoneNumbers([
            "7399425",
            "SEXY-GAL",
            "Sexy-GAL",
            "sexy-gal",
            "SEXY-425",
            "S-E-X-Y-G-A-L",
        ]) == ["739-9425:6"]
    )

    assert(
        findDuplicatePhoneNumbers([
            "4873279",
            "ITS-EASY",
            "888-4567",
            "3-10-10-10",
            "888-GLOP",
            "TUT-GLOP",
            "967-11-11",
            "310-GINO",
            "F101010",
            "888-1200",
            "-4-8-7-3-2-7-9-",
            "487-3279",
        ]) == [
            "310-1010:2",
            "487-3279:4",
            "888-4567:3",
        ]
    )
}

main()
