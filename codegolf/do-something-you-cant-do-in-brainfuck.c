/*

Goal
Do some action (like delete a file, connect to a server, ...) that you can not do in standard Brainfuck.

What
As you know, all calculations you can do in almost any programming language, you can also do in standard Brainfuck. However, since standard Brainfuck can't do most syscalls, there are many things that are impossible to do in Brainfuck. Your goal is to do anything that is impossible in Brainfuck.

Rules
Anything on this list counts as impossible with standard Brainfuck. Write a program that does at least on thing from this list or something else that is impossible in standard Brainfuck:

Create, Delete or Move a File**.
Getting / displaying the current Time.
Shutdown, restart, ... the system.
Change pwd
Getting / displaying the arguments.
Anything that requires the internet.
Forking / Starting and killing processes (Except the own execution).
Get Random numbers from a external source.
Wait on user input with a timeout.
Send a signal to a different process.
Change its own cmdline.
Change the baud rate on a serial port.
Mount, unmount, format, defragment, eject .... a drive/partition.
Enable / disable network connections.
...
**Maybe it would be possible to write a program that emulates a shell where you can create and delete files within, but that file would only exist in RAM inside the Brainfuck program, so it is not the same.

Things that are, at least theoretically, possible in Brainfuck and don't count:

Doing any calculations
Working with text
Showing graphics (A Brainfuck program can use coloured text to display an image)
Showing animations
Delay / wait a certain amount of time (If an interpreter has a fixed rate at which it interprets code, you can create a delay in Brainfuck)
Exit with EXIT_SUCCESS or EXIT_FAILURE (Some interpreters will exit with EXIT_FAILURE when a negative cell is reached)
Using a certain amount of RAM / requesting more memory from the OS
Writing or reading from a single file
Shortest Code wins

Example
Ungolfed Example in Python

import datetime
now = datetime.datetime.now()
print(now.strftime("%Y-%m-%d %H:%M:%S"))

*/

#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <unistd.h>

int
main()
{
	int fd;

	fd = syscall(SYS_open, "brainfucked.txt", O_RDWR | O_CREAT);
	if (fd < 0) {
		syscall(SYS_write, 1, "BRAINFUCKED\n", 12);
		return 1;
	}
	syscall(SYS_write, fd, "brainfucker\n", 12);
	syscall(SYS_close, fd);
	return 0;
}
