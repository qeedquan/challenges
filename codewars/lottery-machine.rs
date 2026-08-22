/*

Your task is to write an update for a lottery machine. Its current version produces a sequence of random letters and integers (passed as a string to the function). Your code must filter out all letters and return unique integers as a string, in their order of first appearance. If there are no integers in the string return "One more run!"

Examples
"hPrBKWDH8yc6Lt5NQZWQ"  -->  "865"
"ynMAisVpHEqpqHBqTrwH"  -->  "One more run!"
"555"                   -->  "5"

*/

fn main() {
    assert_eq!(lottery("hPrBKWDH8yc6Lt5NQZWQ"), "865");
    assert_eq!(lottery("ynMAisVpHEqpqHBqTrwH"), "One more run!");
    assert_eq!(lottery("555"), "5");
}

fn lottery(input: &'static str) -> String {
    let mut output = String::new();
    for symbol in input.chars() {
        match symbol {
            '0'..'9' => {
                if output.find(symbol) == None {
                    output.push(symbol);
                }
            }
            _ => (),
        }
    }
    if output == "" {
        output = format!("One more run!");
    }
    output
}
