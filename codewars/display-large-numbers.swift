/*

In some locales (like the US) large numbers are displayed with commas every 3 digits to help users understand the size of the number at a glance.

You're going to write a function to format a number for display in that way.

For example:

displayLargeNumber(1234); // "1,234"
displayLargeNumber(1234567); // "1,234,567"

It should also work for string inputs that contain numbers:

displayLargeNumber("1234"); // "1,234"

This exercise can be great practice for off-by-one errors. For the full benefit, try not to use the test suite too much. Think through your input and iteration carefully instead.

Also, the best practice for this in real life would probably be to use toLocaleString. I can't stop you from "cheating", but the spirit of this task is to do the parsing yourself.

Good luck!

*/

import Foundation

func display(_ number: Int) -> String {
    let formatter = NumberFormatter()
    formatter.numberStyle = .decimal
    return formatter.string(from: NSNumber(value: number))!
}

print(display(1234))
print(display(1_234_567))
print(display(-13_555_323))
