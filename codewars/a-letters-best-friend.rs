/*

### Task

Given a string, return if all occurrences of a given letter are always immediately followed by the other given letter.

### Worked Example

```
("he headed to the store", "h", "e") ➞ True

# All occurences of "h": ["he", "headed", "the"]
# All occurences of "h" have an "e" after it.
# Return True

('abcdee', 'e', 'e') ➞ False

# For first "e" we can get "ee"
# For second "e" we cannot have "ee"
# Return False
```

### Examples

```
("i found an ounce with my hound", "o", "u") ➞ True
("we found your dynamite", "d", "y") ➞ False
```

### Notes

- All sentences will be given in lowercase.

*/

fn main() {
    assert_eq!(bestfriend("he headed to the store", 'h', 'e'), true);
    assert_eq!(bestfriend("", 'x', 'y'), true);
    assert_eq!(bestfriend("xaeaex", 'a', 'e'), true);
    assert_eq!(bestfriend("e headed to the store", 'h', 'e'), true);
    assert_eq!(bestfriend("i found an ounce with my hound", 'o', 'u'), true);
    assert_eq!(
        bestfriend("those were their thorns they said", 't', 'h'),
        true,
    );

    assert_eq!(bestfriend("a test", 't', 'e'), false);
    assert_eq!(bestfriend("abcdee", 'e', 'e'), false);
    assert_eq!(bestfriend("abcde", 'e', 'e'), false);
    assert_eq!(bestfriend("we found your dynamite", 'd', 'y'), false);
    assert_eq!(bestfriend("look they took the cookies", 'o', 'o'), false);
}

fn bestfriend(s: &'static str, a: char, b: char) -> bool {
    let mut l = s.chars();
    let mut c = l.next();
    while c != None {
        let nc = l.next();
        if c == Some(a) && nc != Some(b) {
            return false;
        }
        c = nc;
    }
    return true;
}
