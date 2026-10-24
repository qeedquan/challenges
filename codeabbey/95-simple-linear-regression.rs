/*

Brethren of CodeAbbey are running several small businesses to support the Monastery. One of them is the Winemaking.

One of the interesting issues here is that the price of the wine is not constant. At some years customers are ready to buy more barrels and pay higher, while at other years they are reluctant and brotherhood needs to lower prices to get rid of wine stores.

It was found that the reason for such behavior is simple - after rainy years grapes yield wine of better quality and people are more eager to purchase it.

This gives monks the idea - they need to find the formula for calculating more just price depending on weather records from the preceeding year, so that trade will run more smoothly. (the wine which is sold this year was prepared from the grapes picked the year before)

You are to help them in finding this formula. To keep things simple let us try approximating the dependency with the linear function in the form

Y = K * X + B
Where X is the amount of rainy days and Y is the price.

Problem statement
You will be given a list of records, each containing the number of rainy days during previous year along with the average price for which the wine was sold during current year.

Use the Simple Linear Regression and criteria of the Ordinary Least Squares to find parameters of the linear function which can approximate the dependence between price and amound of rainy days.

Input data contains starting A and ending B year in the first line.
Then lines follow for each year in form YYYY: D P where YYYY is the mark of year, D is the number of rainy days (in previous season) and P is the wine price (in crowns per barrel).
Answer should contain values for K and B with accuracy of 1e-7 or better.

Example:

input data:
1925 1947
1925: 89 257
1926: 75 226
1927: 83 235
1928: 52 173
1929: 148 332
1930: 109 268
1931: 129 306
1932: 115 289
1933: 102 265
1934: 99 269
1935: 50 228
1936: 102 265
1937: 91 256
1938: 79 238
1939: 118 298
1940: 134 311
1941: 61 155
1942: 146 340
1943: 108 274
1944: 96 242
1945: 89 232
1946: 143 328
1947: 133 303

answer:
1.54053779316 107.312854273

*/

fn main() {
    println!(
        "{:?}",
        fit(&vec![
            [89, 257],
            [75, 226],
            [83, 235],
            [52, 173],
            [148, 332],
            [109, 268],
            [129, 306],
            [115, 289],
            [102, 265],
            [99, 269],
            [50, 228],
            [102, 265],
            [91, 256],
            [79, 238],
            [118, 298],
            [134, 311],
            [61, 155],
            [146, 340],
            [108, 274],
            [96, 242],
            [89, 232],
            [143, 328],
            [133, 303],
        ])
    );
}

#[allow(non_snake_case)]
fn fit(p: &Vec<[isize; 2]>) -> (f64, f64) {
    let n = p.len();
    let mut X = 0.0;
    let mut Y = 0.0;
    let mut XX = 0.0;
    let mut XY = 0.0;
    for i in 0..n {
        let x = p[i][0] as f64;
        let y = p[i][1] as f64;
        X += x;
        Y += y;
        XX += x * x;
        XY += x * y;
    }

    let d = (n as f64) * XX - X * X;
    let a = XX * Y - X * XY;
    let b = (n as f64) * XY - X * Y;
    return (b / d, a / d);
}
