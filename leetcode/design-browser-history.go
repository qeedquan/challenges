/*

You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

    BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
    void visit(string url) Visits url from the current page. It clears up all the forward history.
    string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
    string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.

Example:

Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

Explanation:
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"

Constraints:

    1 <= homepage.length <= 20
    1 <= url.length <= 20
    1 <= steps <= 100
    homepage and url consist of  '.' or lower case English letters.
    At most 5000 calls will be made to visit, back, and forward.

Hint 1
Use two stacks: one for back history, and one for forward history. You can simulate the functions by popping an element from one stack and pushing it into the other.

Hint 2
Can you improve program runtime by using a different data structure?

*/

package main

func main() {
	h := NewHistory("leetcode.com")
	h.Visit("google.com")
	h.Visit("facebook.com")
	h.Visit("youtube.com")
	assert(h.Back(1) == "facebook.com")
	assert(h.Back(1) == "google.com")
	assert(h.Forward(1) == "facebook.com")
	h.Visit("linkedin.com")
	assert(h.Forward(2) == "linkedin.com")
	assert(h.Back(2) == "google.com")
	assert(h.Back(7) == "leetcode.com")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type History struct {
	mem []string
	cur int
}

func NewHistory(home string) *History {
	return &History{
		mem: []string{home},
	}
}

func (h *History) Visit(url string) {
	h.cur += 1
	h.mem = append(h.mem[:h.cur], url)
}

func (h *History) Back(steps int) string {
	if len(h.mem) == 0 {
		return ""
	}
	h.cur = max(h.cur-steps, 0)
	return h.mem[h.cur]
}

func (h *History) Forward(steps int) string {
	if len(h.mem) == 0 {
		return ""
	}
	h.cur = min(h.cur+steps, len(h.mem)-1)
	return h.mem[h.cur]
}
