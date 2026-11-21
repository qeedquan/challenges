/*

A bit-counting comparator (BCC) is a logic circuit that takes some number of counting inputs A1, A2, A3, ..., An as well as inputs B1, B2, B4, B8, ... representing a number. It then returns 1 if the total number of A inputs that are on is greater than the number represented in binary by the B inputs (e.g. B1, B2, and B8 would make the number 11), and 0 otherwise.

For example, for a bit-counting comparator that takes 5 inputs, of which A2, A4, A5, and B2 are set to 1, will return 1 because there are 3 A inputs that are on, which is greater than 2 (the number represented by only B2 being on).

Your task is to create a bit-counting comparator that takes a total of 16 A inputs and 4 B inputs (representing bits from 1 to 8), using only two-input NAND gates, and using as few NAND gates as possible. To simplify things, you may use AND, OR, NOT, and XOR gates in your diagram, with the following corresponding scores:

NOT: 1
AND: 2
OR: 3
XOR: 4
Each of these scores corresponds to the number of NAND gates that it takes to construct the corresponding gate.

The logic circuit that uses the fewest NAND gates to produce a correct construction wins.

*/

#![allow(non_snake_case)]

fn main() {
    let mut A = vec![0; 16];
    let mut B = vec![0; 4];
    for a in 0usize..=0xffff {
        for b in 0usize..=0xf {
            cir(a, &mut A);
            cir(b, &mut B);
            assert_eq!(a.count_ones() as usize > b, bcc(&A, &B));
        }
    }
}

fn bcc(A: &Vec<usize>, B: &Vec<usize>) -> bool {
    let (mut n, mut m) = (0, 0);
    for i in 0..A.len() {
        if A[i] != 0 {
            n += 1;
        }
    }
    for i in 0..B.len() {
        if B[i] != 0 {
            m |= 1 << i;
        }
    }
    n > m
}

fn cir(x: usize, r: &mut Vec<usize>) {
    for i in 0..r.len() {
        r[i] = 0;
        if x & (1 << i) != 0 {
            r[i] = 1;
        }
    }
}
