/*

http://i.imgur.com/tfJ9UWcm.jpg

The image shows how we can obtain the Harmonic Conjugated Point of three aligned points A, B, C.

We choose any point L, that is not in the line with A, B and C. We form the triangle ABL

Then we draw a line from point C that intersects the sides of this triangle at points M and N respectively.

We draw the diagonals of the quadrilateral ABNM; they are AN and BM and they intersect at point K

We unit, with a line L and K, and this line intersects the line of points A, B and C at point D

The point D is named the Conjugated Harmonic Point of the points A, B, C. You can get more knowledge related with this point at: (https://en.wikipedia.org/wiki/Projective_harmonic_conjugate)

If we apply the theorems of Ceva (https://en.wikipedia.org/wiki/Ceva%27s_theorem) and Menelaus (https://en.wikipedia.org/wiki/Menelaus%27_theorem) we will have this formula:

http://i.imgur.com/PfmzXU4.jpg?1

AC, in the above formula is the length of the segment of points A to C in this direction and its value is:

AC = xA - xC

Transform the above formula using the coordinates xA, xB, xC and xD

The task is to create a function harmon_pointTrip(), that receives three arguments, the coordinates of points xA, xB and xC, with values such that : xA < xB < xC, this function should output the coordinates of point D for each given triplet, such that

xA < xD < xB < xC, or to be clearer

let's see some cases:

harmonPointTrip(xA, xB, xC) ------> xD # the result should be expressed as a string with `.toFixed(2)`
harmonPointTrip(2, 10, 20) -----> "7.14" # (2 < 7.14 < 10 < 20, satisfies the constraint)
harmonPointTrip(3, 9, 18) -----> "6.75"

Enjoy it and happy coding!!

*/

fn main() {
    test(2.0, 10.0, 20.0, 7.14);
    test(3.0, 9.0, 18.0, 6.75);
}

fn test(a: f64, b: f64, c: f64, r: f64) {
    let v = harmonic_point_triplet(a, b, c);
    println!("{}", v);
    assert_eq!((v - r).abs() < 1e-2, true);
}

fn harmonic_point_triplet(a: f64, b: f64, c: f64) -> f64 {
    (((a - c) / (b - c)) * b + a) / (1.0 + (a - c) / (b - c))
}
