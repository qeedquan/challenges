#!/bin/bash

cat << EOF >/dev/null

Introduction
In our recent effort to collect catalogues of shortest solutions for standard programming exercises, here is PPCG's first ever vanilla FizzBuzz challenge. If you wish to see other catalogue challenges, there is "Hello World!" and "Is this number a prime?".

Challenge
Write a program that prints the decimal numbers from 1 to 100 inclusive. But for multiples of three print “Fizz” instead of the number and for the multiples of five print “Buzz”. For numbers which are multiples of both three and five print “FizzBuzz”.

Output
The output will be a list of numbers (and Fizzes, Buzzes and FizzBuzzes) separated by a newline (either \n or \r\n). A trailing newline is acceptable, but a leading newline is not. Apart from your choice of newline, the output should look exactly like this:

1
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz
16
17
Fizz
19
Buzz
Fizz
22
23
Fizz
Buzz
26
Fizz
28
29
FizzBuzz
31
32
Fizz
34
Buzz
Fizz
37
38
Fizz
Buzz
41
Fizz
43
44
FizzBuzz
46
47
Fizz
49
Buzz
Fizz
52
53
Fizz
Buzz
56
Fizz
58
59
FizzBuzz
61
62
Fizz
64
Buzz
Fizz
67
68
Fizz
Buzz
71
Fizz
73
74
FizzBuzz
76
77
Fizz
79
Buzz
Fizz
82
83
Fizz
Buzz
86
Fizz
88
89
FizzBuzz
91
92
Fizz
94
Buzz
Fizz
97
98
Fizz
Buzz
The only exception to this rule is constant output of your language's interpreter that cannot be suppressed, such as a greeting, ANSI color codes or indentation.

Further Rules
This is not about finding the language with the shortest approach for playing FizzBuzz, this is about finding the shortest approach in every language. Therefore, no answer will be marked as accepted.

Submissions are scored in bytes in an appropriate preexisting encoding, usually (but not necessarily) UTF-8. Some languages, like Folders, are a bit tricky to score--if in doubt, please ask on Meta.

Nothing can be printed to STDERR.

Feel free to use a language (or language version) even if it's newer than this challenge. If anyone wants to abuse this by creating a language where the empty program generates FizzBuzz output, then congrats for paving the way for a very boring answer.

Note that there must be an interpreter so the submission can be tested. It is allowed (and even encouraged) to write this interpreter yourself for a previously unimplemented language.

If your language of choice is a trivial variant of another (potentially more popular) language which already has an answer (think BASIC or SQL dialects, Unix shells or trivial Brainfuck derivatives like Alphuck and ???), consider adding a note to the existing answer that the same or a very similar solution is also the shortest in the other language.

Because the output is fixed, you may hardcode the output (but this may not be the shortest option).

You may use preexisting solutions, as long as you credit the original author of the program.

Standard loopholes are otherwise disallowed.

As a side note, please don't downvote boring (but valid) answers in languages where there is not much to golf; these are still useful to this question as it tries to compile a catalogue as complete as possible. However, do primarily upvote answers in languages where the authors actually had to put effort into golfing the code.

EOF

fizzbuzz() {
	for i in $(seq 1 $1); do
		if !((i % 15)); then
			echo "FizzBuzz"
		elif !((i % 3)); then
			echo "Fizz"
		elif !((i % 5)); then
			echo "Buzz"
		else
			echo $i
		fi
	done
}

fizzbuzz 100
