/*

Given the functions

L: (x, y) => (2x - y, y)
R: (x, y) => (x, 2y - x)
and a number N generate a minimal sequence of function applications which take the initial pair (0, 1) to a pair which contains N (i.e. either (x, N) or (N, y)).

Example: N = 21. The minimal sequence is of length 5, and one such sequence is

          (  0,  1)
1. L ---> ( -1,  1)
2. L ---> ( -3,  1)
3. R ---> ( -3,  5)
4. L ---> (-11,  5)
5. R ---> (-11, 21)
Write the shortest function or program you can which generates a minimal sequence in O(lg N) time and O(1) space. You may output / return a string in either application order (LLRLR) or composition order (RLRLL), but document which.

*/

fn main() {
    assert_eq!(unfold(21), "RLRLL");
}

/*

@Howard

f=->n{(n>0?n-1:-n).to_s(2).tr'01',n>1?'LR':n<0?'RL':''}
The function returns the function sequence in composition order.

Usage:

puts f[21]     # RLRLL
puts f[-6]     # LLR
Edit: If we allow recursion (which violates the O(1) memory constraint but such does any function since the return value itself is O(lg n)) we can shrink the code to 39 characters.

f=->n{n<n*n ?f[(n-1)/2+1]+'RL'[n%2]:''}

*/

fn unfold(n: usize) -> String {
    let sym = ['R', 'L'];
    if n < n * n {
        return format!("{}{}", unfold((n - 1) / 2 + 1), sym[n & 1]);
    }
    return format!("");
}
