#!/usr/bin/env python3

"""

Description:

Write a function, where given a string of arbitrary characters, returns true if all brackets (defined as parentheses, square-brackets, curly-braces, and chevrons) are correctly paired and ordered. This is to say that all brackets, if they enclose other brackets, enclose both the paired opening and closing characters.

Formal Inputs & Outputs:

Input Description:

string data - a given string that may or may not have correctly formed brackets.

Output Description:

Return True or False - true if the given string is correctly bracket formed.

Sample Inputs & Outputs:

"123", "(abc)", "()abc()", and "([<{abc123abc}>])" should return true, but "(abc[123)abc]" (wrong pairing) and "(abc>" (not closed) should return false.

Notes:

This is a very easy problem if you use a specific primitive data-structure.

"""

def bracket(string):
    opening = ["(", "[", "{", "<"]
    closed = [")", "]", "}", ">"]
    stack = []
    for i in range(len(string)):
        if string[i] in opening:
            stack.append(opening.index(string[i]))
        elif string[i] in closed:
            if closed.index(string[i]) != stack.pop():
                return False
    return len(stack) == 0

def main():
    assert(bracket("123") == True)
    assert(bracket("(abc)") == True)
    assert(bracket("()abc()") == True)
    assert(bracket("([<{abc123abc}>])") == True)

    assert(bracket("(abc[123)abc]") == False)
    assert(bracket("(abc>") == False)
    assert(bracket("(") == False)

main()
