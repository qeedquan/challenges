#!/usr/bin/env python3

"""

Introduction
Esolangs.org user "Tommyaweosme", after getting 3-4 hours into a 17-hour video called "albuquerque but every time a word repeats it loops (normal speed)", created this challenge.

Challenge
Input: A string.
Output: A string.
The output must be exactly the same as the input, except that: if a character appears twice, it repeats the substring from its previous usage to itself. (the repeated substring is taken from the original string.)
To be clear, here's step-by-step how "success" becomes the "succcesuccesss":

s <- ok
su <- ok
suc <- ok
succc <- loop since it appears twice (cc)
succce <- ok
succcesucces <- loop since it appears twice (succes)
succcesuccesss <- loop since it appears more than twice, just looping back to the previous one (ss)

Example Input and Output
Input #1:

albuquerque
Output #1:

albuququerquerquerquerque
Input #2:

challenge
Output #2:

challlengenge
Input #3:

supercalifragilisticexpialidocious
Output #3:

supercalifrcalifralifragifragilifragililisupercalifragilististicalifragilisticercalifragilisticexpercalifragilisticexpicexpiagilisticexpialisticexpialialidocexpialidocidociocioupercalifragilisticexpialidociousticexpialidocious
The input could be one of the equivalents:

A list of ASCII values (possible integers);
A list of characters;
A string.
The input is guaranteed to contain only ASCII letters.

Official implementation where you can test your custom input in it.

def albuquerque(p):
    res = ""
    for i in range(len(p)):
        if p[i] in p[:i]:
            q = p[i-1::-1]      # first reverse and then pick the last i-1 characters
            q = q.find(p[i])    # find the first occurence for the letter
            res += p[i-q-1:i+1] # negate q, so that the index of reversed list can be converted back to the original index
        else: res += p[i]
    return res

"""

def albuquerque(p):
    r = ""
    for i in range(len(p)):
        if p[i] in p[:i]:
            q = p[i-1::-1]
            q = q.find(p[i])
            r += p[i-q-1:i+1]
        else:
            r += p[i]
    return r

def main():
    assert(albuquerque("albuquerque") == "albuququerquerquerquerque")
    assert(albuquerque("challenge") == "challlengenge")
    assert(albuquerque("supercalifragilisticexpialidocious") == "supercalifrcalifralifragifragilifragililisupercalifragilististicalifragilisticercalifragilisticexpercalifragilisticexpicexpiagilisticexpialisticexpialialidocexpialidocidociocioupercalifragilisticexpialidociousticexpialidocious")

main()
