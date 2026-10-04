/*

Kata Task
I have a cat and a dog.

I got them at the same time as kitten/puppy. That was humanYears years ago.

Return their respective ages now as [humanYears,catYears,dogYears]

NOTES:

humanYears >= 1
humanYears are whole numbers only
Cat Years
15 cat years for first year
+9 cat years for second year
+4 cat years for each year after that
Dog Years
15 dog years for first year
+9 dog years for second year
+5 dog years for each year after that

*/

fn main() {
    assert_eq!(owned_cat_and_dog(9, 7), (0, 0));

    assert_eq!(owned_cat_and_dog(15, 15), (1, 1));
    assert_eq!(owned_cat_and_dog(18, 21), (1, 1));
    assert_eq!(owned_cat_and_dog(19, 17), (1, 1));

    assert_eq!(owned_cat_and_dog(24, 24), (2, 2));
    assert_eq!(owned_cat_and_dog(25, 25), (2, 2));
    assert_eq!(owned_cat_and_dog(26, 26), (2, 2));
    assert_eq!(owned_cat_and_dog(27, 27), (2, 2));

    assert_eq!(owned_cat_and_dog(56, 64), (10, 10));
}

fn owned_cat_and_dog(cat_years: isize, dog_years: isize) -> (isize, isize) {
    (get_age("cat", cat_years), get_age("dog", dog_years))
}

fn get_age(pet: &'static str, mut years: isize) -> isize {
    let mut age = 0;
    while years > 0 {
        if age < 1 {
            years -= 15;
        } else if age < 2 {
            years -= 9;
        } else if pet == "cat" {
            years -= 4;
        } else if pet == "dog" {
            years -= 5;
        }
        if years >= 0 {
            age += 1;
        }
    }
    age
}
