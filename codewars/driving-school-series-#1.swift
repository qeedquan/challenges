/*

Every month, a random number of students take the driving test at Fast & Furious (F&F) Driving School. To pass the test, a student cannot accumulate more than 18 demerit points.

At the end of the month, F&F wants to calculate the average demerit points accumulated by ONLY the students who have passed, rounded to the nearest integer.

Write a function which would allow them to do so. If no students passed the test that month, return 'No pass scores registered.'.


Example:

[10,10,10,18,20,20] --> 12

*/

func passed(_ values: [Int]) -> Any {
    var total = 0
    var length = 0
    for value in values {
        if value <= 18 {
            total += value
            length += 1
        }
    }

    if length == 0 {
        return "No pass scores registered."
    }

    var average = Double(total) / Double(length)
    average.round()
    return Int(average)
}

assert(passed([10, 10, 10, 18, 20, 20]) as! Int == 12)
assert(passed([21, 22, 24]) as! String == "No pass scores registered.")
assert(passed([3, 22, 9, 13, 20, 18, 2, 14, 20, 8, 23, 12, 7, 21, 21, 19, 20, 11, 18, 7, 13, 22, 11, 20, 9]) as! Int == 10)
assert(passed([19, 16, 8, 11, 25, 10, 29, 22, 23]) as! Int == 11)
