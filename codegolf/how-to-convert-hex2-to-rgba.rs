/*

The world of art is full of colour, but the world of the network is even fuller than the world of art of diferent colours and it's renderings. That's why we need to know how to convert one type of colour format to another.

The challenge is self-evident:
Write a program / function than converts an given HEX code (#00ff0080, for instance) to RGBA (like rgba(0, 255, 0, 0.5)).

Rules:
External libraries/ built-ins for converting HEX to RGBA are disallowed. However, jQuery and syntax replacers like that are acceptable.
Standard Input/Output rules apply.
Format of the alpha can be between (1 == 100%) or the other (100 == 100%) that's not really important.
The output is flexible, as long as it returns the 4 converted values (as a String, Array, List, your choice).
You may choose to take the input without the # in the beginning. Hence, you can take input as either #RRGGBBAA or RRGGBBAA. You can assume that the hex code (excluding the #) will always be 8 characters long.
You should divide all the values by 255, including the alpha. The minimum decimal precision (for the alpha will be 2 decimal places).

Test Cases
Input:  00ff0080
Output: 0, 255, 0, 0.5
Scoring
code-golf, the code with the least amount of bytes wins.

*/

fn main() {
    println!("{:?}", hex2rgba("00ff0080"));
}

fn hex2rgba(hex: &'static str) -> (u8, u8, u8, f64) {
    let color = u32::from_str_radix(hex, 16);
    match color {
        Ok(rgba) => (
            (rgba >> 24) as u8,
            (rgba >> 16) as u8,
            (rgba >> 8) as u8,
            (rgba & 0xff) as f64 / 256.0,
        ),
        _ => (0, 0, 0, 0.0),
    }
}
