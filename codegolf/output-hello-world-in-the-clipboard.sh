#!/bin/sh

cat << EOF >/dev/null

Make a program (or a function) that copies the exact text "Hello, World!" to the clipboard, and terminates.

EOF

echo -n "Hello, World!" | xclip -selection clipboard

