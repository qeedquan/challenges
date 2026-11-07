/*

Story
YouTube had a like and a dislike button, which allowed users to express their opinions about particular content. It was set up in such a way that you cannot like and dislike a video at the same time. There are two other interesting rules to be noted about the interface: Pressing a button, which is already active, will undo your press. If you press the like button after pressing the dislike button, the like button overwrites the previous "Dislike" state. The same is true for the other way round.

Task
Create a function that takes in a list of button inputs and returns the final state.

Examples
rate([Dislike]) => Dislike
rate([Like,Like]) => Nothing
rate([Dislike,Like]) => Like
rate([Like,Dislike,Dislike]) => Nothing

Notes
If no button is currently active, return Nothing.
If the list is empty, return Nothing.

*/

func rate(_ values: [String]) -> String {
    var result = 0
    for value in values {
        switch value {
        case "Like":
            result = (result == 1) ? 0 : 1
        case "Dislike":
            result = (result == 2) ? 0 : 2
        default:
            break
        }
    }

    if result == 0 {
        return "Nothing"
    }
    if result == 1 {
        return "Like"
    }
    return "Dislike"
}

assert(rate(["Dislike"]) == "Dislike")
assert(rate(["Like", "Like"]) == "Nothing")
assert(rate(["Dislike", "Like"]) == "Like")
assert(rate(["Like", "Dislike", "Dislike"]) == "Nothing")
assert(rate(["Dislike", "Dislike"]) == "Nothing")
assert(rate(["Like", "Like", "Like"]) == "Like")
assert(rate(["Like", "Dislike"]) == "Dislike")
assert(rate(["Dislike", "Like", "Dislike"]) == "Dislike")
assert(rate(["Like", "Like", "Dislike", "Like", "Like", "Like", "Like", "Dislike"]) == "Dislike")
assert(rate([]) == "Nothing")
