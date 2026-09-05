/*

For every good kata idea there seem to be quite a few bad ones!

In this kata you need to check the provided array (x) for good ideas 'good' and bad ideas 'bad'. If there are one or two good ideas, return 'Publish!', if there are more than 2 return 'I smell a series!'. If there are no good ideas, as is often the case, return 'Fail!'.

*/

fn main() {
    assert_eq!(well(&["good", "good"]), "Publish!");
    assert_eq!(well(&["good", "good", "good"]), "I smell a series!");
    assert_eq!(well(&[]), "Failed!");
}

fn well(ideas: &[&'static str]) -> &'static str {
    let mut good = 0;
    for &idea in ideas {
        if idea == "good" {
            good += 1;
        }
    }
    if good > 2 {
        return "I smell a series!";
    }
    if good > 0 {
        return "Publish!";
    }
    return "Failed!";
}
