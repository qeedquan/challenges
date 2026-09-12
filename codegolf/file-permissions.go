/*

Adapted from the UIL - Computer Science Programming free response question "Carla" for 2018 District.

Introduction
In UNIX-like operating systems, each file, directory, or link is "owned" by a "user", who is a member of a "group", and has certain "permissions" represented by a ten-character string such as "drwxrwxrwx". The first character is 'd', '-', or 'l' (directory, file, or link), followed by three sets of "rwx" values, indicating "read, write, execute" permissions. The first set is the user's rights, the middle set the group's rights, and the third everyone else's rights to that object.

Permission denied for any of these rights is represented by a '-' in place of the 'r', 'w', or 'x'. For example, a sample directory permission string would be "drwxr--r--", indicating full directory rights for the user, but "read-only" rights for the group member and all others.

Each "rwx" combination can also be represented by an octal value (0-7) with the most significant bit representing read permission, the next most significant bit representing write permission, and the least significant bit representing execute permission.

Challenge
Given a four-character code string made up of a character: 'D', 'F', or 'L', followed by a three-digit octal integer value, like 664, output the resulting 10 character string that represents the permission value indicated.

Input
Your program or function may either read the input from standard in (four characters will be entered, optionally followed by a newline) or be passed the input as an argument.

Your program may accept uppercase or lowercase inputs but must be consistent (either all inputs are uppercase or all inputs are lowercase).

Output
Your program must print the resulting ten-character string that represents the permission value indicated in the exact format specified above. Tailing white space is allowed.

Test Cases
In: F664 Out: -rw-rw-r--
In: D775 Out: drwxrwxr-x
In: L334 Out: l-wx-wxr--
In: F530 Out: -r-x-wx---
In: D127 Out: d--x-w-rwx

Scoring and Rules
Standard loop-holes are forbidden.
Standard rules apply.
Please provide a link to test your code as well as an explanation.
This is code-golf, so the shortest answer in bytes wins!

*/

package main

import (
	"bytes"
)

func main() {
	assert(permission("F664") == "-rw-rw-r--")
	assert(permission("D775") == "drwxrwxr-x")
	assert(permission("L334") == "l-wx-wxr--")
	assert(permission("F530") == "-r-x-wx---")
	assert(permission("D127") == "d--x-w-rwx")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func permission(s string) string {
	if len(s) != 4 {
		return ""
	}

	w := new(bytes.Buffer)
	switch s[0] {
	case 'F':
		w.WriteByte('-')
	case 'D':
		w.WriteByte('d')
	case 'L':
		w.WriteByte('l')
	default:
		return ""
	}

	const mode = "xwr"
	for i := 1; i < 4; i++ {
		m := s[i] - '0'
		if !(0 <= m && m <= 7) {
			return ""
		}

		for j := len(mode) - 1; j >= 0; j-- {
			if m&(1<<j) != 0 {
				w.WriteByte(mode[j])
			} else {
				w.WriteByte('-')
			}
		}
	}
	return w.String()
}
