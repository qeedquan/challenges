/*

Background
The number 1729 is the Hardy-Ramanujan number. An amazing property of it was discovered by S. Ramanujan (who is widely regarded as the greatest Indian mathematician1), when G.H. Hardy paid a visit to him in a hospital. In Hardy's own words:

I remember once going to see him when he was ill at Putney. I had ridden in taxi cab number 1729 and remarked that the number seemed to me rather a dull one, and that I hoped it was not an unfavorable omen. "No," he replied, "it is a very interesting number; it is the smallest number expressible as the sum of two cubes in two different ways."

Besides that, it has many other amazing properties. One such property is that it's a Harshad Number, i.e the sum of its digits (1+7+2+9=19) is a factor of it. That too, a special one. As Masahiko Fujiwara showed, 1729 is a positive integer which, when its digits are added together, produces a sum which, when multiplied by its reversal, yields the original number:

1+7+2+9 = 19

19 × 91 = 1729

A positive integer having such property is what I define as Hardy-Ramanujan-ish Harshad Number, for the purpose of this post. (There might be a technical term for it, but I couldn't find it, unless it's member of A110921)

The Task
Given a positive integer n as input, output a truthy or falsey value based on whether the input n is a Hardy-Ramanujan-ish Harshad Number. Output truthy, if it is. Otherwise, output falsey.

Note that only four Hardy-Ramanujan-ish Harshad Numbers exist (1,81,1458 and 1729), and you can write code which checks for equivalence with them. But I don't think that will be fun.

Input
Your program should take a positive integer (a natural number, in other words). It may take it in any way except assuming it to be present in a variable. Reading from modal window, input box, command line, file etc. is allowed. Taking input as function argument is allowed as well.

Output
Your program should output a truthy or falsey value. They need not be consistent. Your program may output in any way except writing the output to a variable. Writing to screen, command line, file etc. is allowed. Outputting with function return is allowed as well.

Additional Rules
You must not use a built-in to accomplish the task (I wonder any language will have such built-in, but then Mathematica...)

Standard Loopholes apply.

Test Cases
Input        Output
1            Truthy (because 1 × 1 (reverse of 1) = 1)
2            Falsey
3            Falsey
4            Falsey
5            Falsey
81           Truthy (because 9 (8 + 1) × 9 (reverse of 9) = 81)
1458         Truthy (because 18 (1 + 4 + 5 + 8) × 81 (reverse of 18) = 1458)
1729         Truthy (because 19 (1 + 7 + 2 + 9) × 91 (reverse of 19) = 1729)
1730         Falsey
2017         Falsey
Winning Criterion
This is code-golf, so the shortest code in bytes wins!

1Every year, on 22nd December, the birthday of Srinivasa Ramanujan, National Mathematics Day is observed in India. His colleagues, those in Cambridge, compared him to Jacobi, Euler, and even Newton. Besides being so great, he had almost no formal training in Pure Mathematics, but still, he made important contributions to mathematical analysis, number theory, infinite series, and continued fractions. Unfortunately, he died at an early age of 32 with thousands of mathematical discoveries in his mind. A film was also made on him, which was based on his biography, The Man Who Knew Infinity.

*/

fn main() {
    assert_eq!(joyful(1), true);
    assert_eq!(joyful(2), false);
    assert_eq!(joyful(3), false);
    assert_eq!(joyful(4), false);
    assert_eq!(joyful(5), false);
    assert_eq!(joyful(81), true);
    assert_eq!(joyful(1458), true);
    assert_eq!(joyful(1729), true);
    assert_eq!(joyful(1730), false);
    assert_eq!(joyful(2017), false);
}

// https://oeis.org/A110921
fn joyful(n: usize) -> bool {
    match n {
        1 | 81 | 1458 | 1729 => true,
        _ => false,
    }
}
