/*

Find the longest palindrome in the following 1169-character string:

Fourscoreandsevenyearsagoourfaathersbroughtforthonthisconta inentanewnationconceivedinzLibertyanddedicatedtotheproposit ionthatallmenarecreatedequalNowweareengagedinagreahtcivilwa rtestingwhetherthatnaptionoranynartionsoconceivedandsodedic atedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWeh avecometodedicpateaportionofthatfieldasafinalrestingplacefo rthosewhoheregavetheirlivesthatthatnationmightliveItisaltog etherfangandproperthatweshoulddothisButinalargersensewecann otdedicatewecannotconsecratewecannothallowthisgroundThebrav elmenlivinganddeadwhostruggledherehaveconsecrateditfarabove ourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorl ongrememberwhatwesayherebutitcanneverforgetwhattheydidhereI tisforusthelivingrathertobededicatedheretotheulnfinishedwor kwhichtheywhofoughtherehavethusfarsonoblyadvancedItisrather forustobeherededicatedtothegreattdafskremainingbeforeusthat fromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwh ichtheygavethelastpfullmeasureofdevotionthatweherehighlyres olvethatthesedeadshallnothavediedinvainthatthisnationunsder Godshallhaveanewbirthoffreedomandthatgovernmentofthepeopleb ythepeopleforthepeopleshallnotperishfromtheearth

Your task is to write a function that finds the longest palindrome in a string and apply it to the string given above.

taken from http://challenge.greplin.com/ :)

It seems the number of users giving challenges have been reduced. Since my final exams are going on and its kinda difficult to think of all the challenges, I kindly request you all to suggest us interesting challenges at r/dailyprogrammer_ideas .. Thank you!

*/

package main

import (
	"slices"
)

func main() {
	assert(lps("Fourscoreandsevenyearsagoourfaathersbroughtforthonthisconta inentanewnationconceivedinzLibertyanddedicatedtotheproposit ionthatallmenarecreatedequalNowweareengagedinagreahtcivilwa rtestingwhetherthatnaptionoranynartionsoconceivedandsodedic atedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWeh avecometodedicpateaportionofthatfieldasafinalrestingplacefo rthosewhoheregavetheirlivesthatthatnationmightliveItisaltog etherfangandproperthatweshoulddothisButinalargersensewecann otdedicatewecannotconsecratewecannothallowthisgroundThebrav elmenlivinganddeadwhostruggledherehaveconsecrateditfarabove ourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorl ongrememberwhatwesayherebutitcanneverforgetwhattheydidhereI tisforusthelivingrathertobededicatedheretotheulnfinishedwor kwhichtheywhofoughtherehavethusfarsonoblyadvancedItisrather forustobeherededicatedtothegreattdafskremainingbeforeusthat fromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwh ichtheygavethelastpfullmeasureofdevotionthatweherehighlyres olvethatthesedeadshallnothavediedinvainthatthisnationunsder Godshallhaveanewbirthoffreedomandthatgovernmentofthepeopleb ythepeopleforthepeopleshallnotperishfromtheearth") == "ranynar")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func lps(s string) string {
	t := []byte(s)
	slices.Reverse(t)
	return lcs(s, string(t))
}

func lcs(s, t string) string {
	p := make([][]int, len(s))
	for i := range p {
		p[i] = make([]int, len(t))
	}

	r, z := "", 0
	for i := range s {
		for j := range t {
			if s[i] != t[j] {
				continue
			}

			if i == 0 || j == 0 {
				p[i][j] = 1
			} else {
				p[i][j] = p[i-1][j-1] + 1
			}

			if p[i][j] > z {
				r, z = "", p[i][j]
			}

			if p[i][j] == z {
				r = s[i-z+1 : i+1]
			}
		}
	}
	return r
}
