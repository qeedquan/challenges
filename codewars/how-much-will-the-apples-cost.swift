/*

Buying in bulk is often cheaper than buying individual items. You will have to determine the total cost of apples. Write a function called apples that takes the arguments kilos and price. Purchases of 1 or more kilograms get a discount of 5%, purchases of 3 or more kilograms get a discount of 10%, purchases of 5 or more kilograms get a discount of 15%, and so on until you reach the maxium discount of 30%.

*/

func apples(_ kilos: Float64, _ price: Float64) -> Float64 {
    var disc = 1.0
    if kilos >= 11 {
        disc = 0.7
    } else if kilos >= 9 {
        disc = 0.75
    } else if kilos >= 7 {
        disc = 0.8
    } else if kilos >= 5 {
        disc = 0.85
    } else if kilos >= 3 {
        disc = 0.90
    } else if kilos >= 1 {
        disc = 0.95
    }
    return kilos * price * disc
}

print(apples(0.5, 2.98))
print(apples(1, 6.7))
print(apples(6, 2.75))
