fn main() {
    assert_eq!(hajj("Hajj"), "Hajj-e-Akbar");
    assert_eq!(hajj("Umrah"), "Hajj-e-Asghar");
}

fn hajj(input: &'static str) -> &'static str {
    match input {
        "Hajj" => "Hajj-e-Akbar",
        "Umrah" => "Hajj-e-Asghar",
        _ => input,
    }
}
