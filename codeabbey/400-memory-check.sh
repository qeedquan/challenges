#!/bin/sh

cat << EOF >/dev/null

This task was inspired by the recent thread in forum here - we want to know how much memory our program devours. If you like such system-oriented problems, check our satellite site, for example by tag "shell".

It is to be solved in Python and should utilize specific (somewhat hackerish) approach. Python itself doesn't have (as far as I know) convenient way to report memory usage. So instead we shall invoke special system program called top and parse its output.

This command is found in probably any Unix-like operating system, and given that most of servers nowadays run some unix-like OS (yep, unlike your laptop probably) - this could be regarded as pretty universal approach for real programmer's life. Here is wiki article on top though you may prefer man page for details.

Don't worry if you can't invoke it on your computer. Use solution box below - type in some code which calls top with proper arguments and click Run button (make sure Python is chosen as the solution language). Since the code is executed on server (running some version of Linux), you should be fine.

To begin with try fragment like this:

import os
os.system('top ...')
Find out proper arguments for top command. By default it starts in interactive mode (which won't work on server).

Keep in mind that os.system as shown above is not well suited for your purpose as it sends output of the program being executed to the standard output while you want to capture it and parse.

Additionally by default it shows data for all the programs it can find running currently. You don't need that much. There is a command line argument telling it to show stats only for program with given pid (process identifier). Of course you'll need to find a pid for your program being executed.

There are several columns in top output, in our case we are interested in VIRT column (which means "virtual", total memory allocated for process code, data, swapped out and live in physical memory).

Input - this task has no input, though your program, on being submitted, is affected by some cunning random logic which makes it to consume less or more memory between launches.

Answer - print single number, the one reported in VIRT column for your process. It is in kilobytes (and you may be impressed how much memory is taken by code which does almost nothing - but remember, here is Python interpreter running itself...)

The checker tests the memory consumed by your code in similar way. There could be minor discrepancies, but we allow about 1% tolerance. Just make sure you are not suddenly allocating large bulks of memory (probably you have no reason to do this). Also feel free to resubmit the code without change if you suspect some erratic behavior (this may happen rarely if our auxiliary server is busy).

EOF

PID=$(echo $$)
top -b -n 1 | awk '/PID/ {p=1} p' | sed 's/^[ \t]*//' | grep $PID | awk '{ print $5 }'
