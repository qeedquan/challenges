/*

Yet another Brainfuck parsing problem, but this time... different.

You are working in the Infinite Monkeys Incorporated, the company making Brainfuck programs, to solve various interesting problems (by accident, no less - after all, the company makes random programs). However, it appears that your fast Turing machines that only execute Brainfuck have a small and expensive problem with syntax errors - make one, and the computer explodes. It's probably a design flaw, but nobody had bothered to find why it happens.

As Turing machines (especially fast ones) are expensive (after all, they have infinity RAM which costs), it would be better to make sure that the program doesn't have any syntax errors before executing the code. Your company is going to run lots of code, so manual verification won't work. Write a program that reads the STDIN for Brainfuck code, and exits with exit status set to anything other than 0 (error) if program has any syntax error (for example, ] is a syntax error, because there is no matching [). Exit with exit status set to 0 if the program is completely fine.

Make sure that your program correctly notices mistakes involving []. You wouldn't want another computer to explode, would you? Oh, and make sure it's as short as possible - your boss pays for short programs (because he thinks they are fast, or something). Oh, and you don't have to code in Brainfuck (in fact, you cannot, because Brainfuck doesn't support exit codes) - your code will be ran on normal computer.

So, as you can see, your job is to check if Brainfuck program is "valid" (has paired [] symbols). Please note that Brainfuck programs can have other characters than [], so don't refuse the program just because it has other commands. Smallest code wins, but probably you would care more about upvotes anyway.

*/

use std::io::*;
use std::process::*;

fn main() {
    if verify(stdin().lock()) {
        exit(0);
    } else {
        exit(1);
    }
}

fn verify(mut stream: StdinLock<'static>) -> bool {
    let mut byte = [0_u8];
    let mut count = 0;
    loop {
        let result = stream.read_exact(&mut byte);
        if !result.is_ok() {
            break;
        }
        if byte[0] == b'[' {
            count += 1;
        } else if byte[0] == b']' {
            count -= 1;
        }
    }
    count == 0
}
