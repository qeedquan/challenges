/*

Quantum mechanics tells us that a molecule is only allowed to have specific, discrete amounts of internal energy. The 'rigid rotor model', a model for describing rotations, tells us that the amount of rotational energy a molecule can have is given by:

E =  B * J * (J + 1),

where J is the state the molecule is in, and B is the 'rotational constant' (specific to the molecular species).

Write a function that returns an array of allowed energies for levels between Jmin and Jmax.

Notes:

return empty array if Jmin is greater than Jmax (as it make no sense).
Jmin, Jmax are integers.
physically B must be positive, so return empty array if B <= 0

*/

fn main() {
    println!("{:?}", rotational_energies(2.0, 0, 10));
}

#[allow(non_snake_case)]
fn rotational_energies(B: f64, Jmin: isize, Jmax: isize) -> Vec<f64> {
    if B <= 0.0 {
        return vec![];
    }

    let mut R = vec![];
    for Ji in Jmin..Jmax + 1 {
        let J = Ji as f64;
        let E = B * J * (J + 1.0);
        R.push(E);
    }
    R
}
