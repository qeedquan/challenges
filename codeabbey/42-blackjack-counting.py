#!/usr/bin/env python3

"""

The game of Blackjack has very simple rules: players should take cards one by one trying to collect more points than opponents, but not exceeding 21 (refer Wikipedia for complete rules).

The deck contains all cards from 2 to 10 inclusive, which are counted according to their value, also Kings, Queens and Jacks which cost 10 points each and also Aces, which could be counted as 1 or 11 points, whatever is better.

Let us learn the programming of scoring algorithm for such game.

Input data will contain the number of test-cases in the first line.
Then test-cases will follow on separate lines. Each test-case consists of several cards expressed with symbols:
2, 3, 4, 5, 6, 7, 8, 9,
T, J, Q, K - for 10, Jack, Queen, King,
A - for Ace.
Answer should contain the number of points in each test-case, not exceeding 21 - or the word Bust if the total is greater than 21 (i.e. player immediately loss).

Example:

input data:
4
A T
2 K 4
3 A Q 8
A 3 3 3 A

answer:
21 16 Bust 21

"""

def blackjack(cards):
    lookup = {
        "2": 2,
        "3": 3,
        "4": 4,
        "5": 5,
        "6": 6,
        "7": 7,
        "8": 8,
        "9": 9,
        "T": 10,
        "J": 10,
        "Q": 10,
        "K": 10,
        "A": 11,
    }
    
    aces = 0
    score = 0
    for card in cards.split(' '):
        if card in lookup:
            score += lookup[card]
        if card == 'A':
            aces += 1

    while score > 21 and aces > 0:
        score -= 10
        aces -= 1

    if score > 21:
        return "Bust"
    return score

def main():
    assert(blackjack("A T") == 21)
    assert(blackjack("2 K 4") == 16)
    assert(blackjack("3 A Q 8") == "Bust")
    assert(blackjack("A 3 3 3 A") == 21)

main()
