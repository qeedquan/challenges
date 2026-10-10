#!/usr/bin/env python3

"""

Given a permutation of the alphabet and an intended "word", determine if the word was guessed in a game of Hangman, where the permutation is the list of guesses.

For example, given ASTNORDYUVKFMCLWIHEBQGPJXZ as the permutation, and ASTRONAUT as the word, we know that the word was guessed. Only 2 letters (DY) were wrong before guessing U to complete the word. At the end of the game, the gallows look like

  |
  |
  |
  |
  |
  |
------
so the man wasn't hanged and the guesser wins.

However, if the word was PAYMENT, then there are 12 wrong guesses (SORDUVKFCLWI) before the word is complete (the "filled in" word looks like _AYM_NT at the end), so the guesser loses.

The full gallows takes 12 steps to finish:

                                      ------   ------   ------   ------   ------   ------   ------   ------
           |        |        |/       |/       |/   |   |/   |   |/   |   |/   |   |/   |   |/   |   |/   |
           |        |        |        |        |        |    O   |    O   |    O   |    O   |    O   |    O
           |        |        |        |        |        |        |    |   |   /|   |   /|\  |   /|\  |   /|\
           |        |        |        |        |        |        |        |        |        |   /    |   / \
           |        |        |        |        |        |        |        |        |        |        |
           |        |\       |\       |\       |\       |\       |\       |\       |\       |\       |\
------   ------   ------   ------   ------   ------   ------   ------   ------   ------   ------   ------
So 12 wrong guesses before the final correct letter is a loss and the final correct letter before 12 wrong guesses is a win.

You are to take 2 strings as input:

A 26 character long string, containing 26 unique letters in a consistent case i.e. a permutation of either the uppercase or lowercase alphabet
A string containing a maximum of 26 unique characters and a minimum of 1 character, in the same case as the permutation
You should then output 2 distinct values to indicate whether the word was guessed before 12 wrong guesses or not.

You may input and output in any convenient method. The length of the second input will never exceed your language's integer maximum.

This is code-golf so the shortest code in bytes wins.

Test cases
permutation, word -> output
ABCDEFGHIJKLMNOPQRSTUVWXYZ, CGCC -> 1
ABCDEFGHIJKLMNOPQRSTUVWXYZ, LAB -> 1
ABCDEFGHIJKLMNOPQRSTUVWXYZ, MOP -> 0
ABCDEFGHIJKLMNOPQRSTUVWXYZ, MNOPQRSTUVWXYZ -> 0
ABCDEFGHIJKLMNOPQRSTUVWXYZ, LMNOPQRSTUVWXYZ -> 1
NYLZCBTOAFEQMVJWRHKIUGDPSX, NYLON -> 1
NYLZCBTOAFEQMVJWRHKIUGDPSX, GOLF -> 0
DXAPMHBYRVNKOFQZCSWUEJLTGI, ABCDEFGHIJKLMNOPQRSTUVWXYZ -> 1
INRLVTXOZSAKWJYFBQDMGPHUCE, IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII -> 1
INRLVTXOZSAKWJYFBQDMGPHUCE, EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE -> 0
FICUJKXZYVDGEWRLMANBHOPSTQ, RDRYMUTSDOVSEHWT -> 0
ASTNORDYUVKFMCLWIHEBQGPJXZ, ASTRONAUT -> 1
ASTNORDYUVKFMCLWIHEBQGPJXZ, PAYMENT -> 0
Here is a Jelly program which automatically generates test cases in the form

permutation
word
output
Spoilers for anyone who understands Jelly

"""

def dead(p, w):
    if len(w) == 0:
        return True

    h = set(w)
    m = 0
    for c in p:
        if c not in h:
            m += 1
            if m >= 12:
                break
        else:
            h.remove(c)
            if len(h) == 0:
                return True
    
    return False

def main():
    assert(dead("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "CGCC") == True)
    assert(dead("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "LAB") == True)
    assert(dead("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "MOP") == False)
    assert(dead("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "MNOPQRSTUVWXYZ") == False)
    assert(dead("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "LMNOPQRSTUVWXYZ") == True)
    assert(dead("NYLZCBTOAFEQMVJWRHKIUGDPSX", "NYLON") == True)
    assert(dead("NYLZCBTOAFEQMVJWRHKIUGDPSX", "GOLF") == False)
    assert(dead("DXAPMHBYRVNKOFQZCSWUEJLTGI", "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == True)
    assert(dead("INRLVTXOZSAKWJYFBQDMGPHUCE", "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII") == True)
    assert(dead("INRLVTXOZSAKWJYFBQDMGPHUCE", "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE") == False)
    assert(dead("FICUJKXZYVDGEWRLMANBHOPSTQ", "RDRYMUTSDOVSEHWT") == False)
    assert(dead("ASTNORDYUVKFMCLWIHEBQGPJXZ", "ASTRONAUT") == True)
    assert(dead("ASTNORDYUVKFMCLWIHEBQGPJXZ", "PAYMENT") == False)

main()
