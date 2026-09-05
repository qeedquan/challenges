#!/usr/bin/env python3

"""

Challenge:
Given the input array l with a list of strings, only keep the elements in the sequence that have a letter that's repeated 3 times. Like 'lessons' has 3 s letters, so it should be kept in the sequence. But, 'lesson' has only two s letters, so it should be removed.

Notes:
l will always be a sequence, and its elements will always be strings with only alphabetical characters.

I am using the example output with Python Lists. You can use any type of sequence in your own language.

Test cases:
['element', 'photoshop', 'good'] -> ['element', 'photoshop']
['happy', 'colorful', 'luggage'] -> ['luggage']
['reference', 'tomorrow', 'today'] -> ['reference', 'tomorrow']
This is code-golf, so the shortest code in bytes wins!

"""

def has3(s):
    m = {}
    for c in s:
        if c not in m:
            m[c] = 0
        m[c] += 1
        if m[c] >= 3:
            return True
    return False

def keep3(a):
    return list(filter(has3, a))

def main():
    assert(keep3(['element', 'photoshop', 'good']) == ['element', 'photoshop'])
    assert(keep3(['happy', 'colorful', 'luggage']) == ['luggage'])
    assert(keep3(['reference', 'tomorrow', 'today']) == ['reference', 'tomorrow'])

main()
