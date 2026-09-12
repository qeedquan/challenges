#!/usr/bin/env python3

"""

The new operating system BerOS has a nice feature. It is possible to use any number of characters '/' as a delimiter in path instead of one traditional '/'. For example, strings //usr///local//nginx/sbin// and /usr/local/nginx///sbin are equivalent. The character '/' (or some sequence of such characters) at the end of the path is required only in case of the path to the root directory, which can be represented as single character '/'.

A path called normalized if it contains the smallest possible number of characters '/'.

Your task is to transform a given path to the normalized form.

Input
The first line of the input contains only lowercase Latin letters and character '/' — the path to some directory. All paths start with at least one character '/'. The length of the given line is no more than 100 characters, it is not empty.

Output
The path in normalized form.

Examples

input
//usr///local//nginx/sbin

output
/usr/local/nginx/sbin

"""

from os.path import *

def main():
    assert(realpath("//usr///local//nginx/sbin") == "/usr/local/nginx/sbin")

main()
