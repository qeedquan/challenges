/*

Implement String#to_cents, which should parse prices expressed as $1.23 and return number of cents, or in case of bad format return nil.

*/

package main

import (
	"fmt"
	"regexp"
)

func main() {
	fmt.Println(tocents("$1.23"))
	fmt.Println(tocents("$0.64"))
}

func tocents(str string) any {
	re := regexp.MustCompile(`^\$\d+\.\d\d$`)
	if !re.MatchString(str) {
		return nil
	}

	var val float64
	fmt.Sscan(str[1:], &val)
	return val * 100
}
