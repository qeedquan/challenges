/*

Mount the Bowling Pins!
Task:
Did you ever play Bowling? Short: You have to throw a bowl into 10 Pins arranged like this:

I I I I  # each Pin has a Number:    7 8 9 10
 I I I                                4 5 6
  I I                                  2 3
   I                                    1
You will get an array of integers between 1 and 10, e.g. [3, 5, 9], and have to remove them from the field like this:

I I   I
 I   I
  I   
   I   
Return a string with the current field.

Note that:
The pins rows are separated by a newline (\n)
Each Line must be 7 chars long
Fill the missing pins with a space character ( )

*/

fn main() {
    assert_eq!(
        bowling_pins(&[1, 2, 3]),
        "I I I I\n I I I \n       \n       "
    );

    assert_eq!(
        bowling_pins(&[3, 5, 9]),
        "I I   I\n I   I \n  I    \n   I   "
    );
}

fn bowling_pins(pins: &[usize]) -> String {
    let layout = vec![
        [7, 0, 8, 0, 9, 0, 10],
        [0, 4, 0, 5, 0, 6, 0],
        [0, 0, 2, 0, 3, 0, 0],
        [0, 0, 0, 1, 0, 0, 0],
    ];

    let mut mask = 0;
    for pin in pins {
        mask |= 1 << pin;
    }

    let mut result = String::new();
    for line in layout {
        for value in line {
            if value == 0 || (mask & (1 << value)) != 0 {
                result.push(' ');
            } else {
                result.push('I');
            }
        }
        result.push('\n');
    }
    result.pop();
    result
}
