/*

Given a string, you've to split it into groups of three characters (by padding _ at the end).

Related, but still it's different.

Sample I/O:

'abcde' -> 'abc', 'de_'

'1234' -> '123', '4__'

'' -> [] or falsey value

'Three spree!' -> 'Thr', 'ee ', 'spr', 'ee!'

6 MB string
https://uccbd9b506b6ddbfd79139ccbb55.dl.dropboxusercontent.com/cd/0/inline/CaZJInRV1MuK1idrzbyaQuuTeDA_qgEekmQvFgYad9TTpS0hg4oIvrlMzGoZh1TcQG002RPyTQ48LwKR8r_g_pnP3bfwbFX91IhlJuC73poVpAr0bfbVCX-GiLLpXwRAZbY/file#

This is a code-golf, so fewest bytes will win!

Edit: Finally, output is unrestricted.

*/

fn main() {
    assert_eq!(split3("abcde"), vec!["abc", "de_"]);
    assert_eq!(split3("1234"), vec!["123", "4__"]);
    assert_eq!(split3(""), Vec::<String>::new());
    assert_eq!(split3("Three spree!"), vec!["Thr", "ee ", "spr", "ee!"]);
}

fn split3(s: &'static str) -> Vec<String> {
    let mut r = vec![];
    let mut t = format!("");
    for c in s.chars() {
        t = format!("{t}{c}");
        if t.len() == 3 {
            r.push(t);
            t = format!("");
        }
    }

    match t.len() {
        1 => r.push(format!("{t}__")),
        2 => r.push(format!("{t}_")),
        _ => (),
    }

    r
}
