/*

Positive integers have so many gorgeous features.
Some of them could be expressed as a sum of two or more consecutive positive numbers.

### Consider an Example :

* `10` could be expressed as the sum of `1 + 2 + 3 + 4 `.

___

## Task

**_Given_** *Positive integer*, N , return true if it could be expressed as a sum of two or more
consecutive positive numbers , otherwise return false .
___

### Notes

* Guaranteed constraint  :  **_2  ≤  N  ≤  (2^31) -1_** .

___

### Input >> Output Examples:

```
* consecutiveDucks(9)  ==>  return (true)  //  9 , could be expressed as a sum of ( 2 + 3 + 4 ) or ( 4 + 5 ) . 
* consecutiveDucks(64)  ==>  return (false)
* consecutiveDucks(42)  ==>  return (true) //  42 , could be expressed as a sum of ( 9 + 10 + 11 + 12 )  . 
```

*/

fn main() {
    assert_eq!(consecutive(13), true);
    assert_eq!(consecutive(6), true);
    assert_eq!(consecutive(69), true);
    assert_eq!(consecutive(8), false);
    assert_eq!(consecutive(57), true);
    assert_eq!(consecutive(16), false);
    assert_eq!(consecutive(91), true);

    assert_eq!(consecutive(522), true);
    assert_eq!(consecutive(974), true);
    assert_eq!(consecutive(755), true);
    assert_eq!(consecutive(512), false);
    assert_eq!(consecutive(739), true);
    assert_eq!(consecutive(1006), true);
    assert_eq!(consecutive(838), true);

    assert_eq!(consecutive(382131), true);
    assert_eq!(consecutive(118070), true);
    assert_eq!(consecutive(17209), true);
    assert_eq!(consecutive(32768), false);
    assert_eq!(consecutive(161997), true);
    assert_eq!(consecutive(400779), true);
    assert_eq!(consecutive(198331), true);
}

// https://oeis.org/A138591
fn consecutive(n: usize) -> bool {
    if n == 0 {
        return false;
    }
    return (n & (n - 1)) > 0;
}
