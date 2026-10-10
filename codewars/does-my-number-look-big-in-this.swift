/*

A Narcissistic Number is a positive number which is the sum of its own digits, each raised to the power of the number of digits in a given base. In this Kata, we will restrict ourselves to decimal (base 10).

For example, take 153 (3 digits), which is narcisstic:

    1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
and 1652 (4 digits), which isn't:

    1^4 + 6^4 + 5^4 + 2^4 = 1 + 1296 + 625 + 16 = 1938
The Challenge:

Your code must return true or false (not 'true' and 'false') depending upon whether the given number is a Narcissistic number in base 10. This may be True and False in your language, e.g. PHP.

Error checking for text strings or other invalid inputs is not required, only valid positive non-zero integers will be passed into the function.

*/

func ipow(_ base: Int, _ exp: Int) -> Int {
    var (exp, base, result) = (exp, base, 1)
    while true {
        if (exp & 1) != 0 {
            result *= base
        }
        exp >>= 1
        if exp == 0 {
            break
        }
        base *= base
    }

    return result
}

// https://oeis.org/A005188
func narcissistic(_ number: Int) -> Bool {
    var (digits, value) = (0, number)
    while value > 0 {
        digits += 1
        value /= 10
    }

    var sum = 0
    value = number
    while value > 0 {
        sum += ipow(value % 10, digits)
        value /= 10
    }
    return sum == number
}

let table = [
    1, 2, 3, 4, 5, 6, 7, 8, 9, 153, 370, 371, 407, 1634, 8208, 9474, 54748, 92727, 93084, 548834,
]

for i in 1...table.max()! {
    if table.contains(i) {
        assert(narcissistic(i) == true)
    } else {
        assert(narcissistic(i) == false)
    }
}
