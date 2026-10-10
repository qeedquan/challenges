/*

Mr. E Ven only likes even length words. Please create a translator so that he doesn't have to hear those pesky odd length words. For some reason he also hates punctuation, he likes his sentences to flow.

Your translator should take in a string and output it with all odd length words having an extra letter (the last letter in the word). It should also remove all punctuation (.,?!) as well as any underscores (_).

"How did we end up here? We go?" translated becomes-> "Howw didd we endd up here We go"

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	assert(translate("How did we end up here? We go?") == "Howw didd we endd up here We go")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func translate(s string) string {
	r := strings.NewReplacer(".", "", ",", "", "?", "", "!", "", "_", "")
	s = r.Replace(s)
	t := strings.Split(s, " ")
	w := new(bytes.Buffer)
	for i, p := range t {
		fmt.Fprintf(w, "%s", p)
		if len(p)&1 != 0 {
			fmt.Fprintf(w, "%c", p[len(p)-1])
		}
		if i+1 < len(t) {
			fmt.Fprintf(w, " ")
		}
	}
	return w.String()
}
