#!/usr/bin/env python3

r"""

Description

Given a source path and a destination path, output the relative path to the destination with respect to the source.

Rules

The input can come from stdin or as arguments to the program/function.

Both Windows and Unix style paths must be supported.

The output path can use / and/or \ for the path separator (your choice and combination of both is OK).

You can assume a relative path is possible.

The use of external programs, built-in or library functions made for computing relative paths is prohibited (e.g. Python's os.path.relpath)

This is code-golf

Edit: New rule from comments.

The relative path must be the shortest relative path possible.

Assume the destination path is different from the source path.

Example 1

# In
/usr/share/geany/colorschemes
/usr/share/vim/vim73/ftplugin

# Out
../../vim/vim73/ftplugin
Example 2

# In
C:\Windows\System32\drivers
C:\Windows\System32\WindowsPowerShell\v1.0

# Out
..\WindowsPowerShell\v1.0

"""

from os.path import relpath

def main():
    assert(relpath("/usr/share/vim/vim73/ftplugin", "/usr/share/geany/colorschemes") == "../../vim/vim73/ftplugin")

main()
