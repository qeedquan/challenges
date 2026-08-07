/*

In this kata you will be given an integer n, which is the number of times that a coin is thown. You will have to return a sorted array of strings for all the possibilities ( heads is 'H', tails is 'T' ).

Examples
coin(1) should return {"H", "T"}
coin(2) should return {"HH", "HT", "TH", "TT"}
coin(3) should return {"HHH", "HHT", "HTH", "HTT", "THH", "THT", "TTH", "TTT"}
In C and C++ just return a char* with all elements separated by , ( no space ):

coin(2) should return "HH,HT,TH,TT"
Input
0 < n < 18

Careful with performance!! You'll have to pass 3 basic test (n = 1, n = 2, n = 3), many medium tests (3 < n <= 10) and many large tests (10 < n < 18)

*/

fn main() {
    assert_eq!(coin(1), vec!["H", "T"]);
    assert_eq!(coin(2), vec!["HH", "HT", "TH", "TT"]);
    assert_eq!(
        coin(3),
        vec!["HHH", "HHT", "HTH", "HTT", "THH", "THT", "TTH", "TTT"]
    );
}

fn coin(n: usize) -> Vec<String> {
    let mut r = vec![];
    for i in 0..1 << n {
        let mut s = String::new();
        for j in (0..n).rev() {
            if i & (1 << j) == 0 {
                s.push('H');
            } else {
                s.push('T');
            }
        }
        r.push(s);
    }
    r
}
