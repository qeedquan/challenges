/*

In the IRC protocol, raw messages look similar to this:

command arg1 arg2 :arg3 with spaces :arg4 with spaces :arg5
In a shell environment (e.g. bash), that would be equivalent to:

command arg1 arg2 "arg3 with spaces" "arg4 with spaces" arg5
The format specification is as follows:

Raw messages will only contain printable ASCII characters (ordinals 32-126).
Raw messages will start with a command, which will not contain any spaces.
Any number of arguments may follow a command. Arguments are delimited by one or more spaces followed by a colon (<space>: and <space><space>: are both valid delimiters).
Any arguments that do not contain spaces may omit the colon from the delimiter so long as all previous arguments (if any) have omitted the colon.
Colons will not appear within arguments or commands.
Arguments will not begin with a space.
For example, these are all valid raw messages:

join #foo #bar #baz
msg person hi
msg #channel :hello world
help :how do I use IRC
foo bar :baz bip :abc def :ghi
These are all invalid raw messages:

error :n:o colons within arguments
error ::need spaces between colons
:error no colons in commands
error non-ASCII character Ω
Given a valid raw IRC message as input, output a list containing the command and the arguments, properly parsed.

Test Cases
"join #foo #bar #baz" -> ["join", "#foo", "#bar", "#baz"]
"msg person hi" -> ["msg", "person", "hi"]
"msg #channel :hello world" -> ["msg", "#channel", "hello world"]
"help :how do I use IRC" -> ["help", "how do I use IRC"]
foo bar :baz bip :abc def :ghi :xyz -> ["foo", "bar", "baz bip", "abc def", "ghi", "xyz"]

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Printf("%q\n", parse("join #foo #bar #baz"))
	fmt.Printf("%q\n", parse("msg person hi"))
	fmt.Printf("%q\n", parse("msg #channel :hello world"))
	fmt.Printf("%q\n", parse("help :how do I use IRC"))
	fmt.Printf("%q\n", parse("foo bar :baz bip :abc def :ghi :xyz"))
}

func parse(msg string) []string {
	msg, cmd := parsecmd(msg)
	res := []string{cmd}
	for {
		var (
			arg string
			eof bool
		)
		msg, arg, eof = parsearg(msg)
		if eof {
			break
		}
		res = append(res, arg)
	}
	return res
}

func parsecmd(msg string) (string, string) {
	msg = parsews(msg)
	idx := strings.IndexByte(msg, ' ')
	if idx < 0 {
		idx = len(msg)
	}
	return msg[idx:], msg[:idx]
}

func parsearg(msg string) (string, string, bool) {
	msg = parsews(msg)
	if len(msg) == 0 {
		return msg, msg, true
	}

	beg := 0
	idx := -1
	if msg[0] == ':' {
		idx = strings.IndexByte(msg[1:], ':')
		beg = 1
	} else {
		idx = strings.IndexByte(msg, ' ')
	}
	if idx < 0 {
		idx = len(msg)
	}
	return msg[idx:], msg[beg:idx], false
}

func parsews(msg string) string {
	for len(msg) > 0 && msg[0] == ' ' {
		msg = msg[1:]
	}
	return msg
}
