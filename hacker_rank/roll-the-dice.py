#!/usr/bin/env python3

"""

You're in a casino now, and you entered Roll The Dice Game, you have money of B you can bet with.
You guess the output of the two dice, if your guess is correct in the 2 dice, you earn 10 times your bet, and if it's correct in only one you earn 5 times your bet,
if both of them not correct you lose your bet.

Input Format:
The first line contains your bet. the second line contains 2 integers indicating your guess.
The third line contains the number of test cases T. Each of the next T lines contains two integers indicates dice output.

Output Format:
T Lines each line indicates your profit for each case

Sample input

10
1 5
3
1 5
1 6
2 3

Sample Output

100
50
0

"""

def sim(bet, guess, rolls):
    for roll in rolls:
        amount = bet
        correct = 0
        for i in range(len(guess)):
            if guess[i] == roll[i]:
                correct += 1

        if correct == 0:
            amount = 0
        elif correct == 1:
            amount *= 5
        else:
            amount *= 10

        print(amount)

def main():
    sim(10, [1, 5], [[1, 5], [1, 6], [2, 3]])

main()
