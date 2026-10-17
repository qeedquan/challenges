/*

This is the simple version of Shortest Code series. If you need some challenges, please try the challenge version

Task
John reading a book, When he met a word that he had never read, he will read the word spelling, each letter(not for punctuation,number, only letter) takes 1 second; If he have read the word, he will read the word, each word takes 1 second.

Give you a parameter words(Each word is separated by space)

Return a number that how many seconds John can finish reading.

Example:
sc("Hello World!")=10
John read all the word spelling.

sc("black cat and white cat all are cat")=24
John read the 2nd 'cat' and 3rd 'cat' used 2 seconds.

sc("black Cat and white cat all are cat")=24
'Cat' and 'cat' are same words,your code should ignore the case

words1="Related Articles: Ruby Environment, CoffeeScript Environment, JavaScript Environment, Python Environment, Haskell Environment, Java Environment, Clojure Environment, .NET Environment."
sc(words1)=86

words2="Related Articles: Ruby Environment, Coffee Script Environment, Java Script Environment, Python Environment, Haskell Environment, Java Environment, Clojure Environment, .NET Environment."
sc(words2)=78
CoffeeScript is one word, Coffee Script are two words

*/

package main

import (
	"bytes"
	"strings"
	"unicode"
)

func main() {
	assert(sc("Hello World!") == 10)
	assert(sc("black cat and white cat all are cat") == 24)
	assert(sc("black Cat and white cat all are cat") == 24)
	assert(sc("Related Articles: Ruby Environment, CoffeeScript Environment, JavaScript Environment, Python Environment, Haskell Environment, Java Environment, Clojure Environment, .NET Environment.") == 86)
	assert(sc("Related Articles: Ruby Environment, Coffee Script Environment, Java Script Environment, Python Environment, Haskell Environment, Java Environment, Clojure Environment, .NET Environment.") == 78)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sc(words string) int {
	seen := make(map[string]bool)
	duration := 0
	for _, word := range strings.Split(words, " ") {
		word = filter(word)
		if seen[word] {
			duration += 1
		} else {
			duration += len(word)
			seen[word] = true
		}
	}
	return duration
}

func filter(word string) string {
	output := new(bytes.Buffer)
	for _, symbol := range word {
		if unicode.IsLetter(symbol) {
			output.WriteRune(unicode.ToLower(symbol))
		}
	}
	return output.String()
}
