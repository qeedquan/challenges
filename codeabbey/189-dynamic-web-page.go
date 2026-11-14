/*

Now you have learned creation of static web page and using basic html we are ready to move forward.

Interned would remain only collection of documents if nothing except static pages could be stored. However it is an obvious idea that content sent to user could be generated "on-the-fly" instead being stored in static file. This principle is a cornerstone of building web-applications which render different content depending on user's submissions and state of internal database.

Let us try to create very primitive page which is generated dynamically. We will output random value in it so it is changed every time user loads the page.

In PHP this could be achieved in a simple way:

<?php

echo "Random value is " . rand();
You can store this code in file like simple.php and upload to the server - here is my demo at AwardSpace (currently it seems you can use awardspace.com for free PHP hosting, though control panel could be a bit confusing at first - we use it for "interactive" problems also)

With Python in CGI mode it is only a bit more complicated:

#!/usr/bin/env python

import random

print "Content-Type: text/plain"
print

print "Random value is " + str(random.randint(100000, 999999));
Name it simple.py for example and also try at server. This is what we call "CGI script" and it could be written almost in any language, from C to shell interpreters. Here is my version in KSH at SDF / freeshell.

Important thing to note is that we need to output some "response header" and an empty line before the content of our page. With PHP headers are also sent but you need not print them manually. These headers are some technical info hinting browser about how to render the document. I hope you will read a bit more about them (and HTTP protocol) in wikipedia later.

Note however that with Django or Flask frameworks for Python (e.g. at pythonanywhere.com) this code won't fit - you'd better work by improving template code provided to you by these frameworks in that case.

Problem statement
So you should simply create web-page which generates random values each time it is loaded. To avoid making things too simple we also introduce secret value here - your random numbers should be divisible by this value.

I.e. if you are given secret value of 10 than random values like 1230 and 5240 will do, while 7913 is incorrect. Also please make your random values contain no less than 5 and no more than 8 digits.

Checker for this problem will load your page few times to see it is changing.

Input data will contain a secret value (in range 1000..1999).
Answer should provide an url to your page. Please note that generated output should conform Random value is ##### format.

P.S. please note that for generating random number divisible by secret you don't need to make multiple attempts until you get something suitable. Instead try generating value based upon the secret, just modified in some way with auxiliary random number.

After you solve this exercise, you will be ready to create page which processed user's data as described in task about Query String Parameters.

*/

package main

import (
	"flag"
	"fmt"
	"log"
	"math/rand/v2"
	"net/http"
)

var (
	addr   = flag.String("addr", ":8080", "address to listen on")
	secret = flag.Int("secret", 10, "specify secret value")
)

func main() {
	flag.Parse()
	log.Println("Starting server...")
	http.HandleFunc("/", mainpage)
	check(http.ListenAndServe(*addr, nil))
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func mainpage(w http.ResponseWriter, r *http.Request) {
	value := randn(1e4 / *secret, 1e7 / *secret) * *secret
	fmt.Fprintf(w, "Random value is %d", value)
}

func randn(min, max int) int {
	return rand.N(max-min) + min
}
