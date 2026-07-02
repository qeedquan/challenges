#!/bin/sh

cat << EOF >/dev/null

Sometimes I find myself wanting a hot dog (don't we all) and so I make one. Now to make a hot dog, it is very simple.

1) Put the hot dogs into boiling water

2) Wait for a certain amount of time (detailed below)

3) Eat the hot dog once the time has elapsed.

You may have noticed that I said

certain time (detailed below)

and so I will detail.

Many different brands have many different recommendations for how long we should cook the hot dogs, but I have found it best to cook them for exactly 4 minutes and 27 seconds (don't ask). I have tried many different timers, but have found that a program that continuously outputs is the best way to attract my attention.

YOUR TASK
You have to make a program that will output the message Not ready yet for exactly 4 minutes and 27 seconds. After this time has elasped, you should output Eat your hot dog until the end of time. Please don't take any input.

HOW TO WIN
You must write the shortest code in bytes to win because this is a code-golf

EOF

for i in $(seq 1 $(echo 4*60+27 | bc)); do
	echo "Not ready yet"
	sleep 1
done

echo "Eat your hot dog"
