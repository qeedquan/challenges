#!/usr/bin/env python3

"""

Verify a Chinese ID Number
The Resident Identity Card (居民身份证) is a document issued to most Chinese citizens.
It contains information about its holder, including their name, address, and ID number, an 18-character code with the following structure:

https://i.sstatic.net/ANYlMa8J.png

Digits 1 - 6: Address code of the birthplace.
Digits 7 - 14: Birth date in YYYYMMDD format.
Digits 15 - 17: Order code (3 random digits).
Digit 18: Checksum, computed from the sum of the first 17 digits. Given s[:17], interpret it as a base-13 integer, then compute: c = (1 - 2 * int(s[:17], 13)) % 11. The digit becomes X if equal to 10. A more detailed explation is available here.
The task: Given a ID number as a string, return whether it is valid. It is valid if:

It has exactly 18 characters,
All characters except possibly the last are numeric digits,
Digits 7 - 14 form a valid date in YYYYMMDD format. The month and day need to be valid (so no 0632 or 0230), but the year does not need checking.
The last character equals the checksum digit, calculated using the method above.
Examples:

ID number	Validity
110105199001010037	Valid
11010519491231002X	Valid. The checksum 10 is replaced by X.
110105199001010039	Invalid. Checksum is 9 instead of 7
110105199913010045	Invalid. Month 13 doesn't exist.
110105199906310045	Invalid. June only has 30 days.
1101051999012312345	Invalid. 19 characters instead of 18.
123AB1239518BBC123	Invalid. Non-numeric characters.
The input is an ASCII string containing a single ID number and nothing else. Any output format is fine, as long as it is clear which ID numbers are valid and which aren't. Standard code-golf scoring is used.

Good luck!

"""

from datetime import *

def valid(s):
    if len(s) != 18:
        return False
    
    try:
        date.fromisoformat(s[6:14])
    except:
        return False

    c = (1 - 2*int(s[:17], 13)) % 11
 
    if s[17] == 'X' and c > 9:
        return True
    return int(s[17]) == c

def main():
    assert(valid("110105199001010037") == True)
    assert(valid("11010519491231002X") == True)
    assert(valid("110105199001010039") == False)
    assert(valid("110105199913010045") == False)
    assert(valid("110105199906310045") == False)
    assert(valid("1101051999012312345") == False)
    assert(valid("123AB1239518BBC123") == False)

main()
