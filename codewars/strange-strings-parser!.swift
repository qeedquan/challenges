/*

Here you have a connected to a socket, and the data looks very strange.
It seems to be separated by a random special character! Oh No!
We need your help to find the special character, parse the data, and return it translated!
There isn't much time, hurry we need your help!

*/

func wordSplitter(_ string: String) -> [String] {
    var result: [String] = []
    var word = ""
    for symbol in string {
        if "+|:;~!=&*$#@>?%".contains(symbol) {
            result.append(word)
            word = ""
        } else {
            word += String(symbol)
        }
    }
    if word != "" {
        result.append(word)
    }
    return result
}

assert(wordSplitter("11:11:11:11:11") == ["11", "11", "11", "11", "11"])
assert(wordSplitter("RADIO+FREQ+12500+NW+1600+END") == ["RADIO", "FREQ", "12500", "NW", "1600", "END"])
assert(wordSplitter("CODE*SEVEN|FOURTY#THREE&HUNDRED") == ["CODE", "SEVEN", "FOURTY", "THREE", "HUNDRED"])
assert(wordSplitter("56&SHORT!BEACH+WEST=HOUSE") == ["56", "SHORT", "BEACH", "WEST", "HOUSE"])
assert(wordSplitter("320000;56C*7200RPM#MODE%65>LATCH?ON") == ["320000", "56C", "7200RPM", "MODE", "65", "LATCH", "ON"])
assert(wordSplitter("320000;56C:7200RPM#MODE%65>LATCH?ON") == ["320000", "56C", "7200RPM", "MODE", "65", "LATCH", "ON"])
assert(wordSplitter("32.0500;-6C:PITCH=-72#ROLL!21.3*REGISTER:90.345689&ARMED?-25") == ["32.0500", "-6C", "PITCH", "-72", "ROLL", "21.3", "REGISTER", "90.345689", "ARMED", "-25"])
