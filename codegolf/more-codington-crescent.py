#!/usr/bin/env python3

"""

Who's up for a second attempt?

If you've ever listened to the radio program "I'm sorry, I haven't a clue", then you've probably heard of the game called "Mornington Crescent". For those who haven't, it's a game where players name random stations on the London Underground network. The first person to name "Mornington Crescent" wins the game.1

Very much like last time, I present to you another game of Codington Crescent.

The Challenge
The winner of this challenge is the first person to post a working program that, given a variable-sized list of positive integers, returns the average (arithmetic mean) of said list. The list will not be empty and will always have at least one item. Input and output can be given in any reasonable and convenient format

Test Cases
[150, 541, 168, 225, 65, 191, 964, 283, 825, 5, 802, 426, 45, 326, 22, 619, 281] => 349.29411764705884
[874, 33, 423, 36, 1000, 255, 345, 902, 700, 141, 916, 959, 222, 246, 96] => 476.53333333333336
[567, 868, 680, 121, 574, 391, 233, 39, 764, 499, 455, 684, 742, 117, 376] => 474.0
[177, 372, 778, 709, 474, 796, 840, 742] => 611.0
[181, 751, 940, 782, 727, 756, 541, 762, 677, 751, 719] => 689.7272727272727
[47, 804, 782, 231, 170] => 406.8
[315, 972] => 643.5
[679, 727] => 703.0
[859, 229, 363, 468, 103, 104, 570, 772, 83, 693, 898, 672, 306, 733, 189, 717, 231] => 470.0
[228, 839] => 533.5
[395, 622, 760, 820, 70, 814, 797, 202, 277, 663, 93, 218, 564, 735] => 502.14285714285717
[724, 631, 932, 333, 605, 880, 670, 468, 703, 744, 680, 28] => 616.5
[950, 733, 305, 178, 995] => 632.2
[762, 506, 553, 284, 499, 694, 665, 998, 576, 504, 123, 658, 943, 385, 354, 732] => 577.25
[151, 919, 514, 721, 426, 333, 808, 514] => 548.25
[995] => 995.0
[891, 243, 42, 968, 458, 372, 301, 269, 559, 394, 980, 372, 804, 429, 738] => 521.3333333333334
[147, 473, 632] => 417.3333333333333
[105, 483, 225, 541, 684, 456, 328] => 403.14285714285717
[311, 1, 770, 417, 910, 185, 375, 631, 226, 266, 609] => 427.3636363636364
Test case generator

The Rules
Each player has their own program that they will add/change characters. This is termed their running program.
In this way, the only answer-chaining aspect is the rules. Everyone uses their own running program. No one shares a program at all
Each answer (a turn) has to obey source restrictions defined by previous answers. These are called rules. Each variant lasts for 5 turns. Rules are in the form of restricted-source restrictions.

Running programs can change languages between turns.

Answerers (players) can either add, change or remove (but only one of the options) as many characters of their running program per turn as they like. Alternatively, they can choose to "pass" (more scientifically, farkle), adding no new rules, and still counting as a turn. This may be the only choice if rules conflict with each other. The turn count is still incremented and is to be posted. Pro tip: You probably might want to mark it community wiki because it doesn't add much.

At the end of each turn, the player declares a new rule that will span the next 5 turns. Rules must be objective, and a TIO verification program is highly recommended. Also, rules have to be able to be applied to every language (e.g. Programs must not error using Python 3.4.2 isn't a valid rule).

Play continues until a running program achieves the target result.

If a turn hasn't been taken for a week, then an implicit farkle will occur. You can always take a turn after an implicit farkle, as it counts as a turn (think of it as the Community user's turn).

Starting Rules
As to kick off the game, the first 5 turns must follow these rules:

Turns may not accomplish the end goal
Minimum program length is 10 bytes
Permanent Rules
Last time, it was noted that the following rules suited better as a permanent rule rather than 5-turn rules:

Running programs must be irreducible. Irreducible in this case means that the program doesn't produce the output of the whole program if characters from the whole program are removed. Ie. There does not exist a program that has the default same output that can be constructed by removing characters from the original program.)

A program cannot win within 5 turns of its first appearance

Example Rules
These are purely examples of what you could add as rules to the challenge. They do not apply unless someone decides to use them.

The first and last character of the running program must be a space
Running programs must have an even amount of bytes
Running programs must not be more than 30 bytes
Extra Answer Chaining Rules
You cannot answer twice in a row. Someone else needs to answer before you have another go.
Languages need to be on Try It Online to be valid answers.
Pro-tip: sort by oldest for a more cohesive flow of answers

1 The original game of Mornington Crescent doesn't really have rules... It's more of an activity that looks like it's a complicated game.

Answer Template
# [Language], turn number [your turn]

    <code>

[Try it online link]
[prev answer link]

## Rules

- Rule (n turns left)
- Rule (n turns left)
- Rule (n turns left)

"""

def mean(a):
    if len(a) == 0:
        return 0
    return sum(a) / len(a)

def test(a, r):
    assert(abs(mean(a) - r) < 1e-8)

def main():
    test([150, 541, 168, 225, 65, 191, 964, 283, 825, 5, 802, 426, 45, 326, 22, 619, 281], 349.29411764705884)
    test([874, 33, 423, 36, 1000, 255, 345, 902, 700, 141, 916, 959, 222, 246, 96], 476.53333333333336)
    test([567, 868, 680, 121, 574, 391, 233, 39, 764, 499, 455, 684, 742, 117, 376], 474.0)
    test([177, 372, 778, 709, 474, 796, 840, 742], 611.0)
    test([181, 751, 940, 782, 727, 756, 541, 762, 677, 751, 719], 689.7272727272727)
    test([47, 804, 782, 231, 170], 406.8)
    test([315, 972], 643.5)
    test([679, 727], 703.0)
    test([859, 229, 363, 468, 103, 104, 570, 772, 83, 693, 898, 672, 306, 733, 189, 717, 231], 470.0)
    test([228, 839], 533.5)
    test([395, 622, 760, 820, 70, 814, 797, 202, 277, 663, 93, 218, 564, 735], 502.14285714285717)
    test([724, 631, 932, 333, 605, 880, 670, 468, 703, 744, 680, 28], 616.5)
    test([950, 733, 305, 178, 995], 632.2)
    test([762, 506, 553, 284, 499, 694, 665, 998, 576, 504, 123, 658, 943, 385, 354, 732], 577.25)
    test([151, 919, 514, 721, 426, 333, 808, 514], 548.25)
    test([995], 995.0)
    test([891, 243, 42, 968, 458, 372, 301, 269, 559, 394, 980, 372, 804, 429, 738], 521.3333333333334)
    test([147, 473, 632], 417.3333333333333)
    test([105, 483, 225, 541, 684, 456, 328], 403.14285714285717)
    test([311, 1, 770, 417, 910, 185, 375, 631, 226, 266, 609], 427.3636363636364)

main()
