/*

This is a simple web frontend and web server (CGI, PHP, servlet, server component, etc.) exercise. Write a web frontend that contains a text area and button. Then write a program that accepts the contents of the text area and writes them out to a file. When the user clicks the button, the submission of the content can be either form-based, AJAX-based, or even websockets-based.

You can complete this project in several ways. You can write up the HTML yourself and submit the form to a program written in C/C++, Perl, Python, PHP, etc. You can do all the work in Javascript and hit a server using Node.js. You can also show off how easy it is to do this project using a Java/Python/Ruby/etc. web framework.

*/

package main

import (
	"flag"
	"fmt"
	"log"
	"math/rand"
	"net/http"
	"os"
)

var (
	addr = flag.String("addr", ":8080", "address to listen on")
)

func main() {
	flag.Parse()
	log.Println("Starting server...")
	http.HandleFunc("/", mainpage)
	http.HandleFunc("/text", textpage)
	check(http.ListenAndServe(*addr, nil))
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

const html = `
<html>
	<title>Text Form</title>
	<body>
		<form action="text" method="POST">
			<textarea name="mytext" rows="25" cols="80" id="mytext"></textarea>
			<br />
			<input type="submit" value="Submit" />
		</form>
	</body>
</html>
`

func mainpage(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintln(w, html)
}

func textpage(w http.ResponseWriter, r *http.Request) {
	err := r.ParseForm()
	if err != nil {
		log.Println(err)
		return
	}

	name := fmt.Sprintf("text_%d.txt", rand.Int())
	text := r.Form["mytext"]
	if len(text) == 0 {
		log.Println("No text detected")
		return
	}
	err = os.WriteFile(name, []byte(text[0]), 0644)
	if err != nil {
		log.Println(err)
		return
	}

	fmt.Fprintf(w, "Saved text data to file: %s\n", name)
}
