#!/bin/sh

cat << EOF >/dev/null

The well known cat command simply copies its stdin directly to stdout unchanged. But there are plenty of other commandline tools that exist...

What other commands can be used to duplicate the functionality of the venerable cat?

Rules
You are not allowed to use any shell features, including pipes, file redirection, variables, etc.
Your answer can only directly invoke one command - e.g. foo-cmd; bar is disallowed because you are directly invoking both foo-cmd and bar (not to mention, the use of a semicolon breaks rule 1). However, commands that internally execute other commands (such as xargs) are allowed.
The command you use should already exist and be at least somewhat widely known. And an explanation of nontrivial answers would also be nice.
This contest is not about finding a single "best" cat implementation, and as such will not have a single accepted answer. Rather, this is an exercise in creativity: how many different ways can we collectively implement cat?
Solutions
So far, we have a cat implementation for the following commands (add yours to the list when you answer):

awk
sed

EOF

sed ""
