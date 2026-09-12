package main

import (
	"bytes"
	"fmt"
	"sort"
	"strings"
	"unicode"
)

func main() {
	analyze(2, TEXT)
}

func analyze(occurence int, text string) {
	text = trim(text)
	words := strings.Split(text, " ")
	count := make(map[string]int)
	for _, word := range words {
		word = clean(word)
		if word != "" {
			count[word] += 1
		}
	}

	result := []string{}
	for word, value := range count {
		if value == occurence {
			result = append(result, word)
		}
	}

	sort.Strings(result)
	for index := range result {
		fmt.Println(result[index])
	}
}

func clean(word string) string {
	word = strings.ToLower(word)
	if word == "endoftext" {
		return ""
	}

	output := new(bytes.Buffer)
	for _, symbol := range word {
		if unicode.IsLetter(symbol) {
			output.WriteRune(symbol)
		}
	}
	return output.String()
}

func trim(text string) string {
	text = strings.Replace(text, "\t", " ", -1)
	text = strings.Replace(text, "\n", " ", -1)
	for {
		newtext := strings.Replace(text, "  ", " ", -1)
		if text == newtext {
			break
		}
		text = newtext
	}
	return strings.TrimSpace(text)
}

const TEXT = `
In practice, the difference between theory and practice is always
greater than the difference between theory and practice in theory.
	- Anonymous
Man will occasionally stumble over the truth, but most of the
time he will pick himself up and continue on.
	- W. S. L. Churchill
EndOfText
`
