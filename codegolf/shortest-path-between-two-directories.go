/*

The challenge is to write a program which will find the shortest (least number of characters) command which will navigate to a target directory, given a starting directory, assuming a standard linux file system.

Take the following file system as an example, starting from ~:

.
├── target
└── test
    └── starting
If the user is in ~/test/starting and wants to navigate to ~/target, the shortest command is cd ~/target.

However, if the user is in ~/test/starting and wants to navigate to ~/test, the shortest command is cd ..

If the user wants to navigate to ~, the shortest command is cd ~.

If the user wants to navigate to /etc, the shortest command is cd /etc.

INPUT

The input is two strings; the starting directory and the target directory. For example: /etc/kernel and /opt. The method and order these are input is up to you. (eg: array, list, arguments, input, etc)

OUTPUT

Print or return the shortest command which navigates to the target directory.

SCORING

Standard code golf rules.

Some example test cases

Input format is starting target

Input: ~/a/b/c ~/a/z

Output: cd ~/a/z

Input: ~/apple/banana/carrot ~/apple/banana/z

Output: cd ../z

Input: ~/apple/banana/carrot /test

Output: cd /test

Input: /a/b /a/b/c

Output: cd c

Input: /a/b /a/b

Output: cd .

CLARIFICATIONS

~ is equivalent to /home/golfer
Assume that inputs are already minimal. For example, you would not get /home/golfer/a as an input, and would instead get ~/a
The only aliases you need to worry about are / and ~
Shortest path from ~ to /home is ..
@loopywalt has pointed out that cd with no argument will navigate to ~. This behaviour will be ignored, so please assume that an argument must always be specified.

*/

package main

import (
	"path/filepath"
)

func main() {
	assert(shortest("~/a/b/c", "~/a/z") == "cd ~/a/z")
	assert(shortest("~/apple/banana/carrot", "~/apple/banana/z") == "cd ../z")
	assert(shortest("~/apple/banana/carrot", "/test") == "cd /test")
	assert(shortest("/a/b", "/a/b/c") == "cd c")
	assert(shortest("/a/b", "/a/b") == "cd .")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func shortest(start, target string) string {
	start = filepath.FromSlash(start)
	target = filepath.FromSlash(target)

	rel, err := filepath.Rel(start, target)
	if err != nil {
		return "cd " + filepath.ToSlash(target)
	}

	abs := filepath.Join(start, rel)
	if len(abs) < len(rel) {
		return "cd " + filepath.ToSlash(abs)
	}

	return "cd " + filepath.ToSlash(rel)
}
