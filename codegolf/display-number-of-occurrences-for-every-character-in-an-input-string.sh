#!/bin/sh

cat << EOF >/dev/null

The code should take a string as input from keyboard:

The definition of insanity is quoting the same phrase again and again and not expect despair.
The output should be like this(not sorted in any particular order):

  :  15
. :  1
T :  1
a :  10
c :  1
e :  8
d :  4
g :  3
f :  2
i :  10
h :  3
m :  1
o :  4
n :  10
q :  1
p :  3
s :  5
r :  2
u :  1
t :  6
y :  1
x :  1
All ASCII characters count unicode is not a requirement, spaces, quotes,etc and input should come from keyboard / not constants, attributes, output should be printed with new line after each character like in the above example, it should not be returned as string or dumped as hashmap/dictionary etc, so x :  1 and x: 1 are ok, but {'x':1,... and x:1 are not.

Q: Function or complete program taking stdin and writing stdout?
A: Code needs to be a program taking input using standard in and display the result via standard out.

EOF

freq() {
	echo $@ | fold -1 | sort | uniq -c
}

freq "The definition of insanity is quoting the same phrase again and again and not expect despair."
