/*

Your Challenge
You must write a program/function etc. that takes a domain name of a StackExchange site and outputs the domain for the meta version of the site passed to it. Examples:

stackoverflow.com => meta.stackoverflow.com
codegolf.stackexchange.com => codegolf.meta.stackexchange.com
mathoverflow.net => meta.mathoverflow.net
codereview.stackexchange.com => codereview.meta.stackexchange.com
Note: Subdomains are added to meta.stackexchange.com. Separate domains have meta. prepended. You don't need to worry about stackexchange.com or meta.stackexchange.com passed.

Shortest answer in bytes wins!

*/

package main

import (
	"strings"
)

func main() {
	assert(meta("stackoverflow.com") == "meta.stackoverflow.com")
	assert(meta("codegolf.stackexchange.com") == "codegolf.meta.stackexchange.com")
	assert(meta("mathoverflow.net") == "meta.mathoverflow.net")
	assert(meta("codereview.stackexchange.com") == "codereview.meta.stackexchange.com")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func meta(s string) string {
	i := strings.Index(s, "stackexchange")
	if i < 0 {
		return "meta." + s
	}
	return s[:i] + "meta." + s[i:]
}
