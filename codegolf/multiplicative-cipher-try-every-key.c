/*

Try every key for these 3 messages encrypted with a multiplicative cipher (E(x) = a * x mod m):

JQmc uQiZ yKTHmKmNfafyQN fZu aHH Emuc?
q mOiKK MoqK iAeIWEMqCA yiMoCg qK AC wCAmiI KieOIi.
mGAKYakqoakWGAe, OGq kYO ywyYO iyO!
Alphabet: abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ

Here's the output for q mOiKK MoqK iAeIWEMqCA yiMoCg qK AC wCAmiI KieOIi.:

1 q mOiKK MoqK iAeIWEMqCA yiMoCg qK AC wCAmiI KieOIi.
2 i guess this encryption method is no longer secure.
3 O eWumm EwOm uAKUqkEOSA iuEwSc Om AS QSAeuU muKWUu.
5 y SimCC sIyC mAGMugsyqA KmsIqw yC Aq UqASmM CmGiMm.
6 u cykgg plug knsxifpuwn ekplwb ug nw vwnckx gksyxk.
7 G yCquu YcGu qAiQSIYGeA WqYceM Gu Ae seAyqQ uqiCQq.
9 W Kqyee kQWe yAmYOMkWGA uykQGs We AG oGAKyY eymqYy.
10 m wegoo jrmo gnqtkdjmin sgjril mo ni xinwgt ogqetg.
11 S uGWii UgSi WAywCYUSmA OWUgmk Si Am cmAuWw iWyGwW.
14 q moikk zbqk inevwrzqcn yizbct qk nc jcnmiv kieovi.
15 i GueSS gUiS eACEycgiOA megUOQ iS AO YOAGeE SeCuEe.
17 e qKCWW QkeW CAOcmoQeuA GCQkuI eW Au MuAqCc WCOKcC.
18 y simcc fvyc mngzutfyqn kmfvqj yc nq hqnsmz cmgizm.
19 u CyKGG cYuG KASkiscuWA eKcYWo uG AW IWACKk GKSykK.
21 C iSOyy IsCy OAuoGUICKA qOIsKE Cy AK gKAiOo yOuSoO.
22 w kqyee xdwe ynmlozxwgn uyxdgf we ng bgnkyl eymqly.
23 m WeGOO wEmO GAqgKQwmiA SGwEiY mO Ai kiAWGg OGqegG.
25 K OmSqq oMKq SAWsewoKyA CSoMyU Kq Ay EyAOSs qSWmsS.
27 q mOiKK MoqK iAeIWEMqCA yiMoCg qK AC wCAmiI KieOIi.
29 O eWumm EwOm uAKUqkEOSA iuEwSc Om AS QSAeuU muKWUu.
30 e qkcww dxew cnopmbdeun gcdxuv ew nu zunqcp wcokpc.
31 y SimCC sIyC mAGMugsyqA KmsIqw yC Aq UqASmM CmGiMm.
33 G yCquu YcGu qAiQSIYGeA WqYceM Gu Ae seAyqQ uqiCQq.
34 c isoyy vfcy onubghvckn qovfkr cy nk tkniob yousbo.
35 W Kqyee kQWe yAmYOMkWGA uykQGs We AG oGAKyY eymqYy.
...
47 C iSOyy IsCy OAuoGUICKA qOIsKE Cy AK gKAiOo yOuSoO.
49 m WeGOO wEmO GAqgKQwmiA SGwEiY mO Ai kiAWGg OGqegG.
50 s ugwii htsi wnyjclhsmn owhtmx si nm pmnuwj iwygjw.
51 K OmSqq oMKq SAWsewoKyA CSoMyU Kq Ay EyAOSs qSWmsS.
Shortest code wins.

Example implementation:

from contextlib import suppress
from string import ascii_letters


def encrypt(text: str, key: int, mapping: str = ascii_letters) -> str:
    result: str = ""
    for char in text:
        if char in ascii_letters:
            idx: int = mapping.index(char)
            result += ascii_letters[idx * key % len(ascii_letters)]
        else:
            result += char

    return result


def decrypt(text: str, key: int) -> str:
    return encrypt(text, 1, encrypt(ascii_letters, key))


encrypted_text: str = input("Encrypted Text:")
for encryption_key in range(1, len(ascii_letters)):
    with suppress(ValueError):
        print(encryption_key, decrypt(encrypted_text, encryption_key))

*/

#include <stdio.h>
#include <string.h>

static const char ascii[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

char *
encrypt(const char *src, int key, const char *map, char *dst)
{
	size_t i, maplen;
	char *ptr;

	maplen = strlen(map);
	for (i = 0; src[i]; i++) {
		dst[i] = src[i];
		if ((ptr = strchr(map, src[i])))
			dst[i] = ascii[((ptr - map) * key) % maplen];
	}
	dst[i] = '\0';

	return dst;
}

char *
decrypt(const char *src, int key, char *dst)
{
	char *map;

	map = dst + strlen(src) + 3;
	encrypt(ascii, key, ascii, map);
	encrypt(src, 1, map, dst);
	return dst;
}

void
test(const char *src)
{
	char dst[1024];
	size_t key;

	printf("%s\n", src);
	for (key = 1; key < sizeof(ascii) - 1; key++)
		printf("%zu %s\n", key, decrypt(src, key, dst));
	printf("\n");
}

int
main(void)
{
	test("JQmc uQiZ yKTHmKmNfafyQN fZu aHH Emuc?");
	test("q mOiKK MoqK iAeIWEMqCA yiMoCg qK AC wCAmiI KieOIi.");
	test("mGAKYakqoakWGAe, OGq kYO ywyYO iyO!");

	return 0;
}
