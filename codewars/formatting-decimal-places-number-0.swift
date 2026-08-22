/*

Each number should be formatted that it is rounded to two decimal places. You don't need to check whether the input is a valid number because only valid numbers are used in the tests.

Example:    
5.5589 is rounded 5.56   
3.3424 is rounded 3.34

*/

import Foundation

func twoDecimals(_ number: Double) -> Double {
    return round(number * 100) / 100
}

print(twoDecimals(5.5589))
print(twoDecimals(3.3424))
