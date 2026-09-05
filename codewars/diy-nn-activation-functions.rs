/*

For this task, you'll write four functions:

One that takes in a number and returns the output after it's been passed through the identity function.

One that takes in a number and returns the output after it's been passed through the sigmoid function.

One that takes in a number and returns the output after it's been passed through the ReLu function.

One that takes in a number and returns the output after it's been passed through the leaky ReLu function.

*/

fn main() {
    let n = 10.0;
    let a = 0.4;
    let mut x = -n;
    while x <= n {
        println!(
            "{:.2} {:.2} {:.2} {:.2}",
            identity(x),
            sigmoid(x),
            relu(x),
            leaky_relu(a, x)
        );
        x += 0.1;
    }
}

fn identity(x: f64) -> f64 {
    x
}

fn sigmoid(x: f64) -> f64 {
    1.0 / (1.0 + (-x).exp())
}

fn relu(x: f64) -> f64 {
    x.max(0.0)
}

fn leaky_relu(a: f64, x: f64) -> f64 {
    if x < 0.0 {
        a * x
    } else {
        x
    }
}
