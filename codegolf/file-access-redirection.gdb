# gdb -x file.gdb --args program args ...

# This one ought to be a little more of a challenge than your normal "compute these numbers" or "print this sequence of text" puzzles:
#
# Write a program that launches another program and when that other program tries to access a certain file the program causes it to open a different file.
#
# Example:
#
# The program launches Notepad.
# Notepad attempts to open "orange.txt"
# The program detects it and makes notepad open "green.txt" instead.
#
# Rules:
# WinAPI is allowed, but your code will stand out better if you can get this some other way.
# You can use any language, but it must be able to run on either Windows or Linux

start

# works on x86_64 sysv calling convention
# breakpoint when the open() call is passed with a filename that we want to match
b open if $_streq((char*)$rdi, "orange.txt")

# setup a sequence of commands to be ran when a breakpoint is hit 
comm
	set $rdi="green.txt"
	c
end

c
