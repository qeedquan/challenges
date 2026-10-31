#!/usr/bin/env python3

"""

Ali-Baba found a secret cave with treasures, stored by The Forty Thieves. However, famous magical phrase Open Sesame obviously does not work.

Instead there is a long and strange text inscribed on the stone wall - and Ali-Baba guessed that one should find matching words in this inscription (i.e. ones which are encountered more than once) and pronounce them in alphabetical order.

We are to help the poor craftsman to access the thieves' treasury. Let's write a program that sieves necessary words from the given text, and prints them in the proper order.

Input data consist of about 300 words, each made of 3 Latin letters. The end is signaled by the word end.
Answer should contain all the words which are encountered more than once in lexicographic order.

Example:

input data:
nun lam mip tex bal pif sot bal bod tex end

answer:
bal tex

Note: although for small amount of words one can write double nested loop to compare words,
this approach is inefficient for large numbers of words - it is not suitable for one million words etc. Try to invent a better approach.

"""

def solve(words):
    count = {}
    for word in words.split(' '):
        if word == "end":
            break
        if word not in count:
            count[word] = 0
        count[word] += 1

    result = []
    for word in count:
        if count[word] > 1:
            result.append(word)
    return sorted(result)

def main():
    assert(solve("nun lam mip tex bal pif sot bal bod tex end") == ["bal", "tex"])

main()
