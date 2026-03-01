#!/usr/bin/env python3

"""

Pirates have notorious difficulty with enunciating. They tend to blur all the letters together and
scream at people.

At long last, we need a way to unscramble what these pirates are saying.

Write a function that will accept a jumble of letters as well as a dictionary, and output a list of
words that the pirate might have meant.

For example:

grabscrab( "ortsp", ["sport", "parrot", "ports", "matey"] )

Should return ["sport", "ports"].

Return matches in the same order as in the dictionary. Return an empty array if there are no
matches.

"""

def grabscrab(string, words):
    result = []
    string = sorted(string)
    for word in words:
        if string == sorted(word):
            result.append(word)
    return result

def main():
    assert(grabscrab("trisf", ["first"]) == ["first"])
    assert(grabscrab("oob", ["bob", "baobab"]) == [])
    assert(grabscrab("ainstuomn", ["mountains", "hills", "mesa"]) == ["mountains"])
    assert(grabscrab("oolp", ["donkey", "pool", "horse", "loop"]) == ["pool", "loop"])
    assert(grabscrab("ortsp", ["sport", "parrot", "ports", "matey"]) == ["sport", "ports"])
    assert(grabscrab("ourf", ["one", "two", "three"]) == [])

main()
