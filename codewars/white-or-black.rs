/*

Complete the function that returns the color of the given square on a normal, 8x8 chess board:

https://i.imgur.com/aM0oVWW.png

Examples
"a", 8  ==>  "white"
"b", 2  ==>  "black"
"f", 5  ==>  "white"

*/

fn main() {
    assert_eq!(color('a', 8), "white");
    assert_eq!(color('b', 2), "black");
    assert_eq!(color('f', 5), "white");
}

fn color(file: char, rank: u32) -> &'static str {
    let column = (file as u32) - 96;
    if (rank & 1) == (column & 1) {
        return "black";
    }
    return "white";
}
