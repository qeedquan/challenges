/*

Create a public class called Cube without a constructor which gets one single private integer variable Side, a getter GetSide() and a setter SetSide(int num) method for this property.
Actually, getter and setter methods are not the common way to write this code in C#. In the next kata of this series, we gonna refactor the code and make it a bit more professional...

Notes:

There's no need to check for negative values!
initialise the side to 0.

*/

fn main() {
    let mut cube: Cube = Default::default();
    for side in 0..12 {
        println!("{}", cube.get());
        cube.set(side);
    }
}

#[derive(Default)]
struct Cube {
    side: isize,
}

impl Cube {
    fn set(&mut self, side: isize) {
        self.side = side;
    }

    fn get(&self) -> isize {
        self.side
    }
}
