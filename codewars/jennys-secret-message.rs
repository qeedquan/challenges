/*

Jenny has written a function that returns a greeting for a user. However, she's in love with Johnny, and would like to greet him slightly different. She added a special case to her function, but she made a mistake.

Can you help her?

*/

fn main() {
    assert_eq!(greet("Jim"), "Hello, Jim!");
    assert_eq!(greet("Jane"), "Hello, Jane!");
    assert_eq!(greet("Simon"), "Hello, Simon!");
    assert_eq!(greet("Johnny"), "Hello, my love!");
}

fn greet(name: &'static str) -> String {
    if name == "Johnny" {
        return format!("Hello, my love!");
    }
    return format!("Hello, {name}!");
}
