#!/usr/bin/env python3

"""

In Russia regular bus tickets usually consist of 6 digits. The ticket is called lucky when the sum of the first three digits equals to the sum of the last three digits. Write a function to find out whether the ticket is lucky or not. Return true if so, otherwise return false. Consider that input is always a string. Watch examples below.

isLucky('123321') => 1+2+3 = 3+2+1 => true // The ticket is lucky
isLucky('12341234') => false // Only six-digit numbers allowed :(
isLucky('12a21a') => false // Letters are not allowed :(
isLucky('100200') => false // :(
isLucky('22') => false // :(
isLucky('abcdef') => false // :(

"""

def islucky(s):
    if len(s) != 6:
        return False

    x = y = 0
    for i in range(3):
        if not s[i].isdigit() or not s[i + 3].isdigit():
            return False
        x += ord(s[i])
        y += ord(s[i + 3])
    return x == y

def main():
    assert(islucky("123321") == True)
    assert(islucky("12341234") == False)
    assert(islucky("12a21a") == False)
    assert(islucky("100200") == False)
    assert(islucky("22") == False)
    assert(islucky("abcdef") == False)

main()
