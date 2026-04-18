/*

Given the coefficients of a polynomial from degree 8 down to 0, you are to format the polynomial in a
readable format with unnecessary characters removed. For instance, given the coefficients 0, 0, 0, 1, 22,
-333, 0, 1, and -1, you should generate an output line which displays x^5 + 22x^4 - 333x^3 + x - 1.
The formatting rules which must be adhered to are as follows:
1. Terms must appear in decreasing order of degree.
2. Exponents should appear after a caret “^”.
3. The constant term appears as only the constant.
4. Only terms with nonzero coefficients should appear, unless all terms have zero coefficients in
which case the constant term should appear.
5. The only spaces should be a single space on either side of the binary + and − operators.
6. If the leading term is positive then no sign should precede it; a negative leading term should be
preceded by a minus sign, as in -7x^2 + 30x + 66.
7. Negated terms should appear as a subtracted unnegated term (with the exception of a negative
leading term which should appear as described above). That is, rather than x^2 + -3x, the
output should be x^2 - 3x.
8. The constants 1 and -1 should appear only as the constant term. That is, rather than -1x^3 + 1x^2 + 3the output should appear as -x^3 + x^2 + 3x - 1.

Input
The input file will contain one or more lines of coefficients delimited by one or more spaces. There are
nine coefficients per line, each coefficient being an integer with a magnitude of less than 1000.

Output
The output file should contain the formatted polynomials, one per line.

Sample Input
0 0 0 1 22 -333 0 1 -1
0 0 0 0 0 0 -55 5 0

Sample Output
x^5 + 22x^4 - 333x^3 + x - 1
-55x^2 + 5x

*/

fn main() {
    poly([-1, 1, 0, -333, 22, 1, 0, 0, 0]);
    poly([0, 5, -55, 0, 0, 0, 0, 0, 0]);
}

fn poly(mut p: [isize; 9]) {
    let mut f = true;
    for i in (0..p.len()).rev() {
        if p[i] != 0 {
            if f {
                f = false;
            } else {
                if p[i] > 0 {
                    print!(" + ");
                } else {
                    print!(" - ");
                    p[i] = -p[i];
                }
            }

            if i > 0 && p[i] == -1 {
                print!("-");
            } else if i == 0 || p[i] != 1 {
                print!("{}", p[i]);
            }

            if i != 0 {
                print!("x");
                if i > 1 {
                    print!("^{}", i);
                }
            }
        } else if f && i == 0 {
            print!("0");
        }
    }
    println!();
}
