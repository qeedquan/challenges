/*

Reaching Population Equilibrium
In “The Wright-Fisher Model of Genetic Drift”, we introduced the Wright-Fisher model of genetic drift.
Although the effects of genetic drift are inevitable, we should be able to quantify how many alleles for a given trait will remain in the next generation.

Intuitively, because Wright-Fisher demands that we randomly and independently select alleles for the next generation based off the allele frequency of the present generation,
we would hope that on average this frequency would illustrate a stabilizing effect: that is, the expected frequency in the next generation should equal the allele frequency in the current generation.
In this problem, we will see if the mathematics matches our intuition.

Problem
In “The Wright-Fisher Model of Genetic Drift”, we generalized the concept of a binomial random variable Bin(n,p) as a "weighted coin flip."
It is only natural to calculate the expected value of such a random variable.

For example, in the case of unweighted coin flips (i.e., p=1/2), our intuition would indicate that E(Bin(n,1/2)) is n/2; what should be the expected value of a binomial random variable?

Given: A positive integer n (n≤1000000) followed by an array P of length m (m≤20) containing numbers between 0 and 1.
Each element of P can be seen as representing a probability corresponding to an allele frequency.

Return: An array B of length m for which B[k] is the expected value of Bin(n,P[k]); in terms of Wright-Fisher, it represents the expected allele frequency of the next generation.

Sample Dataset
17
0.1 0.2 0.3

Sample Output
1.7 3.4 5.1

*/

fn main() {
    println!("{:?}", solve(17, &[0.1, 0.2, 0.3]));
}

// The expected value of a binomial random variable X given by X ~ Bin(n,p) has expected value E(X)=n*p.
fn solve(n: usize, p: &[f64]) -> Vec<f64> {
    let mut r = vec![];
    for i in 0..p.len() {
        r.push(n as f64 * p[i]);
    }
    r
}
