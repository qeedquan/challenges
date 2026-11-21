/*

Challenge #19 will use The Adventures of Sherlock Holmes from Project Gutenberg.

Write a program that counts the number of alphanumeric characters there are in The Adventures of Sherlock Holmes.
Exclude the Project Gutenberg header and footer, book title, story titles, and chapters.
Post your code and the alphanumeric character count.

*/

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
)

func main() {
	lines, err := load("pg1661.txt")
	check(err)
	lines = filter(lines)
	fmt.Println(count(lines))
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func load(name string) ([]string, error) {
	file, err := os.Open(name)
	if err != nil {
		return nil, nil
	}
	defer file.Close()

	scan := bufio.NewScanner(file)
	lines := []string{}
	for scan.Scan() {
		line := strings.TrimSpace(scan.Text())
		if line != "" {
			lines = append(lines, line)
		}
	}
	return lines, nil
}

func filter(lines []string) []string {
	i := findline(lines, "I.", true)
	j := findline(lines, "*** END", false)
	if i >= 0 && j >= 0 && i < j {
		lines = lines[i+1 : j-1]
	}

	chapters := []string{
		"II.", "III.", "IV.", "V.", "VI.",
		"VII.", "IX.", "X.", "XI.", "XII.",
	}

	result := []string{}
loop:
	for _, line := range lines {
		for _, chapter := range chapters {
			if strings.HasPrefix(lines[i], chapter) {
				continue loop
			}
		}
		result = append(result, line)
	}
	return result
}

func findline(lines []string, prefix string, full bool) int {
	for i := range lines {
		if full && lines[i] == prefix {
			return i
		} else if !full && strings.HasPrefix(lines[i], prefix) {
			return i
		}
	}
	return -1
}

func count(lines []string) int {
	result := 0
	for _, line := range lines {
		for _, char := range line {
			if isalnum(char) {
				result += 1
			}
		}
	}
	return result
}

func isalnum(r rune) bool {
	switch {
	case '0' <= r && r <= '9':
		return true
	case 'a' <= r && r <= 'z':
		return true
	case 'A' <= r && r <= 'Z':
		return true
	}
	return false
}
