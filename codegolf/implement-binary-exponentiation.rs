/*

Background
In programming, there is a recursive algorithm called binary exponentiation, which allows for large integer powers to be calculated in a faster way. Given a non-zero base x and a non-negative exponent n, the algorithm goes something like this (based on the example code from Wikipedia):

Function exp_by_squaring(x, n)
    if n = 0  then return  1;
    else if n is even  then return exp_by_squaring(x * x,  n / 2);
    else if n is odd  then return x * exp_by_squaring(x * x, (n - 1) / 2);

Basically, the code "reduces" the exponent term by first checking whether the current exponent is odd or even, then if it is even, just square root it; otherwise, divide by the base then square root it.
Then repeat until the exponent reaches 0. If the exponent is initially 0, then just return 1 directly.

This allows for an exponent term to be calculated faster than just multiplying the base by itself one at a time.

Example
Here is an example of the algorithm being applied on x=3, n=21.

n=21 is odd and non-zero, so we divide by the base, then square root. In this case, the number reduces to sqrt(3^21 / 3) = 3^10.
n=10 is even and non-zero, so we simply take the square root. sqrt(3^10) = 3^5.
n=5 is odd and non-zero, so we divide by the base, then square root. sqrt(3^5 / 3) = 3^2.
Continuing the process, we get 3^1 then 3^0, after which the recursion stops.

Task
Notice how at each step in the example above, we have a value which resulted from reducing the original number. Your task is to return a list of these numbers, given a non-zero integer base x != -1 and a non-negative integer exponent n.
The list should always contain the initial value as the first element. The list can be returned in reverse order if you want to.

Test Cases
   x, n     -> Output
   3, 21    -> [10460353203, 59049, 243, 9, 3, 1]
1000, 0     -> [1]
   2, 15    -> [32768, 128, 8, 2, 1]
   1, 40000 -> [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
  21, 3     -> [9261, 21, 1]
   2, 30    -> [1073741824, 32768, 128, 8, 2, 1]

This is code-golf, so shortest code in bytes wins!

*/

fn main() {
    assert_eq!(binexp(3, 21), vec![10460353203, 59049, 243, 9, 3, 1]);
    assert_eq!(binexp(1000, 0), vec![1]);
    assert_eq!(binexp(2, 15), vec![32768, 128, 8, 2, 1]);
    assert_eq!(
        binexp(1, 40000),
        vec![1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    );
    assert_eq!(binexp(21, 3), vec![9261, 21, 1]);
    assert_eq!(binexp(2, 30), vec![1073741824, 32768, 128, 8, 2, 1]);
}

fn binexp(x: usize, mut n: u32) -> Vec<usize> {
    let mut r = vec![x.pow(n)];
    while n > 0 {
        if n & 1 == 0 {
            n /= 2;
        } else {
            n = (n - 1) / 2;
        }
        r.push(x.pow(n));
    }
    r
}
