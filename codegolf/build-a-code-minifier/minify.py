#!/usr/bin/env python3

"""

Pick a programming language.

In that language, write a function or program that takes as input a string of working code (in the same language).

It should return/output a minified version of the input code. The output should be functionally equivalent to the input.

Answers should contain both

The code that does the minifying (should be readable/non-golfed)
The resulting output after passing your code (that is, the code that does the minifying) in to itself
The shortest output wins.

Edit: notes explaining the minification methods you used are appreciated.

Edit: obviously, minification methods could vary from language to language, but a good-faith attempt at writing a minifier for this challenge would most likely perform actions such as

Removing unnecessary whitespace
Removing unnecessary newlines
Removing comments
Shortening variable names

"""

import clang.cindex as CX
import sys

class Minifier:
    def __init__(self, name):
        self.index = CX.Index.create()
        self.tu = self.index.parse(name, args=['-fparse-all-comments', '-fsyntax-only'])
        self.rewriter = CX.Rewriter.create(self.tu)

        self.minify(self.tu.cursor)
    
    def minify(self, node):
        self.remove_comments()
        self.refactor(self.tu.cursor)
        self.rewriter.write_main_file_to_stdout()

    def remove_comments(self):
        for token in self.tu.get_tokens(extent=self.tu.cursor.extent):
            if token.kind == CX.TokenKind.COMMENT:
                self.rewriter.remove_text(token.extent)

    def remove_spaces(self, tokens):
        position = None
        for token in tokens:
            start, end = token.extent.start, token.extent.end
            if position == None:
                position = start

            distance = start.offset - position.offset
            if start.line == position.line and distance > 1:
                ranges = CX.SourceRange.from_locations(position, start)
                self.rewriter.remove_text(ranges)
            elif start.line != position.line and start.column > 1:
                begin = CX.SourceLocation.from_position(self.tu, start.file, start.line, 1)
                ranges = CX.SourceRange.from_locations(begin, start)
                self.rewriter.remove_text(ranges)

            position = end

    def refactor(self, cursor):
        if cursor.location.file and cursor.location.file.name == self.tu.spelling:
            self.remove_spaces(cursor.get_tokens())

        for child in cursor.get_children():
            self.refactor(child)

def main():
    if len(sys.argv) < 2:
        print("usage: file.c")
        exit(2)

    Minifier(sys.argv[1])

main()
