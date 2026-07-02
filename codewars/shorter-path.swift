/*

You are given a list of directions in the form of a list:

goal = ["N", "S", "E", "W"]

Pretend that each direction counts for 1 step in that particular direction.

Your task is to create a function called directions, that will return a reduced list that will get you to the same point.The order of
directions must be returned as N then S then E then W.

If you get back to beginning, return an empty array.

*/

func directions(_ goal: [String]) -> [String] {
    var (x, y) = (0, 0)
    for dir in goal {
        switch dir {
        case "N":
            y += 1
        case "S":
            y -= 1
        case "E":
            x += 1
        case "W":
            x -= 1
        default:
            break
        }
    }

    var ans = [String]()
    let dir0 = (y > 0) ? "N" : "S"
    let dir1 = (x > 0) ? "E" : "W"
    for _ in 0..<abs(y) {
        ans.append(dir0)
    }
    for _ in 0..<abs(x) {
        ans.append(dir1)
    }
    return ans
}

assert(directions(["N", "N", "N", "N", "N", "E", "N", "N"]) == ["N", "N", "N", "N", "N", "N", "N", "E"])
assert(directions(["S", "S", "N", "E", "W", "S", "N"]) == ["S"])
assert(directions(["N", "W", "S", "E"]) == [])
