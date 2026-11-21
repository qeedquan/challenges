/*

Chinese characters (and by extension, kanji in Japanese and hanja in Korean) are usually indexed in dictionaries by radicals (the components that are prominently featured in Chinese characters and that are usually semantic, but with many exceptions).

The Kangxi radicals are a set of 214 components that are the most common set for indexing Chinese characters. (This set actually originated by a dictionary called Zihui (字彙) in 1615, but is more commonly known as Kangxi radicals due to the popularity of the Kangxi Dictionary (康熙字典) later in 1716.) Newer Chinese dictionaries usually have radical sets more or less derived from the Kangxi set, including dictionaries designed for Japanese and Korean readers.

The goal of this challenge is to output this list:

一丨丶丿乙亅
二亠人儿入八冂冖冫几凵刀力勹匕匚匸十卜卩厂厶又
口囗土士夂夊夕大女子宀寸小尢尸屮山巛工己巾干幺广廴廾弋弓彐彡彳
心戈戶手支攴文斗斤方无日曰月木欠止歹殳毋比毛氏气水火爪父爻爿片牙牛犬
玄玉瓜瓦甘生用田疋疒癶白皮皿目矛矢石示禸禾穴立
竹米糸缶网羊羽老而耒耳聿肉臣自至臼舌舛舟艮色艸虍虫血行衣襾
見角言谷豆豕豸貝赤走足身車辛辰辵邑酉釆里
金長門阜隶隹雨靑非
面革韋韭音頁風飛食首香
馬骨高髟鬥鬯鬲鬼
魚鳥鹵鹿麥麻
黃黍黑黹
黽鼎鼓鼠
鼻齊
齒
龍龜
龠
The radicals themselves are ordered by the number of strokes. In the list above, radicals with the same number of strokes are grouped together in one line.

The "CJK Unified Ideographs" blocks in Unicode are ordered by this set of Kangxi radicals. Therefore, the Unicode code points of them come in an increasing order. Challengers can use this as an advantage to compress the output.

Output requirements
Please output using the characters in the "CJK Unified Ideographs" block, not the characters in the "Kangxi Radicals" block (U+2F00–U+2FD5). The code points in the "Kangxi Radicals" block are continuous, making them less interesting as a challenge.
Please group the radicals with the same number of strokes in one line, and separate each group with line breaks, just as the output shown above.
Please use the exact code points as the output shown above for the radical ideographs. In modern Chinese (and Japanese), the radicals may be written in the forms different from the Kangxi Dictionary forms. Some of the forms even have disunified code points (examples: 戶 (U+6236) vs. 户 (U+6237) vs. 戸 (U+6238); 靑 (U+9751) vs. 青 (U+9752); 黑 (U+9ED1) vs. 黒 (U+9ED2)), so be careful.
You may output the table in any character encoding (not limited to UTF-8, UTF-16 or GB 18030). If you use a non-Unicode CJK character encoding, please indicate the fact in your submission entry (as the compression ratio could be significantly different). However, a made-up encoding is considered a loophole and is disallowed.
Other requirements
Your program must not fetch any external data source (from file, from the internet, or whatever).
code-golf. Aim for code size as small as possible.
Informative notes
Q: Why do Chinese dictionaries often order characters by radicals instead of pronunciation or other methods?

A: For the majority of cases where a reader need to look up a Chinese character, they might not know the pronunciations of such characters, and the character shapes are the only known information. In addition, radicals serve as rough categories for semantics of Chinese characters (although it's not reliable to guess the characters' meanings by their radicals), so dictionaries traditionally use radicals for characters' ordering. Chinese character dictionaries might also provide indices allowing readers to look up by pronunciation, or by total stroke count (in case the radical of a character is less obvious or is more arbitrarily chosen). Such indices are just secondary ways to look up characters.

*/

#include <stdio.h>
#include <uchar.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
output()
{
	static const char8_t *tab[] = {
		u8"一丨丶丿乙亅",
		u8"二亠人儿入八冂冖冫几凵刀力勹匕匚匸十卜卩厂厶又",
		u8"口囗土士夂夊夕大女子宀寸小尢尸屮山巛工己巾干幺广廴廾弋弓彐彡彳",
		u8"心戈戶手支攴文斗斤方无日曰月木欠止歹殳毋比毛氏气水火爪父爻爿片牙牛犬",
		u8"玄玉瓜瓦甘生用田疋疒癶白皮皿目矛矢石示禸禾穴立",
		u8"竹米糸缶网羊羽老而耒耳聿肉臣自至臼舌舛舟艮色艸虍虫血行衣襾",
		u8"見角言谷豆豕豸貝赤走足身車辛辰辵邑酉釆里",
		u8"金長門阜隶隹雨靑非",
		u8"面革韋韭音頁風飛食首香",
		u8"馬骨高髟鬥鬯鬲鬼",
		u8"魚鳥鹵鹿麥麻",
		u8"黃黍黑黹",
		u8"黽鼎鼓鼠",
		u8"鼻齊",
		u8"齒",
		u8"龍龜",
		u8"龠",
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		printf("%s\n", tab[i]);
}

int
main()
{
	output();
	return 0;
}
