/*

This kata is about static method that should return different values.

On the first call it must be 1, on the second and others - it must be a double from previous value.

Look tests for more examples, good luck :)

*/

#[derive(Default)]
struct Number {
    value: u128,
}

impl Number {
    fn next(&mut self) -> u128 {
        if self.value == 0 {
            self.value = 1;
        } else {
            self.value <<= 1;
        }
        return self.value;
    }
}

fn main() {
    let mut number: Number = Default::default();
    for _ in 0..64 {
        println!("{}", number.next());
    }
}
