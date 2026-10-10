/*

I have made a short script that will pull dns txt records down from a server and combine them into a single string. DNS txt records are:

1.website.com 2.website.com 3.website.com

Each of these are iterated through using the single digit number.
The double quotes at the beginning and the end of the strings are trimmed
This works exactly as I would like it too I am simply interested in seeing how short I can get it

$i = 1
1..2 | foreach {
$w="$i.website.com"
sv -N v -Va ((nslookup -q=txt $w )[-1]).Trim().Trim('"')
$p += "$v"
$i += 1
}
and ideally I'd like to return the $p variable, that being the concatenated string

this is what I ended getting it down to

1..2|%{$p+=Resolve-DnsName "$_.website.com." -Ty TXT -EA 0|% S*s};powershell .($p)

*/

package main

import (
	"flag"
	"fmt"
	"log"
	"net"
	"os"
)

func main() {
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	for _, url := range flag.Args() {
		txts, err := net.LookupTXT(url)
		if err != nil {
			log.Printf("%v: %v\n\n", url, err)
			continue
		}

		fmt.Printf("%v\n", url)
		for _, txt := range txts {
			fmt.Printf("%v\n", txt)
		}
		fmt.Println()
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <url> ...")
	flag.PrintDefaults()
	os.Exit(2)
}
