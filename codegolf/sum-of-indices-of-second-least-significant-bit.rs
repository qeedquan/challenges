/*

This is a pure code-golf question.

Input: A non-negative integer n

Output: Sum of the indices of the second least significant set bit in the binary representation of the integers 0...n. If the number doesn't have two set bits then the contribution to the sum should be zero.

Your code should be runnable on a standard linux machine using free software and shouldn't take more than n+1 seconds to run.

Sample answers for n from 0..20

0 0 0 1 1 3 5 6 6 9 12 13 16 18 20 21 21 25 29 30
Here is some sample ungolfed python code.

def get_2nd_least_bit(x):
    sum = 0
    for i in range(0,x.bit_length()):
        sum += (x >> i) & 1
        if sum == 2 :
            return i 
    return 0
for x in xrange(20):
    print sum(get_2nd_least_bit(i) for i in xrange(x+1)),

*/

fn main() {
    for x in 0..20 {
        let mut s = 0;
        for i in 0..x + 1 {
            s += lsb2(i);
        }
        print!("{s} ");
    }
    println!();
}

fn lsb2(x: usize) -> usize {
    let mut r = 0;
    for i in 0..usize::BITS {
        r += (x >> i) & 1;
        if r == 2 {
            return i as usize;
        }
    }
    return 0;
}
