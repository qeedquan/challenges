/*

This question has been spreading like a virus in my office. There are quite a variety of approaches:

Print the following:

        1
       121
      12321
     1234321
    123454321
   12345654321
  1234567654321
 123456787654321
12345678987654321
 123456787654321
  1234567654321
   12345654321
    123454321
     1234321
      12321
       121
        1

Answers are scored in characters with fewer characters being better.

*/

fn main() {
    diamond();
}

fn diamond() {
    let n = 9isize;
    for i in (-n + 1..n).rev() {
        let l = i.abs();
        for _ in 0..l {
            print!(" ");
        }

        let m = n + 1 - l;
        for j in 1..m {
            print!("{}", j);
        }
        for j in (1..m - 1).rev() {
            print!("{}", j);
        }
        println!();
    }
}
