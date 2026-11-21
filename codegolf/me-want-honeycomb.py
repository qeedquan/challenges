#!/usr/bin/env python3

"""

Write the shortest program that prints this ASCII art section of a hexagonal tiling or honeycomb:

       __
    __/  \__
 __/  \__/  \__
/  \__/  \__/  \
\__/  \__/  \__/
/  \__/  \__/  \
\__/  \__/  \__/
/  \__/  \__/  \
\__/  \__/  \__/
   \__/  \__/
      \__/
No input should be taken.
Output to stdout or your language's closest alternative.
Instead of a program, you may write a named function that takes no parameters and prints the result normally or returns it as a string.
The output may have any number of leading and/or trailing newlines and each line in the output may have any number of leading and/or trailing spaces (as long as the pattern lines up properly.)
The shortest code in bytes wins.

"""

HONEYCOMB = """
       __
    __/  \__
 __/  \__/  \__
/  \__/  \__/  \\
\__/  \__/  \__/
/  \__/  \__/  \\
\__/  \__/  \__/
/  \__/  \__/  \\
\__/  \__/  \__/
   \__/  \__/
      \__/

"""

def main():
    print(HONEYCOMB)

main()
