/*

You are given a single printable ASCII string containing no newlines, and a multiline "mold", containing spaces (), and hashes (#).

You must go character by character in the string, and replace hashes using the characters from the string in left-right, top-bottom order.
If the string is too short to fill the mold, you stop outputting, if the string is too long you truncate the string to exactly fill the mold.

Example string/mold (string too long, truncated):

Loremipsumdolorsitamet,consecteturadipiscingelit.Namsuscipitmagnanoneratgravidacondimentum.Vestibulumnecnisllorem.Fuscemolestieviverranibh,eueleifendnislplaceratnon.Namblanditturpislacus,vitaemolestielacusimperdietquis.Nullapulvinar,exquissollicitudinfacilisis,eratnullavolutpatlectus,etluctusenimvelitegetex.Inhachabitasseplateadictumst.Donecinterdumnullalacinia,sodalesloremin,eleifendturpis.Pellentesqueanisimi.Aeneannonlobortisdiam,quisaliquetquam.Aeneanaugueipsum,imperdietsedaliquetnon,volutpategetsapien.Nullampharetranullaquispretiumornare.Aliquamfermentumvestibulummassavitaevehicula.
###########################################################
##### ##############   ###### ###### ######################
#####  ##   ######   #  ##### ###### ########        ######
###### #  #  ####  #### ##### ###### #######  ######  #####
######   ###  ###       ##### ###### ####### #######  #####
######  ##### ### ########### ###### #######   ###   ######
###### ###### ###  ########## ######      #####   #########
##################       ####    ##########################
###########################################################
Example output:

Loremipsumdolorsitamet,consecteturadipiscingelit.Namsuscipi
tmagn anoneratgravid   acondi mentum .Vestibulumnecnisllore
m.Fus  ce   molest   i  evive rranib h,euelei        fendni
slplac e  r  atno  n.Na mblan dittur pislacu  s,vita  emole
stiela   cus  imp       erdie tquis. Nullapu lvinar,  exqui
ssolli  citud inf acilisis,er atnull avolutp   atl   ectus,
etluct usenim vel  itegetex.I nhacha      bitas   seplatead
ictumst.Donecinter       dumn    ullalacinia,sodalesloremin
,eleifendturpis.Pellentesqueanisimi.Aeneannonlobortisdiam,q
Example string/mold (string too short, output stopped):

This probably won't look good.
### ### ### ###
# # # # #   #
### ### #   # #
#   #   #   # #
#   #   ### ###
Corresponding output:

Thi s p rob abl
y   w o n   '
t l ook     g o
o   d   .
Shortest code in bytes wins.

Credit for the idea to this website.
http://jollo.org/ascii2uri.htm

*/

package main

import "fmt"

func main() {
	mold(TEXT1, MOLD1)
	mold(TEXT2, MOLD2)
}

func mold(s, m string) {
	r := []rune(s)
	i := 0
loop:
	for _, c := range m {
		switch {
		case c != '#':
			fmt.Printf("%c", c)
		case i < len(r):
			fmt.Printf("%c", r[i])
			i++
		default:
			break loop
		}
	}
	fmt.Println()
}

const TEXT1 = `Loremipsumdolorsitamet,consecteturadipiscingelit.Namsuscipitmagnanoneratgravidacondimentum.Vestibulumnecnisllorem.Fuscemolestieviverranibh,eueleifendnislplaceratnon.Namblanditturpislacus,vitaemolestielacusimperdietquis.Nullapulvinar,exquissollicitudinfacilisis,eratnullavolutpatlectus,etluctusenimvelitegetex.Inhachabitasseplateadictumst.Donecinterdumnullalacinia,sodalesloremin,eleifendturpis.Pellentesqueanisimi.Aeneannonlobortisdiam,quisaliquetquam.Aeneanaugueipsum,imperdietsedaliquetnon,volutpategetsapien.Nullampharetranullaquispretiumornare.Aliquamfermentumvestibulummassavitaevehicula.`

const MOLD1 = `
###########################################################
##### ##############   ###### ###### ######################
#####  ##   ######   #  ##### ###### ########        ######
###### #  #  ####  #### ##### ###### #######  ######  #####
######   ###  ###       ##### ###### ####### #######  #####
######  ##### ### ########### ###### #######   ###   ######
###### ###### ###  ########## ######      #####   #########
##################       ####    ##########################
###########################################################
`

const TEXT2 = `This probably won't look good.`

const MOLD2 = `
### ### ### ###
# # # # #   #
### ### #   # #
#   #   #   # #
#   #   ### ###
`
