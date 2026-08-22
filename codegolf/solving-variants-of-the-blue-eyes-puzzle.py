#!/usr/bin/env python3

"""

The original "Blue Eyes" puzzle is given here (and below).

A group of people with assorted eye colors live on an island. They are all perfect logicians -- if a conclusion can be logically deduced, they will do it instantly. No one knows the color of their eyes. Every night at midnight, a ferry stops at the island. Any islanders who have figured out the color of their own eyes then leave the island, and the rest stay. Everyone can see everyone else at all times and keeps a count of the number of people they see with each eye color (excluding themselves), but they cannot otherwise communicate. Everyone on the island knows all the rules in this paragraph.

On this island there are 100 blue-eyed people, 100 brown-eyed people, and the Guru (she happens to have green eyes). So any given blue-eyed person can see 100 people with brown eyes and 99 people with blue eyes (and one with green), but that does not tell him his own eye color; as far as he knows the totals could be 101 brown and 99 blue. Or 100 brown, 99 blue, and he could have red eyes.

The Guru is allowed to speak once (let's say at noon), on one day in all their endless years on the island. Standing before the islanders, she says the following:

"I can see someone who has blue eyes."

Who leaves the island, and on what night?

The answer is that they all leave on the hundredth day. This is due to the following logic:

If there is one blue-eyed person only, he will leave on day 1. If there are two-blue-eyed people only, nobody leaves on day 1. Following this, they both leave on day 2. Now if there are 3 blue-eyed people, nobody leaves on day 1. Nobody leaves on day 2 either. Now everyone knows that there are 3 blue-eyed people, because if there were only one, he would have left on day 1 and if there are two, they both would have left on day 2. Hence all 3 leave on day 3.

We can now write an inductive proof that if n blue-eyed people require n days to figure out their eye colours and leave, then n+1 blue-eyed people require n+1 days to do the same.

However, the code you write should be capable of solving not just the original puzzle, but also some variants that require slightly different inductive steps.

You will be told how many of the islanders have blue eyes and how many don't. You will also be given a statement by the oracle (a system of equations/inequations) that everyone on the island hears. You need to determine when the island will be free of the blue-eyed people.

The oracle's statements will use b for the number of blue-eyed people and r for the number of non-blue-eyed people. The equations can include < > <= >= = + - and any whole numbers.

Test cases
Based on this set of variants

50 50
b>=1
b<b+r
Output: 50

The second equation gives no new information, hence this problem becomes exactly the same as the original puzzle.

100 50
b+3>=r+4
Output: 25

100 0
b-2>8+1-1
Output: 90

50 50
b>=10
b<=75
Output: 41

"""

"""

Ported from @Anders Kaseorg solution

How it works
By induction:

If the island composition is (b, r) and it is known that (b − 1, r + 1) is not possible, then on day 1, the blue-eyed islanders, seeing (b − 1, r), will conclude that they are blue-eyed and leave.
If the island composition is (b, r) and it is known that the blue-eyed islanders would have left on day n if the composition were (b − 1, r + 1), then on day n + 1, the blue-eyed islanders, seeing (b − 1, r), will conclude that they are blue-eyed and leave.
This second inference fails if b = 1, but in that case, the blue-eyed islander would never leave if they hadn’t already, and the test case would be invalid.

Note that non-blue-eyed islanders will never leave, in this version of the puzzle, because even if they use similar logic to conclude that they are not blue-eyed, they still don’t know which non-blue color their eyes are.

"""
def solve(b, r, eq):
    if not all(map(eval, eq)):
        return 0
    return solve(b - 1, r + 1, eq) + 1

def main():
    assert(solve(50, 50, ['b>=1', 'b<b+r']) == 50)
    assert(solve(100, 50, ['b+3>=r+4']) == 25)
    assert(solve(100, 0, ['b-2>8+1-1']) == 90)
    assert(solve(50, 50, ['b>=10', 'b<=75']) == 41)

main()
