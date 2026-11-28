/*

Semantic Versioning, or Semver as it's known on the streets, is an attempt to standardise the way that software versions are incrementally changed. In the world there are many different pieces of software whose developers have conflicting ideas about how software should be developed. For example, Dwarf Fortress is currently at version 0.40.13, whereas Google Chrome (which has been around for 2 years less than Dwarf Fortress) is currently at version 37.0.2062.124. How can those version numbers even be compared? They both represent around the same progress of development but in totally different ways. Semantic versioning aims to solve this problem by splitting the version string into 3, 4 or 5 parts:

<major>.<minor>.<patch>-<label>+<metadata>
major: Increased when your program changes in a way that makes it incompatible with older versions (major changes) - like the Python 2 to Python 3 change which, in order to make progress, broke a lot of existing programs.

minor: Increased when you add functionality but keep compatibility and don't change existing bits of the API (minor changes) - for example, adding a new section of a standard library to a programming language.

patch: Increased when you make minor functionality changes or bug fixes, like adding a new keyboard shortcut.

label: Used to indicate pre-release program status, such as beta, alpha or rc2 (release candidate 2.)

metadata: Used to describe build metadata when a version is in the early development stages - this might include the build date of the program.

For the purpose of this challenge, you will be sorting a list of Semantic Versions into chronological order, and you will do it like so:

First, compare the major version.

If they are the same, compare the minor version.

If they are the same, compare the patch version.

If those are all the same, check if the version has a label - ignore the content of the label. A version with a label (prerelease) comes before one without a label (final release.)

Ignore the build metadata.

If the semantic versions are still the same at this point, they can be considered the same version. For the purpose of this challenge we won't attempt to parse the label - but if you're feeling up to you can give it a try!

The full specification for Semantic Versioning can be found here.

Formal Inputs and Outputs
Input Description
You will first be given a number N. You will then be given N more lines, each one with a semantic version.

Output Description
You will print the versions in chronological order, as described by the rules above.

Sample Inputs and Outputs
Sample Input
7
2.0.11-alpha
0.1.7+amd64
0.10.7+20141005
2.0.12+i386
1.2.34
2.0.11+i386
20.1.1+i386
Sample Output
0.1.7+amd64
0.10.7+20141005
1.2.34
2.0.11-alpha
2.0.11+i386
2.0.12+i386
20.1.1+i386
Tip
If your chosen language supports it, create a SemanticVersion record/structure with the appropriate fields. If your language supports it, overload the comparison (<, >) operators to compare for you.

If your language does not support sorting of data structures by default, you could adjust your solution to the Quicksort challenge to work with this one.

*/

package main

import (
	"bytes"
	"fmt"
	"sort"
	"strings"
)

type Version struct {
	Major    int
	Minor    int
	Patch    int
	Label    string
	Metadata string
}

type VersionSlice []Version

func main() {
	test([]string{
		"2.0.11-alpha",
		"0.1.7+amd64",
		"0.10.7+20141005",
		"2.0.12+i386",
		"1.2.34",
		"2.0.11+i386",
		"20.1.1+i386",
	})
}

func test(lines []string) {
	versions := parse(lines)
	sort.Sort(VersionSlice(versions))
	for _, version := range versions {
		fmt.Println(version)
	}
}

func parse(lines []string) []Version {
	var versions []Version
	for _, line := range lines {
		var version Version
		buffer := bytes.NewBufferString(line)
		_, err := fmt.Fscanf(buffer, "%d.%d.%d", &version.Major, &version.Minor, &version.Patch)
		if err != nil {
			continue
		}
		fields := strings.Split(buffer.String(), "+")
		for i := range fields {
			fields[i] = strings.TrimPrefix(fields[i], "+")
			fields[i] = strings.TrimPrefix(fields[i], "-")
		}
		version.Label = fields[0]
		if len(fields) >= 2 {
			version.Metadata = fields[1]
		}
		versions = append(versions, version)
	}
	return versions
}

func (v VersionSlice) Less(i, j int) bool {
	if v[i].Major != v[j].Major {
		return v[i].Major < v[j].Major
	}
	if v[i].Minor != v[j].Minor {
		return v[i].Minor < v[j].Minor
	}
	if v[i].Patch != v[j].Patch {
		return v[i].Patch < v[j].Patch
	}
	if v[i].Label != "" && v[j].Label == "" {
		return true
	}
	if v[i].Label == "" && v[j].Label != "" {
		return false
	}
	return i < j
}

func (v VersionSlice) Len() int {
	return len(v)
}

func (v VersionSlice) Swap(i, j int) {
	v[i], v[j] = v[j], v[i]
}

func (v Version) String() string {
	s := fmt.Sprintf("%d.%d.%d", v.Major, v.Minor, v.Patch)
	if v.Label != "" {
		s += fmt.Sprintf("-%s", v.Label)
	}
	if v.Metadata != "" {
		s += fmt.Sprintf("+%s", v.Metadata)
	}
	return s
}
