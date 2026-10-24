package main

func main() {
	assert(solve([]string{"+z", "-z"}) == "+x")
	assert(solve([]string{"+z", "+y"}) == "+z")
	assert(solve([]string{"+z"}) == "+z")
	assert(solve([]string{"+z", "+y", "+z"}) == "-x")
	assert(solve([]string{"No", "+z", "No", "No"}) == "+z")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(cmds []string) string {
	dir := 0
	for _, cmd := range cmds {
		switch cmd {
		case "+z":
			switch dir {
			case 0:
				dir = 4
			case 1:
				dir = 5
			case 4:
				dir = 1
			case 5:
				dir = 0
			}

		case "-z":
			switch dir {
			case 0:
				dir = 5
			case 1:
				dir = 4
			case 4:
				dir = 0
			case 5:
				dir = 1
			}

		case "+y":
			switch dir {
			case 0:
				dir = 2
			case 1:
				dir = 3
			case 2:
				dir = 1
			case 3:
				dir = 0
			}

		case "-y":
			switch dir {
			case 0:
				dir = 3
			case 1:
				dir = 2
			case 2:
				dir = 0
			case 3:
				dir = 1
			}
		}
	}

	switch dir {
	case 0:
		return "+x"
	case 1:
		return "-x"
	case 2:
		return "+y"
	case 3:
		return "-y"
	case 4:
		return "+z"
	case 5:
		return "-z"
	}
	return ""
}
