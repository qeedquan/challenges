/*

Create a parser to interpret and execute the Deadfish language.

Deadfish operates on a single value in memory, which is initially set to 0.

It uses four single-character commands:

i: Increment the value
d: Decrement the value
s: Square the value
o: Output the value to a result array
All other instructions are no-ops and have no effect.

Examples
Program "iiisdoso" should return numbers [8, 64].
Program "iiisdosodddddiso" should return numbers [8, 64, 3600].

*/

fn main() {
    assert_eq!(interpret("iiisdoso"), vec![8, 64]);
    assert_eq!(interpret("iiisdosodddddiso"), vec![8, 64, 3600]);
}

fn interpret(code: &'static str) -> Vec<isize> {
    let mut mem = vec![];
    let mut acc = 0;
    for op in code.chars() {
        match op {
            'i' => acc += 1,
            'd' => acc -= 1,
            's' => acc *= acc,
            'o' => mem.push(acc),
            _ => (),
        }
    }
    mem
}
