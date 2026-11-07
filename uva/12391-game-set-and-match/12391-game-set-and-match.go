package main

import "fmt"

func main() {
	fmt.Println(solve(0.5))
	fmt.Println(solve(0.3))
	fmt.Println(solve(0.7))
}

func solve(P float64) (game_p, set_p, match_p float64) {
	game_p = get_game(P, 0, 0, 4)
	tie_p := get_game(P, 0, 0, 7)
	set_p = get_set(game_p, tie_p, 0, 0, 6)
	match_p = set_p*set_p + set_p*set_p*(1-set_p)*2
	return
}

func get_game(P float64, sa, sb, line int) float64 {
	if sa == line && sa-sb >= 2 {
		return 1
	}
	if sb == line && sb-sa >= 2 {
		return 0
	}
	if sa == sb && sa == line-1 {
		return P * P / (1 - 2*P*(1-P))
	}
	return get_game(P, sa+1, sb, line)*P + get_game(P, sa, sb+1, line)*(1-P)
}

func get_set(game_p, tie_p float64, sa, sb, line int) float64 {
	if sa >= line && sa-sb >= 2 {
		return 1
	}
	if sb >= line && sb-sa >= 2 {
		return 0
	}
	if sa == sb && sa == line {
		return tie_p
	}
	return get_set(game_p, tie_p, sa+1, sb, line)*game_p + get_set(game_p, tie_p, sa, sb+1, line)*(1-game_p)
}
