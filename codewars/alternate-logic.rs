/*

Create an OR function that takes a list of boolean values and runs OR against all of them, without ( depending on language ) the or keyword or the || operator,.

There will be between 0 and 6 elements ( inclusive ).
Return None, nil or a similar empty value for an empty list.

*/

fn main() {
    assert_eq!(altor(vec![]), None);
    assert_eq!(
        altor(vec![false, false, false, false, false, false]),
        Some(false)
    );
    assert_eq!(
        altor(vec![false, false, false, false, false, true]),
        Some(true)
    );
    assert_eq!(
        altor(vec![false, false, false, false, true, false]),
        Some(true)
    );
    assert_eq!(
        altor(vec![false, false, false, false, true, true]),
        Some(true)
    );
    assert_eq!(
        altor(vec![false, false, false, true, false, false]),
        Some(true)
    );

    assert_eq!(
        altor(vec![false, false, false, true, false, true]),
        Some(true)
    );
    assert_eq!(
        altor(vec![false, false, false, true, true, false]),
        Some(true)
    );
    assert_eq!(
        altor(vec![false, false, false, true, true, true]),
        Some(true)
    );
    assert_eq!(
        altor(vec![false, false, true, false, false, false]),
        Some(true)
    );
    assert_eq!(
        altor(vec![false, false, true, false, false, true]),
        Some(true)
    );
    assert_eq!(altor(vec![false, false, false, false]), Some(false));
    assert_eq!(altor(vec![false, false, false]), Some(false));
    assert_eq!(altor(vec![false, false]), Some(false));
    assert_eq!(altor(vec![false]), Some(false));
}

fn altor(conditions: Vec<bool>) -> Option<bool> {
    if conditions.len() == 0 {
        return None;
    }

    let mut result = conditions[0];
    for i in 1..conditions.len() {
        result = result || conditions[i];
    }
    return Some(result);
}
