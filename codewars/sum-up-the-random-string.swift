/*

Given a random string consisting of numbers, letters, symbols, you need to sumFromString up the numbers in the string.

Note:

Consecutive integers should be treated as a single number. eg, 2015 should be treated as a single number 2015, NOT four numbers
All the numbers should be treaded as positive integer. eg, 11-14 should be treated as two numbers 11 and 14. Same as 3.14, should be treated as two numbers 3 and 14
If no number was given in the string, it should return 0
Example:

str = "In 2015, I want to know how much does iPhone 6+ cost?"
The numbers are 2015, 6

Sum is 2021.

*/

import Foundation

func sumFromString(_ string: String) -> Int {
    var total = 0
    var value = 0
    for symbol in string {
        if "0" <= symbol && symbol <= "9" {
            value = (value * 10) + symbol.wholeNumberValue!
        } else {
            total += value
            value = 0
        }
    }
    total += value
    return total
}

assert(sumFromString("In 2015, I want to know how much does iPhone 6+ cost?") == 2021)
assert(sumFromString("1+1=2") == 4)
assert(sumFromString("e=mc^2") == 2)
assert(sumFromString("abc0777def") == 777)
assert(sumFromString("0x10") == 10)
assert(sumFromString("0xFF") == 0)
assert(sumFromString("1e8") == 9)
assert(sumFromString("") == 0)
assert(sumFromString("12.4") == 16)
assert(sumFromString("15-15") == 30)
assert(sumFromString("150x15- 30-0050") == 245)
assert(sumFromString("h3ll0w0rld") == 3)
assert(sumFromString("2 + 3 = ") == 5)
assert(sumFromString("Our company made approximately 1 million in gross revenue last quarter.") == 1)
assert(sumFromString("The Great Depression lasted from 1929 to 1939.") == 3868)
assert(sumFromString("Dogs are our best friends.") == 0)
assert(sumFromString("C4t5 are 4m4z1ng.") == 18)
assert(sumFromString("The30quick20brown10f0x1203jumps914ov3r1349the102l4zy dog") == 3635)
