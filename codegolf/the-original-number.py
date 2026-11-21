#!/usr/bin/env python3

"""

Scenario
John has an important number, and he doesn't want others to see it.

He decided to encrypt the number, using the following steps:

His number is always a non-decreasing sequence (ie. "1123")

He converted each digit into English words. (ie. "123" -> "ONETWOTHREE")

And then, rearrange the letters randomly. (ie. "ONETWOTHREE" -> "ENOWTOHEETR")

John felt that his number were safe in doing so. In fact, such encryption can be easily decrypted :(

Task
Given the encrypted string s, your task is to decrypt it and return the original number.

Rules
This is code golf, so the shortest answer in bytes wins
You can assume that the input string is always valid
The input string only contains uppercase letters
The original numbers are always arranged in ascending order
You may return the number in string or integer format
The letters will only be shuffled between one word, not between the whole string.
The numbers will only be from 1 to 9 inclusive (ONE to NINE)
Possible Unscrambled String
Here is a list of the strings just after they have been converted to strings from the numbers:

 1 -> ONE
 2 -> TWO
 3 -> THREE
 4 -> FOUR
 5 -> FIVE
 6 -> SIX
 7 -> SEVEN
 8 -> EIGHT
 9 -> NINE

Examples
"NEO" -> 1

"ENOWOT" -> 12

"EONOTWHTERE" -> 123

"SNVEEGHEITNEIN" -> 789

"ENOOWTEERHTRUOFEVIFXISNEVESTHGIEENIN" -> 123456789

"NOEWOTTOWHEERT" -> 1223

"""

"""

@Score_Under

Magic number finder:
#!/usr/bin/env python33
from itertools import count, permutations

def cumul(x):
    s = 0
    for v in x:
        s += v
        yield s

all_words = 'ONE TWO THREE FOUR FIVE SIX SEVEN EIGHT NINE'.split()

for modulo in range(1, 1000):
    for power in range(1, 300):
        combinations = []
        for word in all_words:
            my_combination = []
            for perm in permutations(word):
                my_combination += cumul(power**(ord(x)) % modulo for x in perm)
            combinations.append(my_combination)

        past_combinations = set(())
        past_intermediates = set(())
        collision = False
        for combination in combinations:
            final = combination[-1]
            if final in past_intermediates or any(intermediate in past_combinations for intermediate in combination):
                collision = True
                break
            past_combinations.add(final)
            past_intermediates.update(combination)

        if not collision:
            print("Good params:", power, modulo)
            print("Results:", ", ".join(str(x[-1]) for x in combinations))

Explanation:
I had a feeling that I could smash the ASCII bits together and sum them up somehow to determine when I had a full word. Originally I tried messing with 3**ord(letter) and comparing to expected results, but it resulted in some very large numbers. I though it would be appropriate to brute-force some parameters a little, namely modulus (to ensure the numbers are small) and a multiplier to disperse the numbers differently around the range of the modulus.

I ended up changing the multiplier variable into a variable affecting the power itself because (from trial and error) that somehow managed to give me a slightly shorter golfed answer.

And above you see the results of that brute-forcing and a little manual golfing.

The reason for choosing 3**x originally is because I knew you could represent every number there. The most repeated digits any number had is two (thrEE, sEvEn, NiNe, etc), so I decided to think of every input as a base-3 number. That way I could (mentally) represent them as something like 10100000000010020000 (three; a 1 in the t slot, a 1 in the r slot, a 1 in the h slot, and a 2 in the e slot). Each number this way gets a unique representation which can be easily pieced together by iterating the string and summing some numbers, and it ends up independent of the actual order of the letters. Of course, this didn't turn out to be the ideal solution, but the current solution is still written with this idea in mind.

"""

def decode(s):
    tab = [80, 33, 131, 117, 142, 73, 146, 124, 90]

    v = 0
    t = ""
    for c in s:
        v += 34**ord(c) % 43
        if v in tab:
            t += str(1 + tab.index(v))
            v = 0
    return int(t)

def main():
    assert(decode("NEO") == 1)
    assert(decode("ENOWOT") == 12)
    assert(decode("EONOTWHTERE") == 123)
    assert(decode("SNVEEGHEITNEIN") == 789)
    assert(decode("ENOOWTEERHTRUOFEVIFXISNEVESTHGIEENIN") == 123456789)
    assert(decode("NOEWOTTOWHEERT") == 1223)

main()
