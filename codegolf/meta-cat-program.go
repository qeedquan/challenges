/*

Write a program or function that takes input and outputs/returns a full program (in the same language) that outputs said input. Note that the input may contain any printable ASCII character or newline (AKA 0x20-0x7f and 0x0a). However, the input will not have trailing whitespace nor preceding whitespace, nor will it be empty.

Test cases (Javascript):
cat => console.log("cat")
fish => console.log("fish")
m(newline)ta-c t => console.log("m\neta-c t")
m"'`\c => console.log("m\"'`\\c")

Example program
function metaCat(text){
  return "console.log(\"" + text.replace(/\\/g,"\\\\").replace(/"/g,"\\\"").replace(/\n/g,"\\n") + "\")"
}

*/

package main

import "fmt"

func main() {
	metacat("cat")
	metacat("fish")
	metacat("m(newline)ta-c t")
	metacat("m\"'`\\c")
}

func metacat(s string) {
	fmt.Printf("fmt.Println(%q)\n", s)
}
