/*

Your job is to build a function which determines whether or not there are double characters in a string (including whitespace characters). For example aa, !! or   .

You want the function to return true if the string contains double characters and false if not. The test should not be case sensitive; for example both aa & aA return true.

Examples:

  doubleCheck("abca")
  //returns false
  
  doubleCheck("aabc")
  //returns true
  
  doubleCheck("a 11 c d")
  //returns true
  
  doubleCheck("AabBcC")
  //returns true
  
  doubleCheck("a b  c")
  //returns true
  
  doubleCheck("a b c d e f g h i h k")
  //returns false
  
  doubleCheck("2020")
  //returns false
  
  doubleCheck("a!@€£#$%^&*()_-+=}]{[|\"':;?/>.<,~")
  //returns false

*/

fn main() {
    assert_eq!(doubles("abca"), false);
    assert_eq!(doubles("aabc"), true);
    assert_eq!(doubles("a 11 c d"), true);
    assert_eq!(doubles("AabBcC"), true);
    assert_eq!(doubles("a b  c"), true);
    assert_eq!(doubles("a b c d e f g h i h k"), false);
    assert_eq!(doubles("2020"), false);
    assert_eq!(doubles("a!@€£#$%^&*()_-+=}]{[|\"':;?/>.<,~"), false);
}

fn doubles(s: &'static str) -> bool {
    let mut c: char = '\0';
    for nc in s.to_lowercase().chars() {
        if c == nc {
            return true;
        }
        c = nc;
    }
    return false;
}
