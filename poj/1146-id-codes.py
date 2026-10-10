"""

Description

It is 2084 and the year of Big Brother has finally arrived, albeit a century late. In order to exercise greater control over its citizens and thereby to counter a chronic breakdown in law and order, the Government decides on a radical measure--all citizens are to have a tiny microcomputer surgically implanted in their left wrists. This computer will contains all sorts of personal information as well as a transmitter which will allow people's movements to be logged and monitored by a central computer. (A desirable side effect of this process is that it will shorten the dole queue for plastic surgeons.)

An essential component of each computer will be a unique identification code, consisting of up to 50 characters drawn from the 26 lower case letters. The set of characters for any given code is chosen somewhat haphazardly. The complicated way in which the code is imprinted into the chip makes it much easier for the manufacturer to produce codes which are rearrangements of other codes than to produce new codes with a different selection of letters. Thus, once a set of letters has been chosen all possible codes derivable from it are used before changing the set.

For example, suppose it is decided that a code will contain exactly 3 occurrences of `a', 2 of `b' and 1 of `c', then three of the allowable 60 codes under these conditions are:
      abaabc

      abaacb

      ababac


These three codes are listed from top to bottom in alphabetic order. Among all codes generated with this set of characters, these codes appear consecutively in this order.

Write a program to assist in the issuing of these identification codes. Your program will accept a sequence of no more than 50 lower case letters (which may contain repeated characters) and print the successor code if one exists or the message `No Successor' if the given code is the last in the sequence for that set of characters.

Input

Input will consist of a series of lines each containing a string representing a code. The entire file will be terminated by a line consisting of a single #.

Output

Output will consist of one line for each code read containing the successor code or the words 'No Successor'.

Sample Input

abaacb
cbbaa
#

Sample Output

ababac
No Successor

Source

New Zealand 1991 Division I,UVA 146

"""

# https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
# https://stackoverflow.com/questions/4223349/python-implementation-for-next-permutation-in-stl
def next_permutation(a):
    for i in reversed(range(len(a) - 1)):
        if a[i] < a[i + 1]:
            break
    else:
        return False

    j = next(j for j in reversed(range(i + 1, len(a))) if a[i] < a[j])
    a[i], a[j] = a[j], a[i]
    a[i + 1:] = reversed(a[i + 1:])
    return True

def successor(s):
    a = list(s)
    if not next_permutation(a):
        return "No Successor"
    return ''.join(a)

def main():
    assert(successor("abaacb") == "ababac")
    assert(successor("cbbaa") == "No Successor")

main()
