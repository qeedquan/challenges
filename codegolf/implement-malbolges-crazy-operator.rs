/*

One of many unique features of the Malbolge programming language is its highly unintuitive OP operator, referred to only as "op" in the documentation and source code but popularly known as the "crazy" operator. As described by Ben Olmstead, the creator of the language, in its documentation: "don't look for pattern, it's not there."

op is a "tritwise" operator -- it operates on corresponding ternary digits of its two arguments. For each trit (ternary bit), the result of op is given by the following lookup table:

           a
op(a,b)  0 1 2
       +-------
     0 | 1 0 0
   b 1 | 1 0 2
     2 | 2 2 1
For example, to calculate op(12345, 54321), first write out both numbers in ternary and then look up each pair of trits in the table:

   0121221020   (12345_3)
op 2202111220   (54321_3)
--------------
   2202220211   (54616_3)
The last important point is that all values in Malbolge are 10 trits wide, so input values should be padded with zeroes to a width of 10. (For instance, op(0, 0) is 1111111111 in ternary.)

Your task is to take two integers 0 ≤ a, b < 59049 as input, and output the integer value of op(a,b).

Test cases (in the format a b op(a,b)):

0 0 29524
1 2 29525
59048 5 7
36905 2214 0
11355 1131 20650
12345 54321 54616

Here is a reference implementation (copied directly from the Malbolge source code).

unsigned short op( unsigned short x, unsigned short y )
{
  unsigned short i = 0, j;
  static const unsigned short p9[5] =
    { 1, 9, 81, 729, 6561 };
  static const unsigned short o[9][9] =
    {
      { 4, 3, 3, 1, 0, 0, 1, 0, 0 },
      { 4, 3, 5, 1, 0, 2, 1, 0, 2 },
      { 5, 5, 4, 2, 2, 1, 2, 2, 1 },
      { 4, 3, 3, 1, 0, 0, 7, 6, 6 },
      { 4, 3, 5, 1, 0, 2, 7, 6, 8 },
      { 5, 5, 4, 2, 2, 1, 8, 8, 7 },
      { 7, 6, 6, 7, 6, 6, 4, 3, 3 },
      { 7, 6, 8, 7, 6, 8, 4, 3, 5 },
      { 8, 8, 7, 8, 8, 7, 5, 5, 4 },
    };
  for ( j = 0; j < 5; j++ )
    i += o[y / p9[j] % 9][x / p9[j] % 9] * p9[j];
  return ( i );
}

*/

fn main() {
    assert_eq!(op(0, 0), 29524);
    assert_eq!(op(1, 2), 29525);
    assert_eq!(op(59048, 5), 7);
    assert_eq!(op(36905, 2214), 0);
    assert_eq!(op(11355, 1131), 20650);
    assert_eq!(op(12345, 54321), 54616);
}

fn op(x: usize, y: usize) -> usize {
    let p9 = [1, 9, 81, 729, 6561];
    let lut = [
        [4, 3, 3, 1, 0, 0, 1, 0, 0],
        [4, 3, 5, 1, 0, 2, 1, 0, 2],
        [5, 5, 4, 2, 2, 1, 2, 2, 1],
        [4, 3, 3, 1, 0, 0, 7, 6, 6],
        [4, 3, 5, 1, 0, 2, 7, 6, 8],
        [5, 5, 4, 2, 2, 1, 8, 8, 7],
        [7, 6, 6, 7, 6, 6, 4, 3, 3],
        [7, 6, 8, 7, 6, 8, 4, 3, 5],
        [8, 8, 7, 8, 8, 7, 5, 5, 4],
    ];

    let mut r = 0;
    for i in 0..5 {
        r += lut[y / p9[i] % 9][x / p9[i] % 9] * p9[i];
    }

    r
}
