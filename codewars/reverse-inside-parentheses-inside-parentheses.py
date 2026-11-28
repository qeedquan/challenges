#!/usr/bin/env python3

r"""

In this kata, you will be given a string of text and valid parentheses, such as "h(el)lo".

You must return the string, with only the text inside parentheses reversed, so "h(el)lo" becomes "h(le)lo". However, if said parenthesized text contains parenthesized text itself, then that too must reversed back, so it faces the original direction. When parentheses are reversed, they should switch directions, so they remain syntactically correct (i.e. "h((el)l)o" becomes "h(l(el))o").

This pattern should repeat for however many layers of parentheses. There may be multiple groups of parentheses at any level (i.e. "(1) (2 (3) (4))"), so be sure to account for these.

Input parentheses will always be valid (e.g.. you will never get "(()" or ")"). String without any parentheses are possible and should be returned as-is.

Examples
"h(el)lo" ==>
"h(le)lo"

"a ((d e) c b)" ==>
"a (b c (d e))"

"one (two (three) four)" ==>
"one (ruof (three) owt)"

"one (ruof ((rht)ee) owt)" ==>
"one (two ((thr)ee) four)"

"no parentheses"  ==>
"no parentheses"

"""

def reverse_in_parentheses(s):
    stack = [""]
    swap = str.maketrans("()", ")(")
    for c in s:
        if c == "(":
            stack.append("")
        elif c == ")":
            top = stack.pop()[::-1].translate(swap)
            stack[-1] += f"({top})"
        else:
            stack[-1] += c
    return stack[0]

def main():
    assert(reverse_in_parentheses("h(el)lo") == "h(le)lo")
    assert(reverse_in_parentheses("a ((d e) c b)") == "a (b c (d e))")
    assert(reverse_in_parentheses( "one (two (three) four)") == "one (ruof (three) owt)")
    assert(reverse_in_parentheses("one (ruof ((rht)ee) owt)") == "one (two ((thr)ee) four)")
    assert(reverse_in_parentheses("no parentheses") == "no parentheses")

main()
