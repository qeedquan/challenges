#!/bin/bash

cat << EOF > /dev/null

Is this Q too easy to ask, or has it just never been thought of?

Generate a random number, either 0 or 1 using a program

You may use a pre-defined function. The code must be executable. (It can't be just a function that requires more code to execute.) Randomness of the output will be verified by showing that it is not possible for a human/computer today to predict the output of the next execution (unless the exact algorithm is revealed), even when given an infinite set of outputs on previous executions of the code.

I'm looking for the most interesting code (never mind if it's lengthy).

Note: I had initially asked for the shortest code. The answer to that is 2 bytes long. It's O2 in Pyth, according to @Dennis

EOF

echo $((RANDOM % 2))
