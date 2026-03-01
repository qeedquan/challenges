/*

Create new mechanism to add numbers using Rust macros.

examples:
add![2,3,4]; // returns 9
add![4,5,6,7,8]; // returns 30
add![]; // return 0

*/

macro_rules! add {
    () => {{ 0 }};
    ( $( $x:expr ),* ) => {{
            let mut s = 0;
            $( s += $x;)*
            s
    }};
}

fn main() {
    assert_eq!(add!(1, 2, 3), 6);
    assert_eq!(add!(4, 5, 6, 7, 8), 30);
    assert_eq!(add!(), 0);

    for i in 0..10 {
        println!("{}", add!(i, i + 1));
    }
}
