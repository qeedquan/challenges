/*

Given a string that is a number between 0 and 100 (included) spelled out in french, write a function (or a whole program) that outputs the corresponding integer.

List of all test cases :

zero                   ==>  0
un                     ==>  1
deux                   ==>  2
trois                  ==>  3
quatre                 ==>  4
cinq                   ==>  5
six                    ==>  6
sept                   ==>  7
huit                   ==>  8
neuf                   ==>  9
dix                    ==>  10
onze                   ==>  11
douze                  ==>  12
treize                 ==>  13
quatorze               ==>  14
quinze                 ==>  15
seize                  ==>  16
dix-sept               ==>  17
dix-huit               ==>  18
dix-neuf               ==>  19
vingt                  ==>  20
vingt-et-un            ==>  21
vingt-deux             ==>  22
vingt-trois            ==>  23
vingt-quatre           ==>  24
vingt-cinq             ==>  25
vingt-six              ==>  26
vingt-sept             ==>  27
vingt-huit             ==>  28
vingt-neuf             ==>  29
trente                 ==>  30
trente-et-un           ==>  31
trente-deux            ==>  32
trente-trois           ==>  33
trente-quatre          ==>  34
trente-cinq            ==>  35
trente-six             ==>  36
trente-sept            ==>  37
trente-huit            ==>  38
trente-neuf            ==>  39
quarante               ==>  40
quarante-et-un         ==>  41
quarante-deux          ==>  42
quarante-trois         ==>  43
quarante-quatre        ==>  44
quarante-cinq          ==>  45
quarante-six           ==>  46
quarante-sept          ==>  47
quarante-huit          ==>  48
quarante-neuf          ==>  49
cinquante              ==>  50
cinquante-et-un        ==>  51
cinquante-deux         ==>  52
cinquante-trois        ==>  53
cinquante-quatre       ==>  54
cinquante-cinq         ==>  55
cinquante-six          ==>  56
cinquante-sept         ==>  57
cinquante-huit         ==>  58
cinquante-neuf         ==>  59
soixante               ==>  60
soixante-et-un         ==>  61
soixante-deux          ==>  62
soixante-trois         ==>  63
soixante-quatre        ==>  64
soixante-cinq          ==>  65
soixante-six           ==>  66
soixante-sept          ==>  67
soixante-huit          ==>  68
soixante-neuf          ==>  69
soixante-dix           ==>  70
soixante-et-onze       ==>  71
soixante-douze         ==>  72
soixante-treize        ==>  73
soixante-quatorze      ==>  74
soixante-quinze        ==>  75
soixante-seize         ==>  76
soixante-dix-sept      ==>  77
soixante-dix-huit      ==>  78
soixante-dix-neuf      ==>  79
quatre-vingts          ==>  80
quatre-vingt-un        ==>  81
quatre-vingt-deux      ==>  82
quatre-vingt-trois     ==>  83
quatre-vingt-quatre    ==>  84
quatre-vingt-cinq      ==>  85
quatre-vingt-six       ==>  86
quatre-vingt-sept      ==>  87
quatre-vingt-huit      ==>  88
quatre-vingt-neuf      ==>  89
quatre-vingt-dix       ==>  90
quatre-vingt-onze      ==>  91
quatre-vingt-douze     ==>  92
quatre-vingt-treize    ==>  93
quatre-vingt-quatorze  ==>  94
quatre-vingt-quinze    ==>  95
quatre-vingt-seize     ==>  96
quatre-vingt-dix-sept  ==>  97
quatre-vingt-dix-huit  ==>  98
quatre-vingt-dix-neuf  ==>  99
cent                   ==>  100

Rules:
This is code-golf, so the shortest solution in bytes wins.
Input will always be well formatted (except for the accent) like above
There won't be an accent in zero to help with character encoding
Input must be in lower-case (because if not, there could be a loophole that allows to encode the number in the casing of the input)
No standard loopholes
Not allowed: using an external source such as a website, as well as any libraries or APIs, that convert from a text to a number in any language, or translate text between languages
Allowed: if a language happens to natively have a built-in function that helps with converting from text to number, or translate from one language to another, you can use it


*/

package main

import (
	"bufio"
	"fmt"
	"strconv"
	"strings"
)

func main() {
	for number := range 101 {
		fmt.Println(number, LUT[number])
	}
}

func init() {
	reader := strings.NewReader(TABLE)
	scanner := bufio.NewScanner(reader)
	for scanner.Scan() {
		tokens := strings.Split(scanner.Text(), "==>")
		if len(tokens) != 2 {
			continue
		}
		for index := range tokens {
			tokens[index] = strings.TrimSpace(tokens[index])
		}

		key, _ := strconv.Atoi(tokens[1])
		value := tokens[0]
		LUT[key] = value
	}
}

var LUT = make(map[int]string)

const TABLE = `
zero                   ==>  0
un                     ==>  1
deux                   ==>  2
trois                  ==>  3
quatre                 ==>  4
cinq                   ==>  5
six                    ==>  6
sept                   ==>  7
huit                   ==>  8
neuf                   ==>  9
dix                    ==>  10
onze                   ==>  11
douze                  ==>  12
treize                 ==>  13
quatorze               ==>  14
quinze                 ==>  15
seize                  ==>  16
dix-sept               ==>  17
dix-huit               ==>  18
dix-neuf               ==>  19
vingt                  ==>  20
vingt-et-un            ==>  21
vingt-deux             ==>  22
vingt-trois            ==>  23
vingt-quatre           ==>  24
vingt-cinq             ==>  25
vingt-six              ==>  26
vingt-sept             ==>  27
vingt-huit             ==>  28
vingt-neuf             ==>  29
trente                 ==>  30
trente-et-un           ==>  31
trente-deux            ==>  32
trente-trois           ==>  33
trente-quatre          ==>  34
trente-cinq            ==>  35
trente-six             ==>  36
trente-sept            ==>  37
trente-huit            ==>  38
trente-neuf            ==>  39
quarante               ==>  40
quarante-et-un         ==>  41
quarante-deux          ==>  42
quarante-trois         ==>  43
quarante-quatre        ==>  44
quarante-cinq          ==>  45
quarante-six           ==>  46
quarante-sept          ==>  47
quarante-huit          ==>  48
quarante-neuf          ==>  49
cinquante              ==>  50
cinquante-et-un        ==>  51
cinquante-deux         ==>  52
cinquante-trois        ==>  53
cinquante-quatre       ==>  54
cinquante-cinq         ==>  55
cinquante-six          ==>  56
cinquante-sept         ==>  57
cinquante-huit         ==>  58
cinquante-neuf         ==>  59
soixante               ==>  60
soixante-et-un         ==>  61
soixante-deux          ==>  62
soixante-trois         ==>  63
soixante-quatre        ==>  64
soixante-cinq          ==>  65
soixante-six           ==>  66
soixante-sept          ==>  67
soixante-huit          ==>  68
soixante-neuf          ==>  69
soixante-dix           ==>  70
soixante-et-onze       ==>  71
soixante-douze         ==>  72
soixante-treize        ==>  73
soixante-quatorze      ==>  74
soixante-quinze        ==>  75
soixante-seize         ==>  76
soixante-dix-sept      ==>  77
soixante-dix-huit      ==>  78
soixante-dix-neuf      ==>  79
quatre-vingts          ==>  80
quatre-vingt-un        ==>  81
quatre-vingt-deux      ==>  82
quatre-vingt-trois     ==>  83
quatre-vingt-quatre    ==>  84
quatre-vingt-cinq      ==>  85
quatre-vingt-six       ==>  86
quatre-vingt-sept      ==>  87
quatre-vingt-huit      ==>  88
quatre-vingt-neuf      ==>  89
quatre-vingt-dix       ==>  90
quatre-vingt-onze      ==>  91
quatre-vingt-douze     ==>  92
quatre-vingt-treize    ==>  93
quatre-vingt-quatorze  ==>  94
quatre-vingt-quinze    ==>  95
quatre-vingt-seize     ==>  96
quatre-vingt-dix-sept  ==>  97
quatre-vingt-dix-huit  ==>  98
quatre-vingt-dix-neuf  ==>  99
cent                   ==>  100
`
