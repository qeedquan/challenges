/*

*************************
*  Create a frame!      *
*           __     __   *
*          /  \~~~/  \  *
*    ,----(     ..    ) *
*   /      \__     __/  *
*  /|         (\  |(    *
* ^  \  /___\  /\ |     *
*    |__|   |__|-..     *
*************************
Given an array of strings and a character to be used as border, output the frame with the content inside.

Notes:

Always keep a space between the input string and the left and right borders.
The biggest string inside the array should always fit in the frame.
The input array is never empty.
Example
frame(['Create', 'a', 'frame'], '+')

Output:

++++++++++
+ Create +
+ a      +
+ frame  +
++++++++++

*/

fn main() {
    frame(vec!["Create", "a", "frame"], '+');
    frame(vec!["bull", "quantum", "machination"], '*');
}

fn frame(words: Vec<&'static str>, decorator: char) {
    let mut maxlen = 0;
    for word in &words {
        maxlen = maxlen.max(word.len());
    }

    for _ in 0..maxlen + 4 {
        print!("{decorator}");
    }
    println!("");

    for word in &words {
        print!("{decorator} {word}");
        for _ in 2 + word.len()..maxlen + 3 {
            print!(" ");
        }
        println!("{decorator}");
    }

    for _ in 0..maxlen + 4 {
        print!("{decorator}");
    }
    println!("");
}
