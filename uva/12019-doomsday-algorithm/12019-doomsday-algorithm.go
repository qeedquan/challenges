package main

func main() {
	assert(doomsday(1, 6) == "Thursday")
	assert(doomsday(2, 28) == "Monday")
	assert(doomsday(4, 5) == "Tuesday")
	assert(doomsday(5, 26) == "Thursday")
	assert(doomsday(8, 1) == "Monday")
	assert(doomsday(11, 1) == "Tuesday")
	assert(doomsday(12, 25) == "Sunday")
	assert(doomsday(12, 31) == "Saturday")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func doomsday(m, d int) string {
	return WEEKDAY[MONTH[m][d]]
}

var (
	MONTH   [13][32]int
	WEEKDAY = [8]string{"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}
)

func init() {
	mday := [13]int{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	for d, i := 6, 12; i >= 1; i-- {
		for j := mday[i]; j >= 1; j-- {
			MONTH[i][j], d = d, d-1
			if d < 1 {
				d = 7
			}
		}
	}
}
