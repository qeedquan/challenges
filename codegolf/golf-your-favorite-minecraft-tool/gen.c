/*

In Minecraft, the default item textures are all reasonably simple 16×16 pixel images, which makes them seem ideal for golfing.

Below are simplified textures of the five "core" diamond tools in Minecraft: pickaxe, shovel, axe, sword, and hoe.

The images shown are enlarged to show their detail. Click on an image to view its correctly sized 16×16 pixel version.

To make golfing easier, I've modified each of them from the originals to only use the five same 24-bit RGB colors:

R=75 G=82 B=73 for the background.
R=51 G=235 B=203 for the diamond tool heads.
R=14 G=63 B=54 for the diamond outlines.
R=137 G=103 B=39 for the wooden handle core.
R=40 G=30 B=11 for the wooden handle outlines.
Choose your favorite tool out of the five and write a program that outputs its simplified 16×16 pixel texture in any common lossless truecolor image format (such as bpm, png, ppm, etc.).

So, for example, if you chose the axe, you would write a program that outputs this image: axe example

No input should be taken and a web connection should not be required. The image can be output as a file with the name of your choice, or the raw image file data can be output to stdout, or you can simply display the image.

You only need to choose one of the five images. The program that outputs any one of the five images in the fewest number of bytes is the winner.

You may write programs for more than one of the images, but only the one with the minimum number of bytes counts towards your score. If there's a tie, the highest voted post wins.

If you enjoy PPCG and play Minecraft, I invite you to come join our trial Minecraft server. Just ask in the dedicated chatroom.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	const void *data;
	size_t size;
} Asset;

const uint8_t pickaxe[] = {
#embed "pickaxe.png"
};

const uint8_t shovel[] = {
#embed "shovel.png"
};

const uint8_t axe[] = {
#embed "axe.png"
};

const uint8_t sword[] = {
#embed "sword.png"
};

const uint8_t hoe[] = {
#embed "hoe.png"
};

int
main()
{
	static const Asset assets[] = {
		{ pickaxe, sizeof(pickaxe) },
		{ shovel, sizeof(shovel) },
		{ axe, sizeof(axe) },
		{ sword, sizeof(sword) },
		{ hoe, sizeof(hoe) },
	};

	const Asset *asset;

	srand(time(NULL));
	asset = &assets[rand() % nelem(assets)];
	fwrite(asset->data, asset->size, 1, stdout);

	return 0;
}
