#!/usr/bin/env python3

"""

A normal deck of 52 playing cards contains suits 'H', 'C', 'D', 'S' - Hearts, Clubs, Diamonds, Spades respectively - and cards with values from Ace (1) to King (13): 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13

Your Task
Complete the function that returns a shuffled deck of 52 playing cards without repeats.

Each card should have format "{suit} {value}", e.g. the Queen of Hearts is "H 12" and the Ace of Spades is "S 1".
The order of the cards must be different each time the function is called.

"""

from random import sample

def shuffled_deck():
    deck = [f'{suit} {value}' for suit in 'HCDS' for value in range(1, 14)]
    return sample(deck, 52)

def main():
    print(shuffled_deck())

main()
