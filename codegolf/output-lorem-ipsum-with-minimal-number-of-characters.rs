/*

I remember people saying that code size should be measured in bytes, and not in characters, because it's possible to store information with weird Unicode characters, which have no visual meaning.

How bad can it be?

In this challenge, you should output the following Lorem Ipsum text, taken from Wikipedia:

Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
Please specify the number of characters (not bytes) in your code. Code with the minimal number of characters wins.

Your code should only contain valid Unicode characters, as described here, that is:

Code points up to U+10FFFF
No surrogates (the range D800–DBFF is forbidden)
No characters FFFE and FFFF
No null characters (code 0)
If your code cannot be displayed, provide a version with offending characters redacted, and a hexdump.

Some notes:

The output must be one long line (445 characters). If your system cannot do that (e.g. you're printing it on paper), output a closest approximation. Trailing linebreaks don't matter.
Built-in functions that generate Lorem Ipsum text are not allowed
Please specify a valid text encoding for your code, if relevant

*/

fn main() {
    println!("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
}
