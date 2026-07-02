#!/bin/sh

cat << EOF >/dev/null

Markdown is the text markup system used by reddit in comments and text submissions. Write a script that converts a piece of Markdown into HTML.

EOF

pandoc -f markdown -t html5 -o $2 $1 -c style.css

