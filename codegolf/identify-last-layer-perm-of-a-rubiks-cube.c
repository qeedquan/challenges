/*

A popular method for solving Rubik's cube consists of:

solving its first two layers, by convention starting with the white side

orienting the last layer's pieces so they face the same direction with their common colour - usually yellow, which is opposite white

permuting the last layer's pieces, so that all of them occupy their proper places without losing their orientation

In this challenge we will be considering only the last step.

Depending on how the last layer's pieces are positioned before that step, we must choose an algorithm (a predefined sequence of twists) to apply in order to move them to their correct places and thus solve the last layer. Those layouts and the corresponding algorithms are called perms and are identified with a capital letter.

The possible perms, up to rotation, reflection, and inverse (reversing all arrows), are:

https://i.sstatic.net/wjTtAbfY.png

represent a view on the top layer with all 9 pieces' yellow facelets facing the viewer. Other colours represent the facelets pointing outward - up, right, down, or left. The arrows are just for illustration, to show which piece goes where. They can be deduced from the facelet colours.

Sometimes people add a lowercase letter to distinguish between symmetries, for instance symmetries of the G perm are known as Ga,Gb,Gc,Gd - they are reflections and inverses of each other. In this challenge we'll use the name G for any of them.

Before or after applying the last perm, we might need to rotate the top layer in order to line it up with the other layers. Regardless of the amount of rotation needed, we consider the perm to remain the same.

For more detailed information about perms, not required for this specific challenge, see:

https://solvethecube.com/algorithms#pll

https://www.speedsolving.com/wiki/index.php?title=PLL

Input
You are given a 12-character string describing the colours on the periphery of the top layer. The description starts at an arbitrary corner and goes clockwise around the top layer, using "rbog" for red, blue, orange, and green facelets respectively. For instance the following picture can be described in four different ways:

https://i.sstatic.net/wj2vaP6Y.png

starting from the top left corner: "oogrgrbrogbb"

starting from the top right corner: "rgrbrogbboog"

starting from the bottom right corner: "brogbboogrgr"

starting from the bottom left corner: "gbboogrgrbro"

(This is the A perm as described in the list of perms above. The arrows can be determined uniquely from the colours, so they are not included in the input or in the above picture.)

The input will be a valid layout that could show up on a standard physical Rubik's cube. The solved cube's red, blue, orange, and green sides will appear in clockwise order when looked from its yellow side.

The input will not be trivial, i.e. it will not describe an already solved (even if rotated) top layer.

This is a chart of all valid inputs:

https://i.sstatic.net/F00Lh5CV.png

Output
A single uppercase letter identifying the perm type.

Tests
//test(input,expectedOutput)
test("bbboggroogrr","J")
test("bbbogogrgror","U")
test("bbboogrroggr","J")
test("bbborgrgogor","F")
test("bbborogogrgr","U")
test("bbgrgborogor","G")
test("bbgrgogoborr","V")
test("bbgrobogogrr","A")
test("bbgroogrbogr","Y")
test("bbgrrboooggr","J")
test("bbgrroggboor","N")
test("bboggboogrrr","J")
test("bbogggrrboor","J")
test("bbogoborgrgr","R")
test("bbogogrgborr","A")
test("bbogrboggror","T")
test("bbogrgrobogr","G")
test("bgbobgrrogor","G")
test("bgbobogogrrr","U")
test("bgboogrbogrr","T")
test("bgbooogrgrbr","U")
test("bgborgroogbr","G")
test("bgborogbgror","H")
test("bggrbbooogrr","J")
test("bggrbogrboor","Y")
test("bggroborogbr","G")
test("bggroogbborr","N")
test("bggrrbobogor","A")
test("bggrrogobobr","V")
test("bgogbborgror","G")
test("bgogbgroborr","G")
test("bgogobobgrrr","F")
test("bgogogrrbobr","R")
test("bgogrboogrbr","G")
test("bgogrgrbboor","A")
test("bobobgrgogrr","R")
test("bobobogrgrgr","Z")
test("boboggrrogbr","A")
test("bobogogbgrrr","U")
test("boborgrboggr","G")
test("boborogggrbr","U")
test("bogrbboroggr","T")
test("bogrboggborr","Y")
test("bogrgbobogrr","G")
test("bogrgogrbobr","E")
test("bogrrbogogbr","G")
test("bogrrogbbogr","Y")
test("boogbboggrrr","J")
test("boogbgrrbogr","T")
test("booggborgrbr","A")
test("boogggrbborr","J")
test("boogrbobgrgr","G")
test("boogrgrgbobr","R")
test("brbobgrooggr","A")
test("brbobogggror","U")
test("brboggrbogor","G")
test("brbogogogrbr","Z")
test("brboogrgogbr","R")
test("brbooogbgrgr","U")
test("brgrbbogogor","R")
test("brgrbogobogr","E")
test("brgrgbooogbr","F")
test("brgrgogbboor","V")
test("brgroboboggr","R")
test("brgrooggbobr","V")
test("brogbboogrgr","A")
test("brogbgrgboor","G")
test("broggbobgror","G")
test("brogggrobobr","F")
test("brogoboggrbr","R")
test("brogogrbbogr","G")
test("gbboggrrrboo","J")
test("gbbogrbogrro","Y")
test("gbboogrgrbro","A")
test("gbboorbrgrgo","V")
test("gbborgrorbgo","G")
test("gbborrbggroo","N")
test("gbgrgboorbro","G")
test("gbgrgrbrbooo","U")
test("gbgroborrbgo","G")
test("gbgrorbgboro","H")
test("gbgrrbogrboo","T")
test("gbgrrrbobogo","U")
test("gbrbgborgroo","G")
test("gbrbggroboro","G")
test("gbrboboggrro","A")
test("gbrbogrrbogo","G")
test("gbrbrboogrgo","R")
test("gbrbrgrgbooo","F")
test("ggbobgrorbro","G")
test("ggbobrbrgroo","V")
test("ggboogrrrbbo","J")
test("ggboorbbgrro","N")
test("ggborgrbrboo","A")
test("ggborrbogrbo","Y")
test("gggrbborrboo","J")
test("gggrbrboboro","U")
test("gggrobobrbro","F")
test("gggrorbrbobo","U")
test("gggrrboorbbo","J")
test("ggrbbboogrro","J")
test("ggrbbgrrbooo","J")
test("ggrboborgrbo","G")
test("ggrbogrbboro","T")
test("ggrbrbobgroo","A")
test("ggrbrgrobobo","R")
test("gobobgrrrbgo","F")
test("gobobrbggrro","V")
test("goboggrbrbro","R")
test("gobogrbrgrbo","E")
test("goborgrgrbbo","R")
test("goborrbbgrgo","V")
test("gogrbbogrbro","G")
test("gogrbrbrbogo","Z")
test("gogrgborrbbo","A")
test("gogrgrbbboro","U")
test("gogrrbobrbgo","R")
test("gogrrrbgbobo","U")
test("gorbbborgrgo","F")
test("gorbbgrgboro","G")
test("gorbgbobgrro","G")
test("gorbggrrbobo","A")
test("gorbrboggrbo","G")
test("gorbrgrbbogo","R")
test("grbobgrgrboo","G")
test("grbobrbogrgo","E")
test("grboggrorbbo","T")
test("grbogrbbgroo","Y")
test("grboogrbrbgo","G")
test("grboorbggrbo","Y")
test("grgrbboorbgo","A")
test("grgrbrbgbooo","U")
test("grgrgbobrboo","R")
test("grgrgrbobobo","Z")
test("grgrobogrbbo","G")
test("grgrorbbbogo","U")
test("grrbbboggroo","J")
test("grrbbgrobogo","A")
test("grrbgboogrbo","T")
test("grrbggrbbooo","J")
test("grrbobobgrgo","R")
test("grrbogrgbobo","G")
test("obgrgogrrbob","R")
test("obgrgrboogrb","G")
test("obgrooggrbrb","A")
test("obgrorbroggb","G")
test("obgrrogorbgb","G")
test("obgrrrbgogob","F")
test("obogggrorbrb","U")
test("oboggrbrgrob","R")
test("obogogrrrbgb","U")
test("obogorbggrrb","A")
test("obogrgrgrbob","Z")
test("obogrrbogrgb","G")
test("obrbggrrogob","V")
test("obrbgogogrrb","R")
test("obrbogrgogrb","E")
test("obrboogrgrgb","R")
test("obrbrgrooggb","V")
test("obrbrogggrob","F")
test("oggrbogorbrb","G")
test("oggrbrbrogob","R")
test("oggroogrrbbb","J")
test("oggrorbbogrb","T")
test("oggrrogbrbob","A")
test("oggrrrboogbb","J")
test("ogogbgrrrbob","U")
test("ogogbrbogrrb","G")
test("ogogogrbrbrb","Z")
test("ogogorbrgrbb","R")
test("ogogrgrorbbb","U")
test("ogogrrbbgrob","A")
test("ogrbbgroogrb","Y")
test("ogrbbogrgrob","G")
test("ogrbogrrogbb","Y")
test("ogrboogbgrrb","T")
test("ogrbrgrbogob","E")
test("ogrbrogogrbb","G")
test("oogrbogrrbgb","T")
test("oogrbrbgogrb","G")
test("oogrgogbrbrb","R")
test("oogrgrbrogbb","A")
test("oogrroggrbbb","J")
test("oogrrrbboggb","J")
test("ooogbgrgrbrb","U")
test("ooogbrbrgrgb","F")
test("oooggrbbgrrb","J")
test("ooogrgrbrbgb","U")
test("ooogrrbggrbb","J")
test("oorbbgrroggb","N")
test("oorbbogggrrb","J")
test("oorbggrbogrb","Y")
test("oorbgogrgrbb","A")
test("oorbrgrgogbb","V")
test("oorbrogbgrgb","G")
test("orgrboggrbob","G")
test("orgrbrbooggb","A")
test("orgrgogorbbb","F")
test("orgrgrbbogob","R")
test("orgroogbrbgb","G")
test("orgrorbgogbb","G")
test("orogbgrorbgb","H")
test("orogbrbggrob","G")
test("orogggrbrbob","U")
test("oroggrbogrbb","T")
test("orogogrgrbbb","U")
test("orogorbbgrgb","G")
test("orrbbgrgogob","V")
test("orrbbogogrgb","A")
test("orrbggroogbb","N")
test("orrbgogbgrob","G")
test("orrbogrboggb","Y")
test("orrboogggrbb","J")
test("rbbogogorbrg","R")
test("rbbogrbrogog","G")
test("rbbooogrrbgg","J")
test("rbboorbgogrg","A")
test("rbboroggrbog","T")
test("rbborrbooggg","J")
test("rboggborrbog","Y")
test("rboggrboborg","G")
test("rbogobogrbrg","E")
test("rbogorbrbogg","G")
test("rbogrboorbgg","Y")
test("rbogrrbgboog","T")
test("rbrbgbooogrg","U")
test("rbrbgogrboog","G")
test("rbrboboroggg","U")
test("rbrbooggborg","A")
test("rbrbrbogogog","Z")
test("rbrbrogobogg","R")
test("rgbobogrrbog","G")
test("rgbobrboogrg","R")
test("rgbooogbrbrg","F")
test("rgboorbrogbg","G")
test("rgborogorbbg","G")
test("rgborrbbogog","A")
test("rgogbboorbrg","V")
test("rgogbrbrboog","R")
test("rgogoborrbbg","V")
test("rgogorbbborg","F")
test("rgogrbobrbog","E")
test("rgogrrbobobg","R")
test("rgrbbborogog","U")
test("rgrbbogoborg","R")
test("rgrbobobogrg","Z")
test("rgrboogrbobg","G")
test("rgrbrbooogbg","U")
test("rgrbrogbboog","A")
test("roboboggrbrg","R")
test("robobrbroggg","F")
test("robogogrrbbg","A")
test("robogrbbogrg","G")
test("roborogbrbgg","G")
test("roborrbgogbg","G")
test("roogbborrbgg","N")
test("roogbrbgborg","G")
test("rooggbobrbrg","V")
test("rooggrbrbobg","A")
test("roogrbogrbbg","Y")
test("roogrrbbbogg","J")
test("rorbbbogogrg","U")
test("rorbbogrbogg","T")
test("rorbgborogbg","H")
test("rorbgogbborg","G")
test("rorbrboboggg","U")
test("rorbroggbobg","G")
test("rrbobogorbgg","A")
test("rrbobrbgogog","R")
test("rrbogogbrbog","G")
test("rrbogrboogbg","T")
test("rrboooggrbbg","J")
test("rrboorbboggg","J")
test("rrogbbogrbog","Y")
test("rrogbrbobogg","A")
test("rroggboorbbg","N")
test("rroggrbbboog","J")
test("rrogobobrbgg","V")
test("rrogorbgbobg","G")
test("rrrbboggboog","J")
test("rrrbgbobogog","U")
test("rrrbgogobobg","F")
test("rrrbobogogbg","U")
test("rrrboogbbogg","J")
Shortest code wins.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
compare(const void *configuration, const void *permutations)
{
	const char *const *permutation;

	permutation = permutations;
	return strcmp(configuration, permutation[0]);
}

const char *
identify(const char *configuration)
{
	static const char *permutations[][2] = {
		{ "bbboggroogrr", "J" },
		{ "bbbogogrgror", "U" },
		{ "bbboogrroggr", "J" },
		{ "bbborgrgogor", "F" },
		{ "bbborogogrgr", "U" },
		{ "bbgrgborogor", "G" },
		{ "bbgrgogoborr", "V" },
		{ "bbgrobogogrr", "A" },
		{ "bbgroogrbogr", "Y" },
		{ "bbgrrboooggr", "J" },
		{ "bbgrroggboor", "N" },
		{ "bboggboogrrr", "J" },
		{ "bbogggrrboor", "J" },
		{ "bbogoborgrgr", "R" },
		{ "bbogogrgborr", "A" },
		{ "bbogrboggror", "T" },
		{ "bbogrgrobogr", "G" },
		{ "bgbobgrrogor", "G" },
		{ "bgbobogogrrr", "U" },
		{ "bgboogrbogrr", "T" },
		{ "bgbooogrgrbr", "U" },
		{ "bgborgroogbr", "G" },
		{ "bgborogbgror", "H" },
		{ "bggrbbooogrr", "J" },
		{ "bggrbogrboor", "Y" },
		{ "bggroborogbr", "G" },
		{ "bggroogbborr", "N" },
		{ "bggrrbobogor", "A" },
		{ "bggrrogobobr", "V" },
		{ "bgogbborgror", "G" },
		{ "bgogbgroborr", "G" },
		{ "bgogobobgrrr", "F" },
		{ "bgogogrrbobr", "R" },
		{ "bgogrboogrbr", "G" },
		{ "bgogrgrbboor", "A" },
		{ "bobobgrgogrr", "R" },
		{ "bobobogrgrgr", "Z" },
		{ "boboggrrogbr", "A" },
		{ "bobogogbgrrr", "U" },
		{ "boborgrboggr", "G" },
		{ "boborogggrbr", "U" },
		{ "bogrbboroggr", "T" },
		{ "bogrboggborr", "Y" },
		{ "bogrgbobogrr", "G" },
		{ "bogrgogrbobr", "E" },
		{ "bogrrbogogbr", "G" },
		{ "bogrrogbbogr", "Y" },
		{ "boogbboggrrr", "J" },
		{ "boogbgrrbogr", "T" },
		{ "booggborgrbr", "A" },
		{ "boogggrbborr", "J" },
		{ "boogrbobgrgr", "G" },
		{ "boogrgrgbobr", "R" },
		{ "brbobgrooggr", "A" },
		{ "brbobogggror", "U" },
		{ "brboggrbogor", "G" },
		{ "brbogogogrbr", "Z" },
		{ "brboogrgogbr", "R" },
		{ "brbooogbgrgr", "U" },
		{ "brgrbbogogor", "R" },
		{ "brgrbogobogr", "E" },
		{ "brgrgbooogbr", "F" },
		{ "brgrgogbboor", "V" },
		{ "brgroboboggr", "R" },
		{ "brgrooggbobr", "V" },
		{ "brogbboogrgr", "A" },
		{ "brogbgrgboor", "G" },
		{ "broggbobgror", "G" },
		{ "brogggrobobr", "F" },
		{ "brogoboggrbr", "R" },
		{ "brogogrbbogr", "G" },
		{ "gbboggrrrboo", "J" },
		{ "gbbogrbogrro", "Y" },
		{ "gbboogrgrbro", "A" },
		{ "gbboorbrgrgo", "V" },
		{ "gbborgrorbgo", "G" },
		{ "gbborrbggroo", "N" },
		{ "gbgrgboorbro", "G" },
		{ "gbgrgrbrbooo", "U" },
		{ "gbgroborrbgo", "G" },
		{ "gbgrorbgboro", "H" },
		{ "gbgrrbogrboo", "T" },
		{ "gbgrrrbobogo", "U" },
		{ "gbrbgborgroo", "G" },
		{ "gbrbggroboro", "G" },
		{ "gbrboboggrro", "A" },
		{ "gbrbogrrbogo", "G" },
		{ "gbrbrboogrgo", "R" },
		{ "gbrbrgrgbooo", "F" },
		{ "ggbobgrorbro", "G" },
		{ "ggbobrbrgroo", "V" },
		{ "ggboogrrrbbo", "J" },
		{ "ggboorbbgrro", "N" },
		{ "ggborgrbrboo", "A" },
		{ "ggborrbogrbo", "Y" },
		{ "gggrbborrboo", "J" },
		{ "gggrbrboboro", "U" },
		{ "gggrobobrbro", "F" },
		{ "gggrorbrbobo", "U" },
		{ "gggrrboorbbo", "J" },
		{ "ggrbbboogrro", "J" },
		{ "ggrbbgrrbooo", "J" },
		{ "ggrboborgrbo", "G" },
		{ "ggrbogrbboro", "T" },
		{ "ggrbrbobgroo", "A" },
		{ "ggrbrgrobobo", "R" },
		{ "gobobgrrrbgo", "F" },
		{ "gobobrbggrro", "V" },
		{ "goboggrbrbro", "R" },
		{ "gobogrbrgrbo", "E" },
		{ "goborgrgrbbo", "R" },
		{ "goborrbbgrgo", "V" },
		{ "gogrbbogrbro", "G" },
		{ "gogrbrbrbogo", "Z" },
		{ "gogrgborrbbo", "A" },
		{ "gogrgrbbboro", "U" },
		{ "gogrrbobrbgo", "R" },
		{ "gogrrrbgbobo", "U" },
		{ "gorbbborgrgo", "F" },
		{ "gorbbgrgboro", "G" },
		{ "gorbgbobgrro", "G" },
		{ "gorbggrrbobo", "A" },
		{ "gorbrboggrbo", "G" },
		{ "gorbrgrbbogo", "R" },
		{ "grbobgrgrboo", "G" },
		{ "grbobrbogrgo", "E" },
		{ "grboggrorbbo", "T" },
		{ "grbogrbbgroo", "Y" },
		{ "grboogrbrbgo", "G" },
		{ "grboorbggrbo", "Y" },
		{ "grgrbboorbgo", "A" },
		{ "grgrbrbgbooo", "U" },
		{ "grgrgbobrboo", "R" },
		{ "grgrgrbobobo", "Z" },
		{ "grgrobogrbbo", "G" },
		{ "grgrorbbbogo", "U" },
		{ "grrbbboggroo", "J" },
		{ "grrbbgrobogo", "A" },
		{ "grrbgboogrbo", "T" },
		{ "grrbggrbbooo", "J" },
		{ "grrbobobgrgo", "R" },
		{ "grrbogrgbobo", "G" },
		{ "obgrgogrrbob", "R" },
		{ "obgrgrboogrb", "G" },
		{ "obgrooggrbrb", "A" },
		{ "obgrorbroggb", "G" },
		{ "obgrrogorbgb", "G" },
		{ "obgrrrbgogob", "F" },
		{ "obogggrorbrb", "U" },
		{ "oboggrbrgrob", "R" },
		{ "obogogrrrbgb", "U" },
		{ "obogorbggrrb", "A" },
		{ "obogrgrgrbob", "Z" },
		{ "obogrrbogrgb", "G" },
		{ "obrbggrrogob", "V" },
		{ "obrbgogogrrb", "R" },
		{ "obrbogrgogrb", "E" },
		{ "obrboogrgrgb", "R" },
		{ "obrbrgrooggb", "V" },
		{ "obrbrogggrob", "F" },
		{ "oggrbogorbrb", "G" },
		{ "oggrbrbrogob", "R" },
		{ "oggroogrrbbb", "J" },
		{ "oggrorbbogrb", "T" },
		{ "oggrrogbrbob", "A" },
		{ "oggrrrboogbb", "J" },
		{ "ogogbgrrrbob", "U" },
		{ "ogogbrbogrrb", "G" },
		{ "ogogogrbrbrb", "Z" },
		{ "ogogorbrgrbb", "R" },
		{ "ogogrgrorbbb", "U" },
		{ "ogogrrbbgrob", "A" },
		{ "ogrbbgroogrb", "Y" },
		{ "ogrbbogrgrob", "G" },
		{ "ogrbogrrogbb", "Y" },
		{ "ogrboogbgrrb", "T" },
		{ "ogrbrgrbogob", "E" },
		{ "ogrbrogogrbb", "G" },
		{ "oogrbogrrbgb", "T" },
		{ "oogrbrbgogrb", "G" },
		{ "oogrgogbrbrb", "R" },
		{ "oogrgrbrogbb", "A" },
		{ "oogrroggrbbb", "J" },
		{ "oogrrrbboggb", "J" },
		{ "ooogbgrgrbrb", "U" },
		{ "ooogbrbrgrgb", "F" },
		{ "oooggrbbgrrb", "J" },
		{ "ooogrgrbrbgb", "U" },
		{ "ooogrrbggrbb", "J" },
		{ "oorbbgrroggb", "N" },
		{ "oorbbogggrrb", "J" },
		{ "oorbggrbogrb", "Y" },
		{ "oorbgogrgrbb", "A" },
		{ "oorbrgrgogbb", "V" },
		{ "oorbrogbgrgb", "G" },
		{ "orgrboggrbob", "G" },
		{ "orgrbrbooggb", "A" },
		{ "orgrgogorbbb", "F" },
		{ "orgrgrbbogob", "R" },
		{ "orgroogbrbgb", "G" },
		{ "orgrorbgogbb", "G" },
		{ "orogbgrorbgb", "H" },
		{ "orogbrbggrob", "G" },
		{ "orogggrbrbob", "U" },
		{ "oroggrbogrbb", "T" },
		{ "orogogrgrbbb", "U" },
		{ "orogorbbgrgb", "G" },
		{ "orrbbgrgogob", "V" },
		{ "orrbbogogrgb", "A" },
		{ "orrbggroogbb", "N" },
		{ "orrbgogbgrob", "G" },
		{ "orrbogrboggb", "Y" },
		{ "orrboogggrbb", "J" },
		{ "rbbogogorbrg", "R" },
		{ "rbbogrbrogog", "G" },
		{ "rbbooogrrbgg", "J" },
		{ "rbboorbgogrg", "A" },
		{ "rbboroggrbog", "T" },
		{ "rbborrbooggg", "J" },
		{ "rboggborrbog", "Y" },
		{ "rboggrboborg", "G" },
		{ "rbogobogrbrg", "E" },
		{ "rbogorbrbogg", "G" },
		{ "rbogrboorbgg", "Y" },
		{ "rbogrrbgboog", "T" },
		{ "rbrbgbooogrg", "U" },
		{ "rbrbgogrboog", "G" },
		{ "rbrboboroggg", "U" },
		{ "rbrbooggborg", "A" },
		{ "rbrbrbogogog", "Z" },
		{ "rbrbrogobogg", "R" },
		{ "rgbobogrrbog", "G" },
		{ "rgbobrboogrg", "R" },
		{ "rgbooogbrbrg", "F" },
		{ "rgboorbrogbg", "G" },
		{ "rgborogorbbg", "G" },
		{ "rgborrbbogog", "A" },
		{ "rgogbboorbrg", "V" },
		{ "rgogbrbrboog", "R" },
		{ "rgogoborrbbg", "V" },
		{ "rgogorbbborg", "F" },
		{ "rgogrbobrbog", "E" },
		{ "rgogrrbobobg", "R" },
		{ "rgrbbborogog", "U" },
		{ "rgrbbogoborg", "R" },
		{ "rgrbobobogrg", "Z" },
		{ "rgrboogrbobg", "G" },
		{ "rgrbrbooogbg", "U" },
		{ "rgrbrogbboog", "A" },
		{ "roboboggrbrg", "R" },
		{ "robobrbroggg", "F" },
		{ "robogogrrbbg", "A" },
		{ "robogrbbogrg", "G" },
		{ "roborogbrbgg", "G" },
		{ "roborrbgogbg", "G" },
		{ "roogbborrbgg", "N" },
		{ "roogbrbgborg", "G" },
		{ "rooggbobrbrg", "V" },
		{ "rooggrbrbobg", "A" },
		{ "roogrbogrbbg", "Y" },
		{ "roogrrbbbogg", "J" },
		{ "rorbbbogogrg", "U" },
		{ "rorbbogrbogg", "T" },
		{ "rorbgborogbg", "H" },
		{ "rorbgogbborg", "G" },
		{ "rorbrboboggg", "U" },
		{ "rorbroggbobg", "G" },
		{ "rrbobogorbgg", "A" },
		{ "rrbobrbgogog", "R" },
		{ "rrbogogbrbog", "G" },
		{ "rrbogrboogbg", "T" },
		{ "rrboooggrbbg", "J" },
		{ "rrboorbboggg", "J" },
		{ "rrogbbogrbog", "Y" },
		{ "rrogbrbobogg", "A" },
		{ "rroggboorbbg", "N" },
		{ "rroggrbbboog", "J" },
		{ "rrogobobrbgg", "V" },
		{ "rrogorbgbobg", "G" },
		{ "rrrbboggboog", "J" },
		{ "rrrbgbobogog", "U" },
		{ "rrrbgogobobg", "F" },
		{ "rrrbobogogbg", "U" },
		{ "rrrboogbbogg", "J" },
	};

	const char **result;

	result = bsearch(configuration, permutations, nelem(permutations), sizeof(*permutations), compare);
	return (result) ? result[1] : NULL;
}

void
test(const char *configuration, const char *expected)
{
	const char *result;

	result = identify(configuration);
	assert(!strcmp(result, expected));
}

int
main()
{
	test("bbboggroogrr", "J");
	test("bbbogogrgror", "U");
	test("bbboogrroggr", "J");
	test("bbborgrgogor", "F");
	test("bbborogogrgr", "U");
	test("bbgrgborogor", "G");
	test("bbgrgogoborr", "V");
	test("bbgrobogogrr", "A");
	test("bbgroogrbogr", "Y");
	test("bbgrrboooggr", "J");
	test("bbgrroggboor", "N");
	test("bboggboogrrr", "J");
	test("bbogggrrboor", "J");
	test("bbogoborgrgr", "R");
	test("bbogogrgborr", "A");
	test("bbogrboggror", "T");
	test("bbogrgrobogr", "G");
	test("bgbobgrrogor", "G");
	test("bgbobogogrrr", "U");
	test("bgboogrbogrr", "T");
	test("bgbooogrgrbr", "U");
	test("bgborgroogbr", "G");
	test("bgborogbgror", "H");
	test("bggrbbooogrr", "J");
	test("bggrbogrboor", "Y");
	test("bggroborogbr", "G");
	test("bggroogbborr", "N");
	test("bggrrbobogor", "A");
	test("bggrrogobobr", "V");
	test("bgogbborgror", "G");
	test("bgogbgroborr", "G");
	test("bgogobobgrrr", "F");
	test("bgogogrrbobr", "R");
	test("bgogrboogrbr", "G");
	test("bgogrgrbboor", "A");
	test("bobobgrgogrr", "R");
	test("bobobogrgrgr", "Z");
	test("boboggrrogbr", "A");
	test("bobogogbgrrr", "U");
	test("boborgrboggr", "G");
	test("boborogggrbr", "U");
	test("bogrbboroggr", "T");
	test("bogrboggborr", "Y");
	test("bogrgbobogrr", "G");
	test("bogrgogrbobr", "E");
	test("bogrrbogogbr", "G");
	test("bogrrogbbogr", "Y");
	test("boogbboggrrr", "J");
	test("boogbgrrbogr", "T");
	test("booggborgrbr", "A");
	test("boogggrbborr", "J");
	test("boogrbobgrgr", "G");
	test("boogrgrgbobr", "R");
	test("brbobgrooggr", "A");
	test("brbobogggror", "U");
	test("brboggrbogor", "G");
	test("brbogogogrbr", "Z");
	test("brboogrgogbr", "R");
	test("brbooogbgrgr", "U");
	test("brgrbbogogor", "R");
	test("brgrbogobogr", "E");
	test("brgrgbooogbr", "F");
	test("brgrgogbboor", "V");
	test("brgroboboggr", "R");
	test("brgrooggbobr", "V");
	test("brogbboogrgr", "A");
	test("brogbgrgboor", "G");
	test("broggbobgror", "G");
	test("brogggrobobr", "F");
	test("brogoboggrbr", "R");
	test("brogogrbbogr", "G");
	test("gbboggrrrboo", "J");
	test("gbbogrbogrro", "Y");
	test("gbboogrgrbro", "A");
	test("gbboorbrgrgo", "V");
	test("gbborgrorbgo", "G");
	test("gbborrbggroo", "N");
	test("gbgrgboorbro", "G");
	test("gbgrgrbrbooo", "U");
	test("gbgroborrbgo", "G");
	test("gbgrorbgboro", "H");
	test("gbgrrbogrboo", "T");
	test("gbgrrrbobogo", "U");
	test("gbrbgborgroo", "G");
	test("gbrbggroboro", "G");
	test("gbrboboggrro", "A");
	test("gbrbogrrbogo", "G");
	test("gbrbrboogrgo", "R");
	test("gbrbrgrgbooo", "F");
	test("ggbobgrorbro", "G");
	test("ggbobrbrgroo", "V");
	test("ggboogrrrbbo", "J");
	test("ggboorbbgrro", "N");
	test("ggborgrbrboo", "A");
	test("ggborrbogrbo", "Y");
	test("gggrbborrboo", "J");
	test("gggrbrboboro", "U");
	test("gggrobobrbro", "F");
	test("gggrorbrbobo", "U");
	test("gggrrboorbbo", "J");
	test("ggrbbboogrro", "J");
	test("ggrbbgrrbooo", "J");
	test("ggrboborgrbo", "G");
	test("ggrbogrbboro", "T");
	test("ggrbrbobgroo", "A");
	test("ggrbrgrobobo", "R");
	test("gobobgrrrbgo", "F");
	test("gobobrbggrro", "V");
	test("goboggrbrbro", "R");
	test("gobogrbrgrbo", "E");
	test("goborgrgrbbo", "R");
	test("goborrbbgrgo", "V");
	test("gogrbbogrbro", "G");
	test("gogrbrbrbogo", "Z");
	test("gogrgborrbbo", "A");
	test("gogrgrbbboro", "U");
	test("gogrrbobrbgo", "R");
	test("gogrrrbgbobo", "U");
	test("gorbbborgrgo", "F");
	test("gorbbgrgboro", "G");
	test("gorbgbobgrro", "G");
	test("gorbggrrbobo", "A");
	test("gorbrboggrbo", "G");
	test("gorbrgrbbogo", "R");
	test("grbobgrgrboo", "G");
	test("grbobrbogrgo", "E");
	test("grboggrorbbo", "T");
	test("grbogrbbgroo", "Y");
	test("grboogrbrbgo", "G");
	test("grboorbggrbo", "Y");
	test("grgrbboorbgo", "A");
	test("grgrbrbgbooo", "U");
	test("grgrgbobrboo", "R");
	test("grgrgrbobobo", "Z");
	test("grgrobogrbbo", "G");
	test("grgrorbbbogo", "U");
	test("grrbbboggroo", "J");
	test("grrbbgrobogo", "A");
	test("grrbgboogrbo", "T");
	test("grrbggrbbooo", "J");
	test("grrbobobgrgo", "R");
	test("grrbogrgbobo", "G");
	test("obgrgogrrbob", "R");
	test("obgrgrboogrb", "G");
	test("obgrooggrbrb", "A");
	test("obgrorbroggb", "G");
	test("obgrrogorbgb", "G");
	test("obgrrrbgogob", "F");
	test("obogggrorbrb", "U");
	test("oboggrbrgrob", "R");
	test("obogogrrrbgb", "U");
	test("obogorbggrrb", "A");
	test("obogrgrgrbob", "Z");
	test("obogrrbogrgb", "G");
	test("obrbggrrogob", "V");
	test("obrbgogogrrb", "R");
	test("obrbogrgogrb", "E");
	test("obrboogrgrgb", "R");
	test("obrbrgrooggb", "V");
	test("obrbrogggrob", "F");
	test("oggrbogorbrb", "G");
	test("oggrbrbrogob", "R");
	test("oggroogrrbbb", "J");
	test("oggrorbbogrb", "T");
	test("oggrrogbrbob", "A");
	test("oggrrrboogbb", "J");
	test("ogogbgrrrbob", "U");
	test("ogogbrbogrrb", "G");
	test("ogogogrbrbrb", "Z");
	test("ogogorbrgrbb", "R");
	test("ogogrgrorbbb", "U");
	test("ogogrrbbgrob", "A");
	test("ogrbbgroogrb", "Y");
	test("ogrbbogrgrob", "G");
	test("ogrbogrrogbb", "Y");
	test("ogrboogbgrrb", "T");
	test("ogrbrgrbogob", "E");
	test("ogrbrogogrbb", "G");
	test("oogrbogrrbgb", "T");
	test("oogrbrbgogrb", "G");
	test("oogrgogbrbrb", "R");
	test("oogrgrbrogbb", "A");
	test("oogrroggrbbb", "J");
	test("oogrrrbboggb", "J");
	test("ooogbgrgrbrb", "U");
	test("ooogbrbrgrgb", "F");
	test("oooggrbbgrrb", "J");
	test("ooogrgrbrbgb", "U");
	test("ooogrrbggrbb", "J");
	test("oorbbgrroggb", "N");
	test("oorbbogggrrb", "J");
	test("oorbggrbogrb", "Y");
	test("oorbgogrgrbb", "A");
	test("oorbrgrgogbb", "V");
	test("oorbrogbgrgb", "G");
	test("orgrboggrbob", "G");
	test("orgrbrbooggb", "A");
	test("orgrgogorbbb", "F");
	test("orgrgrbbogob", "R");
	test("orgroogbrbgb", "G");
	test("orgrorbgogbb", "G");
	test("orogbgrorbgb", "H");
	test("orogbrbggrob", "G");
	test("orogggrbrbob", "U");
	test("oroggrbogrbb", "T");
	test("orogogrgrbbb", "U");
	test("orogorbbgrgb", "G");
	test("orrbbgrgogob", "V");
	test("orrbbogogrgb", "A");
	test("orrbggroogbb", "N");
	test("orrbgogbgrob", "G");
	test("orrbogrboggb", "Y");
	test("orrboogggrbb", "J");
	test("rbbogogorbrg", "R");
	test("rbbogrbrogog", "G");
	test("rbbooogrrbgg", "J");
	test("rbboorbgogrg", "A");
	test("rbboroggrbog", "T");
	test("rbborrbooggg", "J");
	test("rboggborrbog", "Y");
	test("rboggrboborg", "G");
	test("rbogobogrbrg", "E");
	test("rbogorbrbogg", "G");
	test("rbogrboorbgg", "Y");
	test("rbogrrbgboog", "T");
	test("rbrbgbooogrg", "U");
	test("rbrbgogrboog", "G");
	test("rbrboboroggg", "U");
	test("rbrbooggborg", "A");
	test("rbrbrbogogog", "Z");
	test("rbrbrogobogg", "R");
	test("rgbobogrrbog", "G");
	test("rgbobrboogrg", "R");
	test("rgbooogbrbrg", "F");
	test("rgboorbrogbg", "G");
	test("rgborogorbbg", "G");
	test("rgborrbbogog", "A");
	test("rgogbboorbrg", "V");
	test("rgogbrbrboog", "R");
	test("rgogoborrbbg", "V");
	test("rgogorbbborg", "F");
	test("rgogrbobrbog", "E");
	test("rgogrrbobobg", "R");
	test("rgrbbborogog", "U");
	test("rgrbbogoborg", "R");
	test("rgrbobobogrg", "Z");
	test("rgrboogrbobg", "G");
	test("rgrbrbooogbg", "U");
	test("rgrbrogbboog", "A");
	test("roboboggrbrg", "R");
	test("robobrbroggg", "F");
	test("robogogrrbbg", "A");
	test("robogrbbogrg", "G");
	test("roborogbrbgg", "G");
	test("roborrbgogbg", "G");
	test("roogbborrbgg", "N");
	test("roogbrbgborg", "G");
	test("rooggbobrbrg", "V");
	test("rooggrbrbobg", "A");
	test("roogrbogrbbg", "Y");
	test("roogrrbbbogg", "J");
	test("rorbbbogogrg", "U");
	test("rorbbogrbogg", "T");
	test("rorbgborogbg", "H");
	test("rorbgogbborg", "G");
	test("rorbrboboggg", "U");
	test("rorbroggbobg", "G");
	test("rrbobogorbgg", "A");
	test("rrbobrbgogog", "R");
	test("rrbogogbrbog", "G");
	test("rrbogrboogbg", "T");
	test("rrboooggrbbg", "J");
	test("rrboorbboggg", "J");
	test("rrogbbogrbog", "Y");
	test("rrogbrbobogg", "A");
	test("rroggboorbbg", "N");
	test("rroggrbbboog", "J");
	test("rrogobobrbgg", "V");
	test("rrogorbgbobg", "G");
	test("rrrbboggboog", "J");
	test("rrrbgbobogog", "U");
	test("rrrbgogobobg", "F");
	test("rrrbobogogbg", "U");
	test("rrrboogbbogg", "J");

	return 0;
}
