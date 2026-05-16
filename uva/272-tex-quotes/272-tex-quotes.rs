fn main() {
    assert_eq!(
        quote(r#""To be or not to be," quoth the Bard, "that is the question"."#),
        "``To be or not to be,'' quoth the Bard, ``that is the question''."
    );

    assert_eq!(
        quote(r#"The programming contestant replied: "I must disagree. To `C' or not to `C', that is The Question!""#), 
        "The programming contestant replied: ``I must disagree. To `C' or not to `C', that is The Question!''"
    );
}

fn quote(input: &'static str) -> String {
    let mut output = String::new();
    let mut state = 1;
    for symbol in input.chars() {
        if symbol != '"' {
            output.push(symbol);
        } else {
            if state & 1 != 0 {
                output.push_str("``");
            } else {
                output.push_str("''");
            }
            state ^= 1;
        }
    }
    output
}
