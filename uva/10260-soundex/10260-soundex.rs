fn main() {
    assert_eq!(soundex("KHAWN"), "25");
    assert_eq!(soundex("PFISTER"), "1236");
    assert_eq!(soundex("BOBBY"), "11");
}

fn soundex(input: &'static str) -> String {
    let mut previous = 'n';
    let mut output = String::new();
    for symbol in input.chars() {
        let current = getchar(symbol);
        if current != 'x' && previous != current {
            output.push(current);
        }
        previous = current;
    }
    output
}

fn getchar(symbol: char) -> char {
    match symbol {
        'B' | 'F' | 'P' | 'V' => '1',
        'C' | 'G' | 'J' | 'K' | 'Q' | 'S' | 'X' | 'Z' => '2',
        'D' | 'T' => '3',
        'L' => '4',
        'M' | 'N' => '5',
        'R' => '6',
        _ => 'x',
    }
}
