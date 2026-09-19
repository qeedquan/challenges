/*

Whilst trying to golf several of my answers, I've needed to write large integers in as few characters as possible.

Now I know the best way to do that: I'll be getting you to be writing this program.

The challenge
Write a program that when given a positive integer, outputs a program that prints it to stdout or equivalent.
The output programs don't have to be in the same language as the creator.
The output must be at most 128 bytes.
You may accept input from stdin or equivalent (not function input)
You may output the resulting program to stdout or equivalent.
The number output must be in decimal (base 10)

Scoring
Your score is equal to the smallest positive integer your program can not encode.

The entry with the largest score wins.

*/

use std::env;

fn main() {
    println!("fn main() {{");
    let mut argc = 0;
    for argv in env::args() {
        if argc != 0 {
            println!("\tprintln!(\"{}\");", argv);
        }
        argc += 1;
    }
    println!("}}");
}
