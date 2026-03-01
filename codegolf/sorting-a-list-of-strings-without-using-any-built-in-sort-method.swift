/*

The goal of this Code Golf is to create a program that sorts a list of strings (in ascending order), without using any built-in sort method (such as Array.Sort() in .NET, sort() in PHP, ...). Note that this restriction excludes using a built-in method that sorts an array descending, and then reversing the array.

Some details:

Your program should prompt for input, and this input is a list of strings containing only ASCII lower-case alphabetic characters a-z, comma-separated without spaces. For example:

code,sorting,hello,golf
The output should be the given list of strings, but sorted in ascending order, still comma-separated without spaces. For example:

code,golf,hello,sorting

*/

func sort(_ array: [String]) -> [String] {
    if array.count <= 1 {
        return array
    }
    let pivot = array[0]
    let left = array.filter { $0 < pivot }
    let right = array.filter { $0 > pivot }
    return sort(left) + [String](arrayLiteral: pivot) + sort(right)
}

print(sort(["code", "sorting", "hello", "golf"]))
