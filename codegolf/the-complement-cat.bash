#!/bin/bash

cat << EOF >/dev/null

Objective Write a full program that outputs (to STDOUT or closest alternative) an arbitrary string of text, no more than 64 characters long. Simple enough, right? Well, here's the catch: You may not use any characters that were present in the previous answer's output. That's right, none of them.

Thus, you are trying to be the last answer for a total of three days. That is, you want no one to answer the question in the 72 hours following the posting of your question.
Some rules

    Your answer (and output) may only contain printable ASCII characters, newlines (carriage returns included), and tabs.
    Your answer's output may not be the same as another answer's output. Two output's are the same if and only if they use the exact same characters.
    You may use any language that was not specifically made for this challenge, even if it was made after the challenge. (This language, of course, must be testable.)
    You may not use any language that was previously used.
    Your entry may not include comments. You may, of course, provide an extra commented program.
    You may not answer twice in a row.
    Your program must be at least 1 byte.

Entry format

Your answer should look generally like the following:

# {Language}
Uses: characters present in the output

Does not use: characters used in the previous output from [previous submission, language](link-to-previous-submission]

    {program}

Outputs:

    {output}

An explanation with your answer is appreciated.

EOF

i=0
while [[ $i -lt 64 ]]; do
	x=$((32 + (RANDOM % 96)))
	ascii -d -t $x | tr -d '\n'
	i=$((i+1))
done

echo
