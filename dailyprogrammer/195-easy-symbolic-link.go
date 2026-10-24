/*

Many Unix-based systems support the concept of a symbolic link. This is where one directory name is transparently mapped to another. Before we look further at symbolic links, here's a brief primer on Unix paths.

The root directory on a file-system is /. Everything is contained with in /. This is like C:\ on Windows, but contains everything rather than just the system drive. Thus, all absolute paths begin with a / - if it doesn't, the path is assumed to be relative to the current location.

Successive nested directorys are joined with slashes, so a directory a in a directory b in a directory c in root is denoted /c/b/a.

To distinguish a directory from a file, a trailing slash can be added, so /c/b/a and /c/b/a/ are equivalent assuming a is a directory and not a file.

Path names are case sensitive. /bin/thing is different from /bin/Thing.

Now, symbolic links are the more general equivalent of Windows shortcuts. They can be used to 'redirect' one directory to another. For example, if I have a version of a program thing located at /bin/thing-2, then when thing upgrades to thing 3 then any programs referring to /bin/thing-2 will break once it changes to /bin/thing-3. Thus, I might make a symbolic link /bin/thing which refers to /bin/thing-2. This means any attempt to visit a path beginning with /bin/thing will be silently redirected to /bin/thing-2. Hence, once the program updates, just change the symbolic link and everything is working still.

Symbolic links can have more to them, and you can in fact make them on Windows with some NTFS trickery, but this challenge focuses just on Unix style directories.

Our challenge is to resolve a given path name into its actual location given a number of symbolic links. Assume that symbolic links can point to other links.

Input Description
You will accept a number N. You will then accept N lines in the format:

/path/of/link:/path/of/destination
Then you will accept a path of a directory to be fully expanded.

For example:

4
/bin/thing:/bin/thing-3
/bin/thing-3:/bin/thing-3.2
/bin/thing-3.2/include:/usr/include
/usr/include/SDL:/usr/local/include/SDL
/bin/thing/include/SDL/stan
Output Description
Expand it into its true form, for example:

/usr/local/include/SDL/stan

Sample Inputs and Outputs

Sample Input
1
/home/elite/documents:/media/mmcstick/docs
/home/elite/documents/office
Sample Output
/media/mmcstick/docs/office

Sample Input
3
/bin:/usr/bin
/usr/bin:/usr/local/bin/
/usr/local/bin/log:/var/log-2014
/bin/log/rc
Sample Output
/var/log-2014/rc

Sample Input
2
/etc:/tmp/etc
/tmp/etc/:/etc/
/etc/modprobe.d/config/

Sample Output
Program should hang - recursive loop.

(I know nested symlinks are restricted in practice, but we're livin' life on the edge in this subreddit.)

Extension
Extend your solution to resolve existing symlinks in the definition of successive symlinks. For example:

4
/bin/thing:/bin/thing-3
/bin/thing-3:/bin/thing-3.2
/bin/thing/include:/usr/include
/bin/thing-3.2/include/SDL:/usr/local/include/SDL
/bin/thing/include/SDL/stan
Notice how the 3rd link relies on the first and second symlinks, and the 4th link relies on the 3rd link working.

This should resolve correctly into /usr/local/include/SDL/stan.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	assert(resolve([]string{
		"/bin/thing:/bin/thing-3",
		"/bin/thing-3:/bin/thing-3.2",
		"/bin/thing-3.2/include:/usr/include",
		"/usr/include/SDL:/usr/local/include/SDL",
	}, "/bin/thing/include/SDL/stan") == "/usr/local/include/SDL/stan")

	assert(resolve([]string{
		"/home/elite/documents:/media/mmcstick/docs",
	}, "/home/elite/documents/office") == "/media/mmcstick/docs/office")

	assert(resolve([]string{
		"/bin:/usr/bin",
		"/usr/bin:/usr/local/bin/",
		"/usr/local/bin/log:/var/log-2014",
	}, "/bin/log/rc") == "/var/log-2014/rc")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// ported from @skeeto solution
type directory struct {
	parent  *directory
	self    *entry
	entries *entry
}

type entry struct {
	name    string
	content any
	next    *entry
}

func mkdir(parent *directory, name string) *directory {
	content := &directory{
		parent: parent,
	}
	entry := &entry{
		name:    name,
		content: content,
		next:    parent.entries,
	}
	content.self = entry
	parent.entries = entry
	return content
}

func ln(parent *directory, name, destination string) *entry {
	entry := &entry{
		name:    name,
		content: destination,
		next:    parent.entries,
	}
	parent.entries = entry
	return entry
}

func ls(parent *directory, name string) *entry {
	entry := parent.entries
	for ; entry != nil; entry = entry.next {
		if entry.name == name {
			return entry
		}
	}
	return nil
}

func cd(root *directory, path string) *directory {
	parent := root
	tokens := strings.Split(path, "/")
	for _, token := range tokens {
		if token == "" {
			continue
		}

		entry := ls(parent, token)
		if entry != nil {
			switch content := entry.content.(type) {
			case *directory:
				parent = content
			case string:
				parent = cd(root, content)
			}
		} else {
			parent = mkdir(parent, token)
		}
	}
	return parent
}

func realpath(directory *directory) string {
	result := ""
	if directory.parent != nil {
		result = fmt.Sprintf("%s/%s", realpath(directory.parent), directory.self.name)
	}
	return result
}

func resolve(links []string, path string) string {
	root := &directory{}
	for _, link := range links {
		tokens := strings.Split(link, ":")
		if len(tokens) != 2 {
			continue
		}

		sourcepath := tokens[0]
		destpath := tokens[1]
		sourcefile := ""
		index := strings.LastIndex(sourcepath, "/")
		if index >= 0 {
			sourcefile = sourcepath[index+1:]
			sourcepath = sourcepath[:index]
		}

		source := cd(root, sourcepath)
		ln(source, sourcefile, destpath)
	}

	directory := cd(root, path)
	return realpath(directory)
}
