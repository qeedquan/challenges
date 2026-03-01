/*

You may continue to submit your answer, however you can no longer win. Original post kept for posterity:

Your goal is to convert a whole number between 1-9 into the word it represents.

You will not need to worry about decimals
The user will input a number. Assume that they will never enter anything 10 or higher
The user must type the number at some point, however the method the program reads it does not matter. It can be with stdin, reading a text file, etc, however the user must press the 9 button on their keyboard (for example) at some point
It is not case sensitive (ie, "one", "One", "oNe", "OnE", etc are all acceptable)
HTTP/etc requests are allowed, however any code executed by the server the request is made to counts towards the byte count of your final code (e.g. if I had a C++ program make a HTTP request, the PHP code used in the HTTP request counts)
Anything that can compile and run is acceptable
This contest has ended on June 27th, 2014 (7 days from posting).
This is a code-golf, so the shortest code wins

*/

func convert(_ n: Int) -> String {
    let lut = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    if n >= lut.count {
        return "unsupported"
    }
    return lut[n]
}

for i in 0..<10 {
    print(convert(i))
}
