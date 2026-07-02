/*

Screen scraping involves interacting with the terminal display of a currently running program.
There are commercial screen scraping applications available for mainframe programs that provide a web interface on top of a dumb terminal program.

Write a program that will read the following from a text file to simulate the dumb terminal program.
Each line represents a prompt to the user (always ends with a colon).
Input constraints may be available for prompts. If they are, then they will always be surrounded in parentheses.
The accepted input values will always be separated by a comma, and the value that is actually counted will be surrounded in square brackets.

Once you've parsed the text file, convert the data into an HTML form output file.
If the prompt did not have any input constraints, then the input type is just a text.
If the prompt contained input constraints and there are less than 5 options, then the input type are radio buttons.
If there are 5 or more possible input values, then the input type is a dropdown.

Example:

Input File
Name:

Gender ([M]ale, [F]emale):

Position ([C]ashier, [D]eli Clerk, [M]anager, [P]roduce Clerk, [S]tock Person):

Output File (HTML)
<html>

<body>

<form>

Name:

<input type="text" name="name"/>

<br/>

Gender:

<input type="radio" name="gender" value="m"/> Male

<input type="radio" name="gender" value="f"/> Female

<br/>

Position:

<select name="position">

<option value="c">Cashier</option>

<option value="d">Deli Clerk</option>

<option value="m">Manager</option>

<option value="p">Produce Clerk</option>

<option value="s">Stock Person</option>

</select>

<br/>

<input type="submit" value="Submit"/>

</form>

</body>

</html>

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"os"
	"strings"
	"unicode"
	"unicode/utf8"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	parse(flag.Arg(0))
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: file")
	flag.PrintDefaults()
	os.Exit(2)
}

func parse(name string) error {
	file, err := os.Open(name)
	if err != nil {
		fmt.Println(err)
		return err
	}
	defer file.Close()

	fmt.Println("<html>")
	fmt.Println("<body>")
	fmt.Println("<form>")
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		line = strings.TrimSpace(line)
		if line == "" {
			continue
		}

		form := line
		options := []string{}
		paren0 := strings.IndexByte(line, '(')
		paren1 := strings.LastIndexByte(line, ')')
		if !(paren0 < 0 || paren1 < 0 || paren0 >= paren1) {
			form = line[:paren0] + line[paren1+1:]
			form = strings.Replace(form, " ", "", -1)

			fields := line[paren0+1 : paren1]
			options = strings.Split(fields, ",")
			for i := range options {
				options[i] = strings.Replace(options[i], "[", "", -1)
				options[i] = strings.Replace(options[i], "]", "", -1)
				options[i] = strings.TrimSpace(options[i])
			}
		}
		form = strings.TrimSuffix(form, ":")

		fmt.Println(form + ":")
		switch {
		case len(options) == 0:
			fmt.Printf(`<input type="text" name="%s"/>`, strings.ToLower(form))
			fmt.Println()

		case len(options) < 5:
			for _, option := range options {
				first, _ := utf8.DecodeRuneInString(option)
				first = unicode.ToLower(first)
				fmt.Printf(`<input type="radio" name="%s" value="%c"/> %s`, strings.ToLower(form), first, option)
				fmt.Println()
			}

		default:
			fmt.Printf(`<select name="%s">`, strings.ToLower(form))
			fmt.Println()
			for _, option := range options {
				first, _ := utf8.DecodeRuneInString(option)
				first = unicode.ToLower(first)
				fmt.Printf(`<option value="%c">%s</option>`, first, option)
				fmt.Println()
			}
			fmt.Println("</select>")
		}
		fmt.Println("<br/>")
	}
	fmt.Println(`<input type="submit" value="Submit"/>`)
	fmt.Println("</form>")
	fmt.Println("</body>")
	fmt.Println("</html>")

	return nil
}
