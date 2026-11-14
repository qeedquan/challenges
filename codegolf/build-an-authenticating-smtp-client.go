/*

The basic parts of SMTP can be implemented in surprising little code. I was able to build an example SMTP client that works with Gmail and Amazon SES in about 320 characters using PHP.

Your task is to implement an SMTP client that can send UTF-8 email from at least 2 major providers listed here:

Gmail
Yahoo!
Live/Hotmail
Postmark
Amazon SES
Keep in mind that most require SSL support. Some SMTP services (like Amazon) require different SMTP Auth and From addresses. Your function can take input for the actual data transmitted. After all, it woudn't make sense to hard-code anything into the transport layer.

SMTP User
SMTP Password
SMTP Host
SMTP Port
DATA (message)
From email
To email
Sample DATA (message)

Subject: =?UTF-8?B?VGVzdCBFbWFpbA==?=\r\n
To: <him@gmail.com>\r\n
From: <you@gmail.com>\r\n
MIME-Version: 1.0\r\n
Content-Type: text/html; charset=utf-8\r\n
Content-Transfer-Encoding: base64\r\n\r\n
PGgxPlRlc3QgRW1haWw8L2gxPjxwPkhlbGxvIFRoZXJlITwvcD4=\r\n.

In Summary
Build an SMTP client that can send email through at least two of the services above.
Accepts the seven inputs needed to form a valid SMTP Auth request (above). (Might only need six inputs if you combine the "From" and "SMTP User" inputs).
Use as few characters as posible.

*/

package main

import (
	"flag"
	"fmt"
	"log"
	"net/smtp"
	"os"
)

var flags struct {
	sender    string
	recipient string
	message   string
	server    string
}

func main() {
	parseflags()

	conn, err := smtp.Dial(flags.server)
	check(err)

	err = conn.Mail(flags.sender)
	check(err)

	err = conn.Rcpt(flags.recipient)
	check(err)

	writer, err := conn.Data()
	check(err)

	_, err = fmt.Fprintf(writer, flags.message)
	check(err)

	err = writer.Close()
	check(err)

	err = conn.Quit()
	check(err)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <server>")
	flag.PrintDefaults()
	os.Exit(2)
}

func parseflags() {
	flag.StringVar(&flags.sender, "sender", "sender@example.org", "specify sender")
	flag.StringVar(&flags.recipient, "recipient", "recipient@example.net", "specify recipient")
	flag.StringVar(&flags.message, "message", "This is a test message", "specify message to send")

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}
	flags.server = flag.Arg(0)
}
