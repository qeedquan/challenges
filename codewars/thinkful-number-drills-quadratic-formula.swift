/*

Remember all those quadratic equations you had to solve by hand in highschool? Well, no more! You're going to solve all the quadratic equations you might ever[1] have to wrangle with in the future once and for all by coding up the quadratic formula to handle them automatically.

Write a function quadratic_formula() that takes three arguments, a, b, and c that represent the coefficients in a formula of the form ax^2 + bx + c = 0. Your function shoud return a list with two elements where each element is one of the two roots. If the formula produces a double root the result should be a list where both elements are that value.

For example, quadraticFormula(2, 16, 1) should return the list [-0.06299606299409444, -7.937003937005906].

The order of the roots is not important.

[1] Well, not ever ever. You don't need to worry about getting quadratic equations with complex roots where you need the square root of a negative number. All the test cases will be for equations with real roots.

*/

func quadratic(_ a: Double, _ b: Double, _ c: Double) -> (Double, Double) {
    let d = (b * b) - (4 * a * c)
    let sd = d.squareRoot()
    let r0 = (-b + sd) / (2 * a)
    let r1 = (-b - sd) / (2 * a)
    return (r0, r1)
}

print(quadratic(2, 16, 1))
