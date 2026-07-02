/*

Introduction
The idea is to use the asterisk character (star) * to display an ascii-art star at a specified dimension.
The dimension is an input number greater than or equal to 1 that specifies the height in lines of the upper point of the star.
The stars here are intended to be six pointed stars with larger sizes looking better from a picture perspective.

In all cases the ascii-art representation of the stars are to appear as two triangles that overlap as shown in the following examples.

Parametrics
The following picture and table of data describes attributes for the first seven sizes of the star.
Each of the parameters grows in an arithmetic progression as N increases, except N=1 is different.

https://i.sstatic.net/C6TOV.png
https://i.sstatic.net/IXHK8.png

Examples
For an input of 1 (the degenerate case) the program output should be as follows:

  *
*****
*****
  *
Input of 2:

    *
   ***
*********
 *******
*********
   ***
    *
(3)

       *
      ***
     *****
***************
 *************
  ***********
 *************
***************
     *****
      ***
       *
(5)

             *
            ***
           *****
          *******
         *********
***************************
 *************************
  ***********************
   *********************
    *******************
   *********************
  ***********************
 *************************
***************************
         *********
          *******
           *****
            ***
             *
Challenge
Your task is to create a function or program that will accept the number N as input and then output the appropriately
sized star using just characters and the * character.

You may assume that the input value is always a positive integer.
Trailing whitespace on the output lines is OK.
The program algorithm should be general enough for any N input to produce the star art output.
Practical limitations exist of course due to display output size.
Output should print to STDOUT.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply.

Scoring
This is code-golf so the code with the shortest number of bytes wins!

*/

fn main() {
    for i in 1..=5 {
        stars(i);
    }
}

fn stars(n: isize) {
    println!("n={n}");
    if n < 1 {
        return;
    }

    let mut j = 0;
    if n > 1 {
        j = 2;
    }
    for i in (1..8 * n).step_by(2) {
        let mut s = i;
        if i + j > n * 6 || (i / (n * 2)) % 2 != 0 {
            s = (8 * n) - i - j;
        }

        let p = ((6 * n) - s) / 2;
        for _ in 0..p {
            print!(" ");
        }
        for _ in 0..s {
            print!("*");
        }
        println!();
    }
}
