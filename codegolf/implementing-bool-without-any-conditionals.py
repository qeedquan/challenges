#!/usr/bin/env python3

"""

Title says it all. Given some input, turn it into a boolean value (0 or 1), without using conditional statements (e.x. == > < <= >= != ~=), or any function which uses conditional statements within its implementation, such as if, while and for. Your program must work with floating points, although you get more if it works with other items.

A general rule for determining whether bool(item) is False is if the item is empty ('' is an empty string, [] is an empty list.), or if the function used to turn an item of one type into another is given no input (in Python, str() returns '', list() returns [].)

Here are (some of) the different valid types. Your program is considered to work with one type if it works with one item in the following lists:

Integers, floating points, doubles, longs
Strings
Lists, tuples, arrays (bytearrays)
Dictionaries
Functions
Objects/Classes
Program score will be calculated like this: [# of characters]-(50*[# of types]). The program with the smallest score wins the challenge.

"""

"""

@Geoff Reedy

Works for the following built-in types (as listed in §3.2 The standard type hierarchy)

NotImplemented
Ellipsis
int
long
bool
string
unicode
tuple
list
bytearray
set
frozenset
dict

"""

def bool(x=False):
    try:
        return [False][x]
    except IndexError:
        return True
    except:
        try:
            return bool(len(x))
        except:
            return True

def main():
    assert(bool(1) == True)
    assert(bool(0) == False)
    assert(bool([1, 2, 3]) == True)
    assert(bool("STR") == True)
    assert(bool("") == False)
    assert(bool([]) == False)

main()
