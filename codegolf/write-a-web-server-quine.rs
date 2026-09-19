/*

Write a program that accepts HTTP requests on any port of your choice above 1024, and responds to requests on any URL of your choice with its own source code. It must work with, at least, Firefox and Chrome. The code should be delivered as text/plain (removed requirement because none of the answers but one met it) with no formatting. There is no restriction on the URL, except that it must not be used to encode any portion of the code; serving on the root is encouraged and likely the shortest solution, but is not required.

Standard quine restrictions apply. Web server frameworks are allowed, but are considered separate languages, so, for example, a Python + Flask answer does not compete with a stdlib-only Python answer.

Bonus for HTTPS support:

HTTPS	HTTP	Bonus
No	Yes	None
Yes	No	10%
Yes	Yes	15%
Yes	Redirects to HTTPS	20%
If you do include HTTPS support, you may access the certificate by any reasonable means.

*/

use {io::*, std::*};

// ported from @jan solution
fn main() {
    write!(
        net::TcpListener::bind("127.0.0.1:8080")
            .unwrap()
            .accept()
            .unwrap()
            .0,
        r"HTTP/1.1 200
Content-Type:text/plain
Content-Length:373

{1}{1}{}",
        "\x22#);}",
        r#"use{std::*,io::*};fn main(){write!(net::TcpListener::bind("127.0.0.1:8080").unwrap().accept().unwrap().0,r"HTTP/1.1 200
Content-Type:text/plain
Content-Length:373

{1}{1}{}","\x22#).ok();}",r#""#
    ).ok();
}
