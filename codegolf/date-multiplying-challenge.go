/*

(Inspired by last week's Riddler on FiveThirtyEight.com. Sandbox post.)

Given a year between 2001 and 2099, calculate and return the number of days during that calendar year where mm * dd = yy (where yy is the 2-digit year).

2018, for example, has 5:

January 18th (1 * 18 = 18)
February 9th (2 * 9 = 18)
March 6th (3 * 6 = 18)
June 3rd (6 * 3 = 18)
September 2nd (9 * 2 = 18)
Input can be a 2 or 4-digit numeric year.

Output should be an integer. Optional trailing space or return is fine.

Complete input/output list:
Input = Output
 2001 = 1     2021 = 3     2041 = 0     2061 = 0     2081 = 2
 2002 = 2     2022 = 3     2042 = 4     2062 = 0     2082 = 0
 2003 = 2     2023 = 1     2043 = 0     2063 = 3     2083 = 0
 2004 = 3     2024 = 7     2044 = 3     2064 = 2     2084 = 5
 2005 = 2     2025 = 2     2045 = 3     2065 = 1     2085 = 1
 2006 = 4     2026 = 2     2046 = 1     2066 = 3     2086 = 0
 2007 = 2     2027 = 3     2047 = 0     2067 = 0     2087 = 1
 2008 = 4     2028 = 4     2048 = 6     2068 = 1     2088 = 3
 2009 = 3     2029 = 1     2049 = 1     2069 = 1     2089 = 0
 2010 = 4     2030 = 6     2050 = 3     2070 = 3     2090 = 5
 2011 = 2     2031 = 1     2051 = 1     2071 = 0     2091 = 1
 2012 = 6     2032 = 3     2052 = 2     2072 = 6     2092 = 1
 2013 = 1     2033 = 2     2053 = 0     2073 = 0     2093 = 1
 2014 = 3     2034 = 1     2054 = 4     2074 = 0     2094 = 0
 2015 = 3     2035 = 2     2055 = 2     2075 = 2     2095 = 1
 2016 = 4     2036 = 6     2056 = 4     2076 = 1     2096 = 4
 2017 = 1     2037 = 0     2057 = 1     2077 = 2     2097 = 0
 2018 = 5     2038 = 1     2058 = 0     2078 = 2     2098 = 1
 2019 = 1     2039 = 1     2059 = 0     2079 = 0     2099 = 2
 2020 = 5     2040 = 5     2060 = 6     2080 = 4
This is a code-golf challenge, lowest byte count in each language wins.

Pre-calculating and simply looking up the answers is normally excluded per our loophole rules, but I'm explicitly allowing it for this challenge. It allows for some interesting alternate strategies, although its not likely a 98 99-item lookup list is going to be shortest.

*/

package main

func main() {
	years := []int{
		1, 2, 2, 3, 2, 4, 2, 4, 3, 4, 2, 6, 1, 3, 3, 4, 1, 5, 1, 5,
		3, 3, 1, 7, 2, 2, 3, 4, 1, 6, 1, 3, 2, 1, 2, 6, 0, 1, 1, 5,
		0, 4, 0, 3, 3, 1, 0, 6, 1, 3, 1, 2, 0, 4, 2, 4, 1, 0, 0, 6,
		0, 0, 3, 2, 1, 3, 0, 1, 1, 3, 0, 6, 0, 0, 2, 1, 2, 2, 0, 4,
		2, 0, 0, 5, 1, 0, 1, 3, 0, 5, 1, 1, 1, 0, 1, 4, 0, 1, 2,
	}

	for i, y := range years {
		assert(solve(i+1) == y)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(y int) int {
	r := 0
	for m := 12; m > 0; m-- {
		if y%m == 0 && y/m < 29+((m%2)*3) {
			r++
		}
	}
	return r
}
