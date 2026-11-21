/*

Introduction
This is a small challenge I came up with while trying to make some compact code for my younger brother to use. I don't think it's particularly interesting, but I believe it presents some unique challenges because of its limited input/output requirements.

Challenge
I want to enumerate all the characters that my brother can write on his MacOS computer using only his US English keyboard, as they will be read by my Windows device. He does not have Unicode hex input enabled, so I only have to worry about things he can type using combinations of Shift and Alt/Option. These are as follows:

!"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~¡¢£¥§¨©ª«¬®¯°±´µ¶·¸º»¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÑÒÓÔÕÖØÙÚÛÜßàáâãäåæçèéêëìíîïñòóôõö÷øùúûüÿıŒœŸƒˆˇ˘˙˚˛˜˝Ωπ–—‘’‚“”„†‡•…‰‹›⁄€™∂∆∏∑√∞∫≈≠≤≥◊ﬁﬂ
along with the Apple logo, which my device reads as � (U+FFFD REPLACEMENT CHARACTER). As a list of unicode codepoints, these are

[U+0020, U+0021, U+0022, U+0023, U+0024, U+0025, U+0026, U+0027, U+0028, U+0029, U+002A, U+002B, U+002C, U+002D, U+002E, U+002F, U+0030, U+0031, U+0032, U+0033, U+0034, U+0035, U+0036, U+0037, U+0038, U+0039, U+003A, U+003B, U+003C, U+003D, U+003E, U+003F, U+0040, U+0041, U+0042, U+0043, U+0044, U+0045, U+0046, U+0047, U+0048, U+0049, U+004A, U+004B, U+004C, U+004D, U+004E, U+004F, U+0050, U+0051, U+0052, U+0053, U+0054, U+0055, U+0056, U+0057, U+0058, U+0059, U+005A, U+005B, U+005C, U+005D, U+005E, U+005F, U+0060, U+0061, U+0062, U+0063, U+0064, U+0065, U+0066, U+0067, U+0068, U+0069, U+006A, U+006B, U+006C, U+006D, U+006E, U+006F, U+0070, U+0071, U+0072, U+0073, U+0074, U+0075, U+0076, U+0077, U+0078, U+0079, U+007A, U+007B, U+007C, U+007D, U+007E, U+00A1, U+00A2, U+00A3, U+00A5, U+00A7, U+00A8, U+00A9, U+00AA, U+00AB, U+00AC, U+00AE, U+00AF, U+00B0, U+00B1, U+00B4, U+00B5, U+00B6, U+00B7, U+00B8, U+00BA, U+00BB, U+00BF, U+00C0, U+00C1, U+00C2, U+00C3, U+00C4, U+00C5, U+00C6, U+00C7, U+00C8, U+00C9, U+00CA, U+00CB, U+00CC, U+00CD, U+00CE, U+00CF, U+00D1, U+00D2, U+00D3, U+00D4, U+00D5, U+00D6, U+00D8, U+00D9, U+00DA, U+00DB, U+00DC, U+00DF, U+00E0, U+00E1, U+00E2, U+00E3, U+00E4, U+00E5, U+00E6, U+00E7, U+00E8, U+00E9, U+00EA, U+00EB, U+00EC, U+00ED, U+00EE, U+00EF, U+00F1, U+00F2, U+00F3, U+00F4, U+00F5, U+00F6, U+00F7, U+00F8, U+00F9, U+00FA, U+00FB, U+00FC, U+00FF, U+0131, U+0152, U+0153, U+0178, U+0192, U+02C6, U+02C7, U+02D8, U+02D9, U+02DA, U+02DB, U+02DC, U+02DD, U+03A9, U+03C0, U+2013, U+2014, U+2018, U+2019, U+201A, U+201C, U+201D, U+201E, U+2020, U+2021, U+2022, U+2026, U+2030, U+2039, U+203A, U+2044, U+20AC, U+2122, U+2202, U+2206, U+220F, U+2211, U+221A, U+221E, U+222B, U+2248, U+2260, U+2264, U+2265, U+25CA, U+FB01, U+FB02, U+FFFD]
Your program should take no input and return as output any permutation of the above characters. As such, all of the following are equally valid outputs:

 !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~¡¢£¥§¨©ª«¬®¯°±´µ¶·¸º»¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÑÒÓÔÕÖØÙÚÛÜßàáâãäåæçèéêëìíîïñòóôõö÷øùúûüÿıŒœŸƒˆˇ˘˙˚˛˜˝Ωπ–—‘’‚“”„†‡•…‰‹›⁄€™∂∆∏∑√∞∫≈≠≤≥◊ﬁﬂ�
�ﬂﬁ◊≥≤≠≈∫∞√∑∏∆∂™€⁄›‹‰…•‡†„”“‚’‘—–πΩ˝˜˛˚˙˘ˇˆƒŸœŒıÿüûúùø÷öõôóòñïîíìëêéèçæåäãâáàßÜÛÚÙØÖÕÔÓÒÑÏÎÍÌËÊÉÈÇÆÅÄÃÂÁÀ¿»º¸·¶µ´±°¯®¬«ª©¨§¥£¢¡~}|{zyxwvutsrqponmlkjihgfedcba`_^]\[ZYXWVUTSRQPONMLKJIHGFEDCBA@?>=<;:9876543210/.-,+*)('&%$#"!
'•ö‚›ƒõº≈¶≥πJBè≤‰ˆ®Iã8√=Ÿ“…«PêıÕ*&|UZk£_!œ’uÆ@Ùø¢{Û˚Óüä^j¡5y- 3(nËN∑ò‡⁄D¥S2FhÒîO1ûV6ç,m9ÍæÉ·¸/◊Êw∆~R)é4áÂ%˝Úl°ÿG†˘tKÈ¿Àó∞H]§`rﬁñ≠ìzv.¬»©∏ëâgcbØ÷¨Ã”eíŒ∂?´$Ç\�ÁC˛ïù±ΩªoﬂÄ}#Îµ„:àßXaMxå€ÔT™;˜<qÅ7d∫‹ú‘ˇ+—Ñ0ô[fs–ÏQÖEpÌ˙LW"ÜAi>¯Y
_Õz∆h@`òÈmóc|\á∞IŒ›d˘œ';86åƒ”-§µéX†T·$C.Ú¡Æ˚BíN{ßtSûe¿âÓ’üZπìa˜ËKG]˛±Öb)A"Yx⁄ô*+™ÍQÔı¶0ÜÒ•}4ÿÑ£uêw¢ps–¯—qøﬁ‡HÁR 5k[ΩèL“/≈FyJ≠^˙€~©ﬂ�ï°V7æúE#öªnrM…«WÊ13îgºà◊Ï‘‹´ÛÌÉ=»¨®ÄOÇ∏ˇD(U‚≥Ù‰>v<Ÿõo%√Î∫ç∑Øi2:P&9À„fù≤,∂lj!ë¥Åˆ¸Ãã¬÷Â˝ñä?
The following are invalid outputs:

 !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
(only some of the characters)

D4úÉÄnxJ ]0l“ﬁƒ‹«:£*˜∏Ø¶cÃÈ•ír¥¨(63S˙˚1™R{u˝´é&"#Õ œGÅ9ÂUîÊ¯E®øfH–@ãòp†YÜ‚K”!öïsOâXg·NûQaàiÍÓ'o#&ñìÀÔÑŒt√≤˘Bæ∫„¿ﬂ°,ˆ€çb\…>Ï◊äw)≈C§;ùkÁµ�eºI¬ÛË›V[`∞≠yÎAzˇ»÷j’ÿÇ<_Ì¡Z-õvÆMΩ∂FWm%⁄L2ß∑‘åÒÚ|=‡≥ê¢Öó~ªı+ë$.üq58±∆Ùh/èô^π©—$‰TP%'"¸Ÿ!7á?}d˛
(some characters repeated)

‹ìñ∞]~äÓ_1,òètaqÙ|cıiß≥ÜóÎm{;`ºÃBÏçyxπ˘Ç®—âÆÕ©jîOp¸MV¿éÄT¡êØ∫≠!CΩ≤˝ö∂næ+"PÒ⁄‰°∏GÚ?⍼o∆†Y38£7»AªÅb™u=‡ÍË�ˇUR@Füµﬁ◊ør˙íQe:wkWH46Êv´œ5ﬂNlÈˆdã÷Œ ‚\ÉÖ>ú[}•õ≈ù/Û∑ô›%åÿ¶¥Ì–Á·¬<˜˚¯&ëXà§˛ƒï€«2Ñ-'û)‘√À*ÂZ^#Isf0…K.“¨„gh±SL¢$”Dá(’ÔzE9JŸ
(includes a character not in the list, namely ⍼)

Solutions in Python 2 or Python 3 are preferred because Python is my native programming language, but all standard languages, code-golf oriented or otherwise, are allowed (of course, no standard loopholes). Your program must finish within five seconds, and you must provide a link to a resource to run it online. For Python 3, https://py3.codeskulptor.org is required; for Python 2, https://py2.codeskulptor.org. Programs are scored as follows:

take the length (in bytes) of the UTF-32(-LE) representation of the source code
if your code gives the same output every time, add n to its score, where n is the smallest number of characters you have to remove from its output to make it be sorted in UTF-32 order (either increasing or decreasing)
if it can give different outputs, add 222 (the length of the output) to its score.
if your code uses only ASCII characters, you get to (ceiling-)divide its score by 2, so a score of 731 becomes 366.
The lowest score wins; ties are broken by length of the UTF-8 encoding of the source code.

Baseline/Example Input and Output
Below is my current best code: Python 2, with a score of 664 (166 UTF-32 codepoints, each 4 bytes, plus 0 for giving the same result every time and that result being in UTF-32 sorted order).

print''.join(map(chr,range(32,127)))+'¡¢£¥§¨©ª«¬®¯°±´µ¶·¸º»¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÑÒÓÔÕÖØÙÚÛÜßàáâãäåæçèéêëìíîïñòóôõö÷øùúûüÿıŒœŸƒˆˇ˘˙˚˛˜˝Ωπ–—‘’‚“”„†‡•…‰‹›⁄€™∂∆∏∑√∞∫≈≠≤≥◊ﬁﬂ�'
It takes no input and provides as output the following string:

!"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~¡¢£¥§¨©ª«¬®¯°±´µ¶·¸º»¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÑÒÓÔÕÖØÙÚÛÜßàáâãäåæçèéêëìíîïñòóôõö÷øùúûüÿıŒœŸƒˆˇ˘˙˚˛˜˝Ωπ–—‘’‚“”„†‡•…‰‹›⁄€™∂∆∏∑√∞∫≈≠≤≥◊ﬁﬂ�

*/

#include <stdio.h>

int
main(void)
{
	printf("%s\n", u8" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~¡¢£¥§¨©ª«¬®¯°±´µ¶·¸º»¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÑÒÓÔÕÖØÙÚÛÜßàáâãäåæçèéêëìíîïñòóôõö÷øùúûüÿıŒœŸƒˆˇ˘˙˚˛˜˝Ωπ–—‘’‚“”„†‡•…‰‹›⁄€™∂∆∏∑√∞∫≈≠≤≥◊ﬁﬂ�");
	return 0;
}
