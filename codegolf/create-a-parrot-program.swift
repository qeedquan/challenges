/*

Given an input, output that input followed by a newline endlessly.

Input will be a string consisting only of printable ASCII characters (0x20-0x7E) and newlines (0x0A).

If input is length 0, endlessly output newlines.

This is code-golf so fewest bytes in each language wins!

*/

if let line = readLine() {
    while true {
        print(line)
    }
}
