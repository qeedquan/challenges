#!/usr/bin/env python3

"""

Is it a good chord?
Definition of a chord:
We define a chord as three notes together.

Definition of a note:
We define a note as a number between 1 and 7, inclusive. As in music, we define 1 as do, 2 as re, 3 as fa, etc. However, the note names are not important. They will not be included in the question and likely not in a golfed solution. 1 is a note. 0 and 8 are not a note. As we will mention later, the input is a list of three notes, and invalid notes will not appear as an input. So even if you print the entire Never Gonna Give You Up lyrics when you encounter invalid inputs, I don't care. (However, I don't see how that's more golf-y.)

Definition of a good chord:
We define a good chord as follows:

If there are any two notes that are the same, disregard one of them.

Sort the notes.

Space the result on a piano. For instance, 135 will look like X X X and so will 246, 357, for instance.

If any of the notes are adjacent, it is considered a bad chord and thus not a good chord. That is, a chord containing 1 and 2 is bad, so is a chord containing 1 and 7.

The only possibilities that are left are:

With three digits,

135

136

137

146

147

157

246

247

257

357

And with two digits,

13 which could have been 113 or 133

14 which could have been 114 or 144

15 which could have been 115 or 155

16 which could have been 116 or 166

24 which could have been 224 or 244

25 which could have been 225 or 255

26 which could have been 226 or 266

27 which could have been 227 or 277

35 which could have been 335 or 355

36 which could have been 336 or 366

37 which could have been 337 or 377

46 which could have been 446 or 466

47 which could have been 447 or 477

57 which could have been 557 or 577

And with one digit,

1 which means 111

2 which means 222

3 which means 333

4 which means 444

5 which means 555

6 which means 666

7 which means 777

Note that the above possibilities are already sorted, while you should not expect your input to be sorted. Also, the above possibilities are represented as a three digit number, while your input will be a list of three numbers from 1 to 7 inclusive.

I would not expect an answer that hard-codes the values above, but if you intend to, or for some reason it is more golf-y, you are permitted to do it.

Your challenge:
Given an input, decide whether it is good or not. Return a true-y or false-y value, a true-y value such as 1 means that it is good, while a false-y value such as 0 means that it is not good. Do not use ambiguous values like   or \n (indicating a newline) or [[]] et cetera.

Scoring:
This is code-golf.

"""

def goodchord(values):
    return not ({*values} & {value + 1 for value in values})

def main():
    assert(goodchord([1, 3, 5]) == True)
    assert(goodchord([1, 4, 7]) == True)
    assert(goodchord([3, 5, 7]) == True)
    assert(goodchord([2, 4, 6]) == True)
    assert(goodchord([2, 4, 7]) == True)
    assert(goodchord([1, 1, 5]) == True)
    assert(goodchord([4, 4, 6]) == True)
    assert(goodchord([3, 3, 3]) == True)
    assert(goodchord([1, 2, 3]) == False)
    assert(goodchord([4, 6, 7]) == False)
    assert(goodchord([3, 4, 6]) == False)
    assert(goodchord([2, 5, 6]) == False)
    assert(goodchord([2, 6, 7]) == False)
    assert(goodchord([3, 3, 4]) == False)
    assert(goodchord([6, 6, 7]) == False)
    assert(goodchord([1, 1, 2]) == False)

main()
