/*

Question: Can you get to the number 59 from the number 1, by sequentially either adding 5 or multiplying by 7?

Answer: yes! 59 = 1 x7 x7 +5 +5

Your task is to implement the more general function:

canReach(aim, add, mult)
It returns a boolean value, indicating whether it is possible to reach the number aim from the number 1, by sequentially either adding add or multiplying by mult.

So e.g.

canReach(59, 5, 7) // returns True
N.B. Assume aim, add, and mult will always be positive integers.

*/

fn main() {
    assert_eq!(reachable(59, 5, 7), true);
    assert_eq!(reachable(13, 1, 1), true);
    assert_eq!(reachable(14, 2, 0), false);
}

fn reachable(aim: usize, add: usize, mult: usize) -> bool {
    if aim == 0 {
        if mult == 0 {
            return true;
        }
        return false;
    }

    let mut stack = vec![1];
    while stack.len() > 0 {
        let value = stack.pop().unwrap();
        if value > aim {
            continue;
        }
        if value == aim {
            return true;
        }
        if add > 0 {
            stack.push(value + add);
        }
        if mult > 1 {
            stack.push(value * mult);
        }
    }
    return false;
}
