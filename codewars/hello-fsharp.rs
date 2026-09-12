/*

Your task is to write function hello that will take an option type of string.

Function should return "Hello World" if None is passed otherwise it should return "Hello, " + given string.

*/

fn main() {
    println!("{}", hello(Some("John")));
    println!("{}", hello(None));
}

fn hello(name: Option<&'static str>) -> String {
    match name {
        Some(value) => format!("Hello, {}", value),
        None => format!("Hello World"),
    }
}
