/*

You task is to implement an simple interpreter for the notorious esoteric language HQ9+ that will work for a single character input:

If the input is 'H', return 'Hello World!'
If the input is 'Q', return the input
If the input is '9', return the full lyrics of 99 Bottles of Beer. It should be formatted like this:
99 bottles of beer on the wall, 99 bottles of beer.
Take one down and pass it around, 98 bottles of beer on the wall.
98 bottles of beer on the wall, 98 bottles of beer.
Take one down and pass it around, 97 bottles of beer on the wall.
97 bottles of beer on the wall, 97 bottles of beer.
Take one down and pass it around, 96 bottles of beer on the wall.
...
...
...
2 bottles of beer on the wall, 2 bottles of beer.
Take one down and pass it around, 1 bottle of beer on the wall.
1 bottle of beer on the wall, 1 bottle of beer.
Take one down and pass it around, no more bottles of beer on the wall.
No more bottles of beer on the wall, no more bottles of beer.
Go to the store and buy some more, 99 bottles of beer on the wall.
For everything else, don't return anything (return null in C#, None in Rust, and "" in Haskell).
(+ has no visible effects so we can safely ignore it.)

*/

fn main() {
    println!("{:?}", hq9('9'));
    println!("{:?}", hq9('Q'));
    println!("{:?}", hq9('H'));
    println!("{:?}", hq9('+'));
}

fn hq9(code: char) -> Option<String> {
    match code {
        '9' => Some(bottles(99)),
        'Q' => Some(format!("Q")),
        'H' => Some(format!("Hello World!")),
        _ => None,
    }
}

fn bottles(total: isize) -> String {
    let mut result = format!("");
    let mut amount = total;
    while amount >= 1 {
        let mut plural = "";
        if amount > 1 {
            plural = "s";
        }
        result = format!("{result}{amount} bottle{plural} of beer on the wall, {amount} bottle{plural} of beer.\n");

        if amount - 1 > 0 {
            plural = "";
            if amount - 1 > 1 {
                plural = "s";
            }
            format!("{result}Take one down and pass it around, {} bottle{plural} of beer on the wall.\n\n", amount - 1);
        }

        amount -= 1;
    }

    result = format!(
        "{result}Take one down and pass it around, no more bottles of beer on the wall.\n\n"
    );
    result = format!("{result}No more bottles of beer on the wall, no more bottles of beer.\n");
    result = format!(
        "{result}Go to the store and buy some more, {total} bottles of beer on the wall.\n",
    );

    result
}
