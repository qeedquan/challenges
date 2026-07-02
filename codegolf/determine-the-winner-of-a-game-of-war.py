#!/usr/bin/env python3

"""

The card game War is interesting in that the final outcome is entirely determined by the initial arrangement of the deck, so long as certain rules are followed for the order in which cards are picked up from the playing field and moved to decks. In this challenge, there will only be 2 players, simplifying things greatly.
The Game

    Each player is dealt a deck of 26 cards.
    Each player places the top card in their deck face-up. The player with the higher-ranking card (Ace > King > Queen > Jack > 10 > 9 > 8 > 7 > 6 > 5 > 4 > 3 > 2) wins the round, and places their card on top of their opponent's card, flips them over, and adds them to the bottom of their deck (so their winning card is on the bottom of the deck, and the other player's losing card is just above it). This is done until one of the players runs out of cards.
        If the cards are of equal rank, then each player places the top 2 cards of their deck face-up on top of their previous card (so that the card that was on top of the deck is the second card in the stack, and the card that was second-from-top is on top). Then, the ranks (of the top card of each stack) are compared again, and the winner places their entire stack on top of the loser's entire stack, turns the stack upside-down, and places it on the bottom of their deck. If there is another tie, more cards are played in the same way, until a winner is chosen or one player runs out of cards.

If at any point one of the players needs to draw a card from their deck, but their deck is empty, they immediately lose the game.
The Challenge

Given two lists of cards in the players' decks, in any convenient format, output a truthy value if Player 1 wins, and a falsey value if Player 2 wins.

For convenience, a 10 card will be represented with a T, and face cards will be abbreviated (Ace -> A, King -> K, Queen -> Q, Jack -> J), so that all cards are one character long. Alternatively, ranks may be represented with decimal integers 2-14 (Jack -> 11, Queen -> 12, King -> 13, Ace -> 14) or hex digits 2-E (10 -> A, Jack -> B, Queen -> C, King -> D, Ace -> E). Since suits don't matter, suit information will not be given.

    You may assume that all games will terminate at some point (though it may take a very long time), and one player will always run out of cards before the other.
    Each player places cards simultaneously, and one card at a time, so there is never any ambiguity about which player ran out of cards first.

Test Cases

The test cases use 23456789ABCDE to represent the ranks (in ascending order).

D58B35926B92C7C4C7E8D3DAA2, 8E47C38A2DEA43467EB9566B95 -> False
669D9D846D4B3BA52452C2EDEB, E747CA988CC76723935A3B8EA5 -> False
5744B95ECDC6D325B28A782A72, 68394D9DA96EBBA8533EE7C6C4 -> True
87DB6C7EBC6C8D722389923DC6, E28435DBEBEA543AA47956594A -> False
589EAB9DCD43E9EC264A5726A8, 48DC2577BD68AB9335263B7EC4 -> True
E3698D7C46A739AE5BE2C49286, BB54B7D78954ED526A83C3CDA2 -> True
32298B5E785DC394467D5C9CB2, 5ED6AAD93E873EA628B6A4BC47 -> True
B4AB985B34756C624C92DE5E97, 3EDD5BA2A68397C26CE837AD48 -> False
9A6D9A5457BB6ACBC5E8D7D4A9, 73E658CE2C3E289B837422D463 -> True
96E64D226BC8B7D6C5974BAE32, 58DC7A8C543E35978AEBA34D29 -> True
C2978A35E74D7652BA9762C458, 9A9BB332BE8C8DD44CE3DE66A5 -> False
BEDB44E947693CD284923CEA82, 8CC3B75756255A683A6AB9E7DD -> False
EEDDCCBBAA8877665544332299, EEDDCCBBAA9988776655443322 -> False
EEDDCCBBAA9988776655443322, DDCCBBAA9988776655443E3E22 -> True

Reference Implementation

This reference implementation is written in Python 3, and takes input in the same format as the test cases (except separated by a newline instead of a comma and a space).

#!/usr/bin/env python3

from collections import deque

p1, p2 = [deque(s) for s in (input(),input())]
print(''.join(p1))
print(''.join(p2))

try:
    while p1 and p2:
        p1s = [p1.popleft()]
        p2s = [p2.popleft()]
        while p1s[-1] == p2s[-1]:
            p1s.append(p1.popleft())
            p2s.append(p2.popleft())
            p1s.append(p1.popleft())
            p2s.append(p2.popleft())
        if p1s[-1] > p2s[-1]:
            p1.extend(p2s+p1s)
        else:
            p2.extend(p1s+p2s)
except IndexError:
    pass
finally:
    print(len(p1) > 0)

"""

from collections import deque

def won(s1, s2):
    p1 = deque(s1)
    p2 = deque(s2)
    try:
        while p1 and p2:
            p1s = [p1.popleft()]
            p2s = [p2.popleft()]
            
            while p1s[-1] == p2s[-1]:
                p1s.append(p1.popleft())
                p2s.append(p2.popleft())
                p1s.append(p1.popleft())
                p2s.append(p2.popleft())

            if p1s[-1] > p2s[-1]:
                p1.extend(p2s + p1s)
            else:
                p2.extend(p1s + p2s)
    except IndexError:
        pass
    finally:
        return len(p1) > 0

def main():
    assert(won("D58B35926B92C7C4C7E8D3DAA2", "8E47C38A2DEA43467EB9566B95") == False)
    assert(won("669D9D846D4B3BA52452C2EDEB", "E747CA988CC76723935A3B8EA5") == False)
    assert(won("5744B95ECDC6D325B28A782A72", "68394D9DA96EBBA8533EE7C6C4") == True)
    assert(won("87DB6C7EBC6C8D722389923DC6", "E28435DBEBEA543AA47956594A") == False)
    assert(won("589EAB9DCD43E9EC264A5726A8", "48DC2577BD68AB9335263B7EC4") == True)
    assert(won("E3698D7C46A739AE5BE2C49286", "BB54B7D78954ED526A83C3CDA2") == True)
    assert(won("32298B5E785DC394467D5C9CB2", "5ED6AAD93E873EA628B6A4BC47") == True)
    assert(won("B4AB985B34756C624C92DE5E97", "3EDD5BA2A68397C26CE837AD48") == False)
    assert(won("9A6D9A5457BB6ACBC5E8D7D4A9", "73E658CE2C3E289B837422D463") == True)
    assert(won("96E64D226BC8B7D6C5974BAE32", "58DC7A8C543E35978AEBA34D29") == True)
    assert(won("C2978A35E74D7652BA9762C458", "9A9BB332BE8C8DD44CE3DE66A5") == False)
    assert(won("BEDB44E947693CD284923CEA82", "8CC3B75756255A683A6AB9E7DD") == False)
    assert(won("EEDDCCBBAA8877665544332299", "EEDDCCBBAA9988776655443322") == False)
    assert(won("EEDDCCBBAA9988776655443322", "DDCCBBAA9988776655443E3E22") == True)

main()
