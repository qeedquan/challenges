#!/usr/bin/env python3

r"""

The Symbols vs. The Letters
The ASCII characters have been divided once again! Your sets are The Letters and The Symbols.

The Letters
ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
The Symbols
!"#$%&'()*+,-./0123456789:;<=>?@[\]^_`{|}~
The task is to write two programs:

Print each of The Letters exactly once without using any of them in your program.

Print each of The Symbols exactly once without using any of them in your program.

Rules
Whitespace may appear in your program or the output.
Non-ASCII characters are not allowed.
Output goes to standard out or to a file as either the contents or name of the file.
No input.
Output must only contain ASCII characters from one set or the other.
The programs can be written in different languages or the same language with one exception:
The Whitespace language may only be used for one of the programs.
Standard loopholes apply.
Scoring
# of characters in program 1 +# of characters in program 2 = Score

Lowest score wins!

Note:
To encourage more submissions, you may still post an answer with a solution for only one of the programs. You won't be able to win, but you would still be able to show off something cool.

Thanks to Calvin's Hobbies for inspiring the idea with his previous question.

"""

import string

def main():
    print(string.ascii_letters)
    print(string.digits + string.punctuation)

main()
