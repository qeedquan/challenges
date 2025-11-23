/*

Task
Implement a function that takes an unsigned 32 bit integer as input and sorts its bytes in descending order, returning the resulting (unsigned 32 bit) integer.

An alternative way to state the problem is as follows: The number given as input is made up of four bytes. Reorder these bytes so that the resulting (unsigned 32 bit) integer is as large as possible.

Example
Input: 3735928559
  
3735928559 is 0xdeadbeef in hexadecimal representation and 11011110 10101101 10111110 11101111
in binary representation.
  
After sorting the bytes in descending order the resulting unsigned 32 bit integer is 4024352429 
in decimal representation, which is 0xefdebead in hexadecimal and 11101111 11011110 10111110 10101101
in binary.

Output should be: 4024352429

*/

fn main() {
    assert_eq!(sortbytes(3735928559), 4024352429);
}

fn sortbytes(x: u32) -> u32 {
    let mut b = x.to_le_bytes();
    b.sort();
    u32::from_le_bytes(b)
}
