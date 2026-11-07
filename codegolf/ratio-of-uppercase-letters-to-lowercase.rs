/*

In this challenge you and your friends are debating on which case is better, uppercase or lowercase? To find out, you write a program to do this for you.

Because esolangs scare your friends, and verbose code scares you, your code will need to be as short as possible.

Examples
PrOgRaMiNgPuZzLeS & CoDe GoLf
0.52 uppercase

DowNGoAT RiGHtGoAt LeFTGoat UpGoAT
0.58 uppercase

Foo BaR Baz
0.56 lowercase
Specifications
The input will consist only of ASCII characters. All non-alphabetic characters should be ignored. There will be at least 1 character of each case

The output should be the amount of the case that appears the most often over the total amount of alphabetic characters. It should be a decimal accurate to at least 2 decimal places. If uppercase appears more often, the output should end with uppercase, or lowercase.

There will never the the same amount of uppercase and lowercase characters.

*/

fn main() {
    assert_eq!(ratio("PrOgRaMiNgPuZzLeS & CoDe GoLf"), "0.52 uppercase");
    assert_eq!(
        ratio("DowNGoAT RiGHtGoAt LeFTGoat UpGoAT"),
        "0.58 uppercase"
    );
    assert_eq!(ratio("Foo BaR Baz"), "0.56 lowercase");
}

fn ratio(s: &'static str) -> String {
    let (mut u, mut t) = (0.0, 0.0);
    for c in s.chars() {
        if c.is_ascii_uppercase() {
            u += 1.0;
            t += 1.0;
        } else if c.is_ascii_lowercase() {
            t += 1.0;
        }
    }

    let l = t - u;
    if u >= l {
        format!("{:.2} uppercase", u / t)
    } else {
        format!("{:.2} lowercase", l / t)
    }
}
