#!/usr/bin/env python3

"""

So, normally, this is a forbidden loophole to fetch the desired output from an external source. But this challenge is an exception ! In this challenge you will have to fetch data from the internet and output it to the SDTOUT.

The task
For the purpose of this challenge, you'll be the owner of the imaginary a.pi domain!
You will need to take the first argument from STDIN, pass it to a.pi/{arg}, and print the result to STDOUT.
You don't need to handle errors, the server is always up and running !
This is a code-golf, the winner is the shortest (in bytes or equivalent) valid answer.

Rules
You are allowed to invoke curl and wget [1] commands as child/sub-processes (like child_process with NodeJS).
The ressource at a.pi will only be available in the http and https protocol in their default ports (80 and 443 respectively), you don't need to include the http:// if your language allow to ommit it.
Only the desired output (http response) should be printed, nothing else (no GET http://a.pi/: or whatever).
The input might contain spaces or otherwise reserved characters, and need to be percent-encoded.
Spaces ( ) should be replaced with %20 and % with %25 (As spaces cannot be in URLs). The other characters (including reserved ones) don't need to be encoded, but you can encode them (including unreserved characters) if that makes your code shorter.
If your language/environement doesn't have a STDIN/STDOUT (like in a browser), the shortest equivalent can be used (like prompt() and alert() in javascript).
The CORS Headers are open for any external requests (Access-Control-Allow-Origin: *), if you where wondering.
Note: to test your program, you can use any domain and then replace it with a.pi for the submission.

[1] While it should works the same everywhere, I'd recommend you to precise which OS you used for testing.

Updates
Rule 4 have been modified as it was the hardest part is the percent-encoding, which is already a submitted code golf, and the exact rules of the encoding where unclear.

Note: this the first code-golf challenge that I submit, and I didn't knew about the sandbox before. In the future, I'll definitely post here before submitting.
Also, this change doesn't affect previous entries (Except for their length).

"""

import urllib.request
import sys

def fetch(link):
    url = "http://a.pi/%s" % (link)
    req = urllib.request.urlopen(url)
    print(req.read())

def main():
    if len(sys.argv) < 2:
        print("usage: <link>")
        exit(2)
    fetch(sys.argv[1])

main()
