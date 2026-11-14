/*

Input

A list of words separated by any number of spaces.

Output

A horizontal ASCII art graph, where the n-th line is composed by as many asterisks (*) as the n-th word is long.

Example usage

The > signals user input, you should not input it when testing the program.

> This is an example histogram of word length
****
**
**
*******
*********
**
****
******
> a aa aaa aaaa aaaaa
*
**
***
****
*****
> double space  example
******
*****
*******
Reference implementation

In case of doubt over the specification, the output of your program should match exactly that of the below program under all inputs.

puts gets.chomp.split.map{|word| '*' * word.length}.join("\n")

*/

fn main() {
    graph("This is an example histogram of word length");
    graph("a aa aaa aaaa aaaaa");
    graph("double space  example");
}

fn graph(s: &'static str) {
    let s = s
        .trim()
        .split(' ')
        .filter(|s| !s.is_empty())
        .collect::<Vec<_>>()
        .join(" ");

    println!("> {}", s);
    for t in s.split(" ") {
        for _ in 0..t.len() {
            print!("*");
        }
        println!();
    }
    println!();
}
