#!/usr/bin/env python3

"""

When we throw 2 classical dice (values on each side from 1 to 6) we have 36 (6 * 6) different results.

We want to know the probability of having the sum of the results equals to 11. For that result we have only the combination of 6 and 5. So we will have two events: {5, 6} and {6, 5}

So the probability for that result will be:

P(11, 2) = 2/(6*6) = 1/18    (The two is because we have 2 dice)
Now, we want to calculate the probability of having the sum equals to 8. The combinations for that result will be the following: {4,4}, {3,5}, {5,3}, {2,6}, {6,2} with a total of five combinations.

P(8, 2) = 5/36
Things may be more complicated if we have more dices and sum values higher.

We want to know the probability of having the sum equals to 8 but having 3 dice.

Now the combinations and corresponding events are:

{2,3,3}, {3,2,3}, {3,3,2}
{2,2,4}, {2,4,2}, {4,2,2}
{1,3,4}, {1,4,3}, {3,1,4}, {4,1,3}, {3,4,1}, {4,3,1}
{1,2,5}, {1,5,2}, {2,1,5}, {5,1,2}, {2,5,1}, {5,2,1}
{1,1,6}, {1,6,1}, {6,1,1}

A total amount of 21 different combinations

So the probability is:
P(8, 3) = 21/(6*6*6) = 0.09722222222222222
Summarizing the cases we have seen with a function that receives the two arguments

rolldice_sum_prob(11, 2) == 0.0555555555 # or 1/18

rolldice_sum_prob(8, 2) ==  0.13888888889# or 5/36

rolldice_sum_prob(8, 3) == 0.0972222222222  # or 7/72
And think why we have this result:

rolldice_sum_prob(22, 3) == 0
Create the function rolldice_sum_prob() for this calculation.

Have a nice time!

(You do not have to round the results)

"""

def combinations(value, dices):
    result = 0
    for die in range(1, 7):
        if dices > 1:
            result += combinations(value - die, dices - 1)
        elif die == value:
            return 1
    return result

def probability(value, sides):
    return combinations(value, sides) / 6**sides

def main():
    print(probability(11, 2))
    print(probability(8, 2))
    print(probability(8, 3))
    print(probability(22, 3))

main()
