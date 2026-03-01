#!/usr/bin/env python3

"""

Overview
We often use smiley faces in correspondence with other people. They allow us to quickly show our reaction to the person(s) we are talking to.

But one day you wanted to make your correspondence more joyful. So today you have the opportunity to make it happen.

Task:
In this kata, your task will be to replace sad emoticons with funny ones.

The emoticons, will be represented from:

Eyes: marked as :, ; or =
Nose (optional): marked as - or ~
Mouth: marked as ( or [

Examples:
smile("Howdy :(")  // should return "Howdy :)"
smile("Never be sad =[")  // should return "Never be sad =]"
smile("Change this `=(` and this `:[`")  // should return "Change this `=)` and this `:]`"

"""

def smile(sentence):
    for c0 in ":;=":
        for c1 in " -~":
            for c2 in "([":
                c3 = ')'
                if c2 == '[':
                    c3 = ']'

                sad = c0 + c1 + c2
                happy = c0 + c1 + c3
                if c1 == ' ':
                    sad = c0 + c2
                    happy = c0 + c3
                
                sentence = sentence.replace(sad, happy)
    return sentence

def main():
    assert(smile('Howdy :(') == 'Howdy :)')
    assert(smile('Never be sad =[') == 'Never be sad =]')
    assert(smile('Change this `=(` and this `:[`') == 'Change this `=)` and this `:]`')
    assert(smile('It\'s been raining all day ;-(') == 'It\'s been raining all day ;-)')
    assert(smile('My friend got married ;~[') == 'My friend got married ;~]')

    assert(smile('Change this `=(` and this `:[`') == 'Change this `=)` and this `:]`')
    assert(smile('Funny smileys: ;~[ :( :-( :~[ :-[') == 'Funny smileys: ;~] :) :-) :~] :-]')

    assert(smile('The list of positive numbers is [1,2,3,4...]') == 'The list of positive numbers is [1,2,3,4...]')
    assert(smile('(((-)(((-)))(-)))') == '(((-)(((-)))(-)))')

main()
