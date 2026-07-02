/*

Design a  phone directory that initially has maxNumbers empty slots that can store numbers.
The directory should store numbers, check if a certain slot is empty or not, and empty a given slot.

Implement the PhoneDirectory class:

PhoneDirectory(int maxNumbers) Initializes the phone directory with the number of available slots maxNumbers.
int get() Provides a number that is not assigned to anyone. Returns -1 if no number is available.
bool check(int number) Returns true if the slot number is available and false otherwise.
void release(int number) Recycles or releases the slot number.

Example 1:

Input
["PhoneDirectory", "get", "get", "check", "get", "check", "release", "check"]
[[3], [], [], [2], [], [2], [2], [2]]
Output
[null, 0, 1, true, 2, false, null, true]

Explanation
PhoneDirectory phoneDirectory = new PhoneDirectory(3);
phoneDirectory.get();      // It can return any available phone number. Here we assume it returns 0.
phoneDirectory.get();      // Assume it returns 1.
phoneDirectory.check(2);   // The number 2 is available, so return true.
phoneDirectory.get();      // It returns 2, the only number that is left.
phoneDirectory.check(2);   // The number 2 is no longer available, so return false.
phoneDirectory.release(2); // Release number 2 back to the pool.
phoneDirectory.check(2);   // Number 2 is available again, return true.

Constraints:

1 <= maxNumbers <= 10^4
0 <= number < maxNumbers
At most 2 * 10^4 calls will be made to get, check, and release.

*/

package main

func main() {
	p := NewPhoneDirectory(3)
	assert(p.Get() == 0)
	assert(p.Get() == 1)
	assert(p.Check(2) == true)
	assert(p.Get() == 2)
	assert(p.Check(2) == false)
	p.Release(2)
	assert(p.Check(2) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type PhoneDirectory struct {
	current int
	numbers []int
	used    []bool
}

func NewPhoneDirectory(size int) *PhoneDirectory {
	p := &PhoneDirectory{
		numbers: make([]int, size),
		used:    make([]bool, size),
	}
	for i := range p.numbers {
		p.numbers[i] = i
	}
	return p
}

func (p *PhoneDirectory) Get() int {
	if p.current >= len(p.numbers) {
		return -1
	}

	number := p.numbers[p.current]
	p.current += 1
	p.used[number] = true
	return number
}

func (p *PhoneDirectory) Check(number int) bool {
	if number < 0 || number >= len(p.numbers) {
		return false
	}
	return !p.used[number]
}

func (p *PhoneDirectory) Release(number int) {
	if number < 0 || number >= len(p.numbers) || !p.used[number] {
		return
	}

	p.used[number] = false
	p.current -= 1
	p.numbers[p.current] = number
}
