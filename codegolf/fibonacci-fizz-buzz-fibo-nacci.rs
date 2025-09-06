/*

Fibonacci + FizzBuzz = Fibo Nacci!

Your challenge is to create a Fibo Nacci program!
A Fibo Nacci program outputs the first 100 Fibonacci numbers (starting from 1).
If the Fibonacci number is divisible by both 2 and 3 (i.e. it is divisible by 6), then output FiboNacci instead of the number.
Otherwise, if the Fibonacci number is divisible by 2, then output Fibo instead of the number.
Otherwise, if the Fibonacci number is divisible by 3, then output Nacci instead of the number.
Rules
The program should take no input.
The program should output a new line (\n) after every entry.
The program should not print anything to STDERR.
The program must output the first 100 Fibo Nacci entries (starting from 1).
Standard loopholes are not allowed (by default).
This is code-golf so shortest code in bytes wins!
Here is the expected output:

1
1
Fibo
Nacci
5
Fibo
13
Nacci
Fibo
55
89
FiboNacci
233
377
Fibo
Nacci
1597
Fibo
4181
Nacci
Fibo
17711
28657
FiboNacci
75025
121393
Fibo
Nacci
514229
Fibo
1346269
Nacci
Fibo
5702887
9227465
FiboNacci
24157817
39088169
Fibo
Nacci
165580141
Fibo
433494437
Nacci
Fibo
1836311903
2971215073
FiboNacci
7778742049
12586269025
Fibo
Nacci
53316291173
Fibo
139583862445
Nacci
Fibo
591286729879
956722026041
FiboNacci
2504730781961
4052739537881
Fibo
Nacci
17167680177565
Fibo
44945570212853
Nacci
Fibo
190392490709135
308061521170129
FiboNacci
806515533049393
1304969544928657
Fibo
Nacci
5527939700884757
Fibo
14472334024676221
Nacci
Fibo
61305790721611591
99194853094755497
FiboNacci
259695496911122585
420196140727489673
Fibo
Nacci
1779979416004714189
Fibo
4660046610375530309
Nacci
Fibo
19740274219868223167
31940434634990099905
FiboNacci
83621143489848422977
135301852344706746049
Fibo
Nacci

*/

fn main() {
    fibonacci(100);
}

fn fibonacci(n: u128) {
    let (mut a, mut b) = (1u128, 1u128);
    for _ in 0..n {
        if a % 6 == 0 {
            println!("FiboNacci");
        } else if a % 2 == 0 {
            println!("Fibo");
        } else if a % 3 == 0 {
            println!("Nacci");
        } else {
            println!("{a}");
        }
        (a, b) = (b, a + b);
    }
}
