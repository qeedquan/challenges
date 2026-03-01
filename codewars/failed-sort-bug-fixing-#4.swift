/*

Failed Sort - Bug Fixing #4

Oh no, Timmy's Sort doesn't seem to be working? Your task is to fix the sortArray function to sort all numbers in ascending order

*/

func sortArray(_ array: inout [Int]) -> [Int] {
    array.sort(by: <)
    return array
}

var array = [1, 2, 3, 4, 5]
print(sortArray(&array))

array = [5, 4, 3, 2, 1]
print(sortArray(&array))
