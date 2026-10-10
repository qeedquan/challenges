#!/bin/sh

cat << EOF >/dev/null

Extend the String object (JS) or create a function (Python, C#) that converts the value of the String to and from Base64 using the ASCII (UTF-8 for C#) character set.

Example (input -> output):
'this is a string!!' -> 'dGhpcyBpcyBhIHN0cmluZyEh'
You can learn more about Base64 encoding and decoding here.

Note: This kata uses the non-padding version ("=" is not added to the end).

EOF

echo -n "this is a string!!" | base64
