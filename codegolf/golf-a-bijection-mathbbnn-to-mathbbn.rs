/*

Your task is to write a program which implements a bijection N^n -> N for n≥1.
Your program should take n natural numbers as input, in any acceptable method (including taking them as a single, n element list/array) and output a unique natural number for all possible inputs.

In layman's terms, a bijection N^n -> N means:

Take n natural numbers as input
Map these n natural numbers to a single natural number output
For every possible input, the output is provably unique
For every possible output, there exists an input which will give that output
For example, the Cantor pairing function π:N^2 -> N is a bijection that takes two natural numbers and maps each pair to a unique natural number.

You may implement whatever bijective function you wish, so long as it is proven to be bijective for all possible inputs. Please include this proof (either directly or through a link) in your answer. This is code-golf so the shortest code, in bytes, wins.

You may decide whether you'd like to use N={1,2,3,…} or N={0,1,2,…}, so long as this is consistent for all n.

*/

fn main() {
    println!("{}", map(&vec![1, 2, 3, 4, 5, 6]));
    println!("{}", map(&vec![10, 4, 3]));
}

/*

@xnor

Uses the pairing function p(a,b)=(2*a+1)*2^b
We use bit-shift <<b to shorten *2**b, and write a-~a to save a byte off of 2*a+1.

lambda l:reduce(lambda a,b:(a-~a<<b)-1,l)

*/

fn pair(a: u128, b: u128) -> u128 {
    (((2 * a) + 1) << b) - 1
}

fn map(x: &Vec<u128>) -> u128 {
    let n = x.len();
    if n == 0 {
        return 0;
    }

    let mut r = x[0];
    for i in 1..n {
        r = pair(r, x[i]);
    }
    return r;
}
