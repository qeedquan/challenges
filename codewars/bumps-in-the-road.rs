/*

Your car is old, it breaks easily. The shock absorbers are gone and you think it can handle about 15 more bumps before it dies totally.

Unfortunately for you, your drive is very bumpy! Given a string showing either flat road (_) or bumps (n). If you are able to reach home safely by encountering 15 bumps or less, return Woohoo!, otherwise return Car Dead

*/

fn main() {
    assert_eq!(bumps("n"), "Woohoo!");
    assert_eq!(bumps("__nn_nnnn__n_n___n____nn__nnn"), "Woohoo!");
    assert_eq!(bumps("nnn_n__n_n___nnnnn___n__nnn__"), "Woohoo!");
    assert_eq!(bumps("_nnnnnnn_n__n______nn__nn_nnn"), "Car Dead");
    assert_eq!(bumps("______n___n_"), "Woohoo!");
    assert_eq!(bumps("nnnnnnnnnnnnnnnnnnnnn"), "Car Dead");
}

fn bumps(road: &'static str) -> &'static str {
    let mut count = 0;
    for symbol in road.chars() {
        if symbol == 'n' {
            count += 1;
        }
    }
    if count > 15 {
        return "Car Dead";
    }
    return "Woohoo!";
}
