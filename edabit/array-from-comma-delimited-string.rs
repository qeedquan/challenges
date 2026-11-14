/*

Write a function that turns a comma-delimited list into an array of strings.

Examples
toArray("watermelon, raspberry, orange")
➞ ["watermelon", "raspberry", "orange"]

toArray("x1, x2, x3, x4, x5")
➞ ["x1", "x2", "x3", "x4", "x5"]

toArray("a, b, c, d")
➞ ["a", "b", "c", "d"]

toArray("")
➞ []

Notes
Return an empty array for an empty string.

*/

fn main() {
    assert_eq!(csv2vec("watermelon, raspberry, orange"), vec!["watermelon", "raspberry", "orange"]);
    assert_eq!(csv2vec("x1, x2, x3, x4, x5"), vec!["x1", "x2", "x3", "x4", "x5"]);
    assert_eq!(csv2vec("a, b, c, d"), vec!["a", "b", "c", "d"]);
    assert_eq!(csv2vec(""), Vec::<&str>::new());
}

fn csv2vec(string: &'static str) -> Vec<&str> {
    let mut result = vec![];
    for token in string.split(",") {
        let value = token.trim();
        if value != "" {
            result.push(value);
        }
    }
    result
}
