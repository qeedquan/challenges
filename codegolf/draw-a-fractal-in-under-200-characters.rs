/*

After noticing all the fractal submissions/questions, I thought it would be fun to start a contest where everyone submits their favourite fractal.

The Contest

Generate a fractal in under 200 characters using any language. The output of the function can be an image, ascii art or any representation of a fractal you can think of. In your submission include your code, how to run your code, and sample outputs of your fractal. This is a popularity contest, so the submission with the most votes wins.

Rules

You may use any libraries, except those which generate fractals (e.g. a library function that generates a mandelbrot set is not allowed)
It is difficult to define a true fractal, so I will accept anything that has self-similarity and has fractal dimension greater than its topological dimension
You may submit multiple answers
Good luck, have fun!

*/

use std::cmp::*;

fn main() {
    sierpinski(1024, 1024);
}

// ported from @Beta Decay solution
fn sierpinski(w: isize, h: isize) {
    println!("P3");
    println!("{w} {h} 255");
    let s = 16;
    for y in 0..h {
        for x in 0..w {
            let c = min((y * s) & (x * s), 255);
            println!("{c} {c} {c}");
        }
    }
}
