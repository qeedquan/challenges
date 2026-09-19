/*

Build a pyramid
You will get a string s with an even length, and an integer n which represents the height of the pyramid and your task is to draw the following pattern. Each line is seperated with "\n".

n will always be greater than 3. No need to check for invalid parameters
There are no whitespaces at the end of the lines
Example
build_pyramid("00-00..00-00", 7) should return:

                                    00-00..00-00
                              0000--0000....0000--0000
                        000000---000000......000000---000000
                   00000000----00000000........00000000----00000000
            0000000000-----0000000000..........0000000000-----0000000000
      000000000000------000000000000............000000000000------000000000000
00000000000000-------00000000000000..............00000000000000-------00000000000000

*/

func pyramid(_ string: String, _ levels: Int) {
    if levels < 1 {
        return
    }

    for level in 1...levels {
        let spaces = (string.count / 2) * (levels - level)
        print(String(repeating: " ", count: spaces), terminator: "")
        for symbol in string {
            print(String(repeating: symbol, count: level), terminator: "")
        }
        print()
    }
    print()
}

pyramid("00-00..00-00", 3)
pyramid("00-00..00-00", 7)
