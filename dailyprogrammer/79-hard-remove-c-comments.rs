/*

In the C programming language, comments are written in two different ways:

/* ... */: block notation, across multiple lines.

// ...: a single-line comment until the end of the line.

Write a program that removes these comments from an input file, replacing them by a single space character, but also handles strings correctly. Strings are delimited by a " character, and \" is skipped over. For example:

  int /* comment */ foo() { }
→ int   foo() { }

  void/*blahblahblah*/bar() { for(;;) } // line comment
→ void bar() { for(;;) }

  { /*here*/ "but", "/*not here*/
\" /*or here*/" } // strings
→ {   "but", "/*not here*/ \" /*or here*/" }  

*/

use std::io::{stdin, Read};

fn main() {
    uncomment();
}

// ported from @skeeto solution
fn uncomment() {
    let mut quoted = false;
    let mut block = false;
    let mut line = false;
    loop {
        let (mut c, eof) = getchar();
        if eof {
            break;
        }

        if c == '\\' {
            if !block && !line {
                let (nc, _) = getchar();
                print!("{c}{nc}");
            } else if line {
                getchar();
            }
            continue;
        } else if c == '"' {
            quoted = !quoted;
        } else if !quoted && !block && !line && c == '/' {
            let (nc, _) = getchar();
            if nc == '*' {
                block = true;
            } else if nc == '/' {
                line = true;
            } else {
                print!("{c}");
                c = nc;
            }
        } else if !quoted && block && !line && c == '*' {
            let (nc, _) = getchar();
            if nc == '/' {
                block = false;
            }
            c = ' ';
        } else if !quoted && !block && line && c == '\n' {
            line = false;
        }

        if !block && !line {
            print!("{c}");
        }
    }
}

fn getchar() -> (char, bool) {
    let mut handle = stdin().lock();
    let mut byte = [0];
    match handle.read_exact(&mut byte) {
        Err(_) => ('\0', true),
        Ok(_) => (byte[0] as char, false),
    }
}
