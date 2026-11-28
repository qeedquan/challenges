/*

Task:
Your task is to write a function which returns the sum of following series upto nth term(parameter).

Series: 1 + 1/4 + 1/7 + 1/10 + 1/13 + 1/16 +...
Rules:
You need to round the answer to 2 decimal places and return it as String.

If the given value is 0 then it should return 0.00

You will only be given Natural Numbers as arguments.

Examples:(Input --> Output)
1 --> 1 --> "1.00"
2 --> 1 + 1/4 --> "1.25"
5 --> 1 + 1/4 + 1/7 + 1/10 + 1/13 --> "1.57"

*/

import Foundation

func series(_ n: Int) -> String {
    var r = 0.0
    for i in 0..<n {
        r += 1.0 / (1.0 + Double(3 * i))
    }
    return String(format: "%.2f", r)
}

for i in 0...10 {
    print(i, series(i))
}
