/*

Build Tower Advanced
Build Tower by the following given arguments:
number of floors (integer and always greater than 0)
block size (width, height) (integer pair and always greater than (0, 0))

Tower block unit is represented as *

Python: return a list;
JavaScript: returns an Array;
Have fun!

for example, a tower of 3 floors with block size = (2, 3) looks like below

[
  '    **    ',
  '    **    ',
  '    **    ',
  '  ******  ',
  '  ******  ',
  '  ******  ',
  '**********',
  '**********',
  '**********'
]
and a tower of 6 floors with block size = (2, 1) looks like below

[
  '          **          ',
  '        ******        ',
  '      **********      ',
  '    **************    ',
  '  ******************  ',
  '**********************'
]


*/

import Foundation

func main() {
    build(3, 2, 3)
    build(6, 2, 1)
}

func build(_ floors: Int, _ width: Int, _ height: Int) {
    print(String(format: "floors=%d blocksize=(%d, %d)", floors, width, height))
    for index in 1...floors {
        let stars = width * (2 * index - 1)
        let spaces = width * (2 * floors - 1) - stars
        for _ in 1...height {
            print(String(repeating: " ", count: spaces / 2), terminator: "")
            print(String(repeating: "*", count: stars), terminator: "")
            print(String(repeating: " ", count: spaces / 2))
        }
    }
    print()
}

main()
