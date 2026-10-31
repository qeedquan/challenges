/*

Write a function that when given a URL as a string, parses out just the domain name and returns it as a string. For example:

* url = "http://github.com/carbonfive/raygun" -> domain name = "github"
* url = "http://www.zombie-bites.com"         -> domain name = "zombie-bites"
* url = "https://www.cnet.com"                -> domain name = cnet"

*/

package main

import (
	"net/url"
	"strings"
)

func main() {
	assert(extract("http://github.com/carbonfive/raygun") == "github")
	assert(extract("http://www.zombie-bites.com") == "zombie-bites")
	assert(extract("https://www.cnet.com") == "cnet")
	assert(extract("http://google.com") == "google")
	assert(extract("http://google.co.jp") == "google")
	assert(extract("www.xakep.ru") == "xakep")
	assert(extract("xakep.ru") == "xakep")
	assert(extract("https://youtube.com") == "youtube")
	assert(extract("http://www.codewars.com/kata/") == "codewars")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func extract(addr string) string {
	url, err := url.Parse(addr)
	if err != nil {
		return addr
	}

	domain := url.Host
	if url.Host == "" {
		domain = url.Path
	}

	toks := strings.Split(domain, ".")
	if len(toks) > 1 && toks[0] == "www" {
		toks = toks[1:]
	}
	return toks[0]
}
