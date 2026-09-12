/*

You love coffee and want to know what beans you can afford to buy it.

The first argument to your search function will be a number which represents your budget.

The second argument will be an array of coffee bean prices.

Your 'search' function should return the stores that sell coffee within your budget.

The search function should return a string of prices for the coffees beans you can afford. The prices in this string are to be sorted in ascending order.

*/

fn main() {
    assert_eq!(search(3, &vec![6, 1, 2, 9, 2]), vec![1, 2, 2]);
    assert_eq!(
        search(14, &vec![7, 3, 23, 9, 14, 20, 7]),
        vec![3, 7, 7, 9, 14]
    );
    assert_eq!(search(0, &vec![6, 1, 2, 9, 2]), vec![]);
}

fn search(budget: isize, prices: &Vec<isize>) -> Vec<isize> {
    let mut result = vec![];
    for &price in prices {
        if price <= budget {
            result.push(price);
        }
    }
    result.sort();
    result
}
