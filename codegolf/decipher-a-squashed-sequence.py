#!/usr/bin/env python3

"""

Given a string containing a sequence of ascending consecutive positive integers, but with no separators (such as 7891011), output a list of the separated integers. For that example, the output should be [7, 8, 9, 10, 11].

To disambiguate the possible outputs, we add the restriction that the output must always have at least two elements. This means that the output for 7891011 is definitely [7, 8, 9, 10, 11], and not the singleton list [7891011].

Test cases
1234          -> [1, 2, 3, 4]
7891011       -> [7, 8, 9, 10, 11]
6667          -> [66, 67]
293031323334  -> [29, 30, 31, 32, 33, 34]
9991000       -> [999, 1000]
910911        -> [910, 911]
Rules
Input must be taken as a single unseparated string, integer, or list of digits, in decimal only.

Output must be a proper list/array type, or a string with non-digit separators.

You may assume the input is always valid. This means you do not have to handle inputs like:

the empty string
5 (the output would need to have length  <2
 )
43 (cannot make an ascending sequence)
79 (cannot make a consecutive sequence)
66 (ditto)
01 (zero is not a positive integer)
This is code-golf, so the shortest code in bytes wins.

"""

def longest_consecutive_prefixes(text, values):
    if text == "":
        return values

    next_values = []
    for i in range(len(text)):
        if not values or int(text[:i+1]) == values[-1] + 1:
            next_values.append(longest_consecutive_prefixes(text[i+1:], values + [int(text[:i + 1])]))
    
    if len(next_values) == 0:
        return next_values
    return max(next_values, key=len)

def decipher(text):
    return longest_consecutive_prefixes(text, []) 

def main():
    assert(decipher("1234") == [1, 2, 3, 4])
    assert(decipher("7891011") == [7, 8, 9, 10, 11])
    assert(decipher("6667") == [66, 67])
    assert(decipher("293031323334") == [29, 30, 31, 32, 33, 34])
    assert(decipher("9991000") == [999, 1000])
    assert(decipher("910911") == [910, 911])

main()
