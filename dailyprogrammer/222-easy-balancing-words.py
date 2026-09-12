#!/usr/bin/env python3

"""

Description
Today we're going to balance words on one of the letters in them. We'll use the position and letter itself to calculate the weight around the balance point. A word can be balanced if the weight on either side of the balance point is equal. Not all words can be balanced, but those that can are interesting for this challenge.

The formula to calculate the weight of the word is to look at the letter position in the English alphabet (so A=1, B=2, C=3 ... Z=26) as the letter weight, then multiply that by the distance from the balance point, so the first letter away is multiplied by 1, the second away by 2, etc.

As an example:

STEAD balances at T: 1 * S(19) = 1 * E(5) + 2 * A(1) + 3 * D(4))

Input Description
You'll be given a series of English words. Example:

STEAD
Output Description
Your program or function should emit the words split by their balance point and the weight on either side of the balance point. Example:

S T EAD - 19
This indicates that the T is the balance point and that the weight on either side is 19.

Challenge Input
CONSUBSTANTIATION
WRONGHEADED
UNINTELLIGIBILITY
SUPERGLUE
Challenge Output
Updated - the weights and answers I had originally were wrong. My apologies.

CONSUBST A NTIATION - 456
WRO N GHEADED - 120
UNINTELL I GIBILITY - 521
SUPERGLUE DOES NOT BALANCE

Notes
This was found on a word games page suggested by u/cDull, thanks! If you have your own idea for a challenge, submit it to r/DailyProgrammer_Ideas, and there's a good chance we'll post it.

"""

"""

@kalmakka

Can be done in O(N) time.

Since this is going to be confusing unless I define it: I will use weight to refer to the weight of a character (ignoring distance); and torque to refer to how much the character influences the balance (i.e. weight × distance).

leftS contains the sum of all character weights of the characters I have passed going from the left. leftW is their total torque. (you can tell that I came up with these names before coming up with the definitions above :) )

When I move my balance point candidate one position to the right, then all characters I have passed have their distance increased by 1. As torque = weight × distance, and distance just got increased by 1, torque is increased by the total weight of all characters - or leftS. Therefore I increase leftS (the weight sum) by the value of the new character, and increase leftW (the torque sum) by the value of leftS.

In other words, the multiplication is done by repeated addition. The weight is added once to leftS, and then leftS is added one or many times to leftW.

"""

def balance(s):
    lw, ls, l = 0, 0, 0
    rw, rs, r = 0, 0, len(s) - 1
    while l < r:
        if lw <= rw:
            ls += ord(s[l]) - ord('A') + 1
            lw += ls
            l += 1
        else:
            rs += ord(s[r]) - ord('A') + 1
            rw += rs
            r -= 1
    if l == r and lw == rw:
        return f"{s[:l]} {s[l:l+1]} {s[l+1:]} - {lw}"
    return f"{s} DOES NOT BALANCE"

def main():
    assert(balance("STEAD") == "S T EAD - 19")
    assert(balance("CONSUBSTANTIATION") == "CONSUBST A NTIATION - 456")
    assert(balance("WRONGHEADED") == "WRO N GHEADED - 120")
    assert(balance("UNINTELLIGIBILITY") == "UNINTELL I GIBILITY - 521")
    assert(balance("SUPERGLUE") == "SUPERGLUE DOES NOT BALANCE")

main()
