/*

In the Static Web Page problem you learned uploading simple text file to your web-site. Before trying to create Dynamic Web Page let us learn a bit about pages markup.

The video below almost duplicates the following instructions and shows how to create a couple of simple HTML pages from scratch. So you may either read text, or view video - or both :)

You probably have noticed that most of web-pages do not look like a plain text files. That is because they use simple markup language to change the styles and layouts of words, phrases, paragraphs etc. This popular markup language is called HTML. The core idea is that markup "tags" are placed among the content to tell the browser how certain parts of text should be rendered. These tags are short words enclosed in angular brackets. Most of tags are paired - they have opening and closing tag. Let us see an example:

In this sentence <b>few words are emphasized</b>
If you create the file with such content (name it simple.html for example) and load in your browser, you will see that words between <b> tags are bold. Note that closing tag has a slash prepending the letters.

Let us see a bit larger example:

In this text <b>some words are emphasized</b> and
few <i>others are italicised</i>, while we can
also <u>underline some of them</u>.
You may find the result at http://jsfiddle.net/3c72o9ts/ - at bottom-right corner - note that JsFiddle is a convenient tool to demonstrate some principles of web-page layout.

You may see from this example how different tags affect the text. Also note that line ends are not preserved in the output. Tags like <p>...</p> should be used to create paragraph or <br/> to insert line break manually.

Now your goal is to create a page with the following content:

<html>
    <head>
        <title>Basics of HTML demo</title>
    </head>
    <body>
        <p>Secret value is <b>######</b>.</p>
        <p>Read more at
            <a href="http://www.codeabbey.com/index/task_view/basics-of-html">this task</a>.
        </p>
    </body>
</html>
You should see something like this page and you may notice the effect of these tags:

"Baics of HTML demo" becomes the title of the page (shown at the title bar or as the tab name);
secret value itself is printed in bold;
there are two paragraphs (though very short) thanks to <p> tags;
the <a> tag with href="..." attribute allows to create a hyperlink to other web page.
So please create and upload such file (using the secret value given at input data). You need not care about precise indentation and similar things - we are going to check only few features of your page.

Input data will give you a secret value.
Answer should provide the URL to your page (please use http: url instead of https:).

Example:

input data:
314159

answer:
http://codeabbey.github.io/data/simple.html

*/

package main

import (
	"flag"
	"fmt"
	"log"
	"net/http"
)

var (
	addr   = flag.String("addr", ":8080", "address to listen on")
	secret = flag.String("secret", "314159", "specify secret value")
)

func main() {
	flag.Parse()
	log.Println("Starting server...")
	http.HandleFunc("/data/simple.html", mainpage)
	check(http.ListenAndServe(*addr, nil))
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

const html = `
<html>
    <head>
        <title>Basics of HTML demo</title>
    </head>
    <body>
        <p>Secret value is <b>%s</b>.</p>
        <p>Read more at
            <a href="http://www.codeabbey.com/index/task_view/basics-of-html">this task</a>.
        </p>
    </body>
</html>
`

func mainpage(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, html, *secret)
}
