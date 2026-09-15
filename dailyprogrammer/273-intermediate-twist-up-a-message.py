#!/usr/bin/python3

"""

Description
As we know English uses Latin ALPHABET consisting of 26 characters, both upper- and lower-case:

Aa Bb Cc Dd Ee Ff Gg Hh Ii Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz
However, many other languages use its modified version, with some of the letters removed and additional diacritics added to some of them. For instance, Czech ALPHABET has following additional characters:

Áá Čč Ďď Éé Ěě Íí Ňň Óó Řř Šš Ťť Úú Ůů Ýý Žž
The worst of all is probably Vietnamese:

Áá Àà Ãã Ảả Ạạ Ââ Ấấ Ầầ Ẫẫ Ẩẩ Ậậ Ăă Ắắ Ằằ Ẵẵ Ẳẳ Ặặ Đđ Éé Èè Ẽẽ Ẻẻ Ẹẹ Êê Ếế Ềề Ễễ Ểể Ệệ
Íí Ìì Ĩĩ Ỉỉ Ịị Óó Òò Õõ Ỏỏ Ọọ Ôô Ốố Ồồ Ỗỗ Ổổ Ộộ Ơơ Ớớ Ờờ Ỡỡ Ởở Ợợ
Úú Ùù Ũũ Ủủ Ụụ Ưư Ứứ Ừừ Ữữ Ửử Ựự Ýý Ỳỳ Ỹỹ Ỷỷ Ỵỵ
Your job is to write a method twistUp which "twists up" a string, making it as much filled with diacritics as possible.

Input
Your input will consist of one string of any letters of the English ALPHABET, digits and special characters. Characters that cannot be diactriticized should be returned in its original form.

Output
Output will consist of a modified text.

Sample input
For, after all, how do we know that two and two make four?
Or that the force of gravity works? Or that the past is unchangeable?
If both the past and the external world exist only in the mind,
and if the mind itself is controllable – what then?
Sample output
Ƒǒṝ, āᶂťȅŗ ąľḷ, ħṓẃ ᶁớ ẅē ḵȵȭŵ ŧⱨąť ȶẁô ǎǹḍ ẗŵȫ ᶆầᶄĕ ḟõṵɍ?
Ȯᵳ ƫẖẩť ṯħê ḟṑȑćẽ ỏᵮ ǧŗảᶌıⱦỳ ẘǒᵲᶄṧ? Ṍᵲ țḩᶏᵵ ⱦḥḙ ṗᶏşʈ ḯş ůǹḉḧẳṇģḕâɓƚė?
Ǐḟ Ƅȫţȟ țḧè ƥāṣț ặňḓ ŧħᶒ ḙxᵵęȑᶇȁȴ ẁőŕȴɗ ȩxĭʂƫ ǫȵľȳ ȋɳ ȶḥẽ ṁįƞḋ,
ǡǹƌ ᵻḟ ṱȟë ḿīᵰᶑ ḭẗᵴḛɫᵮ ɨś čổɲȶṙŏłḹạɓɭḕ – ŵḫāṯ ƫḩḕñ?
Notes
If your browser/compiler/console cannot display diacritics, switch encoding to UTF-8.

Other than diacritics, you can use similar-looking characters like CyrillicИ for N

Bonus challenges
Make your twistUp method take not only letters of English ALPHABET, but all the letters:

Dżdżystym rankiem gżegżółki i piegże, zamiast wziąć się za dżdżownice,
nażarły się na czczo miąższu rzeżuchy i rzędem rzygały do rozżarzonej brytfanny.

Ɖẑɗɀỵŝțỳɱ ɾẵᶇḵīȩᵯ ĝʑẻğẑộḷǩᵻ î ƥỉëģźè, ʐậɱǐāʂţ ẅɀỉḁĉ ᶊīė ẑắ ḍɀḏźỏẉᵰiɕȅ,
ṋȧʑȧṝⱡý sïë ƞẩ čʐčʑỡ ɱᶖẵẕśẓǘ ᶉẕẻẓǚḉḣỷ ĩ ɼʑéɗḕᶆ ɼᵶỳǥäḷỵ ƌờ ᵳờẕɀăȓʐőȵḗʝ ɓṛŷṭƒằǹɳý.
Twisted up characters don't need to be the same every time!

Boy, this challenge sure is fun.

Ƀɵƴ, ṫẖiŝ çħẳḽḻęńĝễ ṧụᵳẽ ìṧ ᵮựᵰ.
Ƌȍý, ṯḩįš çẖǎḹļȩᶇġẻ șùɼė īṧ ᶂǔṇ.
Ḇȏƴ, ţȟïš ȼḫẫḹŀẻᶇǧề ŝŭᶉē ìṣ ᵮǘń.
Ƀòý, ȶḥỉṩ ċħǡļḹệǹǥɇ ŝǖȓé ḭʂ ᶂǘǹ.
Write an additional untwist method which takes a twisted up text and converts its characters into plain Latin:

Ṭħë ᶈṝộȱƒ țḣẵţ ƭĥề ɬıṭᵵḷḛ ᵱᵲíȵċɇ ɇxẛṣⱦėḏ ɨś ƫḥẳṯ ħė ẘắś ĉⱨȃṟḿíņğ, ƫħằṫ ĥḛ ᶅẫủᶃḩëᶑ,
áñɗ ţḥầť ḫẻ ẉâṧ łỗǫḳĩņğ ᶂờŕ ầ ᶊĥȅẹᵽ. Īḟ ǡɲÿɓộđʏ ẁȧṉȶȿ â ȿĥểêᵱ, ⱦḣąʈ ᵻṥ ȁ ᵱṟỗǒƒ ṫȟǟṭ ḫĕ ḕᶍĭṩťș.

The proof that the little prince existed is that he was charming, that he laughed,
and that he was looking for a sheep. If anybody wants a sheep, that is a proof that he exists.
bonus 2
Find a creative way to generate the mapping scheme (with minimal "hand crafted" tables, and the most mappings.

"""

from random import choice

WORDS = '''For, after all, how do we know that two and two make four? 
Or that the force of gravity works? Or that the past is unchangeable? 
If both the past and the external world exist only in the mind, 
and if the mind itself is controllable – what then?'''

ALPHABET = {
    'a': 'áăắặằẳẵǎâấậầẩẫäạàảāąåǻãɑɐɒ',
    'b': 'ḅɓß♭␢Б',
    'c': 'ćčçĉɕċ',
    'd': 'ďḓḍɗḏđɖ',
    'e': 'éĕěêếệềểễëėẹèẻēęẽɘəɚ',
    'f': 'ƒſʃʆʅɟʄ',
    'g': 'ǵğǧģĝġɠḡɡ',
    'h': 'ḫĥḥɦẖħɧ',
    'i': 'íĭǐîïịìỉīįɨĩɩı',
    'j': 'ǰĵʝȷɟʄ',
    'k': 'ķḳƙḵĸʞ',
    'l': 'ĺƚɬľļḽḷḹḻŀɫɭł',
    'm': 'ḿṁṃɱɯɰ',
    'n': 'ŉńňņṋṅṇǹɲṉɳñŋ',
    'o': 'óŏǒôốộồổỗöọőòỏơớợờởỡōǫøǿõɵʘ',
    'p': 'ɸþᵱƥᵽṗṕ',
    'q': 'ʠꝗɋq̃ϙ',
    'r': 'ŕřŗṙṛṝɾṟɼɽɿɹɻ',
    's': 'śšşŝșṡṣʂ',
    't': 'ťţṱțẗṭṯʈŧ',
    'u': 'ʉúŭǔûüǘǚǜǖụűùủưứựừửữūųůũʊ',
    'v': 'ʋʌⱴṿṽ',
    'w': 'ẃŵẅẁʍ',
    'x': 'χẍẋⲭ',
    'y': 'ýŷÿẏỵỳƴỷȳỹʎ',
    'z': 'źžʑżẓẕʐƶ',
    'A': 'ÁĂẮẶẰẲẴǍÂẤẬẦẨẪÄẠÀẢĀĄÅǺÃ',
    'B': 'ḄƁᛒ𐌱ɃḂḆ฿β',
    'C': 'ĆČÇĈĊƆʗ',
    'D': 'ĎḒḌƊḎĐÐ',
    'E': 'ÉĔĚÊẾỆỀỂỄËĖẸÈẺĒĘẼƐ',
    'F': 'ƑḞ𐌅₣',
    'G': 'ǴĞǦĢĜĠḠʛ',
    'H': 'ḪĤḤĦ',
    'I': 'ÍĬǏÎÏİỊÌỈĪĮĨ',
    'J': 'ĴɈʝ',
    'K': 'ĶḲƘḴ',
    'L': 'ĹȽĽĻḼḶḸḺĿŁ',
    'M': 'ḾṀṂ',
    'N': 'ŃŇŅṊṄṆǸƝṈÑ',
    'O': 'ÓŎǑÔỐỘỒỔỖÖỌŐÒỎƠỚỢỜỞỠŌƟǪØǾÕ',
    'P': 'Þ𐌐ṔṖⱣƤ₱♇',
    'Q': 'ꝖɊ',
    'R': 'ŔŘŖṘṚṜṞʁ',
    'S': 'ŚŠŞŜȘṠṢ',
    'T': 'ŤŢṰȚṬṮŦ',
    'U': 'ÚŬǓÛÜǗǙǛǕỤŰÙỦƯỨỰỪỬỮŪŲŮŨ',
    'V': 'ṼṾƲ℣∨',
    'W': 'ẂŴẄẀʬ',
    'X': 'χẌẊⲬ𐍇',
    'Y': 'ÝŶŸẎỴỲƳỶȲỸ',
    'Z': 'ŹŽŻẒẔƵ'
}

def twist(string):
    return ''.join([choice(ALPHABET[c]) if c in ALPHABET else c for c in string])

def untwist(string):
    untwisted = []
    for c in string:
        found = False
        for k, v in ALPHABET.items():
            if c in v:
                untwisted.append(k)
                found = True
            if found:
                break
        if not found:
            untwisted.append(c)
    return ''.join(untwisted)

def main():
    print(twist(WORDS))
    print(untwist(twist(WORDS)))

main()
