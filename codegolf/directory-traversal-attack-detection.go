/*

Given a path to a file or a directory, detect whether the path can traverse to outside the current working directory, or attempt to traverse to the "parent directory" of the root directory.

Input
A string representing a Unix file path. For simplicity of this challenge, the path is assumed to never contain any control character ([0x00, 0x1F] ∪ 0x7F), newline, or space (0x20). The input string would also be non-empty. A forward slash (/, 0x2F) is used as a path separator.

The input path may be relative or absolute. An absolute path is indicated by the leading slash in the path string (for example, /usr/share/misc).

If there are multiple consecutive slashes in the path, they are treated as if there is only one slash (footnote 1). Example: a//b///c////d///// is treated the same as a/b/c/d/.
A directory name of . (dot) refers to the same directory as the previous part of the file path. The . directory at the beginning of the file path refers to the working directory. The . doesn't increase any level of directories in the filesystem hierarchy. Example: ./e/./f/././g is the same as e/f/g.
A directory name of .. (dot-dot) refers to the parent directory of the directory previously specified in the file path. It decreases one level of directories in the filesystem hierarchy. Example: h/i/../j/../k/l/../../m is the same as h/m provided that h/i, h/j and h/k/l are all directories and not any other kind of file. POSIX has set an exception that the "parent directory" of the root directory "may refer to the root directory itself" (reference), however for this challenge you must report such path as an attack attempt (see below).
Output
A boolean value (for each input, if your program or function allows multiple path inputs):

True if the path would traverse to outside the working directory when resolved, or, in the case of an absolute path, would traverse to outside the root directory if there were no guard about the "parent directory of root directory" above. (In other words, assume the "chroot jail" is weak that it can break.)

False if the path would resolve to inside the working directory for relative path, or inside the (jailed) root directory for an absolute path.

You may output in other data types as appropriate for your language that can represent boolean states (e.g. zero and nonzero).
(There is no need to print out the resolved file path. That is another challenge.)

Additional requirements
Except for standard input and output streams, there should be no access to the file system during program execution. (If you use mkdir(2) or chdir(2) then your submission entry would be non-competing.) This challenge is about parsing of the path strings, not about actual traversal.
Assume all filenames specified in the input paths exist and are directories.
Support of non-ASCII character sets (such us UTF-8) is optional.
Using built-in functions to resolve paths is allowed, but you must indicate so in your submission. I'm not sure if any built-in from a language would trivialize the problem, but I don't want to ban such submissions if they can provide informative examples for real-world uses.
code-golf. Aim for code size as small as possible.
Test data
.             -> False
...           -> False (footnote 2)
./            -> False
.//           -> False
a             -> False
a/b           -> False
a//b          -> False
a/./b         -> False
a/..          -> False
a/../b/..     -> False
..            -> True
../a/         -> True
a/../..       -> True
a/../b/../..  -> True

/             -> False
//            -> False (footnote 1)
/a/..         -> False
/..           -> True
/a/../..      -> True

C:/           -> False (footnote 3)
C:/..         -> False (footnote 3)
https://      -> False (footnote 3)
https://..    -> False (footnote 3)
C:/../..      -> True (footnote 3)
https://../.. -> True (footnote 3)

Footnotes
POSIX reserves the paths with two leading slashes to be special and "may be interpreted in an implementation-defined manner" (reference). See also this question in Unix/Linux Stack Exchange. For this challenge we ignore such special interpretation.
Unlike in DOS, a directory name of three dots (...) is not special in Unix systems.
Unix filesystems allow colons in filenames, so these examples refer to ordinary directories, not DOS paths or URLs.

*/

package main

import (
	"path"
	"strings"
)

func main() {
	assert(jailbreak(".") == false)
	assert(jailbreak("...") == false)
	assert(jailbreak("./") == false)
	assert(jailbreak(".//") == false)
	assert(jailbreak("a") == false)
	assert(jailbreak("a/b") == false)
	assert(jailbreak("a//b") == false)
	assert(jailbreak("a/./b") == false)
	assert(jailbreak("a/..") == false)
	assert(jailbreak("a/../b/..") == false)

	assert(jailbreak("..") == true)
	assert(jailbreak("../a/") == true)
	assert(jailbreak("a/../..") == true)
	assert(jailbreak("a/../b/../..") == true)

	assert(jailbreak("/") == false)
	assert(jailbreak("//") == false)
	assert(jailbreak("/a/..") == false)

	assert(jailbreak("/..") == true)
	assert(jailbreak("/a/../..") == true)

	assert(jailbreak("C:/") == false)
	assert(jailbreak("C:/..") == false)
	assert(jailbreak("https://") == false)
	assert(jailbreak("https://..") == false)

	assert(jailbreak("C:/../..") == true)
	assert(jailbreak("https://../..") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func jailbreak(name string) bool {
	if path.IsAbs(name) {
		name = "./" + name
	}
	name = path.Clean(name)

	dirs := strings.Split(name, "/")
	level := 0
	for _, dir := range dirs {
		if dir == ".." {
			level--
		} else if dir != "." {
			level++
		}
	}
	return level < 0 || dirs[0] == ".."
}
