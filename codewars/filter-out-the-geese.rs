/*

Write a function that takes a list of strings as an argument and returns a filtered list containing the same elements but with the 'geese' removed.

The geese are any strings in the following array, which is pre-populated in your solution:

  ["African", "Roman Tufted", "Toulouse", "Pilgrim", "Steinbacher"]
For example, if this array were passed as an argument:

 ["Mallard", "Hook Bill", "African", "Crested", "Pilgrim", "Toulouse", "Blue Swedish"]
Your function would return the following array:

["Mallard", "Hook Bill", "Crested", "Blue Swedish"]
The elements in the returned array should be in the same order as in the initial array passed to your function, albeit with the 'geese' removed. Note that all of the strings will be in the same case as those provided, and some elements may be repeated.

*/

use std::collections::HashMap;

fn main() {
    assert_eq!(
        goose_filter(&[
            "Mallard",
            "Hook Bill",
            "African",
            "Crested",
            "Pilgrim",
            "Toulouse",
            "Blue Swedish"
        ]),
        vec!["Mallard", "Hook Bill", "Crested", "Blue Swedish"]
    );

    assert_eq!(
        goose_filter(&["Mallard", "Barbary", "Hook Bill", "Blue Swedish", "Crested"]),
        vec!["Mallard", "Barbary", "Hook Bill", "Blue Swedish", "Crested"]
    );

    assert_eq!(
        goose_filter(&[
            "African",
            "Roman Tufted",
            "Toulouse",
            "Pilgrim",
            "Steinbacher"
        ]),
        Vec::<&'static str>::new(),
    );
}

fn goose_filter(birds: &[&'static str]) -> Vec<&'static str> {
    let geese = HashMap::from([
        ("African", true),
        ("Roman Tufted", true),
        ("Toulouse", true),
        ("Pilgrim", true),
        ("Steinbacher", true),
    ]);

    let mut result = vec![];
    for &bird in birds {
        if !geese.contains_key(bird) {
            result.push(bird);
        }
    }
    result
}
