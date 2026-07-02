#!/usr/bin/env python3

"""

Inspired by this question on SO, your task is to produce a program that is valid in (at least) two major versions of your chosen language that produce different output.

Rules
Any language that has more than one major version can be used.
For the purposes of this challenge, I would suggest a "major version" is where the first number in the version number changes.
PHP 4 and PHP 5 are different, PHP 5.3 and PHP 5.4 are not.
However, since I don't know the versioning scheme for all languages, if you can argue your case well enough, I'm sure the community will determine if you have been fair in determining "major version" yourself.
The code must be compiled and run with the same flags and input each time
Except to change the version of the language if this is pertinent
Errors don't count as output and answers that produce errors are disqualified (rather than error output is just ignored)
The program should take no input other than that required to make it run.
For each given version, the output should always be the same
The intention is that the change should be a consequence of a change in the language spec rather than the VM spec or environmental metadata
Scoring
code-golf type scoring for length, so +1 for each char/byte
-1 for each character difference in the length of the output.
e.g. Version 1 outputs abcde (5 characters), Version 2 outputs 123abc (6 characters) = -1
Other Rules
Standard exceptions apply - no external programs,web requests etc.
Your program should terminate (within 2 seconds)
Lowest score wins.
"Better" Scoring
Keep your original answers, in the interest of fairness, I'll mark the winner based on the original rules.

Since my original scoring is fundamentally broken, why not re-score / retry with the following scoring system:

code-golf type scoring for length, so +1 for each char/byte
+1 for each character difference in length of output
abcde and 123456 -> +1
-1 for each unique character difference in the output (capped to length of shortest output)
abcde and 123456 -> -5
12345 and 123456 -> -1
12345 and 123455 -> 0
Scores closest to zero win
In the event of a second tie break, simple code-golf score wins.

"""

"""

@Tat

In Python 2, this will print the entire list of integers from 0 to 99.
In Python 3, range is a generator and so it will print only "range(0,100)".


"""

print(range(100))

