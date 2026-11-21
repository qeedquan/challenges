/*

For this task you will be given an array of numbers, each number in turn has to be cubed and once all numbers have been cubed all of them have to be added to get a final sum.

If the final sum is less than or equal to the maximum value allowed for an Integer return the sum otherwise return "You've pushed me to the max!".

You can assume that you will receive a valid array of numbers.

*/

fn main() {
    assert_eq!(maxed_out(vec![1, 1, 1]), Ok(3));
    assert_eq!(maxed_out(vec![2, 2, 2]), Ok(24));

    assert_eq!(
        maxed_out(vec![isize::MAX, 1]),
        Err("You've pushed me to the max!")
    );

    assert_eq!(
        maxed_out(vec![isize::MAX, isize::MAX]),
        Err("You've pushed me to the max!")
    );
}

fn maxed_out(a: Vec<isize>) -> Result<isize, &'static str> {
    let err = Err("You've pushed me to the max!");
    let mut r: isize = 0;
    for x in a {
        let (x2, f) = x.overflowing_mul(x);
        if f {
            return err;
        }

        let (x3, mut f) = x2.overflowing_mul(x);
        if f {
            return err;
        }

        (r, f) = r.overflowing_add(x3);
        if f {
            return err;
        }
    }
    Ok(r)
}
