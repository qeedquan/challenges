#!/usr/bin/env python3

"""

Sometimes regexps are not the best approach - generally this happens when interpretation of fragments inside text depends on current state (achieved by parsing previous part). This is typical situation with programming language compilers and interpreters, for example.

As an exercise, let's try to create regular expression which removes comments from lines in Python language. To simplify the matter we slightly reduce syntactic rules.

Normally comment in Python starts with # (called "hash" or "sharp") symbol and lasts till end of line. For example:

print('Username is ' + username) # print username
The solution would be as simple as the following (supposing "replacement" is an empty string):

#.*
This won't work well, however, since hash character could appear inside string literal. Such literals are enclosed in a pair of single or double quotes:

print('comments start with # symbol')
Also literal may need to include quote itself, it is escaped by backslash in such case:

print('I\'m a fine message')
At last, to place backslash inside literal, we escape it with other backslash. Suppose that no other symbol except single or double quote, or backslash could follow escaping backslash (it's "incorrect escape").

Problem statement
So please write a single line in the Solution area. It should have two parts separated with space - regexp itself - and replacement pattern (in which group capture results could be used). If you are ok with empty replacement pattern, omit it, of course.

Your regexp is applied to several test lines then. For each of them comment in the end should be removed, if it exists. Everything before comment (including trailing spaces) should remain unchanged.

No specific input / output example is provided for this task. Your submitted answer is not checked - only solution!

"""

import re

def uncomment(code):
    # Matches strings or a Python comment
    pattern = r'(\"(?:\\\\.|[^\"\\])*\"|\'(?:\\\\.|[^\'\\])*\')|#.*'
    
    def replacer(match):
        # If a string was matched, keep it; otherwise (it's a comment), remove it
        if match.group(1) is not None:
            return match.group(1)
        return ""
        
    return re.sub(pattern, replacer, code)

def main():
    print(uncomment("print('Username is ' + username) # print username"))
    print(uncomment("print('comments start with # symbol')"))
    print(uncomment("print('I\'m a fine message')"))

main()
