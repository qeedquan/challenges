/*

Input: A single word as a string (matches [a-zA-Z]+). If the input doesn't follow these guidelines, print "Error" (but no error should be thrown)

Output: The NATO pronunciation of the word. Print out a space separated list of the NATO word that matches each letter of the input word. Trailing white space is acceptable.

Restrictions:
Your source code must contain each ASCII character from 32 (space) to 126 (tilde) in that order, excluding numbers and letters. You may have anything you like mingled in between the required characters, but the required characters must be there and in order. (If ABC were the required characters, YA8iBC3 or C6ABn#C would be valid, but A7CRT or 8mdB9AC would not be).

Standard loopholes and built-ins for generating the NATO pronunciation are not allowed.

References:
The NATO pronunciation is as follows: Alpha Bravo Charlie Delta Echo Foxtrot Golf Hotel India Juliet Kilo Lima Mike November Oscar Papa Quebec Romeo Sierra Tango Uniform Victor Whiskey Xray Yankee Zulu.

The required symbols (in order) are as follows: !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~

Test cases: (The quotation marks won't be part of input, but are included to show whitespace)

"a"            => Alpha
"Z"            => Zulu
"twig"         => Tango Whiskey India Golf
"PPCG"         => Papa Papa Charlie Golf
"camelCase"    => Charlie Alpha Mike Echo Lima Charlie Alpha Sierra Echo
"Quebec"       => Quebec Uniform Echo Bravo Echo Charlie
""             => Error
" "            => Error
"()"           => Error
"twig "        => Error
" PPCG"        => Error
"one+two"      => Error
"Queen bee"    => Error
This is a code-golf, so the shortest code in your favorite language wins!

*/

fn main() {
    assert_eq!(nato("a"), "Alpha");
    assert_eq!(nato("Z"), "Zulu");
    assert_eq!(nato("twig"), "Tango Whiskey India Golf");
    assert_eq!(nato("PPCG"), "Papa Papa Charlie Golf");
    assert_eq!(
        nato("camelCase"),
        "Charlie Alpha Mike Echo Lima Charlie Alpha Sierra Echo"
    );
    assert_eq!(nato("Quebec"), "Quebec Uniform Echo Bravo Echo Charlie");
    assert_eq!(nato(""), "Error");
    assert_eq!(nato(" "), "Error");
    assert_eq!(nato("()"), "Error");
    assert_eq!(nato("twig "), "Error");
    assert_eq!(nato(" PPCG"), "Error");
    assert_eq!(nato("one+two"), "Error");
    assert_eq!(nato("Queen bee"), "Error");
}

fn nato(s: &'static str) -> String {
    if s.len() == 0 {
        return format!("Error");
    }

    let mut r = format!("");
    for c in s.chars() {
        r = match c {
            'A' | 'a' => format!("{r} Alpha"),
            'B' | 'b' => format!("{r} Bravo"),
            'C' | 'c' => format!("{r} Charlie"),
            'D' | 'd' => format!("{r} Delta"),
            'E' | 'e' => format!("{r} Echo"),
            'F' | 'f' => format!("{r} Foxtrot"),
            'G' | 'g' => format!("{r} Golf"),
            'H' | 'h' => format!("{r} Hotel"),
            'I' | 'i' => format!("{r} India"),
            'J' | 'j' => format!("{r} Juliet"),
            'K' | 'k' => format!("{r} Kilo"),
            'L' | 'l' => format!("{r} Lima"),
            'M' | 'm' => format!("{r} Mike"),
            'N' | 'n' => format!("{r} November"),
            'O' | 'o' => format!("{r} Oscar"),
            'P' | 'p' => format!("{r} Papa"),
            'Q' | 'q' => format!("{r} Quebec"),
            'R' | 'r' => format!("{r} Romeo"),
            'S' | 's' => format!("{r} Sierra"),
            'T' | 't' => format!("{r} Tango"),
            'U' | 'u' => format!("{r} Uniform"),
            'V' | 'v' => format!("{r} Victor"),
            'W' | 'w' => format!("{r} Whiskey"),
            'X' | 'x' => format!("{r} Xray"),
            'Y' | 'y' => format!("{r} Yankee"),
            'Z' | 'z' => format!("{r} Zulu"),
            _ => return format!("Error"),
        };
    }
    format!("{}", r.trim())
}
