/*

On Christmas, in the evening, there were three flowers on the window, from left to right: geranium, crocus, and violet.
Every morning, Mariyka cleans the window and swaps the rightmost flower with the central one.
In the evening, Tetianka waters the flowers and swaps the leftmost flower with the central one.
Determine the order of the flowers after k days, at night.

Input
The first line contains the number of test cases t (1≤t≤12). Each of the following t lines contains an integer k (1≤k≤1000).

Output
For each test case, print a line containing three Latin capital letters: "G", "C", and "V" (without spaces),
representing the order of the flowers after k days (from left to right).
Here, G stands for geranium, C for crocus, and V for violet.

Examples

Input #1
2
1
5

Answer #1
VGC
CVG

*/

fn main() {
    assert_eq!(solve(1), "VGC");
    assert_eq!(solve(5), "CVG");
}

fn solve(n: isize) -> &'static str {
    match n % 3 {
        1 => "VGC",
        2 => "CVG",
        _ => "GVC",
    }
}
