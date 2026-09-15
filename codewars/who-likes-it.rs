/*

You probably know the "like" system from Facebook and other pages. People can "like" blog posts, pictures or other items. We want to create the text that should be displayed next to such an item.

Implement the function which takes an array containing the names of people that like an item. It must return the display text as shown in the examples:

[]                                -->  "no one likes this"
["Peter"]                         -->  "Peter likes this"
["Jacob", "Alex"]                 -->  "Jacob and Alex like this"
["Max", "John", "Mark"]           -->  "Max, John and Mark like this"
["Alex", "Jacob", "Mark", "Max"]  -->  "Alex, Jacob and 2 others like this"

Note: For 4 or more names, the number in "and 2 others" simply increases.

*/

fn main() {
    assert_eq!(likes(&vec![]), "no one likes this");
    assert_eq!(likes(&vec!["Peter"]), "Peter likes this");
    assert_eq!(likes(&vec!["Jacob", "Alex"]), "Jacob and Alex like this");
    assert_eq!(
        likes(&vec!["Max", "John", "Mark"]),
        "Max, John and Mark like this"
    );
    assert_eq!(
        likes(&vec!["Alex", "Jacob", "Mark", "Max"]),
        "Alex, Jacob and 2 others like this"
    );
}

fn likes(names: &Vec<&'static str>) -> String {
    match names.len() {
        0 => format!("no one likes this"),
        1 => format!("{} likes this", names[0]),
        2 => format!("{} and {} like this", names[0], names[1]),
        3 => format!("{}, {} and {} like this", names[0], names[1], names[2]),
        _ => format!(
            "{}, {} and {} others like this",
            names[0],
            names[1],
            names.len() - 2
        ),
    }
}
