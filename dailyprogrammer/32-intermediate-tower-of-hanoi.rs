/*

Tower of Hanoi is a famous problem.

the challenge today is a very famous one where you are to write a function to calculate the total number of moves to solve the tower in fastest way possible

*/

fn main() {
    hanoi(2);
    hanoi(5);
}

fn hanoi(pegs: isize) {
    println!("{pegs}");
    recurse(pegs, "A", "B", "C");
    println!();
}

fn recurse(pegs: isize, source: &'static str, destination: &'static str, spare: &'static str) {
    if pegs > 0 {
        recurse(pegs - 1, source, spare, destination);
        println!("{source} -> {destination}");
        recurse(pegs - 1, spare, destination, source);
    }
}
