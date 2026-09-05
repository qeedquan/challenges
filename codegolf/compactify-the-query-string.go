/*

Introduction
Just on Hacker news, John Resig contemplates transforming a query “foo=1&foo=2&foo=3&blah=a&blah=b” into one that looks like this: “foo=1,2,3&blah=a,b", https://johnresig.com/blog/search-and-dont-replace/. He claims "being 10 lines shorter than Mark’s solution".

Query strings consist of sequences of name-value pairs. Name-value pairs consist of a name and value, separated by =. names and values are possibly empty sequences of alphanumeric characters. Name-value pairs are separated by the & character in the sequence. Values are unique for each name.

Challenge
10 lines shorter than Mark's solution is not enough.

Read a query string.
Combine name value pairs with equal name into a single name value pair, with values concatenated and separated by comma.
Output the combined query string, with name-value pairs in the order the names are found from left to right in the query string.
This is code golf, the standard loopholes are closed.

Example Input and Output
Input:

foo=1&foo=&blah=a&foo=3&bar=x&blah=b&=1&=2

Output:

foo=1,,3&blah=a,b&bar=x&=1,2

Input:

foo=bar&foo=foo

Output:

foo=bar,foo

*/

package main

import (
	"bytes"
	"fmt"
	"net/url"
	"strings"
)

func main() {
	assert(compactify(`foo=1&foo=&blah=a&foo=3&bar=x&blah=b&=1&=2`) == `foo=1,,3&blah=a,b&bar=x&=1,2`)
	assert(compactify(`foo=bar&foo=foo`) == `foo=bar,foo`)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func compactify(query string) string {
	values, err := url.ParseQuery(query)
	if err != nil {
		return query
	}

	output := new(bytes.Buffer)
	seen := make(map[string]bool)
	for _, parameters := range strings.Split(query, "&") {
		tokens := strings.Split(parameters, "=")
		key := tokens[0]
		if seen[key] {
			continue
		}

		fmt.Fprintf(output, "%s=", key)
		for index, value := range values[key] {
			fmt.Fprintf(output, "%s", value)
			if index+1 < len(values[key]) {
				fmt.Fprintf(output, ",")
			}
		}
		fmt.Fprintf(output, "&")
		seen[key] = true
	}

	str := output.String()
	if len(str) > 0 {
		str = str[:len(str)-1]
	}
	return str
}
