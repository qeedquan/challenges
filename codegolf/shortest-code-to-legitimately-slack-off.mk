#!/usr/bin/make -f

# I'm a developer, and I don't feel like doing my work. I know from XKCD that the best excuse for slacking off is that your code's compiling.
# Because of this, I think I need some code that will compile forever! And because I'm lazy and don't want to have to type much, this has to be done with the shortest code possible.
#
# So, your task is to write a program that is syntactically valid, but will cause the compiler to enter an infinite loop.
#
# Specifications
# You must use a language that has a compiler, obviously.
# Specify the implementation used in each solution.
# This is code-golf, so the shortest valid solution (in bytes) wins.
# The compiler can terminate from running out of memory or stack space.

argv0 = $(word $(words $(MAKEFILE_LIST)), $(MAKEFILE_LIST))

all:
	make -f $(argv0)

