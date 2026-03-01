/*

Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

Implement the Solution class:

Solution() Initializes the object of the system.
String encode(String longUrl) Returns a tiny URL for the given longUrl.
String decode(String shortUrl) Returns the original long URL for the given shortUrl. It is guaranteed that the given shortUrl was encoded by the same object.


Example 1:

Input: url = "https://leetcode.com/problems/design-tinyurl"
Output: "https://leetcode.com/problems/design-tinyurl"

Explanation:
Solution obj = new Solution();
string tiny = obj.encode(url); // returns the encoded tiny url.
string ans = obj.decode(tiny); // returns the original url after deconding it.


Constraints:

1 <= url.length <= 10^4
url is guranteed to be a valid URL.

*/

package main

import (
	"bytes"
	"fmt"
	"math/rand"
)

func main() {
	test([]string{
		"https://leetcode.com/problems/design-tinyurl",
		"https://java.com/ide/splx",
		"https://google.com/tinyurl/ixhe12",
		"linenoise.bridge.io",
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(longurls []string) {
	t := NewTiny()
	for _, longurl := range longurls {
		shorturl := t.Encode(longurl)
		xlongurl := t.Decode(shorturl)

		fmt.Printf("%q | %q\n", shorturl, xlongurl)
		assert(xlongurl == longurl)
	}
}

type Tiny struct {
	code map[string]string
	link map[string]string
	rng  *rand.Rand
}

func NewTiny() *Tiny {
	return &Tiny{
		code: make(map[string]string),
		link: make(map[string]string),
		rng:  rand.New(rand.NewSource(1)),
	}
}

func (t *Tiny) Encode(longurl string) string {
	if link := t.link[longurl]; link != "" {
		return link
	}

	var code string
	for tries := 0; tries < 1e9; tries++ {
		xcode := t.gencode()
		if _, exist := t.code[xcode]; !exist {
			code = xcode
			break
		}
	}

	t.code[code] = longurl
	t.link[longurl] = code
	return code
}

func (t *Tiny) Decode(shorturl string) string {
	return t.code[shorturl]
}

func (t *Tiny) gencode() string {
	const chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

	w := new(bytes.Buffer)
	w.WriteString("http://tinyurl.com/")
	for i := 0; i < 6; i++ {
		n := t.rng.Intn(len(chars))
		w.WriteByte(chars[n])
	}
	return w.String()
}
