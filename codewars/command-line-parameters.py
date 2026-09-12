#!/usr/bin/env python3

"""

Given an array of arguments, representing system call arguments keys and values, join it into a single, space-delimited string. You don't need to care about the application name -- your task is only about parameters.

Each element of the given array can be:

a single string,
a single string array,
an array of two strings

In the last case (array of two strings) the first string should have a "--" prefix if it is more than one character long; or a "-" prefix otherwise; e.g.:

["foo", "bar"] becomes "--foo bar"
["f", "bar"] becomes "-f bar"

You may assume that all strings are non-empty and have no spaces.

Examples
["foo", "bar"]                    #  "foo bar"
[["foo", "bar"]]                  #  "--foo bar"
[["f", "bar"]]                    #  "-f bar"
[["foo", "bar"], "baz"]           #  "--foo bar baz"
[["foo"], ["bar", "baz"], "qux"]  #  "foo --bar baz qux"

"""

def args2str(args):
    result = []
    for arg in args:
        if isinstance(arg, list):
            if len(arg) == 2:
                key, value = arg
                prefix = "-"
                if len(key) > 1:
                    prefix = "--"
                result.append(f"{prefix}{key} {value}")
            else:
                result.append(arg[0])
        else:
            result.append(arg)
    return ' '.join(result)

def main():
    assert(args2str(["foo", "bar"]) == "foo bar")
    assert(args2str([["foo", "bar"]]) == "--foo bar")
    assert(args2str([["f", "bar"]]) == "-f bar")
    assert(args2str([["foo", "bar"], "baz"]) == "--foo bar baz")
    assert(args2str([["foo"], ["bar", "baz"], "qux"]) == "foo --bar baz qux")

main()
