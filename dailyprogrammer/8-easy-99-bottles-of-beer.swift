/*

write a program that will print the song "99 bottles of beer on the wall".

for extra credit, do not allow the program to print each loop on a new line.

*/

import Foundation

func bottles(_ n: Int) {
    for i in (1...n).reversed() {
        let s = (i > 1) ? "s" : ""
        print(String(format: "%d bottle%@ of beer on the wall, %d bottle%@ of beer.", i, s, i, s))
        if i - 1 > 0 {
            let s = (i - 1 > 1) ? "s" : ""
            print(String(format: "Take one down and pass it around, %d bottle%@ of beer on the wall.", i - 1, s))
            print()
        }
    }

    print("Take one down and pass it around, no more bottles of beer on the wall.")
    print()
    print("No more bottles of beer on the wall, no more bottles of beer.")
    print()
    print(String(format: "Go to the store and buy some more, %d bottles of beer on the wall.", n))
}

bottles(99)
