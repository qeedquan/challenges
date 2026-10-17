#!/usr/bin/env python3

"""

Flavortext
The Bystander Effect is a phenomenon where individuals are less likely to help a victim if other people are present. The idea is that as there are more people around, the individual burden is less, and each individual thinks "someone else will help them", which results in the counterintuitive fact that fewer people will help when there are more people.

(This is why if you're in public and something bad happens and you / someone else needs help, you should address random individuals ("you in the red shirt") to help specifically rather than "someone please help" to bypass this psychological phenomenon)

Let's take a very simplified interpretation of this theory and assume everyone has a numerical threshold for helping.

Specification
A list of people will be given, each with a threshold to help. The threat level is 1. A person will help if and only if the threat level divided by the number of people in the crowd is greater than equal to their threshold. When a person decides to help, they leave the crowd. This means that the individual threat, which is the threat level (1) divided by the size of the crowd, is now higher as a result because the crowd is smaller.

The total threat level (1) never changes, for simplicity.

How many people end up helping?

Input
You are given a list of floating point numbers in any reasonable format. This list will be non-empty, and every number will be in the inclusive range from 0 to 1. You may assume the list is sorted in either order you would like.

Output
You are to output a single integer, indicating how many of the individuals decide to help.

Example
Consider the test case 0.2, 0.2, 0.3, 0.6, 0.8. The crowd has five people, so the threat to each individual is 0.2.
Therefore, the first two people will help. Now, the crowd is 0.3, 0.6, 0.8. Since there are only three people, the threat to each individual is now 0.3.
Therefore, the third person will now decide to help. The crowd is now 0.6, 0.8, so the individual threat is 0.5, and nobody decides to help anymore. Therefore, the final result is 3.

Test Cases
1                        -> 1
0.5, 0.8                 -> 2 # 0.8 initially won't help, but will when 0.5 leaves
0.2, 0.2                 -> 2 # both will help initially
0.2, 0.2, 0.3, 0.6, 0.8  -> 3 # 0.2 and 0.2 leaving prompts 0.3 to help, but the other two won't help
0, 0.25, 0.33, 0.5, 1    -> 5 # all of them help only after the previous person left, starting with 0
0, 0.25, 0.34, 0.34, 1   -> 2 # 0 and 0.25 help, but 0.34 is just a bit too indifferent to help, which means 1 will never help either
0.5, 0.5, 0.5            -> 0 # nobody helps. RIP

Reference Implementation
This implementation (Python) shows the final answer at the very end. It also breaks down the process stage-by-stage.

"""

def bystanders(people):
    helpers = 0
    threat = 1
    while len(people) > 0:
        indices = []
        for index, person in enumerate(people):
            if threat / len(people) >= person:
                indices.append(index)
                helpers += 1
        if indices == []:
            break
        people = [person for index, person in enumerate(people) if index not in indices]
    return helpers

def main():
    assert(bystanders([1]) == 1)
    assert(bystanders([0.5, 0.8]) == 2)
    assert(bystanders([0.2, 0.2]) == 2)
    assert(bystanders([0.2, 0.2, 0.3, 0.6, 0.8]) == 3)
    assert(bystanders([0, 0.25, 0.33, 0.5, 1]) == 5)
    assert(bystanders([0, 0.25, 0.34, 0.34, 1]) == 2)
    assert(bystanders([0.5, 0.5, 0.5]) == 0)

main()
