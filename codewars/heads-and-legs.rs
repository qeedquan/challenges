/*

Everybody has probably heard of the animal heads and legs problem from the earlier years at school. It goes:

“A farm contains chickens and cows. There are x heads and y legs. How many chickens and cows are there?” 

Where x <= 1000 and y <=1000

#Task

Assuming there are no other types of animals, work out how many of each animal are there.

Return a tuple in Python - (chickens, cows) and an array list - [chickens, cows]/{chickens, cows} in all other languages

If either the heads & legs is negative, the result of your calculation is negative or the calculation is a float return "No solutions" (no valid cases), or [-1, -1] in COBOL.

In the form:

(Heads, Legs) = (72, 200)

VALID - (72, 200) =>             (44 , 28) 
                             (Chickens, Cows)

INVALID - (72, 201) => "No solutions"
However, if 0 heads and 0 legs are given always return [0, 0] since zero heads must give zero animals.

There are many different ways to solve this, but they all give the same answer.

You will only be given integers types - however negative values (edge cases) will be given.

Happy coding!

*/

fn main() {
    assert_eq!(animals(72, 200), (44, 28));
    assert_eq!(animals(116, 282), (91, 25));
    assert_eq!(animals(12, 24), (12, 0));
    assert_eq!(animals(6, 24), (0, 6));
    assert_eq!(animals(344, 872), (252, 92));
    assert_eq!(animals(158, 616), (8, 150));

    assert_eq!(animals(72, 201), (-1, -1));
    assert_eq!(animals(25, 555), (-1, -1));
    assert_eq!(animals(12, 25), (-1, -1));
    assert_eq!(animals(54, 956), (-1, -1));
    assert_eq!(animals(5455, 54956), (-1, -1));

    assert_eq!(animals(0, 0), (0, 0));
    assert_eq!(animals(-1, -1), (-1, -1));
    assert_eq!(animals(500, 0), (-1, -1));
    assert_eq!(animals(0, 500), (-1, -1));
    assert_eq!(animals(-45, 5), (-1, -1));
    assert_eq!(animals(5, -55), (-1, -1));
}

/*

A cow has 1 head and 4 legs.
A chicken has 1 head and 2 legs.

x = cow
y = chicken
h = heads
l = legs

x + y = h
4*x + 2*y = l

x = h - y
4*(h - y) + 2*y = l
-2*y + 4*h = l
y = (4*h - l)/2

*/

fn animals(heads: isize, legs: isize) -> (isize, isize) {
    if heads == 0 && legs == 0 {
        return (0, 0);
    }

    if heads < 0 || legs < 0 || legs <= heads {
        return (-1, -1);
    }

    let mut chickens = (4 * heads) - legs;
    if chickens < 0 || chickens % 2 != 0 {
        return (-1, -1);
    }
    chickens /= 2;

    let cows = heads - chickens;

    return (chickens, cows);
}
