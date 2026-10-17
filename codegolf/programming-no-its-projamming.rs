/*

Hopefully not duplicate, but I did not find one.

Challenge
The challenge is to write full program, which compiles (without errors), but, when executed, will not finish the execution till the end, because an error appears during the execution.

Rules
It has to be full program, which is compile-able or interpret-able in such way, that it produces no syntax errors.
You can use any mechanics, which will do something, so that the interpreter of your program kills the program. This includes (but is not limited to): exceptions, overflows, SIGSEGVs. However, asking the interpreter to kill the program explicitly does not count (by calling exit()-like functions).
It may be compiler/OS dependent, as long as it's not using obvious bug in compiler/interpreter. So depending on Undefined behavior in C/C++ is valid, but using version 1.0.17b of language interpreter, which throws random_exception when run is not. If it depends on something, it's good to write so in the answer.
The program will take no input, but it may (or may not) produce any output to STDOUT, or STDERR.
This is code-golf, but it is not about finding the language with least amount of bytes, but to find a least bytes solution in all languages. So I will not accept any answer.

*/

use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();
    let mut value = 1;
    if args.len() >= 2 {
        match args[1].as_str() {
            string => match string.parse::<usize>() {
                Ok(number) => value = number,
                _ => (),
            },
        }
    }
    println!("{}", (value ^ value) % (value & !value));
}
