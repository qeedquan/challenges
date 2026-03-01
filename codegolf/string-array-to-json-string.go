/*

Introduction
I've seen throughout the code-golf challenges several simple tasks involving JSON, such as interpreting JSON strings with RegExs, and almost every other manipulation I could think of.

In a binding for AppleScript that I was using for a Node project, I noticed that objects would be returned in a strange way: there would be an array of properties in string form, instead of a JSON object being returned as expected. This is where the challenge comes in...

Algorithm
Add { to beginning of the output string
Iterate over all entries, adding them to the output string, delimited by ,
Add } to the end of the output string
Print out the output string
Challenge
Make this strange return format usable. Convert an array of JSON 'key:value's (in string form) to a full JSON object string.

Rules
Any language that can do string manipulations allowed
Must print out JSON string with surrounding curly braces {}, and double quotes "" around string values AND all properties ("property":"value" or "property":3.14, etc.)
Must return a valid, parseable JSON string
Lowest byte count wins per language
Example Input and Output
Input:

['prop1:"val1"', 'prop2:12', 'prop3:3.14', 'prop4:false']

Output:

'{"prop1":"val1", "prop2":12, "prop3":3.14, "prop4":false}'

*/

package main

import (
	"encoding/json"
	"fmt"
	"strconv"
	"strings"
)

func main() {
	fmt.Println(str2json([]string{
		`prop1:"val1"`, `prop2:12`, `prop3:3.14`, `prop4:false`,
	}))
}

func str2json(props []string) string {
	dict := make(map[string]any)
	for _, prop := range props {
		toks := strings.Split(prop, ":")
		if len(toks) != 2 {
			continue
		}
		key := strings.TrimSpace(toks[0])
		val := strings.TrimSpace(toks[1])
		dict[key] = convert(val)
	}
	buf, _ := json.MarshalIndent(dict, "", "\t")
	return string(buf)
}

func convert(str string) any {
	val, err := strconv.Unquote(str)
	if err != nil {
		val = str
	}

	num, err := strconv.ParseFloat(val, 64)
	if err == nil {
		return num
	}

	cond, err := strconv.ParseBool(val)
	if err == nil {
		return cond
	}

	return val
}
