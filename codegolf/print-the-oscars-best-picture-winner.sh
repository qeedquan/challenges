#!/bin/sh

cat << EOF >/dev/null

This challenge is in tribute to the winner of Best Picture at the Oscars 2017, La La Land Moonlight!

Your challenge is to print the text

La La Land
pause one second, then change the text to show
La La Land Moonlight
The original text (La La Land) must have a strikethrough. This can be achieved either by clearing the screen, drawing on top of the original text, or by any other clever solutions.
This is a code-golf so lowest bytes wins. Standard code-golf rules apply.

EOF

clear
printf "La La Land\n"
sleep 1
clear
printf "\e[9m"
printf "La La Land"
printf "\e[m"
printf " Moonlight\n"

