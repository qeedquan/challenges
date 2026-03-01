/*

All of the animals are having a feast! Each animal is bringing one dish. There is just one rule: the dish must start and end with the same letters as the animal's name. For example, the great blue heron is bringing garlic naan and the chickadee is bringing chocolate cake.

Write a function feast that takes the animal's name and dish as arguments and returns true or false to indicate whether the beast is allowed to bring the dish to the feast.

Assume that beast and dish are always lowercase strings, and that each has at least two letters. beast and dish may contain hyphens and spaces, but these will not appear at the beginning or end of the string. They will not contain numerals.

*/

fn main() {
    assert_eq!(feast("great blue heron", "garlic naan"), true);
    assert_eq!(feast("chickadee", "chocolate cake"), true);
    assert_eq!(feast("brown bear", "bear claw"), false);
    assert_eq!(feast("marmot", "mulberry tart"), true);
    assert_eq!(feast("porcupine", "pie"), true);
    assert_eq!(feast("electric eel", "lasagna"), false);
    assert_eq!(feast("slow loris", "salsas"), true);
    assert_eq!(feast("ox", "orange lox"), true);
    assert_eq!(feast("blue-footed booby", "blueberry"), true);
    assert_eq!(feast("blue-footed booby", "binary human"), false);
}

fn feast(beast: &'static str, dish: &'static str) -> bool {
    let (first0, last0) = getchars(beast);
    let (first1, last1) = getchars(dish);
    match (first0, last0, first1, last1) {
        (Some(b0), Some(b1), Some(d0), Some(d1)) => b0 == d0 && b1 == d1,
        _ => false,
    }
}

fn getchars(string: &'static str) -> (Option<char>, Option<char>) {
    let mut chars = string.chars();
    let first = chars.nth(0);
    let last = chars.last();
    (first, last)
}
