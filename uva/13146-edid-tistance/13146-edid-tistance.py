#!/usr/bin/env python3

from nltk import edit_distance

def main():
    assert(edit_distance("impossible", "possible") == 2)
    assert(edit_distance("", "possible") == 8)
    assert(edit_distance("sorry", "scared") == 4)
    assert(edit_distance("excused", "") == 7)
    assert(edit_distance("counted", "proud") == 5)
    assert(edit_distance("two people", "to") == 8)

main()
