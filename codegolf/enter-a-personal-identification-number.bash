#!/bin/bash

cat << EOF >/dev/null

In this challenge your code should allow the user to enter a four digit PIN.

Rules
If the user types a digit, your code should output a * symbol. If the user presses backspace it should delete the previous * symbol. If there are no *s to delete it should do nothing and wait for the next key press. All other key presses should be ignored.

The code has to be interactive, that is it updates the output after each key press and doesn't wait for return to be pressed (which should be ignored anyway).

Once 4 digits have been entered, the code should quit.

EOF

readpin() {
	stars=0
	echo -n "PIN: "
	while [[ $stars -lt 4 ]]; do
		read -s -n 1 key
		case $key in
			['0'-'9'])
				echo -n "*"
				stars=$((stars+1))
				;;
			$'\177')
				if [[ $stars -gt 0 ]]; then
					printf '\b \b'
					stars=$((stars-1))
				fi
				;;
		esac
	done
	echo
}

readpin
